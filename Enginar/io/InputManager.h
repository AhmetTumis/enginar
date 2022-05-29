#pragma once
#include <SDL.h>
#include <iostream>
#include <unordered_map>
#include <SDL_events.h>
#include "../common/Vector.h"

using namespace std;

class InputManager
{
public:

	inline static InputManager* instance;

	inline static InputManager* getInstance()
	{
		return instance;
	}

	InputManager();

	void ListenEvent(SDL_Event event);

	bool isDown(SDL_Scancode key);
	bool isDown(string key);
	bool isDown(SDL_Keycode key);

	bool isPressing(SDL_Scancode key);
	bool isPressing(string key);
	bool isPressing(SDL_Keycode key);

	vector2* getMousePosition() 
	{
		return mousePosition;
	}

private:
	void updateState();
	void updateIsPressedState();
	void updateMouseState();
	const Uint8* keyStates;
	Uint8* keyPressedStates;
	static unordered_map<string, SDL_Scancode> keyMap;

	vector2* mousePosition;
};
