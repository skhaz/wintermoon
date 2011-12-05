import os
import sys
import platform

env = Environment(ENV = { 'PATH' : os.environ['PATH'], 'HOME' : os.environ['HOME'] })
env.ParseConfig('sdl-config --cflags')
env.ParseConfig('sdl-config --libs')

if sys.platform == 'darwin':
	env['FRAMEWORKS'] = ['Cocoa', 'OpenGL', 'OpenAL']
	env.AppendUnique(LIBS = ['SDLmain'])
else:
	env.AppendUnique(LIBS = ['GL'])

env.AppendUnique(LIBS = ['physfs', 'lua', 'luabind', 'SDL_image', 'ogg', 'vorbis', 'vorbisfile'])

env.Append(CXXFLAGS = ['-O3'])
env.Append(CXXFLAGS = ['-W'])
env.Append(CXXFLAGS = ['-Wall'])
env.Append(CXXFLAGS = ['-Wextra'])
env.Append(CPPPATH = ['.'])



env.Program(target = "Wintermoon", source = Glob('Framework/*.cpp'))

