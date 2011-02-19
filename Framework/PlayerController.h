
#ifndef _PlayerController_h
#define _PlayerController_h

#include "EventListener.h"
#include "Key.h"



class Player;

class PlayerController : EventListener
{
	public:
		PlayerController(Player* player);

		virtual ~PlayerController();

		virtual void keyPressEvent(KeyEvent* event);

		virtual void keyReleaseEvent(KeyEvent* event);

	private:
		Player* m_player;

		Key m_key_up;

		Key m_key_down;

		Key m_key_right;

		Key m_key_left;
};

#endif

