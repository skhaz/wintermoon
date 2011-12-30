
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

#include "Url.h"

#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>



WINTERMOON_BEGIN_NAMESPACE

Url::Url()
{
}

Url::Url(const String& url)
{
	setUrl(url);
}

Url::~Url()
{
}

void Url::setUrl(const String& url)
{
	using namespace boost::xpressive;

	size_t found = url.find_first_of("?");

	if (found != String::npos)
	{
		m_filename = url.substr(0, found);
		String query = url.substr(found + 1, url.size());
		sregex pair = ((s1 = +_w) >> "=" >> (s2 = +(set[alnum | '_' | '.' | ','])))
		[ref(m_parameters)[s1] = s2];
		sregex rx = pair >> *('&' >> *(pair));

		if (regex_match(query, rx)) {
		}
	}

	else {
		m_filename = url;
	}

	if (String::npos != (found = m_filename.find_last_of("."))) {
		m_extension = m_filename.substr(found + 1, m_filename.size());
	}
}

String Url::extension() const
{
	return m_extension;
}

String Url::filename() const
{
	return m_filename;
}

map<String, String> Url::parameters() const
{
	return m_parameters;
}

WINTERMOON_END_NAMESPACE

