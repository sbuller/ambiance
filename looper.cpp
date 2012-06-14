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
