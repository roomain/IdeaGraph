#pragma once
#include "IEditNode.h"
#include <functional>

template<typename Type>
using GetterFun = std::function<Type()>;

template<typename Type>
using SetterFun = std::function<void(const Type)>;

template<typename Type>
using SetterFunRef = std::function<void(const Type&)>;

template<typename ValueType, typename Getter = GetterFun<ValueType>, typename Setter = SetterFun<ValueType>>
class TEditNode : public IEditNode
{
private:
	Setter m_setter;
	Getter m_getter;
	QString m_sProperty;

public:
	TEditNode() = delete;
	TEditNode(const QString& a_property, Setter a_setter, Getter a_getter) :
		m_sProperty{ a_property }, m_setter{ a_setter }, m_getter{ a_getter } {}
	[[nodiscard]] virtual QString title()const override { return m_sProperty; }
	[[nodiscard]] virtual bool isEditable()const override { return true; }
	[[nodiscard]] Type type()const final { return Type::Property; }
	[[nodiscard]] QVariant displayRole()const final { return m_getter(); }
	[[nodiscard]] virtual QVariant foregroundRole()const override { return QVariant(); }
	[[nodiscard]] virtual QVariant backgroundRole()const override { return QVariant(); }
	[[nodiscard]] virtual QVariant fontRole()const override { return QVariant(); }
	[[nodiscard]] virtual QVariant decorationRole()const override { return QVariant(); }
	[[nodiscard]] int span()const final { return 1; }
	void setData(const QVariant& a_data) final {
		m_setter(a_data.value<ValueType>());
	}
};