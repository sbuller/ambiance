/* Copyright 2012  Stefan Buller <stefan.buller@gmail.com>
 *
 * This file is part of Ambiance.
 *
 * Ambiance is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ambiance is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Ambiance.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QObject>
#include <QStringList>
#include <QList>

#include "player.h"

Player::Player(QStringList paths, QObject *parent) :
	QObject(parent)
{
	for (int i=0; i<paths.length(); i++) {
		m_loops.append(new Looper(paths[i]));
	}
	m_playing = true;
}

void Player::each(void (*process)(Looper*))
{
	for (int i=0; i<m_loops.length(); i++) {
		process(m_loops[i]);
	}
}

bool Player::isPlaying()
{
	return m_playing;
}

void Player::play()
{
	m_playing = true;
	each([](Looper *l){
		l->play();
	});
}

void Player::pause()
{
	m_playing = false;
	each([](Looper *l){
		l->pause();
	});
}
