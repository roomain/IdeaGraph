#pragma once
#include <memory>
#include <vector>

class IEditNode;
class GraphNode;
class GraphAnchor;

class EditModelFactory
{
public:
	static std::vector<IEditNode*> createEditTree(GraphNode* const a_pNode);
	static std::vector<IEditNode*> createEditTree(GraphAnchor* const a_pAnchor);
};

