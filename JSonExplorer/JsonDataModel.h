#pragma once
#include <qabstractitemmodel.h>
#include "JSonNode.h"

class JsonDataModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	JsonDataModel(QObject* a_pParent = nullptr);
	virtual ~JsonDataModel() = default;
	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const final;
	QModelIndex parent(const QModelIndex& child) const final;
	void setup(std::shared_ptr<JSonNode> a_node);
	int rowCount(const QModelIndex& parent = QModelIndex()) const final;
	int columnCount(const QModelIndex& parent = QModelIndex()) const final;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const final;
	Qt::ItemFlags flags(const QModelIndex& index) const final;

private:
	std::shared_ptr<JSonNode> m_pNode;
};

