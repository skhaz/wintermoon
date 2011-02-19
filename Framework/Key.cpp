
/*
 *                        __                                                    
 *             __        /\ \__                                                 
 *  __  __  __/\_\    ___\ \ ,_\    __  _ __   ___ ___     ___    ___    ___    
 * /\ \/\ \/\ \/\ \ /' _ `\ \ \/  /'__`\\`'__\' __` __`\  / __`\ / __`\/' _ `\  
 * \ \ \_/ \_/ \ \ \/\ \/\ \ \ \_/\  __/ \ \//\ \/\ \/\ \/\ \L\ \\ \L\ \\ \/\ \ 
 *  \ \___x___/'\ \_\ \_\ \_\ \__\ \____\ \_\\ \_\ \_\ \_\ \____/ \____/ \_\ \_\
 *   \/__//__/   \/_/\/_/\/_/\/__/\/____/\/_/ \/_/\/_/\/_/\/___/ \/___/ \/_/\/_/
 *
 * Copyright (c) 2006 - 2011 Wintermoon Project
 *
 * http://wintermoon.sourceforge.net/
 *
 * License: BSD
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Wintermoon nor the names of its contributors may
 *    be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "Key.h"



WINTERMOON_BEGIN_NAMESPACE

std::map<String, SDLKey> Key::m_keymap;

Key::Key()
: m_key(SDLK_UNKNOWN)
{
}

Key::Key(SDLKey key)
: m_key(key)
{
}

Key::Key(const String& key)
: m_key(SDLK_UNKNOWN)
{
	if (m_keymap.size() != 0)
	{
	}

	else {
		m_keymap["BACKSPACE"] = SDLK_BACKSPACE;
		m_keymap["TAB"] = SDLK_TAB;
		m_keymap["CLEAR"] = SDLK_CLEAR;
		m_keymap["RETURN"] = SDLK_RETURN;
		m_keymap["PAUSE"] = SDLK_PAUSE;
		m_keymap["ESC"] = SDLK_ESCAPE;
		m_keymap["SPACE"] = SDLK_SPACE;
		m_keymap["EXCLAIM"] = SDLK_EXCLAIM;
		m_keymap["QUOTEDBL"] = SDLK_QUOTEDBL;
		m_keymap["HASH"] = SDLK_HASH;
		m_keymap["DOLLAR"] = SDLK_DOLLAR;
		m_keymap["AMPERSAND"] = SDLK_AMPERSAND;
		m_keymap["QUOTE"] = SDLK_QUOTE;
		m_keymap["LEFTPAREN"] = SDLK_LEFTPAREN;
		m_keymap["RIGHTPAREN"] = SDLK_RIGHTPAREN;
		m_keymap["ASTERISK"] = SDLK_ASTERISK;
		m_keymap["PLUS"] = SDLK_PLUS;
		m_keymap["COMMA"] = SDLK_COMMA;
		m_keymap["MINUS"] = SDLK_MINUS;
		m_keymap["PERIOD"] = SDLK_PERIOD;
		m_keymap["SLASH"] = SDLK_SLASH;
		m_keymap["0"] = SDLK_0;
		m_keymap["1"] = SDLK_1;
		m_keymap["2"] = SDLK_2;
		m_keymap["3"] = SDLK_3;
		m_keymap["4"] = SDLK_4;
		m_keymap["5"] = SDLK_5;
		m_keymap["6"] = SDLK_6;
		m_keymap["7"] = SDLK_7;
		m_keymap["8"] = SDLK_8;
		m_keymap["9"] = SDLK_9;
		m_keymap["COLON"] = SDLK_COLON;
		m_keymap["SEMICOLON"] = SDLK_SEMICOLON;
		m_keymap["LESS"] = SDLK_LESS;
		m_keymap["EQUALS"] = SDLK_EQUALS;
		m_keymap["GREATER"] = SDLK_GREATER;
		m_keymap["QUESTION"] = SDLK_QUESTION;
		m_keymap["AT"] = SDLK_AT;
		m_keymap["LEFTBRACKET"] = SDLK_LEFTBRACKET;
		m_keymap["BACKSLASH"] = SDLK_BACKSLASH;
		m_keymap["RIGHTBRACKET"] = SDLK_RIGHTBRACKET;
		m_keymap["CARET"] = SDLK_CARET;
		m_keymap["UNDERSCORE"] = SDLK_UNDERSCORE;
		m_keymap["BACKQUOTE"] = SDLK_BACKQUOTE;
		m_keymap["A"] = SDLK_a;
		m_keymap["B"] = SDLK_b;
		m_keymap["C"] = SDLK_c;
		m_keymap["D"] = SDLK_d;
		m_keymap["E"] = SDLK_e;
		m_keymap["F"] = SDLK_f;
		m_keymap["G"] = SDLK_g;
		m_keymap["H"] = SDLK_h;
		m_keymap["I"] = SDLK_i;
		m_keymap["J"] = SDLK_j;
		m_keymap["K"] = SDLK_k;
		m_keymap["L"] = SDLK_l;
		m_keymap["M"] = SDLK_m;
		m_keymap["N"] = SDLK_n;
		m_keymap["O"] = SDLK_o;
		m_keymap["P"] = SDLK_p;
		m_keymap["Q"] = SDLK_q;
		m_keymap["R"] = SDLK_r;
		m_keymap["S"] = SDLK_s;
		m_keymap["T"] = SDLK_t;
		m_keymap["U"] = SDLK_u;
		m_keymap["V"] = SDLK_v;
		m_keymap["W"] = SDLK_w;
		m_keymap["X"] = SDLK_x;
		m_keymap["Y"] = SDLK_y;
		m_keymap["Z"] = SDLK_z;
		m_keymap["DELETE"] = SDLK_DELETE;
		m_keymap["KP00"] = SDLK_KP0;
		m_keymap["KP01"] = SDLK_KP1;
		m_keymap["KP02"] = SDLK_KP2;
		m_keymap["KP03"] = SDLK_KP3;
		m_keymap["KP04"] = SDLK_KP4;
		m_keymap["KP05"] = SDLK_KP5;
		m_keymap["KP06"] = SDLK_KP6;
		m_keymap["KP07"] = SDLK_KP7;
		m_keymap["KP08"] = SDLK_KP8;
		m_keymap["KP09"] = SDLK_KP9;
		m_keymap["KP_PERIOD"] = SDLK_KP_PERIOD;
		m_keymap["KP_DIVIDE"] = SDLK_KP_DIVIDE;
		m_keymap["KP_MULTIPLY"] = SDLK_KP_MULTIPLY;
		m_keymap["KP_MINUS"] = SDLK_KP_MINUS;
		m_keymap["KP_PLUS"] = SDLK_KP_PLUS;
		m_keymap["KP_ENTER"] = SDLK_KP_ENTER;
		m_keymap["KP_EQUALS"] = SDLK_KP_EQUALS;
		m_keymap["UP"] = SDLK_UP;
		m_keymap["DOWN"] = SDLK_DOWN;
		m_keymap["RIGHT"] = SDLK_RIGHT;
		m_keymap["LEFT"] = SDLK_LEFT;
		m_keymap["INSERT"] = SDLK_INSERT;
		m_keymap["HOME"] = SDLK_HOME;
		m_keymap["END"] = SDLK_END;
		m_keymap["PAGEUP"] = SDLK_PAGEUP;
		m_keymap["PAGEDOWN"] = SDLK_PAGEDOWN;
		m_keymap["F1"] = SDLK_F1;
		m_keymap["F2"] = SDLK_F2;
		m_keymap["F3"] = SDLK_F3;
		m_keymap["F4"] = SDLK_F4;
		m_keymap["F5"] = SDLK_F5;
		m_keymap["F6"] = SDLK_F6;
		m_keymap["F7"] = SDLK_F7;
		m_keymap["F8"] = SDLK_F8;
		m_keymap["F9"] = SDLK_F9;
		m_keymap["F10"] = SDLK_F10;
		m_keymap["F11"] = SDLK_F11;
		m_keymap["F12"] = SDLK_F12;
		m_keymap["F13"] = SDLK_F13;
		m_keymap["F14"] = SDLK_F14;
		m_keymap["F15"] = SDLK_F15;
		m_keymap["NUMLOCK"] = SDLK_NUMLOCK;
		m_keymap["CAPSLOCK"] = SDLK_CAPSLOCK;
		m_keymap["SCROLLLOCK"] = SDLK_SCROLLOCK;
		m_keymap["RSHIFT"] = SDLK_RSHIFT;
		m_keymap["LSHIFT"] = SDLK_LSHIFT;
		m_keymap["RCTRL"] = SDLK_RCTRL;
		m_keymap["LCTRL"] = SDLK_LCTRL;
		m_keymap["RALT"] = SDLK_RALT;
		m_keymap["LALT"] = SDLK_LALT;
		//m_keymap["RMETA"] = SDLK_RMETA;
		//m_keymap["LMETA"] = SDLK_LMETA;
		//m_keymap["LSUPER"] = SDLK_LSUPER;
		//m_keymap["RSUPER"] = SDLK_RSUPER;
		m_keymap["MODE"] = SDLK_MODE;
		m_keymap["COMPOSE"] = SDLK_COMPOSE;
		m_keymap["HELP"] = SDLK_HELP;
		m_keymap["PRINT"] = SDLK_PRINT;
		m_keymap["SYSREQ"] = SDLK_SYSREQ;
		m_keymap["BREAK"] = SDLK_BREAK;
		m_keymap["MENU"] = SDLK_MENU;
		m_keymap["POWER"] = SDLK_POWER;
		m_keymap["EURO"] = SDLK_EURO;
		m_keymap["UNDO"] = SDLK_UNDO;
	}

	String temp(key);

	std::transform(temp.begin(), temp.end(), temp.begin(), toupper);

	std::map<String, SDLKey>::const_iterator it = m_keymap.find(temp);

	if (it != m_keymap.end())
	{
		m_key = it->second;
	}
}

Key::Key(const Key& other)
: m_key(other.m_key)
{
}

String Key::name() const
{
	return String(SDL_GetKeyName(m_key));
}

bool Key::empty() const
{
	return m_key != -1;
}

Key::operator int() const
{
	return m_key;
}

const Key& Key::operator=(const Key& other)
{
	if (this != &other)
	{
		m_key = other.m_key;
	}

	return *this;
}

bool Key::operator==(const Key& other)
{
	return m_key == other.m_key;
}

bool Key::operator==(SDLKey key)
{
	return m_key == key;
}

bool Key::operator!=(const Key& other)
{
	return m_key != other.m_key;
}

bool Key::operator!=(SDLKey key)
{
	return m_key != key;
}

WINTERMOON_END_NAMESPACE

