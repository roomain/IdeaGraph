#pragma once
#include "IEditNode.h"
#include <functional>

template<typename Type>
using GetterFun = std::function<Type()>;

template<typename Type>
using SetterFun = std::function<void(const Type)>;

template<typename Type>
class TEditNode : public IEditNode
{
private:
	SetterFun<Type> m_setter;
	GetterFun<Type> m_getter;
	QString m_sProperty;

public:
	TEditNode() = delete;
	TEditNode(const QString& a_property, SetterFun<Type> a_setter, GetterFun<Type> a_getter) :
		m_sProperty{ a_property }, m_setter{ a_setter }, m_getter{ a_getter } {}
	TEditNode(const QString& a_property, SetterFun<Type> a_setter, GetterFun<Type> a_getter, std::shared_ptr<IEditNode>& a_parent) :
		IEditNode(a_parent), m_sProperty{ a_property }, m_setter{ a_setter }, m_getter{ a_getter } {}
	[[nodiscard]] virtual QString title()const final { return m_sProperty; }
	[[nodiscard]] bool isEditable()const final { return true; }
	[[nodiscard]] Type type()const final { return Type::Property; }
	[[nodiscard]] QVariant displayRole()const final { return m_getter(); }
	[[nodiscard]] QVariant foregroundRole()const final { return QVariant(); }
	[[nodiscard]] QVariant backgroundRole()const final { return QVariant(); }
	[[nodiscard]] QVariant fontRole()const final { return QVariant(); }
	[[nodiscard]] QVariant decorationRole()const final { return QVariant(); }
	[[nodiscard]] int span()const final { return 1; }
	void setData(const QVariant& a_data) final { m_setter(a_data.value<Type>()); }
};