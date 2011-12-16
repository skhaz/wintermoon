
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

#include "InputManager.h"



WINTERMOON_BEGIN_NAMESPACE

InputManager::InputManager()
{
	SDL_JoystickOpen(0);

}

InputManager::~InputManager()
{
}

void InputManager::capture()
{
	SDL_Event event;
	Deque<EventListener *>::iterator it = m_listerners.begin();
	Deque<EventListener *>::const_iterator end = m_listerners.end();

	while (SDL_PollEvent(&event))
	{
		for (; it != end; ++it)
		{
			EventListener* listerner = *it;

			switch (event.type)
			{
				case SDL_KEYDOWN:
				{
					KeyEvent key(event.key.keysym.sym, event.key.keysym.mod);
					listerner->keyPressEvent(&key);
				} break;

				case SDL_KEYUP:
				{
					KeyEvent key(event.key.keysym.sym, event.key.keysym.mod);
					listerner->keyReleaseEvent(&key);
				} break;

				case SDL_MOUSEMOTION:
				{
					MouseEvent mouse(Mouse::NoButton, event.button.x, event.button.y);
					listerner->mouseMoveEvent(&mouse);
				} break;

				case SDL_MOUSEBUTTONDOWN:
				{
					MouseEvent mouse(convertMouseButton(event.button.button), event.button.x, event.button.y);
					listerner->mousePressEvent(&mouse);
				} break;

				case SDL_MOUSEBUTTONUP:
				{
					MouseEvent mouse(convertMouseButton(event.button.button), event.button.x, event.button.y);
					listerner->mouseReleaseEvent(&mouse);
				} break;

				case SDL_JOYAXISMOTION:
				{
					// LOG("SDL_JOYAXISMOTION");
				} break;

				case SDL_JOYBALLMOTION:
				{
					LOG("SDL_JOYBALLMOTION");
				} break;

				case SDL_JOYHATMOTION:
				{
					LOG("SDL_JOYHATMOTION");
				} break;

				case SDL_JOYBUTTONUP:
				{
					LOG("SDL_JOYBUTTONUP");
				} break;

				case SDL_JOYBUTTONDOWN:
				{
					LOG("SDL_JOYBUTTONDOWN");
				} break;

				case SDL_QUIT:
				{
					listerner->quitEvent();
				} break;

				default:
					break;
			}
		}
	}
}

void InputManager::addListener(EventListener* listerner)
{
	if (listerner)
	{
		Deque<EventListener *>::const_iterator it = std::find(m_listerners.begin(), m_listerners.end(), listerner);

		if (it == m_listerners.end())
		{
			m_listerners.push_back(listerner);
		}

		else {
			// duplicate
		}
	}
}

void InputManager::removeListener(EventListener* listerner)
{
	if (listerner)
	{
		Deque<EventListener *>::iterator it = std::find(m_listerners.begin(), m_listerners.end(), listerner);

		if (it != m_listerners.end())
		{
			m_listerners.erase(it);
		}

		else {
			// does't exist
		}
	}
}

int InputManager::convertMouseButton(int button)
{
	switch (button)
	{
		case SDL_BUTTON_LEFT:
			return Mouse::LeftButton;
			break;
		case SDL_BUTTON_MIDDLE:
			return Mouse::MiddleButton;
			break;
		case SDL_BUTTON_RIGHT:
			return Mouse::RightButton;
			break;
	}

	return Mouse::NoButton;
}

WINTERMOON_END_NAMESPACE

