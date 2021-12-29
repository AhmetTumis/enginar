#pragma once

#include "Window.h"

class TextureManager
{
public:
	static TextureManager* getInstance() 
	{
		static TextureManager instance;
		return &instance;
	}
	
	Window* getWindow() { return window; };
	void addTextureToWindow(Texture* texture);

	void SetWindow(Window* _window) { window = _window; }

private:
	TextureManager(){}
	Window* window;
};

