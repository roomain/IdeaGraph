#include "DataModelDisplayer.h"


QVariant DataModelDisplayer::displayRole(const QString& a_value)
{
	return a_value;
}

QVariant DataModelDisplayer::foregroundRole(const QString& a_value)
{
	return QVariant();
}
;
QVariant DataModelDisplayer::backgroundRole(const QString& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::fontRole(const QString& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::displayRole(const QColor& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::foregroundRole(const QColor& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::backgroundRole(const QColor& a_value)
{
	return a_value;
}

QVariant DataModelDisplayer::fontRole(const QColor& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::displayRole(const QFont& a_value)
{
	return a_value.family();
}

QVariant DataModelDisplayer::foregroundRole(const QFont& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::backgroundRole(const QFont& a_value)
{
	return QVariant();
}

QVariant DataModelDisplayer::fontRole(const QFont& a_value)
{
	return a_value;
}
