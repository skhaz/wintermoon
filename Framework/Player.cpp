
#include "Player.h"
#include "PlayerController.h"
#include "Exception.h"



Player::Player()
: m_controller(this)
, m_position(DOWN)
, m_x(50)
, m_y(50)
, m_x_velocity(0)
, m_y_velocity(0)
{
	FileSystem::addArchive("media/player.zip");

	m_pixmaps[UP] = Pixmap::get("up.png");
	m_pixmaps[DOWN] = Pixmap::get("down.png");
	m_pixmaps[RIGHT] = Pixmap::get("left.png");
	m_pixmaps[LEFT] = Pixmap::get("right.png");
}

Player::~Player()
{
}

void Player::update(float delta)
{
	m_x += m_x_velocity;
	m_y += m_y_velocity;
}

void Player::draw() const
{
	PixmapRef pixmap = m_pixmaps[m_position];
	int width = pixmap->width();
	int height = pixmap->height();

	glLoadIdentity();

	pixmap->bind();
	glTranslatef(m_x, m_y, .0f);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	    glTexCoord2i(1, 0);
		glVertex3i(m_x - width, m_y - height, 0);
    	glTexCoord2i(1, 1);
		glVertex3i(m_x - width, m_y + height, 0);
	    glTexCoord2i(0, 1);
		glVertex3i(m_x + width, m_y + height, 0);
    	glTexCoord2i(0, 0);
		glVertex3i(m_x + width, m_y - height, 0);
	glEnd();
}

void Player::setXVelocity(int vel)
{
	m_x_velocity = vel;
}

void Player::setYVelocity(int vel)
{
	m_y_velocity = vel;
}

void Player::setVelocity(int xvel, int yvel)
{
	m_x_velocity = xvel;
	m_y_velocity = yvel;
}

int Player::xVelocity() const
{
	return m_x_velocity;
}

int Player::yVelocity() const
{
	return m_y_velocity;
}

void Player::setPosition(Position position)
{
	m_position = position;
}

Player::Position Player::position() const
{
	return m_position;
}

