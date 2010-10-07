
/*
 *                        __                                                    
 *             __        /\ \__                                                 
 *  __  __  __/\_\    ___\ \ ,_\    __  _ __   ___ ___     ___    ___    ___    
 * /\ \/\ \/\ \/\ \ /' _ `\ \ \/  /'__`\\`'__\' __` __`\  / __`\ / __`\/' _ `\  
 * \ \ \_/ \_/ \ \ \/\ \/\ \ \ \_/\  __/ \ \//\ \/\ \/\ \/\ \L\ \\ \L\ \\ \/\ \ 
 *  \ \___x___/'\ \_\ \_\ \_\ \__\ \____\ \_\\ \_\ \_\ \_\ \____/ \____/ \_\ \_\
 *   \/__//__/   \/_/\/_/\/_/\/__/\/____/\/_/ \/_/\/_/\/_/\/___/ \/___/ \/_/\/_/
 *
 * Copyright (c) 2006 - 2009, Rodrigo D. Batista (a.k.a. skhaz)
 *
 * Visit: http://www.wintermoonframework.org/
 *
 * License: (BSD)
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

#ifndef _Internal_h
#define _Internal_h

#include <cmath>
#include <cctype>
#include <map>
#include <algorithm>
#include <sstream>

#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"

#include "physfs.h"

#include "Exception.h"
#include "Logger.h"
#include "Types.h"
#include "Enums.h"
#include "SafeDelete.h"
#include "Namespace.h"

#if defined WIN32 || WINDOWS && BUILD_DLL
# define DLL_EXPORT __declspec(dllexport)
#else
# define DLL_EXPORT
#endif

#ifdef FAILED
# undef FAILED
#endif
#define FAILED(x) (!(x))

#define UNUSED(x) ((void)(x))

#define LOG(...) Logger::instance()->put(__VA_ARGS__);

#define THROW_IF(condition, ...) if ((condition)) do { throw Exception(__VA_ARGS__); } while (0);

#define TR(string) StringTable::instance()->getString(string)



WINTERMOON_BEGIN_NAMESPACE
	class Application;
	class StringList;
	class EventListener;
	class Mutex;
	class Size;
	class Point;
	class Image;
	class FrameListener;
	class Pixmap;
	class Graphics;
	class InputManager;
	class Rectangle;
	class Key;
	class KeyEvent;
	class MouseEvent;
	class KeySequence;
	class ByteArray;
	class Entity;
	class EntityGroup;
	class SceneManager;
	class StringTable;

	using std::size_t;

	typedef boost::shared_ptr<Pixmap> PixmapRef;
WINTERMOON_END_NAMESPACE

#endif

