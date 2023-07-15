#include "EditPropertyModel.h"
#include <vector>
#include "IEditNode.h"
#include <QSize>


//-------------------------------------------------------------------------------------------
EditPropertyModel::EditPropertyModel(QObject* a_pParent) : QAbstractItemModel(a_pParent)
{
}


void EditPropertyModel::clear()
{
	beginResetModel();
	for (auto pItem : m_vTopLevels)
		delete pItem;
	m_vTopLevels.clear();
	endResetModel();
}

void EditPropertyModel::setup(const std::vector<IEditNode*>& a_topLevel)
{ 
	beginResetModel();
	m_vTopLevels = a_topLevel;
	endResetModel();
}

QModelIndex EditPropertyModel::index(int row, int column, const QModelIndex& parent) const
{
	if (!parent.isValid())
	{
		if (m_vTopLevels.empty())
			return QModelIndex();
		return createIndex(row, column, m_vTopLevels.at(row));
	}

	IEditNode* pNode = static_cast<IEditNode*>(parent.internalPointer());
	return createIndex(row, column, pNode->childAt(row));
}

QModelIndex EditPropertyModel::parent(const QModelIndex& child) const
{
	IEditNode* pNode = static_cast<IEditNode*>(child.internalPointer());
	auto pParent = pNode->parent();
	if (!pParent)// vide
		return QModelIndex();

	auto iter = std::ranges::find(m_vTopLevels, pParent);
	if (iter != m_vTopLevels.cend())
		return createIndex(iter - m_vTopLevels.cbegin(), child.column(), pParent);

	return createIndex(pParent->placeInParent(), child.column(), pParent);
	
}

int EditPropertyModel::rowCount(const QModelIndex& parent) const
{
	if (!parent.isValid())
		return m_vTopLevels.size();
	IEditNode* pNode = static_cast<IEditNode*>(parent.internalPointer());
	return pNode->childCount();
}

int EditPropertyModel::columnCount(const QModelIndex& parent) const
{
	return 2;
}

QVariant EditPropertyModel::headerData(int section, Qt::Orientation orientation, int role)const
{
	QVariant var;
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
	{
		switch (section)
		{
		case 0:
			var = "Property";
			break;

		default:
			var = "Value";
		}
	}
	return var;
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
				if (pNode->span() == 2)
					var = pNode->foregroundRole();
				break;
			case Qt::BackgroundRole:
				if (pNode->span() == 2)
					var = pNode->backgroundRole();
				break;
			case Qt::FontRole:
				if (pNode->span() == 2)
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
				if (pNode->span() == 1)
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

bool EditPropertyModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
	IEditNode* pNode = static_cast<IEditNode*>(index.internalPointer());
	pNode->setData(value);
	return true;
}