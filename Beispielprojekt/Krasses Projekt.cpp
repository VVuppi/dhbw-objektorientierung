#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

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
	
	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Gosu::Graphics::draw_rect(
			x_1, 810, breite, hoehe, Gosu::Color::RED,0.0			//dummy linker Char
		);
		Gosu::Graphics::draw_rect(
			x_1, y_1, breite, hoehe, Gosu::Color::RED, 0.0			//dummy linker Char
		);
		Gosu::Graphics::draw_rect(
			x_1_faust+breite-breite_faust, y_1_faust, breite_faust, hoehe_faust, Gosu::Color::RED, 0.0			//Faust linker Char
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
	}
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		if (x_1 < 1860 && x_1<x_2-breite-5) {						//Bewegungslogik linker Char
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
			y_2_faust = 810;
		}
		else {
			y_1 = 780;
			y_1_faust = 800;
		}
		if (input().down(Gosu::KB_W) && ~input().down(Gosu::KB_S)) {								//Schlaglogik linker Char
			x_1_faust = x_1+20;
		}
		else {
			x_1_faust = x_1;
		}



		if (x_2 < 1860) {											//Bewegungslogik rechter Char
			if (input().down(Gosu::KB_RIGHT)) {
				x_2 = x_2 + 5;
			}
		}
		if (x_2 > 30 && x_2>x_1+breite+5) {
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
		if (input().down(Gosu::KB_UP)&&~input().down(Gosu::KB_DOWN)) {								//Schlaglogik linker Char
			x_2_faust = x_2 -20;
		}
		else {
			x_2_faust = x_2;
		}
	}
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();

}
