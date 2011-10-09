
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

#include "Image.h"

WINTERMOON_BEGIN_NAMESPACE

Image::Image(const String& filename)
{
	m_pixmap = Pixmap::get(filename);
}

Image::Image(int width, int height, bool alpha)
{
	SDL_Surface *temp, *surface;

	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
	#else
	surface = SDL_CreateRGBSurface(SDL_SWSURFACE, width, height, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
	#endif

	if (!surface)
	{
		throw Exception("SDL_CreateRGBSurface: %s", SDL_GetError());
	}

	SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));

	if ((temp = alpha ? SDL_DisplayFormatAlpha(surface) : SDL_DisplayFormat(surface)) != NULL)
	{
		SDL_FreeSurface(surface);
		surface = temp;
	}

	m_pixmap = boost::shared_ptr<Pixmap>(new Pixmap(surface));
}

Image::Image(const Image& other)
: m_pixmap(other.m_pixmap)
{
}

Image::~Image()
{
}

void Image::draw(float x, float y, float rotation) const
{
	m_pixmap->bind();
	glLoadIdentity();

	glTranslatef(x, y, 0.0f);
	glRotatef(rotation, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(0.0f, 0.0f);

		glTexCoord2f(1.0f, 0.0f);
		glVertex2f(m_pixmap->width(), 0.0f);

		glTexCoord2f(1.0f, 1.0f);
		glVertex2f(m_pixmap->width(), m_pixmap->height());

		glTexCoord2f(0.0f, 1.0f);
		glVertex2f(0.0f, m_pixmap->height());
	glEnd();
}

uint Image::width() const
{
	return m_pixmap->width();
}

uint Image::height() const
{
	return m_pixmap->height();
}

WINTERMOON_END_NAMESPACE

