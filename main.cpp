#include <QtCore/QCoreApplication>
#include "looper.h"

int main(int argc, char *argv[])
{
	freopen("/dev/null", "w", stderr);
	QCoreApplication a(argc, argv);
	a.setApplicationName("Ambiance");

	Looper track1("track1.ogg");
	Looper track2("track2.ogg");
	Looper track3("track3.ogg");

	return a.exec();
}
