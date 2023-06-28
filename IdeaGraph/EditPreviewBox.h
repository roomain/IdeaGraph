#pragma once
#include <qwidget.h>

class EditPreviewBox : public QWidget
{
	Q_OBJECT
public:
	EditPreviewBox(QWidget* a_parent = nullptr);
	virtual ~EditPreviewBox() = default;

protected:
	void paintEvent(QPaintEvent* a_pEvent)override;
	void dropEvent(QDropEvent* a_pEvent)override;

signals:
	void sg_drop();
};

