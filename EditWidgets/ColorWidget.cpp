#include "ColorWidget.h"
#include <qpainter.h>

ColorWidget::ColorWidget(QWidget* a_parent) : QWidget(a_parent) {}

void ColorWidget::setColor(const QColor& a_color)
{
	m_color = a_color;
}

void ColorWidget::paintEvent(QPaintEvent* pEvent)
{
	QPainter painter(this);
	painter.fillRect(rect(), m_color);
}