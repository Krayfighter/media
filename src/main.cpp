#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ProgressBar.hpp"
#include "MusicPlayer.hpp"

using namespace std;
using namespace sf;



int init(
	RenderWindow* window,
	Font *font,
	Text *text,
	MusicPlayer *song
) {
	window->setFramerateLimit(60);

	text->setPosition(0, 40);
	
	if (!font->loadFromFile("../assets/fonts/Hack-Regular.ttf")) {return EXIT_FAILURE;}
	if(!song->openFromFile("../assets/songs/RaceToMountFuji.wav")) {return EXIT_FAILURE;}


	text->setFont(*font);
	text->setString("Test test to be displayed");
	text->setCharacterSize(25);
	text->setFillColor(Color::Blue);

	song->play();
    song->pause();
	
	return 0;
}


// int main(int argc, char **argv) {
int main() {
	RenderWindow *window = new RenderWindow(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"SFML test window"
	);
	Font font;
	Text text;
	MusicPlayer song;
	ProgressBar progressBar;

	int initOut = init(
		window, &font,
		&text, &song
	);

	if (initOut != 0) {return initOut;}

	bool playing = true;

	while(window->isOpen()) {
		Event event;
		while(window->pollEvent(event)) {
			if (event.type == Event::Closed) {
				window->close();
			}
			if (event.type == Event::EventType::KeyPressed) {
				if (event.key.code == Keyboard::Space) {
					if (playing == true) {
						playing = false;
						song.pause();
					}else {
						playing = true;
						song.play();
					}
				}
				
				if (event.key.code == Keyboard::Left) {
					auto current = song.getPlayingOffset()-seconds(2.f);
					if (current < seconds(0)) {
						song.setPlayingOffset(seconds(0.f));
					}
					else {
						song.setPlayingOffset(current-seconds(2.f));
					}
				}
				else if (event.key.code == Keyboard::Right) {
					auto current = song.getPlayingOffset();
					song.setPlayingOffset(current+seconds(2.f));
				}
				else if (event.key.code == Keyboard::Escape) {
					return 0;
				}
			}
		}
		window->clear(Color(25, 75, 100));
		window->draw(text);
		progressBar.setProgress(&song);
		progressBar.draw(window);
		window->display();
	}

	return EXIT_SUCCESS;

}