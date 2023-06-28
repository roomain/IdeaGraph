#include "PreviewBox.h"
#include <qevent>
#include <qpainter.h>
#include <QColor>
#include <qpainter.h>
#include <qpainterpath.h>

PreviewBox::PreviewBox(QWidget* a_parent) : QWidget{a_parent}{}

void PreviewBox::paintEvent(QPaintEvent* a_pEvent)
{
	QPainter paint(this);
	QPen pen(QColor(0, 0, 0), 3, Qt::DashLine);
	paint.setPen(pen);

	QPainterPath path;
	path.addRoundedRect(rect(), 10, 10);
	paint.fillPath(path, QColor(155, 255, 255));
	paint.drawRoundedRect(rect(), 10, 10);
}

void PreviewBox::dropEvent(QDropEvent* a_pEvent)
{
	//
}