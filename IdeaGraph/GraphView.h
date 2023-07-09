#pragma once
#include <qgraphicsview.h>

class GraphView : public QGraphicsView
{
	Q_OBJECT
public:
	GraphView(QWidget* a_pParent = nullptr);
	virtual ~GraphView() = default;

protected:
	void wheelEvent(QWheelEvent* a_pEvent) override;
	void mouseMoveEvent(QMouseEvent* a_pEvent) override;
	void mousePressEvent(QMouseEvent* a_pEvent) override;
	void mouseReleaseEvent(QMouseEvent* a_pEvent) override;
};

