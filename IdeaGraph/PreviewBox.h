#pragma once
#include <qwidget.h>

class PreviewBox : public QWidget
{
	Q_OBJECT
public:
	PreviewBox(QWidget* a_parent = nullptr);
	virtual ~PreviewBox() = default;

protected:
	void paintEvent(QPaintEvent* a_pEvent)override;
	void dropEvent(QDropEvent* a_pEvent)override;

signals:
	void sg_drop();
};

