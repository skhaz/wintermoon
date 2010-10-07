
/*
 *                        __                                                    
 *             __        /\ \__                                                 
 *  __  __  __/\_\    ___\ \ ,_\    __  _ __   ___ ___     ___    ___    ___    
 * /\ \/\ \/\ \/\ \ /' _ `\ \ \/  /'__`\\`'__\' __` __`\  / __`\ / __`\/' _ `\  
 * \ \ \_/ \_/ \ \ \/\ \/\ \ \ \_/\  __/ \ \//\ \/\ \/\ \/\ \L\ \\ \L\ \\ \/\ \ 
 *  \ \___x___/'\ \_\ \_\ \_\ \__\ \____\ \_\\ \_\ \_\ \_\ \____/ \____/ \_\ \_\
 *   \/__//__/   \/_/\/_/\/_/\/__/\/____/\/_/ \/_/\/_/\/_/\/___/ \/___/ \/_/\/_/
 *
 * Copyright (c) 2006 - 2010 Wintermoon Project
 *
 * http://www.wintermoonframework.org/
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

#include "Color.h"



WINTERMOON_BEGIN_NAMESPACE

Color Color::Black(0, 0, 0);
Color Color::Gray(127, 127, 127);
Color Color::White(255, 255, 255);
Color Color::Red(255, 0, 0);
Color Color::Green(0, 255, 0);
Color Color::Blue(0, 0, 255);
Color Color::Magenta(255, 0, 255);
Color Color::Cyan(0, 255, 255);
Color Color::Yellow(255, 255, 0);

Color::Color()
: m_red(0)
, m_green(0)
, m_blue(0)
, m_alpha(0)
{
}

Color::Color(int r, int g, int b, int a)
{
	m_red   = (r > 255 ? 255 : (r < 0 ? 0 : r));
	m_green = (g > 255 ? 255 : (g < 0 ? 0 : g));
	m_blue  = (b > 255 ? 255 : (b < 0 ? 0 : b));
	m_alpha = (a > 255 ? 255 : (a < 0 ? 0 : a));
}

Color::~Color()
{
}

const Color& Color::setRed(int r)
{
	m_red = (r > 255 ? 255 : (r < 0 ? 0 : r));

	return *this;
}

const Color& Color::setGreen(int g)
{
	m_green = (g > 255 ? 255 : (g < 0 ? 0 : g));

	return *this;
}

const Color& Color::setBlue(int b)
{
	m_blue = (b > 255 ? 255 : (b < 0 ? 0 : b));

	return *this;
}

const Color& Color::setAlpha(int a)
{
	m_alpha = (a > 255 ? 255 : (a < 0 ? 0 : a));

	return *this;
}

bool Color::hasAlpha() const
{
	return m_alpha != 255;
}

Color::operator SDL_Color()
{
	SDL_Color color;
	color.r = static_cast<Uint8>(m_red);
	color.g = static_cast<Uint8>(m_green);
	color.b = static_cast<Uint8>(m_blue);
	color.unused = static_cast<Uint8>(m_alpha);
	return color;
}

bool Color::operator==(const Color& other)
{
	return  m_red == other.m_red && m_green == other.m_green &&	m_blue == other.m_blue && m_alpha == other.m_alpha;
}

bool Color::operator!=(const Color& other)
{
	return  m_red != other.m_red && m_green != other.m_green &&	m_blue != other.m_blue && m_alpha != other.m_alpha;
}

WINTERMOON_END_NAMESPACE

