#pragma once
#include <memory>
#include <vector>
#include <QString>
#include <QVariant>
#include <qcolor.h>
#include "editmodels_global.h"

class EDITMODELS_EXPORT IEditNode : public std::enable_shared_from_this<IEditNode>
{
public:
	enum class Type
	{
		Category,
		Property
	};

private:
	std::weak_ptr<IEditNode> m_parent;
	std::vector<std::shared_ptr<IEditNode>> m_children;

public:
	IEditNode() = default;
	virtual ~IEditNode();
	void addChild(std::shared_ptr<IEditNode>& a_pChild);
	void removeChild(const std::shared_ptr<IEditNode>& a_pChild);
	[[nodiscard]] std::weak_ptr<IEditNode> parent() { return m_parent; }
	[[nodiscard]] int childCount()const { return m_children.size(); }
	[[nodiscard]] int placeInParent()const;
	[[nodiscard]] std::shared_ptr<IEditNode> childAt(const int& a_index)const { return m_children[a_index]; }
	[[nodiscard]] virtual QString title()const = 0;
	[[nodiscard]] virtual bool isEditable()const = 0;
	[[nodiscard]] virtual Type type()const = 0;
	[[nodiscard]] virtual QVariant displayRole()const = 0;
	[[nodiscard]] virtual QVariant foregroundRole()const = 0;
	[[nodiscard]] virtual QVariant backgroundRole()const = 0;
	[[nodiscard]] virtual QVariant fontRole()const = 0;
	[[nodiscard]] virtual QVariant decorationRole()const = 0;
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
	virtual ~CategoryEditNode() = default;
	[[nodiscard]] virtual QString title()const final { return m_sCatName; }
	[[nodiscard]] bool isEditable()const final { return false; }
	[[nodiscard]] Type type()const final { return Type::Category; }
	[[nodiscard]] QVariant displayRole()const final;
	[[nodiscard]] QVariant foregroundRole()const final;
	[[nodiscard]] QVariant backgroundRole()const final;
	[[nodiscard]] QVariant fontRole()const final;
	[[nodiscard]] QVariant decorationRole()const final;
	[[nodiscard]] int span()const final { return 2; }
	void setData(const QVariant& a_data) final {/*nothing todo*/ }
};