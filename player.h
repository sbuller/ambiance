#pragma once
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

#include "looper.h"

class Player : public QObject
{
Q_OBJECT

	bool m_playing;
	QList<Looper*> m_loops;

	void each(void (*process)(Looper*));

public:
	explicit Player(QStringList paths, QObject *parent = 0);

public slots:
	void play();
	void pause();
	bool isPlaying();
};
