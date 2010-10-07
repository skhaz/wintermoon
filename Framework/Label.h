
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

#ifndef _Label_h
#define _Label_h

#include "Internal.h"

#include "Entity.h"
#include "Color.h"
#include "Rect.h"
#include "File.h"



WINTERMOON_BEGIN_NAMESPACE

class DLL_EXPORT Label : public Entity
{
	public:
		enum Style
		{
			NORMAL = TTF_STYLE_NORMAL,
			BOLD = TTF_STYLE_BOLD,
			ITALIC = TTF_STYLE_ITALIC,
			UNDERLINE = TTF_STYLE_UNDERLINE
		};

		Label();

		Label(const String& text, const String& fontname, int size, Color color = Color::White);

		virtual ~Label();

		void setFont(const String& filename);

		const String& font() const;

		void setFontSize(int size);

		int fontSize() const;

		void setStyle(Style style);

		Style style() const;

		void setColor(const Color& color);

		const Color& color() const;

		void setAntiAlias(bool antialias);

		bool antiAlias() const;

		void setCaption(const String& caption);

		const String& caption() const;

		virtual void update();

		virtual void draw() const;

	private:
		String m_text;

		String m_fontname;

		int m_size;

		Style m_style;

		Color m_color;

		String m_caption;

		bool m_anti_alias;

		TTF_Font* m_font;

		SDL_Surface* m_surface;

		bool m_need_update;
};

WINTERMOON_END_NAMESPACE

#endif

