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

#include "looper.h"

Looper::Looper(QString path, QObject *parent) :
	QObject(parent),
	m_src(MediaSource(path))
{
	m_obj = new MediaObject(this);
	m_out = new AudioOutput(MusicCategory,this);

	createPath(m_obj, m_out);
	m_obj->setCurrentSource(m_src);
	m_obj->play();

	connect(m_obj, SIGNAL(aboutToFinish()), this, SLOT(loop()));
}

void Looper::loop()
{
	m_obj->enqueue(m_src);
}

void Looper::play()
{
	m_obj->play();
}

void Looper::pause()
{
	m_obj->pause();
}
