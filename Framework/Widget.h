
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

#ifndef _Widget_h
#define _Widget_h

#include "Internal.h"

#include "Point.h"
#include "Size.h"
#include "Rect.h"
#include "Color.h"



WINTERMOON_BEGIN_NAMESPACE

class DLL_EXPORT Widget
{
	public:
		Widget();

		virtual ~Widget();

		void show();

		void hide();

		bool isVisible() const;

		void setEnabled(bool enabled);

		bool isEnabled() const;

		void setFocus();

		bool hasFocus() const;

		void setSize(const Size& size);

		const Size& size() const;

		void setWidth(int width);

		int width() const;

		void setHeight(int height);

		int height() const;

		void setPos(const Point& point);

		const Point& pos() const;

		void setX(int x);

		int x() const;

		void setY(int y);

		int y() const;

		void setMinimumSize(const Size& size);

		const Size& minimumSize() const;

		void setMinimumWidth(int width);

		int minimumWidth() const;

		void setMinimumHeight(int height);

		int minimumHeight() const;

		void setMaximumSize(const Size& size);

		const Size& maximumSize() const;

		void setMaximumWidth(int width);

		int maximumWidth() const;

		void setMaximumHeight(int height);

		int maximumHeight() const;

	protected:
		virtual void paintEvent();

	private:
		bool m_redraw;

		bool m_enabled;

		bool m_visible;

		bool m_focus;

		Size m_size;

		Point m_pos;

		Size m_maximum_size;

		Size m_minimum_size;
};

WINTERMOON_END_NAMESPACE

#endif

