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
	int x_1=640;											//Startwert linker Char
	int x_2=1280;											//Startwert rechter Char
	int breite=30;											//breite Char
	int hoehe = 30;
	int y_1 = 780;
	int y_2 = 780;
	
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
			x_2, 810, breite, hoehe, Gosu::Color::BLUE, 0.0		//dummy rechter Char
		);
		Gosu::Graphics::draw_rect(
			x_2, y_2, breite, hoehe, Gosu::Color::BLUE, 0.0		//dummy rechter Char
		);
	}
	
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		if (x_1 < 1860 && x_1<x_2-breite) {						//Bewegungslogik linker Char
			if (input().down(Gosu::KB_D)) {
				x_1 = x_1 + 5;
			}
		}
		if (x_1 > 30) {
			if (input().down(Gosu::KB_A)) {
				x_1 = x_1 - 5;
			}
		}
		if (input().down(Gosu::KB_S)) {							//Ducklogik linker Char
			y_1 = 810;
		}
		else {
			y_1 = 780;
		}



		if (x_2 < 1860) {										//Bewegungslogik rechter Char
			if (input().down(Gosu::KB_RIGHT)) {
				x_2 = x_2 + 5;
			}
		}
		if (x_2 > 30 && x_2>x_1+breite) {
			if (input().down(Gosu::KB_LEFT)) {
				x_2 = x_2 - 5;
			}
		}
		if (input().down(Gosu::KB_DOWN)) {						//Ducklogik rechter Char
			y_2 = 810;
		}
		else {
			y_2 = 780;
		}

	}
};


// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();

}
