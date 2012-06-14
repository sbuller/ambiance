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
