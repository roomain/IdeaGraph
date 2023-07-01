#pragma once
#include <qabstractitemmodel.h>
#include "editmodels_global.h"
#include <memory>

class IEditNode;

/*@brief Model that represents properties of an object*/
class EDITMODELS_EXPORT EditPropertyModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    EditPropertyModel(QObject* a_pParent = nullptr);
    virtual ~EditPropertyModel() = default;
    void setup(std::shared_ptr<IEditNode>& a_pRoot) { m_pRoot = a_pRoot; }
    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const final;
    QModelIndex parent(const QModelIndex& child) const final;
    int rowCount(const QModelIndex& parent = QModelIndex()) const final;
    int columnCount(const QModelIndex& parent = QModelIndex()) const final;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const final;
    QSize span(const QModelIndex& index) const final;
    Qt::ItemFlags flags(const QModelIndex& index) const final;

signals:
    /*@brief emitted when a property is updated*/
    void sg_propertyUpdated(const QModelIndex&);

private:
    std::shared_ptr<IEditNode> m_pRoot;
};
