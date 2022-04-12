#pragma once
#include <SDL.h>
#include <iostream>
#include <unordered_map>

using namespace std;

class InputManager
{
public:
	InputManager();

	void ListenEvent(SDL_Event event);

	bool isDown(SDL_Scancode key);
	bool isDown(string key);
	bool isDown(SDL_Keycode key);

private:
	void updateState();
	const Uint8* keyStates;
	static unordered_map<string, SDL_Scancode> keyMap;
};
