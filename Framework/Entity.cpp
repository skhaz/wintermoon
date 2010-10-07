
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

#include "Entity.h"



WINTERMOON_BEGIN_NAMESPACE

Entity::Entity()
{
}

Entity::Entity(const String& type, float x, float y, float rotation, float scaleX, float scaleY)
: m_type(type)
, m_x(x)
, m_y(y)
, m_rotation(rotation)
, m_scaleX(scaleX)
, m_scaleY(scaleY)
{
}

Entity::~Entity()
{
}

void Entity::setPriority(int priority)
{
	m_priority = priority;
}

int Entity::priority() const
{
	return m_priority;
}

String Entity::type() const
{
	return m_type;
}

void Entity::setPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Entity::setX(float x)
{
	m_x = x;
}

float Entity::x() const
{
	return m_x;
}

void Entity::setY(float y)
{
	m_y = y;
}

float Entity::y() const
{
	return m_y;
}

void Entity::setRotation(float rotation)
{
	m_rotation = rotation;
}

float Entity::rotation() const
{
	return m_rotation;
}

void Entity::setScale(float scaleX, float scaleY)
{
	m_scaleX = scaleX;
	m_scaleY = scaleY;
}

void Entity::setScaleX(float scaleX)
{
	m_scaleX = scaleX;
}

float Entity::scaleX() const
{
	return m_scaleX;
}

void Entity::setScaleY(float scaleY)
{
	m_scaleY = scaleY;
}

float Entity::scaleY() const
{
	return m_scaleY;
}

WINTERMOON_END_NAMESPACE

