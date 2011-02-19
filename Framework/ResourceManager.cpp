
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

#include "ResourceManager.h"



WINTERMOON_BEGIN_NAMESPACE

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceRef ResourceManager::get(const String& key)
{
	boost::unordered_map<
			String,
			ResourceRef,
			boost::hash<String>
		>::const_iterator it = m_resource_cache.find(key);

	if (it != m_resource_cache.end())
	{
		return it->second;
	}

	return ResourceRef();
}

void ResourceManager::add(const String& key, ResourceRef resource)
{
	m_resource_cache.insert(std::make_pair(key, resource));
}

bool ResourceManager::find(const String& key) const
{
	return m_resource_cache.find(key) != m_resource_cache.end();
}

size_t ResourceManager::count() const
{
	return m_resource_cache.size();
}

void ResourceManager::flush()
{
	boost::unordered_map<
			String,
			ResourceRef,
			boost::hash<String>
		>::iterator it = m_resource_cache.begin();

	for (it = m_resource_cache.begin(); it != m_resource_cache.end();)
	{
		if (it->second.unique())
		{
			m_resource_cache.erase(it++);
		}

		else {
			++it;
		}
	}
}

void ResourceManager::asyncLoad(const ResourceGroup& resources, boost::function<void (const String& filename)> fun)
{
}

WINTERMOON_END_NAMESPACE

