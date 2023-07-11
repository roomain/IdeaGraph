#pragma once
#include <memory>
#include <vector>
#include <optional>
#include <QVariant>
#include <qjsonvalue.h>

class JSonNode : public std::enable_shared_from_this<JSonNode>
{
public:
	struct JsonAttribute
	{
		QString m_name;
		QVariant m_value;
	};

	enum class NodeType : int
	{
		JSON_OBJECT,
		JSON_ARRAY,
		JSON_VALUE
	};

	JSonNode(const QString& a_title, const NodeType a_type = NodeType::JSON_OBJECT);
	JSonNode(const QString& a_title, const QJsonValue& a_value, const NodeType a_type = NodeType::JSON_VALUE);
	~JSonNode() = default;
	[[nodiscard]] const int placeInParent()const;
	[[nodiscard]] std::weak_ptr<JSonNode> parent();
	[[nodiscard]] size_t childCount()const;
	[[nodiscard]] std::shared_ptr<JSonNode> childAt(const unsigned int a_index);
	void addChild(std::shared_ptr<JSonNode>& a_node);
	void removeChild(std::shared_ptr<JSonNode>& a_node);
	void removeChildAt(const unsigned int a_index);
	void addAttrib(const QString& a_key, const QVariant& a_value);
	const size_t& attribCount()const noexcept;
	const JsonAttribute& attributeAt(const int a_index);
	
	[[nodiscard]] virtual QVariant displayRole()const;
	[[nodiscard]] virtual QVariant foregroundRole()const;
	[[nodiscard]] virtual QVariant backgroundRole()const;
	[[nodiscard]] virtual QVariant fontRole()const;
	[[nodiscard]] virtual QVariant decorationRole()const;

private:
	std::weak_ptr<JSonNode> m_parent;
	std::vector<std::shared_ptr<JSonNode>> m_vChildren;
	QString m_title;
	NodeType m_type;
	std::optional<QJsonValue> m_value;
	std::vector<JsonAttribute> m_vAttrib;
};

