#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"
using namespace std;

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image bild;
	GameWindow()
		: Window(1920, 1080)
	{
		set_caption("Gosu Tutorial Game richtig GG");
	}

	int x_1=640;											//Startwert Fortbewegung linker Char
	int x_1_faust = 640;
	int x_2=1280;											//Startwert Fortbewegung rechter Char
	int x_2_faust = 1280;
	int breite=30;											//breite Char
	int breite_faust=20;
	int hoehe_faust = 5;
	int hoehe = 30;											//Höhe Char
	int y_1 = 780;											//Startwert Höhe linker Char
	int y_1_faust = 810;
	int y_2 = 780;											//Startwert Höhe rechter Char
	int y_2_faust = 810;
	int leben_li = 3;
	int leben_re = 3;
	int herz_y = 50;
	int herz_x = 50;
	int herz_x_2 = 2 * herz_x;
	int herz_x_3 = 3 * herz_x;
	int herz_x_1_2 = 50;
	int herz_x_2_2 = 2 * herz_x_1_2;
	int herz_x_3_2 = 3 * herz_x_1_2;
	int r;
	int b;
	int breite_play=500;
	int hoehe_play=150;
	int breite_end = 50;
	int hoehe_end = 50;
	int breite_maus=10;
	int hoehe_maus=10;
	int x_maus = 960;
	int y_maus = 540;

	enum kapitel {
		menu,
		game,
		winner,
	};

	kapitel spielabschnitt = menu;
	
	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		if (spielabschnitt == menu) {
			Gosu::Graphics::draw_rect(
				(1920 - breite_play) / 2, (1080 - (hoehe_play)) / 2, breite_play, hoehe_play, Gosu::Color::YELLOW, 0.0			//Play Button
			);
			Gosu::Graphics::draw_rect(
				(1920 - 2*breite_end),   hoehe_end , breite_end, hoehe_end, Gosu::Color::RED, 0.0			//End Button
			);
			Gosu::Graphics::draw_rect(
				x_maus, y_maus, breite_maus, hoehe_maus, Gosu::Color::GREEN, 0.0			//Cursor
			);
		};

		if (spielabschnitt == game) {
			Gosu::Graphics::draw_rect(
				x_1, 810, breite, hoehe, Gosu::Color::RED, 0.0			//dummy linker Char
			);
			Gosu::Graphics::draw_rect(
				x_1, y_1, breite, hoehe, Gosu::Color::RED, 0.0			//dummy linker Char
			);
			Gosu::Graphics::draw_rect(
				x_1_faust + breite - breite_faust, y_1_faust, breite_faust, hoehe_faust, Gosu::Color::RED, 0.0			//Faust linker Char
			);
			Gosu::Graphics::draw_rect(
				x_2, 810, breite, hoehe, Gosu::Color::BLUE, 0.0			//dummy rechter Char
			);
			Gosu::Graphics::draw_rect(
				x_2, y_2, breite, hoehe, Gosu::Color::BLUE, 0.0			//dummy rechter Char
			);
			Gosu::Graphics::draw_rect(
				x_2_faust, y_2_faust, breite_faust, hoehe_faust, Gosu::Color::BLUE, 0.0			//Faust rechter Char
			);
			Gosu::Graphics::draw_rect(
				herz_x, herz_y, 20, 20, Gosu::Color::RED, 0.0			//Herzen linker Char
			);
			Gosu::Graphics::draw_rect(
				herz_x_2, herz_y, 20, 20, Gosu::Color::RED, 0.0
			);
			Gosu::Graphics::draw_rect(
				herz_x_3, herz_y, 20, 20, Gosu::Color::RED, 0.0
			);
			Gosu::Graphics::draw_rect(
				herz_x_1_2 + 1710, herz_y, 20, 20, Gosu::Color::RED, 0.0			//Herzen rechter Char
			);
			Gosu::Graphics::draw_rect(
				herz_x_2_2 + 1710, herz_y, 20, 20, Gosu::Color::RED, 0.0
			);
			Gosu::Graphics::draw_rect(
				herz_x_3_2 + 1710, herz_y, 20, 20, Gosu::Color::RED, 0.0
			);
		};
		if (spielabschnitt == winner) {
			Gosu::Graphics::draw_rect(
				(1920-breite)/2, (1080-(2*hoehe))/2, breite, 2*hoehe, Gosu::Color::Color(r,0,b), 0.0
			);
			Gosu::Graphics::draw_rect(
				(1920 - breite) / 2, ((1080 - (2 * hoehe))/2)-(hoehe/3), breite, hoehe/3, Gosu::Color::YELLOW, 0.0
			);
		}
	}
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		if (input().down(Gosu::KB_ESCAPE)) {
			spielabschnitt = menu;
			leben_li = 3;
			leben_re = 3;
		}



		if (spielabschnitt == winner) {
			if (leben_li <= 0) {
				r = 0;
				b = 255;
			}
			if (leben_re <= 0) {
				r = 255;
				b = 0;
			}
			if (input().down(Gosu::MS_LEFT)) {
				spielabschnitt = menu;
			}
		}

		if (spielabschnitt == menu) {
			x_maus = input().mouse_x();
			y_maus = input().mouse_y();
			if (input().down(Gosu::MS_LEFT) && (((1920 - breite_play) / 2) < x_maus)&&(x_maus < ((1920 + breite_play) / 2)) && (((1080 - hoehe_play) / 2) < y_maus)&&(y_maus <( (1080 + hoehe_play) / 2))) {
				spielabschnitt = game;
			}
			if (input().down(Gosu::MS_LEFT) && ((1920 - 2*breite_end< x_maus) && (x_maus < (1920 - breite_end) ) && (( hoehe_end)  < y_maus) && (y_maus <( 2*hoehe_end) ))) {
				close();
			}
		};

		if (spielabschnitt == game) {

			if (leben_li <= 0 || leben_re <= 0) {
				spielabschnitt = winner;
			}

			if (x_2_faust < (x_1 + breite)&~input().down(Gosu::KB_S)&& ~ ((x_1_faust + breite_faust) > x_2 & ~input().down(Gosu::KB_DOWN))) {				//Anfänge Hitlogik
				leben_li--;
				x_1 = 640;											
				x_1_faust = 640;
				x_2 = 1280;											
				x_2_faust = 1280;

			}

			if ((x_1_faust + breite_faust) > x_2 & ~input().down(Gosu::KB_DOWN)&& ~ (x_2_faust < (x_1 + breite)&~input().down(Gosu::KB_S))) {
				leben_re--;
				x_1 = 640;
				x_1_faust = 640;
				x_2 = 1280;
				x_2_faust = 1280;
			}


			if (leben_li == 3) {
				herz_x = 50;
				herz_x_2 = herz_x * 2;
				herz_x_3 = herz_x * 3;
			};
			if (leben_li == 2) {
				herz_x = 50;
				herz_x_2 = herz_x * 2;
				herz_x_3 = herz_x * 2;
			};
			if (leben_li == 1) {
				herz_x = 50;
				herz_x_2 = herz_x ;
				herz_x_3 = herz_x ;
			};

			if (leben_re == 3) {
				herz_x_3_2 = 150;
				herz_x_2_2 = 100;
				herz_x_1_2 = 50;
			};
			if (leben_re == 2) {
				herz_x_3_2 = 150;
				herz_x_1_2 = 100;
				herz_x_2_2 = 100;
			
			};
			if (leben_re == 1) {
				herz_x_3_2 = 150;
				herz_x_1_2 = 150;
				herz_x_2_2 = 150;
			
			};




			if (x_1 < 1860 && x_1 < x_2 - breite - 5) {						//Bewegungslogik linker Char
				if (input().down(Gosu::KB_D)) {
					x_1 = x_1 + 5;
				}
			}
			if (x_1 > 30) {
				if (input().down(Gosu::KB_A)) {
					x_1 = x_1 - 5;
				}
			}
			if (input().down(Gosu::KB_S)) {								//Ducklogik linker Char
				y_1 = 810;
				y_1_faust = 810;
			}
			else {
				y_1 = 780;
				y_1_faust = 800;
			}
			if (input().down(Gosu::KB_W) & ~input().down(Gosu::KB_S)) {								//Schlaglogik linker Char
				
					x_1_faust = x_1 + 20;
				
			}
				
			else {
				x_1_faust = x_1;
			}



			if (x_2 < 1860) {											//Bewegungslogik rechter Char
				if (input().down(Gosu::KB_RIGHT)) {
					x_2 = x_2 + 5;
				}
			}
			if (x_2 > 30 && x_2 > x_1 + breite + 5) {
				if (input().down(Gosu::KB_LEFT)) {
					x_2 = x_2 - 5;
				}
			}
			if (input().down(Gosu::KB_DOWN)) {							//Ducklogik rechter Char
				y_2 = 810;
				y_2_faust = 810;
			}
			else {
				y_2 = 780;
				y_2_faust = 800;
			}
			if (input().down(Gosu::KB_UP)&~input().down(Gosu::KB_DOWN)) {								//Schlaglogik rechter Char
				x_2_faust = x_2 - 20;
			}
			else {
				x_2_faust = x_2;
			}
		};


	}
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();

}
