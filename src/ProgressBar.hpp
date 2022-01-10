#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "globals.hpp"

using namespace sf;




class ProgressBar {
	public:
		ProgressBar() {
			progressBar.setPosition(marginLeft, marginTop);
			progressBar.setSize(Vector2f(0, 20));
			progressBar.setFillColor(Color::Black);

			outlineBar.setPosition(marginLeft, marginTop);
			outlineBar.setSize(Vector2f(WINDOW_WIDTH-20, 20));
			outlineBar.setOutlineColor(Color::Blue);
			outlineBar.setOutlineThickness(2.f);
		}
		void draw(RenderWindow *window) {
			window->draw(outlineBar);
			window->draw(progressBar);
		}
		void setProgress(Music *song) {
			float duration = song->getDuration().asSeconds();
			float listenTime = song->getPlayingOffset().asSeconds();
			float ratio = listenTime / duration;
			
			int barLength = WINDOW_WIDTH-marginLeft-marginRight;
			progressBar.setSize(Vector2f((float)(barLength*ratio), (float)20));
		}
	private:
		RectangleShape outlineBar;
		RectangleShape progressBar;
		int marginLeft = 10;
		int marginTop = 10;
		int marginRight = 20;
};