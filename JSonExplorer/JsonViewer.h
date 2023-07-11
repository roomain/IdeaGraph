#pragma once
#include "jsonexplorer_global.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class JsonViewerClass; };
QT_END_NAMESPACE

class JSONEXPLORER_EXPORT JsonViewer : public QWidget
{
	Q_OBJECT

public:
	JsonViewer(QWidget *parent = nullptr);
	~JsonViewer();
	void loadJson(const QString& a_filename);

private:
	Ui::JsonViewerClass *ui;
	void onJsonNodeClicked(const QModelIndex& a_index);
};
