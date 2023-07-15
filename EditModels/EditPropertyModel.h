#pragma once
#include <qabstractitemmodel.h>
#include "editmodels_global.h"
#include <vector>

class IEditNode;

/*@brief Model that represents properties of an object*/
class EDITMODELS_EXPORT EditPropertyModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    EditPropertyModel(QObject* a_pParent = nullptr);
    virtual ~EditPropertyModel() = default;
    void clear();
    void setup(const std::vector<IEditNode*>& a_topLevel);
    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const final;
    QModelIndex parent(const QModelIndex& child) const final;
    int rowCount(const QModelIndex& parent = QModelIndex()) const final;
    int columnCount(const QModelIndex& parent = QModelIndex()) const final;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const final;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole)const final;
    QSize span(const QModelIndex& index) const final;
    Qt::ItemFlags flags(const QModelIndex& index) const final;
    bool setData(const QModelIndex& index, const QVariant& value, int role)final;

signals:
    /*@brief emitted when a property is updated*/
    void sg_propertyUpdated(const QModelIndex&);

private:
    std::vector<IEditNode*> m_vTopLevels;
};
