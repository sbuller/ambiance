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

#include <QtCore/QCoreApplication>
#include <QDir>
#include "looper.h"

int main(int argc, char *argv[])
{
	freopen("/dev/null", "w", stderr);
	QCoreApplication a(argc, argv);
	a.setApplicationName("Ambiance");

	QList<Looper *> trackList;

	QDir dir = QDir::current();
	auto list = dir.entryInfoList();
	for (int i = 0; i < list.size(); ++i) {
		Looper* l = new Looper(list.at(i).fileName());
		trackList.append(l);
	}

	return a.exec();
}
