#include "EditModelFactory.h"
#include "GraphAnchor.h"
#include "GraphNode.h"
#include "TEditNode.h"
using namespace std::placeholders;

std::shared_ptr<IEditNode> EditModelFactory::createEditTree(GraphNode* const a_pNode)
{
	auto pRoot = std::make_shared<CategoryEditNode>("GraphNode", QColor(255,0,0), QColor(255, 255, 255));
	std::shared_ptr<IEditNode> pItem = std::make_shared<TEditNode<QString, GetterFun<QString>, SetterFunRef<QString>>>
		("Title",  std::bind_front(&GraphNode::setTitle, a_pNode),
			std::bind_front(&GraphNode::title, a_pNode));
	pRoot->addChild(pItem);
	std::shared_ptr<IEditNode> pItemCat = std::make_shared<CategoryEditNode>("Visual", QColor(50, 50, 200), QColor(255, 255, 255));
	pRoot->addChild(pItemCat);
	pItem = std::make_shared<TEditNode<QColor, GetterFun<QColor>, SetterFunRef<QColor>>>("Background color",
		std::bind_front(&GraphNode::setBKColor, a_pNode),
		std::bind_front(&GraphNode::bkcolor, a_pNode));
	pItemCat->addChild(pItem);
	pItem = std::make_shared<TEditNode<QColor, GetterFun<QColor>, SetterFunRef<QColor>>>("Foreground color",
		std::bind_front(&GraphNode::setColor, a_pNode),
		std::bind_front(&GraphNode::color, a_pNode));
	pItemCat->addChild(pItem);
	pItem = std::make_shared<TEditNode<QFont, GetterFun<QFont>, SetterFunRef<QFont>>>("Font",
		std::bind_front(&GraphNode::setFont, a_pNode),
		std::bind_front(&GraphNode::font, a_pNode));
	pItemCat->addChild(pItem);
	return pRoot;
}

std::shared_ptr<IEditNode> EditModelFactory::createEditTree(GraphAnchor* const a_pAnchor)
{
	auto pRoot = std::make_shared<CategoryEditNode>("GraphAnchor", QColor(0, 255, 0), QColor(255, 255, 255));
	//
	return pRoot;
}