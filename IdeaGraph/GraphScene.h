#pragma once
#include "ideagraph_global.h"
#include <qgraphicsscene.h>

class GraphLink;
class GraphAnchor;
class GraphNode;

class IDEAGRAPH_EXPORT GraphScene : public QGraphicsScene
{
public:
	GraphScene(QObject* parent = nullptr);
	virtual ~GraphScene() = default;

protected:
    virtual void wheelEvent(QGraphicsSceneWheelEvent* event)override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event)override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event)override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event)override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

private:
    GraphLink* m_pCurrentLink = nullptr;
    GraphLink* m_pOld = nullptr;

    bool onPressItem(QGraphicsSceneMouseEvent* event, GraphAnchor* const a_pAnchor);
    bool onPressItem(QGraphicsSceneMouseEvent* event, GraphNode* const a_pNode);
    bool connectLink(GraphAnchor* const a_pAnchor);
};

