#include "InputManager.h"

InputManager::InputManager()
{
	instance = this;

	updateState();
	updateIsPressedState();

	mousePosition = new vector2(0, 0);
}

void InputManager::updateState()
{
	keyStates = SDL_GetKeyboardState(nullptr);
}

void InputManager::updateIsPressedState()
{
	keyPressedStates = const_cast<Uint8*>(SDL_GetKeyboardState(nullptr));
}

void InputManager::updateMouseState()
{
}

void InputManager::ListenEvent(SDL_Event event)
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_KEYDOWN: 
			case SDL_KEYUP:
				updateState();
				if (event.key.repeat == false)
				{
					updateIsPressedState();
				}
				break;
		}

		int mx;
		int my;

		SDL_PumpEvents();

		SDL_GetMouseState(&mx, &my);


		mousePosition->x = mx;
		mousePosition->y = my;
	}
}

bool InputManager::isDown(SDL_Scancode key)
{
	if (keyPressedStates[key] == 1)
	{
		keyPressedStates[key] = 0;
		return true;
	}
	return false;
}

bool InputManager::isDown(string key)
{
	SDL_Scancode scanCode = keyMap[key];
	return isDown(scanCode);
}

bool InputManager::isDown(SDL_Keycode key)
{
	SDL_Scancode scanCode = SDL_GetScancodeFromKey(key);
	return isDown(scanCode);
}

bool InputManager::isPressing(SDL_Scancode key)
{
	return keyPressedStates[key];
}

bool InputManager::isPressing(string key)
{
	SDL_Scancode scanCode = keyMap[key];
	return isPressing(scanCode);
}

bool InputManager::isPressing(SDL_Keycode key)
{
	SDL_Scancode scanCode = SDL_GetScancodeFromKey(key);
	return isPressing(scanCode);
}

unordered_map<string, SDL_Scancode> InputManager::keyMap = {
	{"unknown", SDL_SCANCODE_UNKNOWN},

	{"a", SDL_SCANCODE_A},
	{"b", SDL_SCANCODE_B},
	{"c", SDL_SCANCODE_C},
	{"d", SDL_SCANCODE_D},
	{"e", SDL_SCANCODE_E},
	{"f", SDL_SCANCODE_F},
	{"g", SDL_SCANCODE_G},
	{"h", SDL_SCANCODE_H},
	{"i", SDL_SCANCODE_I},
	{"j", SDL_SCANCODE_J},
	{"k", SDL_SCANCODE_K},
	{"l", SDL_SCANCODE_L},
	{"m", SDL_SCANCODE_M},
	{"n", SDL_SCANCODE_N},
	{"o", SDL_SCANCODE_O},
	{"p", SDL_SCANCODE_P},
	{"q", SDL_SCANCODE_Q},
	{"r", SDL_SCANCODE_R},
	{"s", SDL_SCANCODE_S},
	{"t", SDL_SCANCODE_T},
	{"u", SDL_SCANCODE_U},
	{"v", SDL_SCANCODE_V},
	{"w", SDL_SCANCODE_W},
	{"x", SDL_SCANCODE_X},
	{"y", SDL_SCANCODE_Y},
	{"z", SDL_SCANCODE_Z},

	{"1", SDL_SCANCODE_1},
	{"2", SDL_SCANCODE_2},
	{"3", SDL_SCANCODE_3},
	{"4", SDL_SCANCODE_4},
	{"5", SDL_SCANCODE_5},
	{"6", SDL_SCANCODE_6},
	{"7", SDL_SCANCODE_7},
	{"8", SDL_SCANCODE_8},
	{"9", SDL_SCANCODE_9},
	{"0", SDL_SCANCODE_0},

	{"return", SDL_SCANCODE_RETURN},
	{"escape", SDL_SCANCODE_ESCAPE},
	{"backspace", SDL_SCANCODE_BACKSPACE},
	{"tab", SDL_SCANCODE_TAB},
	{"space", SDL_SCANCODE_SPACE},

	{"-", SDL_SCANCODE_MINUS},
	{"=", SDL_SCANCODE_EQUALS},
	{"[", SDL_SCANCODE_LEFTBRACKET},
	{"]", SDL_SCANCODE_RIGHTBRACKET},
	{"\\", SDL_SCANCODE_BACKSLASH},
	{"nonus#", SDL_SCANCODE_NONUSHASH},
	{";", SDL_SCANCODE_SEMICOLON},
	{"'", SDL_SCANCODE_APOSTROPHE},
	{"`", SDL_SCANCODE_GRAVE},
	{",", SDL_SCANCODE_COMMA},
	{".", SDL_SCANCODE_PERIOD},
	{"/", SDL_SCANCODE_SLASH},

	{"capslock", SDL_SCANCODE_CAPSLOCK},

	{"f1", SDL_SCANCODE_F1},
	{"f2", SDL_SCANCODE_F2},
	{"f3", SDL_SCANCODE_F3},
	{"f4", SDL_SCANCODE_F4},
	{"f5", SDL_SCANCODE_F5},
	{"f6", SDL_SCANCODE_F6},
	{"f7", SDL_SCANCODE_F7},
	{"f8", SDL_SCANCODE_F8},
	{"f9", SDL_SCANCODE_F9},
	{"f10", SDL_SCANCODE_F10},
	{"f11", SDL_SCANCODE_F11},
	{"f12", SDL_SCANCODE_F12},

	{"printscreen", SDL_SCANCODE_PRINTSCREEN},
	{"scrolllock", SDL_SCANCODE_SCROLLLOCK},
	{"pause", SDL_SCANCODE_PAUSE},
	{"insert", SDL_SCANCODE_INSERT},
	{"home", SDL_SCANCODE_HOME},
	{"pageup", SDL_SCANCODE_PAGEUP},
	{"delete", SDL_SCANCODE_DELETE},
	{"end", SDL_SCANCODE_END},
	{"pagedown", SDL_SCANCODE_PAGEDOWN},
	{"right", SDL_SCANCODE_RIGHT},
	{"left", SDL_SCANCODE_LEFT},
	{"down", SDL_SCANCODE_DOWN},
	{"up", SDL_SCANCODE_UP},

	{"numlock", SDL_SCANCODE_NUMLOCKCLEAR},
	{"kp/", SDL_SCANCODE_KP_DIVIDE},
	{"kp*", SDL_SCANCODE_KP_MULTIPLY},
	{"kp-", SDL_SCANCODE_KP_MINUS},
	{"kp+", SDL_SCANCODE_KP_PLUS},
	{"kpenter", SDL_SCANCODE_KP_ENTER},
	{"kp1", SDL_SCANCODE_KP_1},
	{"kp2", SDL_SCANCODE_KP_2},
	{"kp3", SDL_SCANCODE_KP_3},
	{"kp4", SDL_SCANCODE_KP_4},
	{"kp5", SDL_SCANCODE_KP_5},
	{"kp6", SDL_SCANCODE_KP_6},
	{"kp7", SDL_SCANCODE_KP_7},
	{"kp8", SDL_SCANCODE_KP_8},
	{"kp9", SDL_SCANCODE_KP_9},
	{"kp0", SDL_SCANCODE_KP_0},
	{"kp.", SDL_SCANCODE_KP_PERIOD},

	{"nonusbackslash", SDL_SCANCODE_NONUSBACKSLASH},
	{"application", SDL_SCANCODE_APPLICATION},
	{"power", SDL_SCANCODE_POWER},
	{"kp=", SDL_SCANCODE_KP_EQUALS},
	{"f13", SDL_SCANCODE_F13},
	{"f14", SDL_SCANCODE_F14},
	{"f15", SDL_SCANCODE_F15},
	{"f16", SDL_SCANCODE_F16},
	{"f17", SDL_SCANCODE_F17},
	{"f18", SDL_SCANCODE_F18},
	{"f19", SDL_SCANCODE_F19},
	{"f20", SDL_SCANCODE_F20},
	{"f21", SDL_SCANCODE_F21},
	{"f22", SDL_SCANCODE_F22},
	{"f23", SDL_SCANCODE_F23},
	{"f24", SDL_SCANCODE_F24},
	{"execute", SDL_SCANCODE_EXECUTE},
	{"help", SDL_SCANCODE_HELP},
	{"menu", SDL_SCANCODE_MENU},
	{"select", SDL_SCANCODE_SELECT},
	{"stop", SDL_SCANCODE_STOP},
	{"again", SDL_SCANCODE_AGAIN},
	{"undo", SDL_SCANCODE_UNDO},
	{"cut", SDL_SCANCODE_CUT},
	{"copy", SDL_SCANCODE_COPY},
	{"paste", SDL_SCANCODE_PASTE},
	{"find", SDL_SCANCODE_FIND},
	{"mute", SDL_SCANCODE_MUTE},
	{"volumeup", SDL_SCANCODE_VOLUMEUP},
	{"volumedown", SDL_SCANCODE_VOLUMEDOWN},
	{"kp,", SDL_SCANCODE_KP_COMMA},
	{"kp=400", SDL_SCANCODE_KP_EQUALSAS400},

	{"international1", SDL_SCANCODE_INTERNATIONAL1},
	{"international2", SDL_SCANCODE_INTERNATIONAL2},
	{"international3", SDL_SCANCODE_INTERNATIONAL3},
	{"international4", SDL_SCANCODE_INTERNATIONAL4},
	{"international5", SDL_SCANCODE_INTERNATIONAL5},
	{"international6", SDL_SCANCODE_INTERNATIONAL6},
	{"international7", SDL_SCANCODE_INTERNATIONAL7},
	{"international8", SDL_SCANCODE_INTERNATIONAL8},
	{"international9", SDL_SCANCODE_INTERNATIONAL9},
	{"lang1", SDL_SCANCODE_LANG1},
	{"lang2", SDL_SCANCODE_LANG2},
	{"lang3", SDL_SCANCODE_LANG3},
	{"lang4", SDL_SCANCODE_LANG4},
	{"lang5", SDL_SCANCODE_LANG5},
	{"lang6", SDL_SCANCODE_LANG6},
	{"lang7", SDL_SCANCODE_LANG7},
	{"lang8", SDL_SCANCODE_LANG8},
	{"lang9", SDL_SCANCODE_LANG9},

	{"alterase", SDL_SCANCODE_ALTERASE},
	{"sysreq", SDL_SCANCODE_SYSREQ},
	{"cancel", SDL_SCANCODE_CANCEL},
	{"clear", SDL_SCANCODE_CLEAR},
	{"prior", SDL_SCANCODE_PRIOR},
	{"return2", SDL_SCANCODE_RETURN2},
	{"separator", SDL_SCANCODE_SEPARATOR},
	{"out", SDL_SCANCODE_OUT},
	{"oper", SDL_SCANCODE_OPER},
	{"clearagain", SDL_SCANCODE_CLEARAGAIN},
	{"crsel", SDL_SCANCODE_CRSEL},
	{"exsel", SDL_SCANCODE_EXSEL},

	{"kp00", SDL_SCANCODE_KP_00},
	{"kp000", SDL_SCANCODE_KP_000},
	{"thsousandsseparator", SDL_SCANCODE_THOUSANDSSEPARATOR},
	{"decimalseparator", SDL_SCANCODE_DECIMALSEPARATOR},
	{"currencyunit", SDL_SCANCODE_CURRENCYUNIT},
	{"currencysubunit", SDL_SCANCODE_CURRENCYSUBUNIT},
	{"kp(", SDL_SCANCODE_KP_LEFTPAREN},
	{"kp)", SDL_SCANCODE_KP_RIGHTPAREN},
	{"kp{", SDL_SCANCODE_KP_LEFTBRACE},
	{"kp}", SDL_SCANCODE_KP_RIGHTBRACE},
	{"kptab", SDL_SCANCODE_KP_TAB},
	{"kpbackspace", SDL_SCANCODE_KP_BACKSPACE},
	{"kpa", SDL_SCANCODE_KP_A},
	{"kpb", SDL_SCANCODE_KP_B},
	{"kpc", SDL_SCANCODE_KP_C},
	{"kpd", SDL_SCANCODE_KP_D},
	{"kpe", SDL_SCANCODE_KP_E},
	{"kpf", SDL_SCANCODE_KP_F},
	{"kpxor", SDL_SCANCODE_KP_XOR},
	{"kpower", SDL_SCANCODE_KP_POWER},
	{"kp%", SDL_SCANCODE_KP_PERCENT},
	{"kp<", SDL_SCANCODE_KP_LESS},
	{"kp>", SDL_SCANCODE_KP_GREATER},
	{"kp&", SDL_SCANCODE_KP_AMPERSAND},
	{"kp&&", SDL_SCANCODE_KP_DBLAMPERSAND},
	{"kp|", SDL_SCANCODE_KP_VERTICALBAR},
	{"kp||", SDL_SCANCODE_KP_DBLVERTICALBAR},
	{"kp:", SDL_SCANCODE_KP_COLON},
	{"kp#", SDL_SCANCODE_KP_HASH},
	{"kp ", SDL_SCANCODE_KP_SPACE},
	{"kp@", SDL_SCANCODE_KP_AT},
	{"kp!", SDL_SCANCODE_KP_EXCLAM},
	{"kpmemstore", SDL_SCANCODE_KP_MEMSTORE},
	{"kpmemrecall", SDL_SCANCODE_KP_MEMRECALL},
	{"kpmemclear", SDL_SCANCODE_KP_MEMCLEAR},
	{"kpmem+", SDL_SCANCODE_KP_MEMADD},
	{"kpmem-", SDL_SCANCODE_KP_MEMSUBTRACT},
	{"kpmem*", SDL_SCANCODE_KP_MEMMULTIPLY},
	{"kpmem/", SDL_SCANCODE_KP_MEMDIVIDE},
	{"kp+-", SDL_SCANCODE_KP_PLUSMINUS},
	{"kpclear", SDL_SCANCODE_KP_CLEAR},
	{"kpclearentry", SDL_SCANCODE_KP_CLEARENTRY},
	{"kpbinary", SDL_SCANCODE_KP_BINARY},
	{"kpoctal", SDL_SCANCODE_KP_OCTAL},
	{"kpdecimal", SDL_SCANCODE_KP_DECIMAL},
	{"kphex", SDL_SCANCODE_KP_HEXADECIMAL},

	{"lctrl", SDL_SCANCODE_LCTRL},
	{"lshift", SDL_SCANCODE_LSHIFT},
	{"lalt", SDL_SCANCODE_LALT},
	{"lgui", SDL_SCANCODE_LGUI},
	{"rctrl", SDL_SCANCODE_RCTRL},
	{"rshift", SDL_SCANCODE_RSHIFT},
	{"ralt", SDL_SCANCODE_RALT},
	{"rgui", SDL_SCANCODE_RGUI},

	{"mode", SDL_SCANCODE_MODE},

	{"audionext", SDL_SCANCODE_AUDIONEXT},
	{"audioprev", SDL_SCANCODE_AUDIOPREV},
	{"audiostop", SDL_SCANCODE_AUDIOSTOP},
	{"audioplay", SDL_SCANCODE_AUDIOPLAY},
	{"audiomute", SDL_SCANCODE_AUDIOMUTE},
	{"mediaselect", SDL_SCANCODE_MEDIASELECT},
	{"www", SDL_SCANCODE_WWW},
	{"mail", SDL_SCANCODE_MAIL},
	{"calculator", SDL_SCANCODE_CALCULATOR},
	{"computer", SDL_SCANCODE_COMPUTER},
	{"acsearch", SDL_SCANCODE_AC_SEARCH},
	{"achome", SDL_SCANCODE_AC_HOME},
	{"acback", SDL_SCANCODE_AC_BACK},
	{"acforward", SDL_SCANCODE_AC_FORWARD},
	{"acstop", SDL_SCANCODE_AC_STOP},
	{"acrefresh", SDL_SCANCODE_AC_REFRESH},
	{"acbookmarks", SDL_SCANCODE_AC_BOOKMARKS},

	{"brightnessdown", SDL_SCANCODE_BRIGHTNESSDOWN},
	{"brightnessup", SDL_SCANCODE_BRIGHTNESSUP},
	{"displayswitch", SDL_SCANCODE_DISPLAYSWITCH},
	{"kbdillumtoggle", SDL_SCANCODE_KBDILLUMTOGGLE},
	{"kbdillumdown", SDL_SCANCODE_KBDILLUMDOWN},
	{"kbdillumup", SDL_SCANCODE_KBDILLUMUP},
	{"eject", SDL_SCANCODE_EJECT},
	{"sleep", SDL_SCANCODE_SLEEP},

	{"app1", SDL_SCANCODE_APP1},
	{"app2", SDL_SCANCODE_APP2}
};
