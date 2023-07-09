#pragma once
#include <qwidget.h>
#include <QColor>

class ColorWidget :  public QWidget
{
	Q_OBJECT
public:
	ColorWidget(QWidget* a_parent = nullptr);
	~ColorWidget() = default;
	void setColor(const QColor& a_color);
protected:
	void paintEvent(QPaintEvent* pEvent)final;
private:
	QColor m_color;
};

