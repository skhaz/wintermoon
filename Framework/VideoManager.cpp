
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

#include "VideoManager.h"

#include "Size.h"
#include "FrameListener.h"

WINTERMOON_BEGIN_NAMESPACE



VideoManager::VideoManager()
{
	if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_VIDEO);
	}
}

VideoManager::~VideoManager()
{
	if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
	{
		SDL_QuitSubSystem(SDL_INIT_VIDEO);
	}
}

void VideoManager::init(Size const& size, uint bpp, String const& caption, bool fullscreen)
{
	SDL_WM_SetCaption(caption.c_str(), NULL);

	const SDL_VideoInfo* videoInfo = SDL_GetVideoInfo();

	uint flags = videoInfo->hw_available ? SDL_HWSURFACE : SDL_SWSURFACE;

	if ((flags & SDL_HWSURFACE) == SDL_HWSURFACE)
	{
		if (videoInfo->video_mem * 1024 > (size.width() * size.height() * bpp / 8))
		{
			flags |= (SDL_DOUBLEBUF | SDL_HWACCEL);
		}

		else {
			flags &= ~SDL_HWSURFACE;
		}
	}

	if (fullscreen)
	{
		flags |= SDL_FULLSCREEN;
	}

	else {
		putenv((char *)"SDL_VIDEO_CENTERED=1");
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	switch (bpp)
	{
		case 32:
		case 24:
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
			SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
			break;

		case 16:
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
			SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
			break;

		default:
			break;
	}

	if (FAILED(SDL_SetVideoMode(size.width(), size.height(), bpp, flags | SDL_OPENGL)))
	{
		throw Exception("SDL_SetVideoMode: %s", SDL_GetError());
	}

	else
	{
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

		glEnable(GL_TEXTURE_2D);
		glDisable(GL_DEPTH_TEST);

		glViewport(0, 0, size.width(), size.height());
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(0.0f, size.width(), size.height(), 0.0f, -1.0f, 1.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
}

void VideoManager::beginDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void VideoManager::endDraw()
{
	SDL_GL_SwapBuffers();
}

WINTERMOON_END_NAMESPACE

