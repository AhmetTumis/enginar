#pragma once
#include <map>
#include "SDL_keycode.h"

using namespace std;

class InputManager
{
public:
	map<SDL_Keycode, bool> keys;

	inline void pressKey(SDL_Keycode key) { keys[key] = true; };
	inline void releaseKey(SDL_Keycode key) { keys[key] = false; };

	inline bool getKeyState(SDL_Keycode key) { return keys[key]; };
};

