
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

#include "SceneManager.h"



WINTERMOON_BEGIN_NAMESPACE

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::addEntity(Entity* entity, int priority)
{
	using namespace std;
	using namespace boost;

	Deque<Entity *>::const_iterator it = find_if(m_entities.begin(), m_entities.end(), bind(&Entity::priority, _1) == priority);

	if (it == m_entities.end())
	{
		m_entities.push_back(entity);

		entity->setPriority(priority);

		sort(m_entities.begin(), m_entities.end(),
					bind(&Entity::priority, _1) >  bind(&Entity::priority, _2));
	}

	else {

	}
}

void SceneManager::removeEntity(Entity* entity)
{
	using namespace std;
	using namespace boost;

	Deque<Entity *>::iterator it = find(m_entities.begin(), m_entities.end(), entity);

	if (it != m_entities.end())
	{
		m_entities.erase(it);

		sort(m_entities.begin(), m_entities.end(),
					bind(&Entity::priority, _1) >  bind(&Entity::priority, _2));
	}
}

void SceneManager::update(float delta)
{
	std::for_each(m_entities.begin(), m_entities.end(),
				boost::bind(&Entity::update, _1, delta));
}

void SceneManager::draw() const
{
	std::for_each(m_entities.begin(), m_entities.end(),
				boost::bind(&Entity::draw, _1));
}

WINTERMOON_END_NAMESPACE

