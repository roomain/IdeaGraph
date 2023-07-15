#pragma once
#include "editmodels_global.h"
#include <QVariant>
#include <QString>
#include <QColor>
#include <QFont>

class EDITMODELS_EXPORT DataModelDisplayer
{
public:
	static QVariant displayRole(const QString& a_value);
	static QVariant foregroundRole(const QString& a_value);
	static QVariant backgroundRole(const QString& a_value);
	static QVariant fontRole(const QString& a_value);

	static QVariant displayRole(const QColor& a_value);
	static QVariant foregroundRole(const QColor& a_value);
	static QVariant backgroundRole(const QColor& a_value);
	static QVariant fontRole(const QColor& a_value);

	static QVariant displayRole(const QFont& a_value);
	static QVariant foregroundRole(const QFont& a_value);
	static QVariant backgroundRole(const QFont& a_value);
	static QVariant fontRole(const QFont& a_value);

	static QVariant displayRole(...) { return QVariant(); }
	static QVariant foregroundRole(...) { return QVariant(); }
	static QVariant backgroundRole(...) { return QVariant(); }
	static QVariant fontRole(...) { return QVariant(); }
};