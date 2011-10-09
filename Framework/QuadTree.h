
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

#ifndef _QuadTree_h
#define _QuadTree_h

#include "Internal.h"

#include "Rect.h"
#include "Deque.h"



WINTERMOON_BEGIN_NAMESPACE

template <typename DataType, class Allocator = std::allocator<DataType> >
class DLL_EXPORT QuadTree : public Rect
{
	private:
		Deque<DataType> m_data;

		QuadTree<DataType> *parent;

		QuadTree<DataType> *nw;
		QuadTree<DataType> *ne;
		QuadTree<DataType> *se;
		QuadTree<DataType> *sw;

	protected:
		bool canSubDivide() const
		{
		}

		void createChild()
		{
		}

	public:
		explicit QuadTree(const Rect& rect, QuadTree<DataType> *p = 0)
		: Rect(rect)
		, nw(0)
		, ne(0)
		, se(0)
		, sw(0)
		, parent(p)
		{
		}

		~QuadTree() { }

		void draw()
		{
			#ifndef DEBUG
			glBegin(GL_LINE_LOOP);
				glVertex2i(x,y);
				glVertex2i(x+w,y);
				glVertex2i(x+w,y+h);
				glVertex2i(x,y+h);
			glEnd();

			if (nw) nw->draw();
			if (ne) ne->draw();
			if (se) se->draw();
			if (sw) sw->draw();
			#endif
		}
};

WINTERMOON_END_NAMESPACE

#endif

