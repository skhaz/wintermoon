
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

#include "Application.h"
#include "FileSystem.h"



WINTERMOON_BEGIN_NAMESPACE

Application* Application::app = 0;

Application::Application()
{
	Application::app = this;
}

Application::~Application()
{
	Application::app = 0;
}

WINTERMOON_END_NAMESPACE



int DLL_EXPORT main(int argc, char** argv)
{
	//using namespace Wintermoon;

	// sanity check
	if (Application::app == 0)
	{
		fprintf(stderr, "fatal error, wintermoon application is null!!!\n");
		exit(666);
	}

	if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "[SDL_Init] %s\n", SDL_GetError());
		exit(-1);
	}

	atexit(SDL_Quit);

	/*
	if (TTF_Init() < 0)
	{
		fprintf(stderr, "[TTF_Init] %s\n", TTF_GetError());
		exit(-1);
	}

	atexit(TTF_Quit);
	*/
	if (!PHYSFS_init(argv[0]))
	{
		fprintf(stderr, "[PHYSFS_init] %s\n", PHYSFS_getLastError());
		exit(-1);
	}

	FileSystem::addArchive(".");

	Deque<String> args;

	for (int i = 0; i < argc; ++i)
	{
		args += argv[i];
	}

	int ret = Application::app->main(args);

	if (PHYSFS_deinit() == 0)
	{
		fprintf(stderr, "[PHYSFS_deinit] %s\n", PHYSFS_getLastError());
	}

	return ret;
}
