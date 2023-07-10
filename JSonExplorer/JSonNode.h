#pragma once
#include <memory>
#include <vector>
#include <optional>
#include <QVariant>
#include <qjsonvalue.h>

class JSonNode : public std::enable_shared_from_this<JSonNode>
{
public:
	enum class NodeType : int
	{
		JSON_OBJECT,
		JSON_TABLE,
		JSON_VALUE
	};

	JSonNode(const QString& a_title, const NodeType a_type = NodeType::JSON_OBJECT, const std::shared_ptr<JSonNode>& a_parent);
	JSonNode(const QString& a_title, const NodeType a_type = NodeType::JSON_VALUE, const QJsonValue& a_value, const std::shared_ptr<JSonNode>& a_parent);
	JSonNode(const QString& a_title, const NodeType a_type, const std::shared_ptr<JSonNode>& a_parent);
	~JSonNode() = default;
	[[nodiscard]] const int placeInParent()const;
	[[nodiscard]] std::weak_ptr<JSonNode> parent();
	[[nodiscard]] size_t childCount()const;
	[[nodiscard]] std::shared_ptr<JSonNode> childAt(const unsigned int a_index);
	void addChild(const std::shared_ptr<JSonNode>& a_node);
	void removeChild(const std::shared_ptr<JSonNode>& a_node);
	void removeChildAt(const unsigned int a_index);
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
};

