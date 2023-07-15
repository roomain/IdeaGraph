#pragma once
#include <vector>
#include <optional>
#include <QVariant>
#include <qjsonvalue.h>

class JSonNode
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

	JSonNode(JSonNode* const a_node, const QString& a_title, const NodeType a_type = NodeType::JSON_OBJECT);
	JSonNode(JSonNode* const a_node, const QString& a_title, const QJsonValue& a_value, const NodeType a_type = NodeType::JSON_VALUE);

	~JSonNode() = default;
	[[nodiscard]] const int placeInParent()const;
	[[nodiscard]] JSonNode* const parent()const;
	[[nodiscard]] size_t childCount()const;
	[[nodiscard]] JSonNode* const childAt(const unsigned int a_index);
	void addChild(JSonNode* const a_node);
	void removeChild(JSonNode* const a_node);
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
	JSonNode* m_parent;
	std::vector<JSonNode*> m_vChildren;
	QString m_title;
	NodeType m_type;
	std::optional<QJsonValue> m_value;
	std::vector<JsonAttribute> m_vAttrib;
};

