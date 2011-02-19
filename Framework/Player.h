
#ifndef _Player_h
#define _Player_h

#include "Entity.h"
#include "Image.h"
#include "PlayerController.h"
#include "FileSystem.h"



class Player : public Entity
{
	public:
		enum Position
		{
			UP = 0,
			DOWN,
			RIGHT,
			LEFT
		};

	public:
		Player();

		virtual ~Player();

		virtual void update(float delta);

		virtual void draw() const;

		void setXVelocity(int vel);

		void setYVelocity(int vel);

		void setVelocity(int xvel, int yvel);

		int xVelocity() const;

		int yVelocity() const;

		void setPosition(Position position);

		Position position() const;

	private:
		PlayerController m_controller;

		Position m_position;

		int m_x;

		int m_y;

		int m_x_velocity;

		int m_y_velocity;

		PixmapRef m_pixmaps[4];
};

#endif

