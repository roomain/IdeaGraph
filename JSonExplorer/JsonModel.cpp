#include "JsonModel.h"
#include "JSonNode.h"
#include <qjsonvalue.h>


//-------------------------------------------------------------------------------------------
JsonModel::JsonModel(QObject* a_pParent) : QAbstractItemModel(a_pParent)
{
}

void JsonModel::setup(const QJsonDocument& a_doc)
{
	auto rootObj = a_doc.object();
	m_pRoot = std::make_shared<JSonNode>("JSON Document");
	for (const auto& iter: rootObj)
	{
		if (iter.isObject())
		{
			//
		}
		else if (iter.isArray())
		{
			//
		}
		else
		{
			//std::make_shared<JSonNode>("JSON Document");
		}
	}
}


void JsonModel::setup(const QJsonObject& a_obj)
{
	for (const auto& iter : a_obj)
	{
		if (iter.isObject())
		{
			//
		}
		else if (iter.isArray())
		{
			//
		}
		else
		{
			//std::make_shared<JSonNode>("JSON Document");
		}
	}
}

void JsonModel::setup(const QJsonArray& a_array)
{
	for (const auto& iter : a_array)
	{
		if (iter.isObject())
		{
			//
		}
		else if (iter.isArray())
		{
			//
		}
		else
		{
			//std::make_shared<JSonNode>("JSON Document");
		}
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
	if (pNode->parent().lock())
		return createIndex(pNode->parent().lock()->placeInParent(), child.column(), pNode->parent().lock().get());

	return QModelIndex();
}

int JsonModel::rowCount(const QModelIndex& parent) const
{
	if (!parent.isValid())
		return m_pRoot ? 0 : 1;
	JSonNode* pNode = static_cast<JSonNode*>(parent.internalPointer());
	return pNode->childCount();
}

int JsonModel::columnCount(const QModelIndex& parent) const
{
	return 2;
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