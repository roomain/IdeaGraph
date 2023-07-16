#pragma once
#include <vector>
#include <QString>
#include <QVariant>
#include <qcolor.h>
#include "editmodels_global.h"

class EDITMODELS_EXPORT IEditNode
{
public:
	enum class Type
	{
		Category,
		Property
	};

private:
	IEditNode* m_parent = nullptr;
	std::vector<IEditNode*> m_children;

public:
	IEditNode() = default;
	IEditNode(IEditNode* const a_pParent);
	virtual ~IEditNode();
	void addChild(IEditNode* const a_pChild);
	void removeChild(IEditNode* const a_pChild);
	[[nodiscard]] IEditNode* const parent()const { return m_parent; }
	[[nodiscard]] int childCount()const { return static_cast<int>(m_children.size()); }
	[[nodiscard]] int placeInParent()const;
	[[nodiscard]] IEditNode* const childAt(const int& a_index)const { return m_children[a_index]; }
	[[nodiscard]] virtual QString title()const = 0;
	[[nodiscard]] virtual bool isEditable()const = 0;
	[[nodiscard]] virtual Type type()const = 0;
	[[nodiscard]] virtual QVariant displayRole()const = 0;
	[[nodiscard]] virtual QVariant foregroundRole()const = 0;
	[[nodiscard]] virtual QVariant backgroundRole()const = 0;
	[[nodiscard]] virtual QVariant fontRole()const = 0;
	[[nodiscard]] virtual QVariant decorationRole()const = 0;
	[[nodiscard]] virtual QVariant data()const = 0;
	[[nodiscard]] virtual int span()const = 0;
	virtual void setData(const QVariant& a_data) = 0;
};

class EDITMODELS_EXPORT CategoryEditNode : public IEditNode
{
private:
	QString m_sCatName;
	QColor m_backgroundColor;
	QColor m_foregroundColor;


public:
	CategoryEditNode() = delete;
	CategoryEditNode(QString a_sCatName, QColor a_backgroundColor, QColor a_forgroundColor);
	CategoryEditNode(IEditNode* const a_pParent, QString a_sCatName, QColor a_backgroundColor, QColor a_forgroundColor);
	virtual ~CategoryEditNode() = default;
	[[nodiscard]] virtual QString title()const final { return m_sCatName; }
	[[nodiscard]] bool isEditable()const final { return false; }
	[[nodiscard]] Type type()const final { return Type::Category; }
	[[nodiscard]] QVariant displayRole()const final;
	[[nodiscard]] QVariant foregroundRole()const final;
	[[nodiscard]] QVariant backgroundRole()const final;
	[[nodiscard]] QVariant fontRole()const final;
	[[nodiscard]] QVariant decorationRole()const final;
	[[nodiscard]] QVariant data()const final{ return QVariant(); }
	[[nodiscard]] int span()const final { return 2; }
	void setData(const QVariant& a_data) final {/*nothing todo*/ }
};