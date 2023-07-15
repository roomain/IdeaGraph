#include "IEditNode.h"
#include <algorithm>
#include <qfont.h>

IEditNode::IEditNode(IEditNode* const a_pParent)
{
	if (a_pParent)
		a_pParent->addChild(this);
}

IEditNode::~IEditNode()
{
	for (auto pChild : m_children)
		delete pChild;
}

void IEditNode::addChild(IEditNode* const a_pChild)
{
	if (a_pChild->m_parent)
		a_pChild->m_parent->removeChild(a_pChild);

	m_children.push_back(a_pChild);
	a_pChild->m_parent = this;
}

void IEditNode::removeChild(IEditNode* const  a_pChild)
{
	auto iter = std::ranges::find(m_children, a_pChild);
	if (iter != m_children.end())
	{
		m_children.erase(iter);
		a_pChild->m_parent = nullptr;
	}
}

int IEditNode::placeInParent()const
{
	int iRet = -1;
	if (auto pParent = m_parent)
	{
		auto iter = std::ranges::find(pParent->m_children, this);
		iRet = iter - pParent->m_children.begin();
	}
	return iRet;
}
//-------------------------------------------------------------------------------------
CategoryEditNode::CategoryEditNode(QString a_sCatName, QColor a_backgroundColor, QColor a_foregroundColor):
	IEditNode(), m_sCatName{ a_sCatName }, m_backgroundColor{ a_backgroundColor }, m_foregroundColor{ a_foregroundColor }
{
	//
}

CategoryEditNode::CategoryEditNode(IEditNode* const a_pParent, QString a_sCatName, QColor a_backgroundColor, QColor a_foregroundColor) :
	IEditNode(a_pParent), m_sCatName{ a_sCatName }, m_backgroundColor{ a_backgroundColor }, m_foregroundColor{ a_foregroundColor }
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

