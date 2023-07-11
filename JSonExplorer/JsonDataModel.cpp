#include "JsonDataModel.h"

JsonDataModel::JsonDataModel(QObject* a_pParent) : QAbstractItemModel(a_pParent)
{
	//
}

void JsonDataModel::setup(std::shared_ptr<JSonNode> a_node)
{
	beginResetModel();
	m_pNode = a_node;
	endResetModel();
}

QModelIndex JsonDataModel::index(int row, int column, const QModelIndex& parent) const
{
	return createIndex(row, column);

}

QModelIndex JsonDataModel::parent(const QModelIndex& child) const
{
	return QModelIndex();
}

int JsonDataModel::rowCount(const QModelIndex& parent) const
{
	if (m_pNode)
		return static_cast<int>(m_pNode->attribCount());
	return 0;
}

int JsonDataModel::columnCount(const QModelIndex& parent) const
{
	return 2;
}

QVariant JsonDataModel::data(const QModelIndex& index, int role) const
{
	QVariant var;
	switch (role)
	{
	case Qt::DisplayRole:
	{
		auto data = m_pNode->attributeAt(index.row());
		var = (index.column() == 0) ? data.m_name : data.m_value;
		break;
	}
	default:
		break;
	}
	return var;
}

Qt::ItemFlags JsonDataModel::flags(const QModelIndex& index) const
{
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}