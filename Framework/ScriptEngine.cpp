
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

#include "ScriptEngine.h"

#include <luabind/luabind.hpp>
#include <sstream>

#include "FileSystem.h"
#include "File.h"
#include "VideoManager.h"



WINTERMOON_BEGIN_NAMESPACE

ScriptEngine::ScriptEngine()
: L(lua_open())
{
	using namespace luabind;

	luaL_openlibs(L);

	luabind::open(L);

	module(L)
	[
		class_<FileSystem>("FileSystem")
		.def(constructor<>())
		.scope
		[
			def("addArchive", FileSystem::addArchive),
			def("removeArchive", FileSystem::removeArchive)
		]
	];

	module(L)
	[
		class_<IODevice>("IODevice")
		.enum_("OpenMode")
		[
			value("ReadOnly", 2),
			value("ReadWrite", 4),
			value("Append", 8),
			value("Text", 16)
		],

		class_<File, IODevice>("File")
		.def(constructor<const String &>())
		.def("open", &File::open)
		.def("length", &File::length)
		.def("eof", &File::eof)
		.def("seek", &File::seek)
		.def("tell", &File::tell)
	];
}

ScriptEngine::~ScriptEngine()
{
	lua_close(L);
}

void ScriptEngine::evaluate(const std::string& program)
{
	const char* buffer = program.c_str();
	luaL_loadbuffer(L, buffer, std::strlen(buffer), buffer);
	luabind::object script(luabind::from_stack(L, -1));

	try
	{
		luabind::call_function<void>(script);
	}

	catch (luabind::error&) { /* TODO print lua stacktrace */ }

	lua_pop(L, 1);
}

void ScriptEngine::collectGarbage()
{
	lua_gc(L, LUA_GCCOLLECT, 0);
}

int ScriptEngine::usedMemory()
{
	return lua_gc(L, LUA_GCCOUNT, 0);
}

WINTERMOON_END_NAMESPACE

