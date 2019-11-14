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
		: Window(800, 600)
	{
		set_caption("Gosu Tutorial Game richtig GG");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Gosu::Graphics::draw_line(
			x, 20, Gosu::Color::GREEN,
			200, 100, Gosu::Color::GREEN,
			0.0);
		Gosu::Graphics::draw_line(
			x, 30, Gosu::Color::RED,
			200, 100, Gosu::Color::BLUE,
			0.0);
		Gosu::Graphics::draw_line(
			x, 40, Gosu::Color::RED,
			200, 100, Gosu::Color::BLUE,
			0.0);
		Gosu::Graphics::draw_line(
			x, 50, Gosu::Color::RED,
			200, 100, Gosu::Color::YELLOW,
			0.0);
		Gosu::Graphics::draw_line(
			x, 60, Gosu::Color::WHITE,
			200, 100, Gosu::Color::YELLOW,
			0.0);
	}
	int x = 0;
	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		x = (x + 1) % 300;
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
