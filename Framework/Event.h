
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

#ifndef _Event_h
#define _Event_h

#include "Internal.h"

#include <boost/utility.hpp>
#include <boost/signal.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/visit_each.hpp>

#include <list>



namespace Wintermoon
{
	template <typename Signature>
	class Event : boost::noncopyable, public boost::signal<Signature>
	{
		public:
			template <typename Slot>
			boost::signals::connection operator+=(const Slot& slot)
			{
				boost::signals::connection c;

				if (!alreadyConnected(slot))
				{
					c = connect(slot);
					SlotConnection sc;
					sc.connection = c;
					sc.slot = slot;
					slotList.push_back(sc);
				}

			return c;
        }

		boost::signals::connection operator+=(const Event& event)
		{
			return connect(event);
        }

		template <typename Slot>
		void operator-=(const Slot & slot)
		{
			typename SlotList::iterator it;
			for (it = slotList.begin(); it != slotList.end(); it++)
			{
				if ((*it).slot == slot)
					break;
			}

			if (it != _slotList.end())
			{
				(*it).connection.disconnect();
				slotList.erase(it);
			}
		}

	private:
		template <typename Slot>
		bool alreadyConnected(const Slot & slot)
		{
			for (typename SlotList::iterator it = slotList.begin(); it != slotList.end();)
			{
				SlotConnection sc = *it;
				if (sc.slot == slot)
				{
					if (sc.connection.connected())
					{
						return true;
					}

					else {
						typename SlotList::iterator it2 = it;
						it = slotList.erase(it2);
					}

				}

				else {
					it++;
				}
			}

			return false;
		}

		struct SlotConnection
		{
			boost::function<Signature> slot;
			boost::signals::connection connection;
		};

		typedef std::list<SlotConnection> SlotList;

		SlotList slotList;
	};
}

#endif

