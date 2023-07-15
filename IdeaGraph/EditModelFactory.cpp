#include "EditModelFactory.h"
#include "GraphAnchor.h"
#include "GraphNode.h"
#include "TEditNode.h"
using namespace std::placeholders;

std::vector<IEditNode*> EditModelFactory::createEditTree(GraphNode* const a_pNode)
{
	std::vector<IEditNode*> vRet;
	IEditNode* pItemCat = new CategoryEditNode("GraphNode", QColor(150, 150, 150), QColor(255, 255, 255));
	IEditNode* pItem = new TEditNode<QString, GetterFun<QString>, SetterFunRef<QString>>
		(pItemCat, "Title",  std::bind_front(&GraphNode::setTitle, a_pNode),
			std::bind_front(&GraphNode::title, a_pNode));
	vRet.emplace_back(pItemCat);
	
	pItemCat = new CategoryEditNode("Visual", QColor(150, 150, 150), QColor(255, 255, 255));
	pItem = new TEditNode<QColor, GetterFun<QColor>, SetterFunRef<QColor>>(pItemCat, "Background color",
		std::bind_front(&GraphNode::setBKColor, a_pNode),
		std::bind_front(&GraphNode::bkcolor, a_pNode));
	pItem = new TEditNode<QColor, GetterFun<QColor>, SetterFunRef<QColor>>(pItemCat, "Foreground color",
		std::bind_front(&GraphNode::setColor, a_pNode),
		std::bind_front(&GraphNode::color, a_pNode));
	pItem = new TEditNode<QFont, GetterFun<QFont>, SetterFunRef<QFont>>(pItemCat,"Font",
		std::bind_front(&GraphNode::setFont, a_pNode),
		std::bind_front(&GraphNode::font, a_pNode));
	vRet.emplace_back(pItemCat);
	return vRet;
}

std::vector<IEditNode*> EditModelFactory::createEditTree(GraphAnchor* const a_pAnchor)
{
	std::vector<IEditNode*> vRet;
	auto pRoot = new CategoryEditNode("GraphAnchor", QColor(0, 255, 0), QColor(255, 255, 255));
	//
	return vRet;
}