
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

#include "Pixmap.h"
#include "PixmapCache.h"
#include "File.h"



WINTERMOON_BEGIN_NAMESPACE

uint Pixmap::m_last_bind = 0;

PixmapRef Pixmap::get(const String& filename)
{
	PixmapCache cache;

	if (!cache.find(filename))
	{
		PixmapRef pixmap(new Pixmap(filename));
		cache.add(filename, pixmap);
		return pixmap;
	}

	return cache.get(filename);
}

Pixmap::Pixmap(SDL_Surface* surface)
{
	// TODO
}

Pixmap::Pixmap(const String& filename)
{
	SDL_RWops* rwops;

	if (FAILED(rwops = PHYSFSRWOPS_openRead(filename.c_str())))
	{
		throw Exception("[PHYSFSRWOPS_openRead] Error while opening file: %s", filename.c_str());
	}

	SDL_Surface* surface;

	if (FAILED(surface = IMG_Load_RW(rwops, true)))
	{
		throw Exception("[IMG_Load_RW] Error while opening file: %s", filename.c_str());
	}

	GLenum format = GL_NONE;
	m_width = surface->w;
	m_height = surface->h;
	GLint bpp = surface->format->BytesPerPixel;

	if (bpp == 4)
	{
		if (surface->format->Rmask == 0x000000ff)
			format = GL_RGBA;
		else
			format = GL_BGRA;
	}

	else if (bpp == 3) {
		if (surface->format->Rmask == 0x000000ff)
			format = GL_RGB;
		else
			format = GL_BGR;
	}

	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glTexImage2D(GL_TEXTURE_2D, 0, bpp, surface->w, surface->h, 0, format, GL_UNSIGNED_BYTE, surface->pixels);

	SDL_FreeSurface(surface);
}

Pixmap::~Pixmap()
{
	glDeleteTextures(1, &m_id);
}

void Pixmap::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_id);
}

uint Pixmap::width() const
{
	return m_width;
}

uint Pixmap::height() const
{
	return m_height;
}

WINTERMOON_END_NAMESPACE

