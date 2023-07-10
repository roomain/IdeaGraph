#pragma once
#include <qabstractitemmodel.h>

class JSonNode;

class JsonModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	JsonModel(QObject* a_pParent = nullptr);
	virtual ~JsonModel() = default;
	void setup(std::shared_ptr<JSonNode>& a_pRoot) { m_pRoot = a_pRoot; }
	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const final;
	QModelIndex parent(const QModelIndex& child) const final;
	int rowCount(const QModelIndex& parent = QModelIndex()) const final;
	int columnCount(const QModelIndex& parent = QModelIndex()) const final;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const final;
	Qt::ItemFlags flags(const QModelIndex& index) const final;


private:
	std::shared_ptr<JSonNode> m_pRoot;
};

