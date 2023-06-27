#pragma once

#include <QWidget>
#include "ui_GraphBox.h"
#include <vector>

class PreviewBox;

class GraphBox : public QWidget
{
	Q_OBJECT

public:
	GraphBox(QWidget *parent = nullptr);
	~GraphBox();
	void setTitle(const QString& a_title);

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
	Ui::GraphBoxClass ui;
	std::vector<PreviewBox*> m_vPreviewInBoxes;
	std::vector<PreviewBox*> m_vPreviewOutBoxes;
	int dragInternal(const QPoint& a_pos, bool& a_isInput);
	int findInput(const QPoint& a_pos)const;
	int findOutput(const QPoint& a_pos)const;
};
