#pragma once

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
