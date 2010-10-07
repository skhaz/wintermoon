
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

#include "AudioManager.h"



WINTERMOON_BEGIN_NAMESPACE

// PHYSFS callback definition
// see http://www.xiph.org/vorbis/doc/vorbisfile/ov_callbacks.html

static size_t ovPHYSFS_read(void* ptr, size_t size, size_t nmemb, void* datasource)
{
	return PHYSFS_read(static_cast<PHYSFS_file*>(datasource), ptr, 1, size * nmemb);
}

static int ovPHYSFS_seek(void* datasource, ogg_int64_t offset, int whence)
{
	UNUSED(datasource);
	UNUSED(offset);
	UNUSED(whence);

	return -1;
}

static int ovPHYSFS_close(void* datasource)
{
	UNUSED(datasource);

	return 0;
}

static long ovPHYSFS_tell(void* datasource)
{
	UNUSED(datasource);

	return -1;
}

static ov_callbacks PHYSFS_callbacks = {
	ovPHYSFS_read,
	ovPHYSFS_seek,
	ovPHYSFS_close,
	ovPHYSFS_tell
};

// end of PHYSFS callback definition

AudioManager::AudioManager()
{
	if (ALCdevice* device = alcOpenDevice(NULL))
	{
		ALCcontext* context = alcCreateContext(device, NULL);

		alcMakeContextCurrent(context);

		alGetError();

		alDistanceModel(AL_NONE);
	}

	else {
		// throw
	}

	alListenerf(AL_GAIN, 1.0);

	LOG("OpenAL:");
	LOG("Vendor     : %s", alGetString(AL_VENDOR));
	LOG("Renderer   : %s", alGetString(AL_RENDERER));
	LOG("Version    : %s", alGetString(AL_VERSION));
	LOG("Extensions : %s", alGetString(AL_EXTENSIONS));
}

AudioManager::~AudioManager()
{
	ALCcontext* context = alcGetCurrentContext();
	ALCdevice* device = alcGetContextsDevice(context);

	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

bool AudioManager::load(const String& filename)
{
	OggVorbis_File stream;

	if (!PHYSFS_exists(filename.c_str()))
	{
		throw Exception("File not found %s", filename.c_str());
	}

	PHYSFS_file* handle = PHYSFS_openRead(filename.c_str());

	if (!handle)
		return false;

	if (ov_open_callbacks(static_cast<void *>(handle), &stream, NULL, 0, PHYSFS_callbacks) < 0)
	{
		throw Exception("Could not open Ogg stream");
	}	

	vorbis_info* info = ov_info(&stream, -1);

	//ALenum format = info->channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
	//ALsizei freq = info->rate;

	//Vector<char> buffer;
	//char array[32768];
/*
	do {
		bytes = ov_read(&oggFile, array, 32768, OGG_ENDIAN, 2, 1, &bitStream);
		buffer.insert(buffer.end(), array, array + bytes);
	} while (bytes > 0);
*/
	ov_clear(&stream);
	PHYSFS_close(handle);

	return true;
}

bool AudioManager::checkError()
{
	/*
	ALenum alError = alGetError();

	if (error != AL_NO_ERROR )
	{
		std::stringstream message;
		message << tag << " : " << alcGetString(device, error);
		String errorString = message.str();

		throw Exception(errorString.c_str());
	}

	ALCcontext* context = alcGetCurrentContext();
	ALCdevice* device = alcGetContextsDevice(context);

	ALCenum alcError = alcGetError(device);

	if (alcError != ALC_NO_ERROR)
	{

	}
	*/
}

WINTERMOON_END_NAMESPACE

