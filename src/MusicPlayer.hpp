#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "globals.hpp"

using namespace sf;



class MusicPlayer: public Music {
	public:
		MusicPlayer() {
			setVolume(50);
		}
		void togglePlaying() {
			if(playing) {playing = false;}
			else {playing = true;}
		}
	private:
		bool playing = false;
};