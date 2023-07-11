#include "JsonModel.h"
#include "JSonNode.h"
#include <qjsonvalue.h>


//-------------------------------------------------------------------------------------------
JsonModel::JsonModel(QObject* a_pParent) : QAbstractItemModel(a_pParent)
{
}

void JsonModel::setup(const QJsonDocument& a_doc)
{
	beginResetModel();
	auto rootObj = a_doc.object();
	m_pRoot = std::make_shared<JSonNode>("JSON Document");
	for (const auto& iterKey: rootObj.keys())
	{
		auto jsonItem = rootObj.value(iterKey);
		if (jsonItem.isObject())
		{
			auto pNode = std::make_shared<JSonNode>(iterKey, JSonNode::NodeType::JSON_OBJECT);
			m_pRoot->addChild(pNode);
			setup(jsonItem.toObject(), pNode);
		}
		else if (jsonItem.isArray())
		{
			auto pNode = std::make_shared<JSonNode>(iterKey, JSonNode::NodeType::JSON_ARRAY);
			m_pRoot->addChild(pNode);
			setup(jsonItem.toArray(), pNode);
		}
		else
		{
			m_pRoot->addAttrib(iterKey, jsonItem.toVariant());
		}
	}
	endResetModel();
}


void JsonModel::setup(const QJsonObject& a_obj, const std::shared_ptr<JSonNode>& a_pParent)
{
	for (const auto& iterKey : a_obj.keys())
	{
		auto jsonItem = a_obj.value(iterKey);
		if (jsonItem.isObject())
		{
			auto pNode = std::make_shared<JSonNode>(iterKey, JSonNode::NodeType::JSON_OBJECT);
			a_pParent->addChild(pNode);
			setup(jsonItem.toObject(), pNode);
		}
		else if (jsonItem.isArray())
		{
			auto pNode = std::make_shared<JSonNode>(iterKey, JSonNode::NodeType::JSON_ARRAY);
			a_pParent->addChild(pNode);
			setup(jsonItem.toArray(), pNode);
		}
		else
		{
			a_pParent->addAttrib(iterKey, jsonItem.toVariant());
		}
	}
}

void JsonModel::setup(const QJsonArray& a_array, const std::shared_ptr<JSonNode>& a_pParent)
{
	int index = 0;
	for (const auto& jsonItem : a_array)
	{
		if (jsonItem.isObject())
		{
			auto pNode = std::make_shared<JSonNode>(QString("[%1] Object").arg(index), JSonNode::NodeType::JSON_OBJECT);
			a_pParent->addChild(pNode);
			setup(jsonItem.toObject(), pNode);
		}
		else if (jsonItem.isArray())
		{
			auto pNode = std::make_shared<JSonNode>(QString("[%1] Array").arg(index), JSonNode::NodeType::JSON_ARRAY);
			setup(jsonItem.toArray(), pNode);
			a_pParent->addChild(pNode);
		}
		else
		{
			a_pParent->addAttrib(QString("[%1] Value").arg(index), jsonItem.toVariant());
		}
		++index;
	}
}

QModelIndex JsonModel::index(int row, int column, const QModelIndex& parent) const
{
	if (!parent.isValid())
	{
		if (m_pRoot)
			return createIndex(row, column, m_pRoot.get());
		return QModelIndex();
	}

	JSonNode* pNode = static_cast<JSonNode*>(parent.internalPointer());
	return createIndex(row, column, pNode->childAt(row).get());
}

QModelIndex JsonModel::parent(const QModelIndex& child) const
{
	JSonNode* pNode = static_cast<JSonNode*>(child.internalPointer());
	
	if(pNode == m_pRoot.get())
		return QModelIndex();

	if (pNode->parent().lock() == m_pRoot)
		return createIndex(0, child.column(), m_pRoot.get());

	if (pNode->parent().lock())
		return createIndex(pNode->parent().lock()->placeInParent(), child.column(), pNode->parent().lock().get());

	return QModelIndex();
}

int JsonModel::rowCount(const QModelIndex& parent) const
{
	int iRet = 0;
	if (!parent.isValid())
	{
		iRet = 1;
	}
	else
	{
		JSonNode* pNode = static_cast<JSonNode*>(parent.internalPointer());
		iRet = pNode->childCount();
	}
	return iRet;
}

int JsonModel::columnCount(const QModelIndex& parent) const
{
	return 1;
}

QVariant JsonModel::data(const QModelIndex& index, int role) const
{
	QVariant var;
	JSonNode* pNode = static_cast<JSonNode*>(index.internalPointer());
	if (pNode)
	{
		if (index.column() == 0)
		{
			switch (role)
			{
			case Qt::DisplayRole:
				var = pNode->displayRole();
				break;
			case Qt::ForegroundRole:
				var = pNode->foregroundRole();
				break;
			case Qt::BackgroundRole:
				var = pNode->backgroundRole();
				break;
			case Qt::FontRole:
				var = pNode->fontRole();
				break;
			default:
				break;
			}
		}
		else
		{
			switch (role)
			{
			case Qt::DisplayRole:
				var = pNode->displayRole();
				break;
			case Qt::ForegroundRole:
				var = pNode->foregroundRole();
				break;
			case Qt::BackgroundRole:
				var = pNode->backgroundRole();
				break;
			case Qt::FontRole:
				var = pNode->fontRole();
				break;
			default:
				break;
			}
		}
	}
	return var;
}

Qt::ItemFlags JsonModel::flags(const QModelIndex& index) const
{
	return Qt::ItemIsEnabled |  Qt::ItemIsSelectable;
}