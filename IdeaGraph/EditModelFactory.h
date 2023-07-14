#pragma once
#include <memory>

class IEditNode;
class GraphNode;
class GraphAnchor;

class EditModelFactory
{
public:
	static std::shared_ptr<IEditNode> createEditTree(GraphNode* const a_pNode);
	static std::shared_ptr<IEditNode> createEditTree(GraphAnchor* const a_pAnchor);
};

