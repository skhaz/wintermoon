
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

#include "File.h"



WINTERMOON_BEGIN_NAMESPACE

static int physfsrwops_seek(SDL_RWops *rw, int offset, int whence)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;

	int pos = 0;

	if (whence == SEEK_SET)
	{
		pos = offset;
	}
	
	else if (whence == SEEK_CUR)
	{
		PHYSFS_sint64 current = PHYSFS_tell(handle);

		if (current == -1)
		{
			SDL_SetError("Can't find position in file: %s", PHYSFS_getLastError());
			return(-1);
		}

		pos = (int)current;

		if (((PHYSFS_sint64)pos) != current)
		{
			SDL_SetError("Can't fit current file position in an int!");
			return(-1);
		}

		if (offset == 0)
			return(pos);

		pos += offset;
	}

	else if (whence == SEEK_END)
	{
		PHYSFS_sint64 len = PHYSFS_fileLength(handle);

		if (len == -1)
		{
			SDL_SetError("Can't find end of file: %s", PHYSFS_getLastError());
			return(-1);
		}

		pos = (int)len;

		if (((PHYSFS_sint64)pos) != len)
		{
			SDL_SetError("Can't fit end-of-file position in an int!");
			return(-1);
		}

		pos += offset;
	}

	else
	{
		SDL_SetError("Invalid 'whence' parameter.");
		return(-1);
	}

	if (pos < 0)
	{
		SDL_SetError("Attempt to seek past start of file.");
		return(-1);
	}

	if (!PHYSFS_seek(handle, (PHYSFS_uint64) pos))
	{
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
		return(-1);
	}
	
	return(pos);
}

static int physfsrwops_read(SDL_RWops *rw, void *ptr, int size, int maxnum)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;
	PHYSFS_uint32 rc = PHYSFS_read(handle, ptr, size, maxnum);

	if (rc != maxnum)
	{
		if (!PHYSFS_eof(handle))
			SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
	}
	
	return((int) rc);
}

static int physfsrwops_write(SDL_RWops *rw, const void *ptr, int size, int num)
{
	PHYSFS_File *handle = (PHYSFS_File *) rw->hidden.unknown.data1;
	PHYSFS_uint32 rc = PHYSFS_write(handle, ptr, size, num);

	if (rc != num)
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());

	return((int) rc);
}

static int physfsrwops_close(SDL_RWops *rw)
{
	PHYSFS_File *handle = (PHYSFS_File*) rw->hidden.unknown.data1;

	if (!PHYSFS_close(handle))
	{
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());
		return(-1);
	}

	SDL_FreeRW(rw);

	return(0);
}

static SDL_RWops *create_rwops(PHYSFS_File *handle)
{
	SDL_RWops *retval = NULL;

	if (handle == NULL)
		SDL_SetError("PhysicsFS error: %s", PHYSFS_getLastError());

	else
	{
		retval = SDL_AllocRW();
		if (retval != NULL)
		{
			retval->seek  = physfsrwops_seek;
			retval->read  = physfsrwops_read;
			retval->write = physfsrwops_write;
			retval->close = physfsrwops_close;
			retval->hidden.unknown.data1 = handle;
		}
	}

	return(retval);
}

SDL_RWops *PHYSFSRWOPS_makeRWops(PHYSFS_File *handle)
{
	SDL_RWops *retval = NULL;

	if (handle == NULL)
		SDL_SetError("NULL pointer passed to PHYSFSRWOPS_makeRWops().");
	else
		retval = create_rwops(handle);

	return(retval);
}

SDL_RWops *PHYSFSRWOPS_openRead(const char *fname)
{
	return(create_rwops(PHYSFS_openRead(fname)));
}

SDL_RWops *PHYSFSRWOPS_openWrite(const char *fname)
{
	return(create_rwops(PHYSFS_openWrite(fname)));
}

SDL_RWops *PHYSFSRWOPS_openAppend(const char *fname)
{
	return(create_rwops(PHYSFS_openAppend(fname)));
}

File::File(String const& filename)
: m_filename(filename)
, m_file(0)
{
}

File::~File()
{
	if (m_file)
	{
		PHYSFS_close(m_file);
	}
}

bool File::open(OpenMode mode)
{
	switch (mode)
	{
		case ReadOnly:
			m_file = PHYSFS_openRead(m_filename.c_str());
			break;

		case ReadWrite:
			m_file = PHYSFS_openWrite(m_filename.c_str());
			break;

		case Append:
			m_file = PHYSFS_openAppend(m_filename.c_str());
			break;

		default:
			break;
	}

	return m_file != 0;
}

int File::length() const
{
	return static_cast<int>(PHYSFS_fileLength(m_file));
}

bool File::eof() const
{
	return PHYSFS_eof(m_file);
}

bool File::seek(int pos) const
{
	return PHYSFS_seek(m_file, pos);
}

int File::tell() const
{
	return static_cast<int>(PHYSFS_tell(m_file));
}

bool File::exists(String const& filename)
{
	return PHYSFS_exists(filename.c_str());
}

WINTERMOON_END_NAMESPACE

