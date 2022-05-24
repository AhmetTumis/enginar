#pragma once
#include <SDL.h>
#include <iostream>
#include <unordered_map>
#include <SDL_events.h>

using namespace std;

class InputManager
{
public:
	static InputManager* getInstance()
	{
		static InputManager instance;
		return &instance;
	}

	InputManager();

	void ListenEvent(SDL_Event event);

	bool isDown(SDL_Scancode key);
	bool isDown(string key);
	bool isDown(SDL_Keycode key);

private:
	void updateState();
	void updateIsPressedState();
	const Uint8* keyStates;
	Uint8* keyPressedStates;
	static unordered_map<string, SDL_Scancode> keyMap;
};
