#pragma once
#include <qwidget.h>

class EditGraphAnchor : public QWidget
{
	Q_OBJECT

public:
	EditGraphAnchor(QWidget* a_parent);
	~EditGraphAnchor() = default;

protected:
	void paintEvent(QPaintEvent* a_event)final;
};

