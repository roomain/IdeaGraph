#include "EditPropertyModel.h"
#include <vector>
#include "IEditNode.h"
#include <QSize>


//-------------------------------------------------------------------------------------------
EditPropertyModel::EditPropertyModel(QObject* a_pParent) : QAbstractItemModel(a_pParent)
{
}

void EditPropertyModel::setup(std::shared_ptr<IEditNode>& a_pRoot) 
{ 
	beginResetModel();
	m_pRoot = a_pRoot;
	endResetModel();
}

QModelIndex EditPropertyModel::index(int row, int column, const QModelIndex& parent) const
{
	if (!parent.isValid())
	{
		if(m_pRoot)
			return createIndex(row, column, m_pRoot.get());
		return QModelIndex();
	}

	IEditNode* pNode = static_cast<IEditNode*>(parent.internalPointer());
	return createIndex(row, column, pNode->childAt(row).get());
}

QModelIndex EditPropertyModel::parent(const QModelIndex& child) const
{
	IEditNode* pNode = static_cast<IEditNode*>(child.internalPointer());
	if (pNode == m_pRoot.get())
		return QModelIndex();

	if (pNode->parent().lock() == m_pRoot)
		return createIndex(0, child.column(), m_pRoot.get());

	if (pNode->parent().lock())
		return createIndex(pNode->parent().lock()->placeInParent(), child.column(), pNode->parent().lock().get());
	
	return QModelIndex();
}

int EditPropertyModel::rowCount(const QModelIndex& parent) const
{
	if (!parent.isValid())
		return m_pRoot ? 0 : 1;
	IEditNode* pNode = static_cast<IEditNode*>(parent.internalPointer());
	return pNode->childCount();
}

int EditPropertyModel::columnCount(const QModelIndex& parent) const
{
	return 2;
}

QVariant EditPropertyModel::data(const QModelIndex& index, int role) const
{
	QVariant var;
	IEditNode* pNode = static_cast<IEditNode*>(index.internalPointer());
	if (pNode)
	{
		if (index.column() == 0)
		{
			switch (role)
			{
			case Qt::DisplayRole:
				var = pNode->title();
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

QSize EditPropertyModel::span(const QModelIndex& index) const
{
	IEditNode* pNode = static_cast<IEditNode*>(index.internalPointer());
	return QSize(pNode->span(), 1);
}

Qt::ItemFlags EditPropertyModel::flags(const QModelIndex& index) const
{
	IEditNode* pNode = static_cast<IEditNode*>(index.internalPointer());
	return Qt::ItemIsEnabled | (pNode->isEditable() ? Qt::ItemIsEditable : Qt::NoItemFlags) | Qt::ItemIsSelectable;
}