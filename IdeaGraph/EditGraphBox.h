#pragma once

#include <QWidget>
#include "ui_EditGraphBox.h"
#include <vector>

class EditPreviewBox;

class EditGraphBox : public QWidget
{
	Q_OBJECT

public:
	EditGraphBox(QWidget *parent = nullptr);
	~EditGraphBox();
	void setTitle(const QString& a_title);
	//void serialize();

protected:
	void mouseMoveEvent(QMouseEvent* a_pEvent)override;
	void mousePressEvent(QMouseEvent* a_pEvent)override;
	void mouseReleaseEvent(QMouseEvent* a_pEvent)override;
	void mouseDoubleClickEvent(QMouseEvent* a_pEvent)override;
	void dragEnterEvent(QDragEnterEvent* a_pEvent)override;
	void dragMoveEvent(QDragMoveEvent* a_pEvent)override;
	void dragLeaveEvent(QDragLeaveEvent* a_pEvent)override;
	void dropEvent(QDropEvent* a_pEvent)override;

private:
	Ui::EditGraphBoxClass ui;
	std::vector<EditPreviewBox*> m_vPreviewInBoxes;
	std::vector<EditPreviewBox*> m_vPreviewOutBoxes;
	int dragInternal(const QPoint& a_pos, bool& a_isInput);
	int findInput(const QPoint& a_pos)const;
	int findOutput(const QPoint& a_pos)const;
};
