
#include "PlayerController.h"
#include "Player.h"



PlayerController::PlayerController(Player* player)
: m_player(player)
, m_key_up("UP")
, m_key_down("DOWN")
, m_key_right("RIGHT")
, m_key_left("LEFT")
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::keyPressEvent(KeyEvent* event)
{
	if (event->key() == m_key_up)
	{
		m_player->setPosition(Player::UP);
		m_player->setYVelocity(-1);
	}

	else if (event->key() == m_key_down)
	{
		m_player->setPosition(Player::DOWN);
		m_player->setYVelocity(1);
	}

	else if (event->key() == m_key_right)
	{
		m_player->setPosition(Player::RIGHT);
		m_player->setXVelocity(1);
	}

	else if (event->key() == m_key_left)
	{
		m_player->setPosition(Player::LEFT);
		m_player->setXVelocity(-1);
	}

	else {
	//	m_player->setVelocity(0, 0);
	}
}

void PlayerController::keyReleaseEvent(KeyEvent* event)
{
	if (event->key() == m_key_up && m_player->yVelocity() < 0)
	{
		m_player->setYVelocity(0);
	}

	else if (event->key() == m_key_down && m_player->yVelocity() > 0)
	{
		m_player->setYVelocity(0);
	}

	else if (event->key() == m_key_right && m_player->xVelocity() > 0)
	{
		m_player->setXVelocity(0);
	}

	else if (event->key() == m_key_left && m_player->xVelocity() < 0)
	{
		m_player->setXVelocity(0);
	}

	else {
	}
}

