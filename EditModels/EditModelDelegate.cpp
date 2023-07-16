#include "EditModelDelegate.h"
#include "TEditNode.h"
#include <QFontDialog>
#include <QColorDialog>



EditModelDelegate::EditModelDelegate(QObject* parent) : QStyledItemDelegate(parent)
{
	//
}

QWidget* EditModelDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QWidget* wdgEdit = nullptr;
	IEditNode*const  pNode = static_cast<IEditNode*>(index.internalPointer());
	if (pNode)
	{
		QVariant var = pNode->data();
		switch (var.type())
		{
		case QMetaType::QColor:
			wdgEdit = new QColorDialog(var.value<QColor>());
			break;

		case QMetaType::QFont:
			wdgEdit = new QFontDialog(var.value<QFont>());
			break;

		default:
			break;
		}
	}
	return wdgEdit;
}

void EditModelDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	/*IEditNode* const  pNode = static_cast<IEditNode*>(index.internalPointer());
	if (pNode)
	{
		QVariant var = pNode->data();
		switch (var.type())
		{
		case QMetaType::QColor:
			pNode->setData(static_cast<QColorDialog*>(editor)->selectedColor());
			break;

		case QMetaType::QFont:
			pNode->setData(static_cast<QFontDialog*>(editor)->selectedFont());
			break;

		default:
			break;
		}
	}*/
}

void EditModelDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	IEditNode* const  pNode = static_cast<IEditNode*>(index.internalPointer());
	if (pNode)
	{
		QVariant var = pNode->data();
		switch (var.type())
		{
		case QMetaType::QColor:
		{
			auto pEditor = static_cast<QColorDialog*>(editor);
			pNode->setData(pEditor->currentColor());
			break;
		}

		case QMetaType::QFont:
			pNode->setData(static_cast<QFontDialog*>(editor)->currentFont());
			break;

		default:
			break;
		}
	}
}
