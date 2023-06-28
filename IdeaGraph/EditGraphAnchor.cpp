#include "EditGraphAnchor.h"
#include <qevent.h>
#include <qpainter.h>
#include <qpainterpath.h>

EditGraphAnchor::EditGraphAnchor(QWidget* a_parent) : QWidget(a_parent)
{
	// TODO
}

void EditGraphAnchor::paintEvent(QPaintEvent* a_event)
{
	QPainter painter(this);
	
	QPainterPath path;
	path.addEllipse(rect());

	QPen pen(QColor(0, 0, 0), 3);
	painter.setPen(pen);
	painter.fillPath(path, QColor(255, 255, 255));
	painter.drawEllipse(rect());
}