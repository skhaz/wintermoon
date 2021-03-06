
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

#include "KeySequence.h"



WINTERMOON_BEGIN_NAMESPACE

KeySequence::KeySequence()
: m_tolerance(0)
, m_key1(Key())
, m_key2(Key())
, m_key3(Key())
, m_key4(Key())
{
}

KeySequence::KeySequence(const Key& key)
: m_tolerance(0)
, m_key1(key)
, m_key2(Key())
, m_key3(Key())
, m_key4(Key())
{
}

KeySequence::KeySequence(const Key& key1, const Key& key2, int tolerance)
: m_tolerance(tolerance)
, m_key1(key1)
, m_key2(key2)
, m_key3(Key())
, m_key4(Key())
{
}

KeySequence::KeySequence(const Key& key1, const Key& key2, const Key& key3, int tolerance)
: m_tolerance(tolerance)
, m_key1(key1)
, m_key2(key2)
, m_key3(key3)
, m_key4(Key())
{
}

KeySequence::KeySequence(const Key& key1, const Key& key2, const Key& key3, const Key& key4, int tolerance)
: m_tolerance(tolerance)
, m_key1(key1)
, m_key2(key2)
, m_key3(key3)
, m_key4(key4)
{
}

KeySequence::~KeySequence()
{
}

void KeySequence::keyPressEvent(KeyEvent* event)
{
	UNUSED(event)
}

WINTERMOON_END_NAMESPACE

