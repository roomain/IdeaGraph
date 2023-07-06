#pragma once
#include "ideagraph_global.h"
#include <qgraphicsscene.h>

class GraphLink;

class IDEAGRAPH_EXPORT GraphScene : public QGraphicsScene
{
public:
	GraphScene(QObject* parent = nullptr);
	virtual ~GraphScene() = default;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;

private:
    GraphLink* m_pCurrentLink = nullptr;
    GraphLink* m_pOld = nullptr;
};

