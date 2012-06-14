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
#include <QString>
#include <phonon>

using namespace Phonon;

class Looper : public QObject
{
	Q_OBJECT

	MediaSource  m_src;
	MediaObject* m_obj;
	AudioOutput* m_out;

public:
	explicit Looper(QString path, QObject *parent = 0);

public slots:
	void loop();
};
