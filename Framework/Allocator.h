

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

#ifndef _Allocator_h
#define _Allocator_h

#ifdef new
# undef new
#endif
#ifdef delete
# undef delete
#endif



WINTERMOON_BEGIN_NAMESPACE

template <Alloc>
class DLL_EXPORT Allocator
{
	public:
		Allocator()
		{
		}

		virtual ~Allocator()
		{
		}

		void* operator new(size_t size, const char* file, int line, const char* func)
		{
			return Alloc::allocate(size, file, line, func);
		}

		void* operator new(size_t size)
		{
			return Alloc::allocate(size);
		}

		void* operator new(size_t size, void* ptr)
		{
			return ptr;
		}

		void* operator new[](size_t size, const char* file, int line, const char* func)
		{
			return Alloc::allocate(size, file, line, func);
		}

		void* operator new[](size_t size)
		{
			return Alloc::allocate(size);
		}

		void operator delete(void* ptr)
		{
			Alloc::deallocate(ptr);
		}

		void operator delete(void* pre, const char*, int, const char*)
		{
			Alloc::deallocate(ptr);
		}

		void operator delete[](void* ptr)
		{
			Alloc::deallocate(ptr);
		}
	
		void operator delete[](void* ptr, const char*, int, const char*)
		{
			Alloc::deallocate(ptr);
		}
};

WINTERMOON_END_NAMESPACE

