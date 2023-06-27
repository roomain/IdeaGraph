#include "PreviewBox.h"
#include <qevent>
#include <qpainter.h>
#include <QColor>

PreviewBox::PreviewBox(QWidget* a_parent) : QWidget{a_parent}{}

void PreviewBox::paintEvent(QPaintEvent* a_pEvent)
{
	QPainter paint(this);
	QPen pen(QColor(0, 0, 0), Qt::DashLine);
	paint.setPen(pen);
	paint.fillRect(rect(), QColor(255, 255, 255));
	paint.drawRoundedRect(rect(), 10, 10);
}

void PreviewBox::dropEvent(QDropEvent* a_pEvent)
{
	//
}