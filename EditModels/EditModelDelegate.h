#pragma once
#include <QStyledItemDelegate>
#include "editmodels_global.h"

class EDITMODELS_EXPORT EditModelDelegate : public QStyledItemDelegate
{
	Q_OBJECT
public:
	EditModelDelegate(QObject* parent = nullptr);
	~EditModelDelegate() = default;
	QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const final;
	void setEditorData(QWidget* editor, const QModelIndex& index) const final;
	void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const final;
};

