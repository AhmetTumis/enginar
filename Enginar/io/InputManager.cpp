#include "InputManager.h"


/*





*/
/*const SDL_Keycode* Keyboard::createKeyMap()
{
	static SDL_Keycode k[Keyboard::KEY_MAX_ENUM] = {SDLK_UNKNOWN};

	k[Keyboard::KEY_UNKNOWN] = SDLK_UNKNOWN;

	k[Keyboard::KEY_RETURN] = SDLK_RETURN;
	k[Keyboard::KEY_ESCAPE] = SDLK_ESCAPE;
	k[Keyboard::KEY_BACKSPACE] = SDLK_BACKSPACE;
	k[Keyboard::KEY_TAB] = SDLK_TAB;
	k[Keyboard::KEY_SPACE] = SDLK_SPACE;
	k[Keyboard::KEY_EXCLAIM] = SDLK_EXCLAIM;
	k[Keyboard::KEY_QUOTEDBL] = SDLK_QUOTEDBL;
	k[Keyboard::KEY_HASH] = SDLK_HASH;
	k[Keyboard::KEY_PERCENT] = SDLK_PERCENT;
	k[Keyboard::KEY_DOLLAR] = SDLK_DOLLAR;
	k[Keyboard::KEY_AMPERSAND] = SDLK_AMPERSAND;
	k[Keyboard::KEY_QUOTE] = SDLK_QUOTE;
	k[Keyboard::KEY_LEFTPAREN] = SDLK_LEFTPAREN;
	k[Keyboard::KEY_RIGHTPAREN] = SDLK_RIGHTPAREN;
	k[Keyboard::KEY_ASTERISK] = SDLK_ASTERISK;
	k[Keyboard::KEY_PLUS] = SDLK_PLUS;
	k[Keyboard::KEY_COMMA] = SDLK_COMMA;
	k[Keyboard::KEY_MINUS] = SDLK_MINUS;
	k[Keyboard::KEY_PERIOD] = SDLK_PERIOD;
	k[Keyboard::KEY_SLASH] = SDLK_SLASH;
	k[Keyboard::KEY_0] = SDLK_0;
	k[Keyboard::KEY_1] = SDLK_1;
	k[Keyboard::KEY_2] = SDLK_2;
	k[Keyboard::KEY_3] = SDLK_3;
	k[Keyboard::KEY_4] = SDLK_4;
	k[Keyboard::KEY_5] = SDLK_5;
	k[Keyboard::KEY_6] = SDLK_6;
	k[Keyboard::KEY_7] = SDLK_7;
	k[Keyboard::KEY_8] = SDLK_8;
	k[Keyboard::KEY_9] = SDLK_9;
	k[Keyboard::KEY_COLON] = SDLK_COLON;
	k[Keyboard::KEY_SEMICOLON] = SDLK_SEMICOLON;
	k[Keyboard::KEY_LESS] = SDLK_LESS;
	k[Keyboard::KEY_EQUALS] = SDLK_EQUALS;
	k[Keyboard::KEY_GREATER] = SDLK_GREATER;
	k[Keyboard::KEY_QUESTION] = SDLK_QUESTION;
	k[Keyboard::KEY_AT] = SDLK_AT;

	k[Keyboard::KEY_LEFTBRACKET] = SDLK_LEFTBRACKET;
	k[Keyboard::KEY_BACKSLASH] = SDLK_BACKSLASH;
	k[Keyboard::KEY_RIGHTBRACKET] = SDLK_RIGHTBRACKET;
	k[Keyboard::KEY_CARET] = SDLK_CARET;
	k[Keyboard::KEY_UNDERSCORE] = SDLK_UNDERSCORE;
	k[Keyboard::KEY_BACKQUOTE] = SDLK_BACKQUOTE;
	k[Keyboard::KEY_A] = SDLK_a;
	k[Keyboard::KEY_B] = SDLK_b;
	k[Keyboard::KEY_C] = SDLK_c;
	k[Keyboard::KEY_D] = SDLK_d;
	k[Keyboard::KEY_E] = SDLK_e;
	k[Keyboard::KEY_F] = SDLK_f;
	k[Keyboard::KEY_G] = SDLK_g;
	k[Keyboard::KEY_H] = SDLK_h;
	k[Keyboard::KEY_I] = SDLK_i;
	k[Keyboard::KEY_J] = SDLK_j;
	k[Keyboard::KEY_K] = SDLK_k;
	k[Keyboard::KEY_L] = SDLK_l;
	k[Keyboard::KEY_M] = SDLK_m;
	k[Keyboard::KEY_N] = SDLK_n;
	k[Keyboard::KEY_O] = SDLK_o;
	k[Keyboard::KEY_P] = SDLK_p;
	k[Keyboard::KEY_Q] = SDLK_q;
	k[Keyboard::KEY_R] = SDLK_r;
	k[Keyboard::KEY_S] = SDLK_s;
	k[Keyboard::KEY_T] = SDLK_t;
	k[Keyboard::KEY_U] = SDLK_u;
	k[Keyboard::KEY_V] = SDLK_v;
	k[Keyboard::KEY_W] = SDLK_w;
	k[Keyboard::KEY_X] = SDLK_x;
	k[Keyboard::KEY_Y] = SDLK_y;
	k[Keyboard::KEY_Z] = SDLK_z;

	k[Keyboard::KEY_CAPSLOCK] = SDLK_CAPSLOCK;

	k[Keyboard::KEY_F1] = SDLK_F1;
	k[Keyboard::KEY_F2] = SDLK_F2;
	k[Keyboard::KEY_F3] = SDLK_F3;
	k[Keyboard::KEY_F4] = SDLK_F4;
	k[Keyboard::KEY_F5] = SDLK_F5;
	k[Keyboard::KEY_F6] = SDLK_F6;
	k[Keyboard::KEY_F7] = SDLK_F7;
	k[Keyboard::KEY_F8] = SDLK_F8;
	k[Keyboard::KEY_F9] = SDLK_F9;
	k[Keyboard::KEY_F10] = SDLK_F10;
	k[Keyboard::KEY_F11] = SDLK_F11;
	k[Keyboard::KEY_F12] = SDLK_F12;

	k[Keyboard::KEY_PRINTSCREEN] = SDLK_PRINTSCREEN;
	k[Keyboard::KEY_SCROLLLOCK] = SDLK_SCROLLLOCK;
	k[Keyboard::KEY_PAUSE] = SDLK_PAUSE;
	k[Keyboard::KEY_INSERT] = SDLK_INSERT;
	k[Keyboard::KEY_HOME] = SDLK_HOME;
	k[Keyboard::KEY_PAGEUP] = SDLK_PAGEUP;
	k[Keyboard::KEY_DELETE] = SDLK_DELETE;
	k[Keyboard::KEY_END] = SDLK_END;
	k[Keyboard::KEY_PAGEDOWN] = SDLK_PAGEDOWN;
	k[Keyboard::KEY_RIGHT] = SDLK_RIGHT;
	k[Keyboard::KEY_LEFT] = SDLK_LEFT;
	k[Keyboard::KEY_DOWN] = SDLK_DOWN;
	k[Keyboard::KEY_UP] = SDLK_UP;

	k[Keyboard::KEY_NUMLOCKCLEAR] = SDLK_NUMLOCKCLEAR;
	k[Keyboard::KEY_KP_DIVIDE] = SDLK_KP_DIVIDE;
	k[Keyboard::KEY_KP_MULTIPLY] = SDLK_KP_MULTIPLY;
	k[Keyboard::KEY_KP_MINUS] = SDLK_KP_MINUS;
	k[Keyboard::KEY_KP_PLUS] = SDLK_KP_PLUS;
	k[Keyboard::KEY_KP_ENTER] = SDLK_KP_ENTER;
	k[Keyboard::KEY_KP_0] = SDLK_KP_0;
	k[Keyboard::KEY_KP_1] = SDLK_KP_1;
	k[Keyboard::KEY_KP_2] = SDLK_KP_2;
	k[Keyboard::KEY_KP_3] = SDLK_KP_3;
	k[Keyboard::KEY_KP_4] = SDLK_KP_4;
	k[Keyboard::KEY_KP_5] = SDLK_KP_5;
	k[Keyboard::KEY_KP_6] = SDLK_KP_6;
	k[Keyboard::KEY_KP_7] = SDLK_KP_7;
	k[Keyboard::KEY_KP_8] = SDLK_KP_8;
	k[Keyboard::KEY_KP_9] = SDLK_KP_9;
	k[Keyboard::KEY_KP_PERIOD] = SDLK_KP_PERIOD;
	k[Keyboard::KEY_KP_COMMA] = SDLK_KP_COMMA;
	k[Keyboard::KEY_KP_EQUALS] = SDLK_KP_EQUALS;

	k[Keyboard::KEY_APPLICATION] = SDLK_APPLICATION;
	k[Keyboard::KEY_POWER] = SDLK_POWER;
	k[Keyboard::KEY_F13] = SDLK_F13;
	k[Keyboard::KEY_F14] = SDLK_F14;
	k[Keyboard::KEY_F15] = SDLK_F15;
	k[Keyboard::KEY_F16] = SDLK_F16;
	k[Keyboard::KEY_F17] = SDLK_F17;
	k[Keyboard::KEY_F18] = SDLK_F18;
	k[Keyboard::KEY_F19] = SDLK_F19;
	k[Keyboard::KEY_F20] = SDLK_F20;
	k[Keyboard::KEY_F21] = SDLK_F21;
	k[Keyboard::KEY_F22] = SDLK_F22;
	k[Keyboard::KEY_F23] = SDLK_F23;
	k[Keyboard::KEY_F24] = SDLK_F24;
	k[Keyboard::KEY_EXECUTE] = SDLK_EXECUTE;
	k[Keyboard::KEY_HELP] = SDLK_HELP;
	k[Keyboard::KEY_MENU] = SDLK_MENU;
	k[Keyboard::KEY_SELECT] = SDLK_SELECT;
	k[Keyboard::KEY_STOP] = SDLK_STOP;
	k[Keyboard::KEY_AGAIN] = SDLK_AGAIN;
	k[Keyboard::KEY_UNDO] = SDLK_UNDO;
	k[Keyboard::KEY_CUT] = SDLK_CUT;
	k[Keyboard::KEY_COPY] = SDLK_COPY;
	k[Keyboard::KEY_PASTE] = SDLK_PASTE;
	k[Keyboard::KEY_FIND] = SDLK_FIND;
	k[Keyboard::KEY_MUTE] = SDLK_MUTE;
	k[Keyboard::KEY_VOLUMEUP] = SDLK_VOLUMEUP;
	k[Keyboard::KEY_VOLUMEDOWN] = SDLK_VOLUMEDOWN;

	k[Keyboard::KEY_ALTERASE] = SDLK_ALTERASE;
	k[Keyboard::KEY_SYSREQ] = SDLK_SYSREQ;
	k[Keyboard::KEY_CANCEL] = SDLK_CANCEL;
	k[Keyboard::KEY_CLEAR] = SDLK_CLEAR;
	k[Keyboard::KEY_PRIOR] = SDLK_PRIOR;
	k[Keyboard::KEY_RETURN2] = SDLK_RETURN2;
	k[Keyboard::KEY_SEPARATOR] = SDLK_SEPARATOR;
	k[Keyboard::KEY_OUT] = SDLK_OUT;
	k[Keyboard::KEY_OPER] = SDLK_OPER;
	k[Keyboard::KEY_CLEARAGAIN] = SDLK_CLEARAGAIN;

	k[Keyboard::KEY_THOUSANDSSEPARATOR] = SDLK_THOUSANDSSEPARATOR;
	k[Keyboard::KEY_DECIMALSEPARATOR] = SDLK_DECIMALSEPARATOR;
	k[Keyboard::KEY_CURRENCYUNIT] = SDLK_CURRENCYUNIT;
	k[Keyboard::KEY_CURRENCYSUBUNIT] = SDLK_CURRENCYSUBUNIT;

	k[Keyboard::KEY_LCTRL] = SDLK_LCTRL;
	k[Keyboard::KEY_LSHIFT] = SDLK_LSHIFT;
	k[Keyboard::KEY_LALT] = SDLK_LALT;
	k[Keyboard::KEY_LGUI] = SDLK_LGUI;
	k[Keyboard::KEY_RCTRL] = SDLK_RCTRL;
	k[Keyboard::KEY_RSHIFT] = SDLK_RSHIFT;
	k[Keyboard::KEY_RALT] = SDLK_RALT;
	k[Keyboard::KEY_RGUI] = SDLK_RGUI;

	k[Keyboard::KEY_MODE] = SDLK_MODE;

	k[Keyboard::KEY_AUDIONEXT] = SDLK_AUDIONEXT;
	k[Keyboard::KEY_AUDIOPREV] = SDLK_AUDIOPREV;
	k[Keyboard::KEY_AUDIOSTOP] = SDLK_AUDIOSTOP;
	k[Keyboard::KEY_AUDIOPLAY] = SDLK_AUDIOPLAY;
	k[Keyboard::KEY_AUDIOMUTE] = SDLK_AUDIOMUTE;
	k[Keyboard::KEY_MEDIASELECT] = SDLK_MEDIASELECT;
	k[Keyboard::KEY_WWW] = SDLK_WWW;
	k[Keyboard::KEY_MAIL] = SDLK_MAIL;
	k[Keyboard::KEY_CALCULATOR] = SDLK_CALCULATOR;
	k[Keyboard::KEY_COMPUTER] = SDLK_COMPUTER;
	k[Keyboard::KEY_APP_SEARCH] = SDLK_AC_SEARCH;
	k[Keyboard::KEY_APP_HOME] = SDLK_AC_HOME;
	k[Keyboard::KEY_APP_BACK] = SDLK_AC_BACK;
	k[Keyboard::KEY_APP_FORWARD] = SDLK_AC_FORWARD;
	k[Keyboard::KEY_APP_STOP] = SDLK_AC_STOP;
	k[Keyboard::KEY_APP_REFRESH] = SDLK_AC_REFRESH;
	k[Keyboard::KEY_APP_BOOKMARKS] = SDLK_AC_BOOKMARKS;

	k[Keyboard::KEY_BRIGHTNESSDOWN] = SDLK_BRIGHTNESSDOWN;
	k[Keyboard::KEY_BRIGHTNESSUP] = SDLK_BRIGHTNESSUP;
	k[Keyboard::KEY_DISPLAYSWITCH] = SDLK_DISPLAYSWITCH;
	k[Keyboard::KEY_KBDILLUMTOGGLE] = SDLK_KBDILLUMTOGGLE;
	k[Keyboard::KEY_KBDILLUMDOWN] = SDLK_KBDILLUMDOWN;
	k[Keyboard::KEY_KBDILLUMUP] = SDLK_KBDILLUMUP;
	k[Keyboard::KEY_EJECT] = SDLK_EJECT;
	k[Keyboard::KEY_SLEEP] = SDLK_SLEEP;

	return k;
}

StringMap<Keyboard::Key, Keyboard::KEY_MAX_ENUM>::Entry Keyboard::keyEntries[] =
{
	{"unknown", Keyboard::KEY_UNKNOWN},

	{"return", Keyboard::KEY_RETURN},
	{"escape", Keyboard::KEY_ESCAPE},
	{"backspace", Keyboard::KEY_BACKSPACE},
	{"tab", Keyboard::KEY_TAB},
	{"space", Keyboard::KEY_SPACE},
	{"!", Keyboard::KEY_EXCLAIM},
	{"\"", Keyboard::KEY_QUOTEDBL},
	{"#", Keyboard::KEY_HASH},
	{"%", Keyboard::KEY_PERCENT},
	{"$", Keyboard::KEY_DOLLAR},
	{"&", Keyboard::KEY_AMPERSAND},
	{"'", Keyboard::KEY_QUOTE},
	{"(", Keyboard::KEY_LEFTPAREN},
	{")", Keyboard::KEY_RIGHTPAREN},
	{"*", Keyboard::KEY_ASTERISK},
	{"+", Keyboard::KEY_PLUS},
	{",", Keyboard::KEY_COMMA},
	{"-", Keyboard::KEY_MINUS},
	{".", Keyboard::KEY_PERIOD},
	{"/", Keyboard::KEY_SLASH},
	{"0", Keyboard::KEY_0},
	{"1", Keyboard::KEY_1},
	{"2", Keyboard::KEY_2},
	{"3", Keyboard::KEY_3},
	{"4", Keyboard::KEY_4},
	{"5", Keyboard::KEY_5},
	{"6", Keyboard::KEY_6},
	{"7", Keyboard::KEY_7},
	{"8", Keyboard::KEY_8},
	{"9", Keyboard::KEY_9},
	{":", Keyboard::KEY_COLON},
	{";", Keyboard::KEY_SEMICOLON},
	{"<", Keyboard::KEY_LESS},
	{"=", Keyboard::KEY_EQUALS},
	{">", Keyboard::KEY_GREATER},
	{"?", Keyboard::KEY_QUESTION},
	{"@", Keyboard::KEY_AT},

	{"[", Keyboard::KEY_LEFTBRACKET},
	{"\\", Keyboard::KEY_BACKSLASH},
	{"]", Keyboard::KEY_RIGHTBRACKET},
	{"^", Keyboard::KEY_CARET},
	{"_", Keyboard::KEY_UNDERSCORE},
	{"`", Keyboard::KEY_BACKQUOTE},
	{"a", Keyboard::KEY_A},
	{"b", Keyboard::KEY_B},
	{"c", Keyboard::KEY_C},
	{"d", Keyboard::KEY_D},
	{"e", Keyboard::KEY_E},
	{"f", Keyboard::KEY_F},
	{"g", Keyboard::KEY_G},
	{"h", Keyboard::KEY_H},
	{"i", Keyboard::KEY_I},
	{"j", Keyboard::KEY_J},
	{"k", Keyboard::KEY_K},
	{"l", Keyboard::KEY_L},
	{"m", Keyboard::KEY_M},
	{"n", Keyboard::KEY_N},
	{"o", Keyboard::KEY_O},
	{"p", Keyboard::KEY_P},
	{"q", Keyboard::KEY_Q},
	{"r", Keyboard::KEY_R},
	{"s", Keyboard::KEY_S},
	{"t", Keyboard::KEY_T},
	{"u", Keyboard::KEY_U},
	{"v", Keyboard::KEY_V},
	{"w", Keyboard::KEY_W},
	{"x", Keyboard::KEY_X},
	{"y", Keyboard::KEY_Y},
	{"z", Keyboard::KEY_Z},

	{"capslock", Keyboard::KEY_CAPSLOCK},

	{"f1", Keyboard::KEY_F1},
	{"f2", Keyboard::KEY_F2},
	{"f3", Keyboard::KEY_F3},
	{"f4", Keyboard::KEY_F4},
	{"f5", Keyboard::KEY_F5},
	{"f6", Keyboard::KEY_F6},
	{"f7", Keyboard::KEY_F7},
	{"f8", Keyboard::KEY_F8},
	{"f9", Keyboard::KEY_F9},
	{"f10", Keyboard::KEY_F10},
	{"f11", Keyboard::KEY_F11},
	{"f12", Keyboard::KEY_F12},

	{"printscreen", Keyboard::KEY_PRINTSCREEN},
	{"scrolllock", Keyboard::KEY_SCROLLLOCK},
	{"pause", Keyboard::KEY_PAUSE},
	{"insert", Keyboard::KEY_INSERT},
	{"home", Keyboard::KEY_HOME},
	{"pageup", Keyboard::KEY_PAGEUP},
	{"delete", Keyboard::KEY_DELETE},
	{"end", Keyboard::KEY_END},
	{"pagedown", Keyboard::KEY_PAGEDOWN},
	{"right", Keyboard::KEY_RIGHT},
	{"left", Keyboard::KEY_LEFT},
	{"down", Keyboard::KEY_DOWN},
	{"up", Keyboard::KEY_UP},

	{"numlock", Keyboard::KEY_NUMLOCKCLEAR},
	{"kp/", Keyboard::KEY_KP_DIVIDE},
	{"kp*", Keyboard::KEY_KP_MULTIPLY},
	{"kp-", Keyboard::KEY_KP_MINUS},
	{"kp+", Keyboard::KEY_KP_PLUS},
	{"kpenter", Keyboard::KEY_KP_ENTER},
	{"kp0", Keyboard::KEY_KP_0},
	{"kp1", Keyboard::KEY_KP_1},
	{"kp2", Keyboard::KEY_KP_2},
	{"kp3", Keyboard::KEY_KP_3},
	{"kp4", Keyboard::KEY_KP_4},
	{"kp5", Keyboard::KEY_KP_5},
	{"kp6", Keyboard::KEY_KP_6},
	{"kp7", Keyboard::KEY_KP_7},
	{"kp8", Keyboard::KEY_KP_8},
	{"kp9", Keyboard::KEY_KP_9},
	{"kp.", Keyboard::KEY_KP_PERIOD},
	{"kp,", Keyboard::KEY_KP_COMMA},
	{"kp=", Keyboard::KEY_KP_EQUALS},

	{"application", Keyboard::KEY_APPLICATION},
	{"power", Keyboard::KEY_POWER},
	{"f13", Keyboard::KEY_F13},
	{"f14", Keyboard::KEY_F14},
	{"f15", Keyboard::KEY_F15},
	{"f16", Keyboard::KEY_F16},
	{"f17", Keyboard::KEY_F17},
	{"f18", Keyboard::KEY_F18},
	{"f19", Keyboard::KEY_F19},
	{"f20", Keyboard::KEY_F20},
	{"f21", Keyboard::KEY_F21},
	{"f22", Keyboard::KEY_F22},
	{"f23", Keyboard::KEY_F23},
	{"f24", Keyboard::KEY_F24},
	{"execute", Keyboard::KEY_EXECUTE},
	{"help", Keyboard::KEY_HELP},
	{"menu", Keyboard::KEY_MENU},
	{"select", Keyboard::KEY_SELECT},
	{"stop", Keyboard::KEY_STOP},
	{"again", Keyboard::KEY_AGAIN},
	{"undo", Keyboard::KEY_UNDO},
	{"cut", Keyboard::KEY_CUT},
	{"copy", Keyboard::KEY_COPY},
	{"paste", Keyboard::KEY_PASTE},
	{"find", Keyboard::KEY_FIND},
	{"mute", Keyboard::KEY_MUTE},
	{"volumeup", Keyboard::KEY_VOLUMEUP},
	{"volumedown", Keyboard::KEY_VOLUMEDOWN},

	{"alterase", Keyboard::KEY_ALTERASE},
	{"sysreq", Keyboard::KEY_SYSREQ},
	{"cancel", Keyboard::KEY_CANCEL},
	{"clear", Keyboard::KEY_CLEAR},
	{"prior", Keyboard::KEY_PRIOR},
	{"return2", Keyboard::KEY_RETURN2},
	{"separator", Keyboard::KEY_SEPARATOR},
	{"out", Keyboard::KEY_OUT},
	{"oper", Keyboard::KEY_OPER},
	{"clearagain", Keyboard::KEY_CLEARAGAIN},

	{"thsousandsseparator", Keyboard::KEY_THOUSANDSSEPARATOR},
	{"decimalseparator", Keyboard::KEY_DECIMALSEPARATOR},
	{"currencyunit", Keyboard::KEY_CURRENCYUNIT},
	{"currencysubunit", Keyboard::KEY_CURRENCYSUBUNIT},

	{"lctrl", Keyboard::KEY_LCTRL},
	{"lshift", Keyboard::KEY_LSHIFT},
	{"lalt", Keyboard::KEY_LALT},
	{"lgui", Keyboard::KEY_LGUI},
	{"rctrl", Keyboard::KEY_RCTRL},
	{"rshift", Keyboard::KEY_RSHIFT},
	{"ralt", Keyboard::KEY_RALT},
	{"rgui", Keyboard::KEY_RGUI},

	{"mode", Keyboard::KEY_MODE},

	{"audionext", Keyboard::KEY_AUDIONEXT},
	{"audioprev", Keyboard::KEY_AUDIOPREV},
	{"audiostop", Keyboard::KEY_AUDIOSTOP},
	{"audioplay", Keyboard::KEY_AUDIOPLAY},
	{"audiomute", Keyboard::KEY_AUDIOMUTE},
	{"mediaselect", Keyboard::KEY_MEDIASELECT},
	{"www", Keyboard::KEY_WWW},
	{"mail", Keyboard::KEY_MAIL},
	{"calculator", Keyboard::KEY_CALCULATOR},
	{"computer", Keyboard::KEY_COMPUTER},
	{"appsearch", Keyboard::KEY_APP_SEARCH},
	{"apphome", Keyboard::KEY_APP_HOME},
	{"appback", Keyboard::KEY_APP_BACK},
	{"appforward", Keyboard::KEY_APP_FORWARD},
	{"appstop", Keyboard::KEY_APP_STOP},
	{"apprefresh", Keyboard::KEY_APP_REFRESH},
	{"appbookmarks", Keyboard::KEY_APP_BOOKMARKS},

	{"brightnessdown", Keyboard::KEY_BRIGHTNESSDOWN},
	{"brightnessup", Keyboard::KEY_BRIGHTNESSUP},
	{"displayswitch", Keyboard::KEY_DISPLAYSWITCH},
	{"kbdillumtoggle", Keyboard::KEY_KBDILLUMTOGGLE},
	{"kbdillumdown", Keyboard::KEY_KBDILLUMDOWN},
	{"kbdillumup", Keyboard::KEY_KBDILLUMUP},
	{"eject", Keyboard::KEY_EJECT},
	{"sleep", Keyboard::KEY_SLEEP},
};*/