#pragma once
#include <qabstractitemmodel.h>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <qjsonarray.h>

class JSonNode;

class JsonModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	JsonModel(QObject* a_pParent = nullptr);
	virtual ~JsonModel() = default;
	void setup(const QJsonDocument& a_doc);
	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const final;
	QModelIndex parent(const QModelIndex& child) const final;
	int rowCount(const QModelIndex& parent = QModelIndex()) const final;
	int columnCount(const QModelIndex& parent = QModelIndex()) const final;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const final;
	Qt::ItemFlags flags(const QModelIndex& index) const final;


private:
	void setup(const QJsonObject& a_obj);
	void setup(const QJsonArray& a_array);
	std::shared_ptr<JSonNode> m_pRoot;
};

