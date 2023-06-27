#include "GraphAnchor.h"
#include <qevent.h>
#include <qpainter.h>
#include <qpainterpath.h>

GraphAnchor::GraphAnchor(QWidget* a_parent) : QWidget(a_parent)
{
	// TODO
}

void GraphAnchor::paintEvent(QPaintEvent* a_event)
{
	QPainter painter(this);
	
	QPainterPath path;
	path.addEllipse(rect());

	QPen pen(QColor(0, 0, 0), 3);
	painter.setPen(pen);
	painter.setBrush(QColor(255, 255, 255));
	painter.drawPath(path);
	painter.drawEllipse(rect());
}