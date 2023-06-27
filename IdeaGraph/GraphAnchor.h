#pragma once
#include <qwidget.h>

class GraphAnchor : public QWidget
{
	Q_OBJECT

public:
	GraphAnchor(QWidget* a_parent);
	~GraphAnchor() = default;

protected:
	void paintEvent(QPaintEvent* a_event)final;
};

