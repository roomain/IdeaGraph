#include "JSonNode.h"
#include <ranges>

JSonNode::JSonNode(const QString& a_title, const NodeType a_type, const std::shared_ptr<JSonNode>& a_parent) :
	m_title{ a_title }, m_type{ a_type }
{
	if (a_parent)
		a_parent->addChild(shared_from_this());
}

JSonNode::JSonNode(const QString& a_title, const QJsonValue& a_value, const NodeType a_type, const std::shared_ptr<JSonNode>& a_parent) :
	m_title{ a_title }, m_value{ a_value }, m_type{ a_type }
{
	if(a_parent)
		a_parent->addChild(shared_from_this());
}


const int JSonNode::placeInParent()const
{
	int iRet = -1;
	if (auto pParent = m_parent.lock())
	{
		auto iter = std::ranges::find(pParent->m_vChildren, shared_from_this());
		iRet = iter - pParent->m_vChildren.begin();
	}
	return iRet;
}

std::weak_ptr<JSonNode> JSonNode::parent()
{
	return m_parent;
}

size_t JSonNode::childCount()const
{
	return  m_vChildren.size();
}

std::shared_ptr<JSonNode> JSonNode::childAt(const unsigned int a_index)
{
	return m_vChildren[a_index];
}

void JSonNode::addChild(const std::shared_ptr<JSonNode>& a_node)
{
	if (a_node->m_parent.lock())
		a_node->m_parent.lock()->removeChild(a_node);

	m_vChildren.push_back(a_node);
	a_node->m_parent = shared_from_this();
}

void JSonNode::removeChild(const std::shared_ptr<JSonNode>& a_node)
{
	auto iter = std::ranges::find(m_vChildren, a_node);
	if (iter != m_vChildren.end())
	{
		m_vChildren.erase(iter);
		a_node->m_parent.reset();
	}
}

void JSonNode::removeChildAt(const unsigned int a_index)
{
	auto pChild = m_vChildren[a_index];
	pChild->m_parent.reset();
	m_vChildren.erase(m_vChildren.begin() + a_index);
}

QVariant JSonNode::displayRole()const
{
	QString title = m_title;
	switch (m_type)
	{
	case NodeType::JSON_OBJECT:
		title = "{} " + title;
		break;
	case NodeType::JSON_TABLE:
		title = "[] " + title;
		break;
	}
	return title;
}

QVariant JSonNode::foregroundRole()const
{
	return QVariant();
}

QVariant JSonNode::backgroundRole()const
{
	return QVariant();
}

QVariant JSonNode::fontRole()const
{
	return QVariant();
}

QVariant JSonNode::decorationRole()const
{
	return QVariant();
}
