import os
import sys
import platform



if sys.platform == 'win32':
	env = Environment(tools = ['mingw'], ENV = os.environ)

else:
	env = Environment(ENV = { 'PATH' : os.environ['PATH'], 'HOME' : os.environ['HOME'] })


def CheckPKGConfig(context, version):
	context.Message('Checking for pkg-config... ')
	ret = context.TryAction('pkg-config --atleast-pkgconfig-version=%s' % version)[0]
	context.Result(ret)
	return ret

def CheckPKG(context, name):
	context.Message('Checking for %s... ' % name)
	ret = context.TryAction('pkg-config --exists \'%s\'' % name)[0]
	context.Result(ret)
	return ret

def CheckMacports(context):
	context.Message('Looking for macports... ')
	prog = context.env.WhereIs('port')
	if prog:
		ret = 1
		prefix = prog.rsplit(os.sep, 2)[0]
		context.env.Append(LIBPATH = [prefix + os.sep + 'lib'], CPPPATH = [prefix + os.sep + 'include'])
		context.Message( 'Adding port lib and include path')
	else:
		ret = 0
        
	context.Result(ret)
	return int(ret)

if sys.platform == 'win32':
	try:
		input = open('libs.conf', 'r').read().split('\n')
	except:
		print "couldn't open libs.conf"
	else:
		libs = { 'SDL' : '', 'BOOST' : '', 'LUA' : '', 'LUABIND' : '', 'PHYSFS' : '',  }

		for line in input:
			if not line.strip() and not line.startswith('#'):
				continue
			else:
				key, value = line.split('=')
				libs[key] = value

				env.AppendUnique(CPPPATH = [os.path.join(libs['SDL'], 'include/SDL')])
				env.AppendUnique(LIBPATH = [os.path.join(libs['SDL'], 'lib')])
				env.AppendUnique(LINKFLAGS = ['-mwindows -s'])
				env.AppendUnique(LIBS = Split('mingw32 SDLmain SDL SDL_image'))

				env.AppendUnique(CPPPATH = [os.path.join(libs['BOOST'], '')])

				env.AppendUnique(CPPPATH = [os.path.join(libs['LUA'], 'include')])
				env.AppendUnique(LIBPATH = [os.path.join(libs['LUA'], 'lib')])
				env.AppendUnique(LIBS = 'lua5.1')

				env.AppendUnique(CPPPATH = [os.path.join(libs['LUABIND'], '')])
				env.AppendUnique(LIBPATH = [os.path.join(libs['LUABIND'], 'lib')])
				env.AppendUnique(LIBS = 'luabind')

				env.AppendUnique(CPPPATH = [os.path.join(libs['PHYSFS'], 'include')])
				env.AppendUnique(LIBPATH = [os.path.join(libs['PHYSFS'], 'lib')])
				env.AppendUnique(LIBS = 'physfs.dll')

				env.AppendUnique(LIBS = 'opengl32')
				env.Tool('mingw')

else:
	conf = Configure(env, custom_tests = {
						'CheckPKGConfig' : CheckPKGConfig,
						'CheckPKG' : CheckPKG,
						'CheckMacports' : CheckMacports
					})

	if not conf.CheckPKGConfig('0.15.0'):
		print 'pkg-config >= 0.15.0 not found.'
		Exit(1)

	if sys.platform == 'darwin':
		conf.CheckMacports()

	env = conf.Finish()

	env.ParseConfig('sdl-config --cflags')
	env.ParseConfig('sdl-config --libs')

	if sys.platform == 'darwin':
		env['FRAMEWORKS'] = ['Cocoa', 'OpenGL', 'OpenAL']
		env.AppendUnique(LIBS = ['SDLmain'])
	else:
		env.AppendUnique(LIBS = ['GL'])

	env.AppendUnique(LIBS = ['physfs','lua','SDL_image', 'ogg', 'vorbis', 'vorbisfile'])

env.Decider('MD5-timestamp')
env.Append(CXXFLAGS = ['-O2'])
env.Append(CXXFLAGS = ['-W'])
env.Append(CXXFLAGS = ['-Wall'])
env.Append(CXXFLAGS = ['-Wextra'])
env.Append(CXXFLAGS = ['-Wuninitialized'])
env.Append(CXXFLAGS = ['-pedantic'])
"""env.Append(CXXFLAGS = ['-Werror'])"""

env.Program(target = "Wintermoon", source = Glob('Framework/*.cpp'))

