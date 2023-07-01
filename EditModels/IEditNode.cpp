#include "IEditNode.h"
#include <algorithm>
#include <qfont.h>

IEditNode::IEditNode(std::shared_ptr<IEditNode>& a_parent)
{
	//
}

IEditNode::~IEditNode()
{
	if (m_parent.lock())
		m_parent.lock()->removeChild(shared_from_this());
}

void IEditNode::addChild(std::shared_ptr<IEditNode>& a_pChild)
{
	if (a_pChild->m_parent.lock())
		a_pChild->m_parent.lock()->removeChild(a_pChild);

	m_children.push_back(a_pChild);
	a_pChild->m_parent = shared_from_this();
}

void IEditNode::removeChild(const std::shared_ptr<IEditNode>& a_pChild)
{
	auto iter = std::ranges::find(m_children, a_pChild);
	if (iter != m_children.end())
	{
		m_children.erase(iter);
		a_pChild->m_parent.reset();
	}
}

int IEditNode::placeInParent()const
{
	int iRet = -1;
	if (auto pParent = m_parent.lock())
	{
		auto iter = std::ranges::find(pParent->m_children, shared_from_this());
	}
	return iRet;
}
//-------------------------------------------------------------------------------------
CategoryEditNode::CategoryEditNode(QString a_sCatName, QColor a_backgroundColor, QColor a_foregroundColor):
	IEditNode(), m_sCatName{ a_sCatName }, m_backgroundColor{ a_backgroundColor }, m_foregroundColor{ a_foregroundColor }
{
	//
}

CategoryEditNode::CategoryEditNode(std::shared_ptr<IEditNode>& a_parent, QString a_sCatName, QColor a_backgroundColor, QColor a_foregroundColor) :
	IEditNode(a_parent), m_sCatName{ a_sCatName }, m_backgroundColor{ a_backgroundColor }, m_foregroundColor{ a_foregroundColor }
{
	//
}


QVariant CategoryEditNode::displayRole()const
{
	return m_sCatName;
}

QVariant CategoryEditNode::foregroundRole()const
{
	return m_foregroundColor;
}

QVariant CategoryEditNode::backgroundRole()const
{
	return m_backgroundColor;
}

QVariant CategoryEditNode::fontRole()const
{
	QFont font;
	font.setBold(true);
	return font;
}

QVariant CategoryEditNode::decorationRole()const
{
	return QVariant();
}

