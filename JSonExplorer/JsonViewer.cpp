#include "JsonViewer.h"
#include "ui_JsonViewer.h"
#include <qjsondocument.h>
#include "JsonDataModel.h"
#include "JsonModel.h"
#include <qfile.h>

JsonViewer::JsonViewer(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::JsonViewerClass())
{
	ui->setupUi(this);
	QList<int> lWidth;
	lWidth << (width() / 3) << (width() * 2 / 3);
	ui->splitter->setSizes(lWidth);
	ui->tvJson->setModel(new JsonModel);
	ui->tJson->setModel(new JsonDataModel);
	QObject::connect(ui->tvJson, &QTreeView::clicked, this, &JsonViewer::onJsonNodeClicked);
}

JsonViewer::~JsonViewer()
{
	delete ui;
}

void JsonViewer::loadJson(const QString& a_filename)
{
	JsonDataModel* pDataModel = static_cast<JsonDataModel*>(ui->tJson->model());
	JsonModel* pModel = static_cast<JsonModel*>(ui->tvJson->model());
	QFile file(a_filename);
	if (file.open(QIODevice::ReadOnly))
	{
		pModel->setup(QJsonDocument::fromJson(file.readAll()));
		pDataModel->setup(nullptr);
	}
}

void JsonViewer::onJsonNodeClicked(const QModelIndex& a_index)
{
	JsonDataModel* pDataModel = static_cast<JsonDataModel*>(ui->tJson->model());
	auto pJsonNode = static_cast<JSonNode*>(a_index.internalPointer());
	if (pJsonNode)
	{
		pDataModel->setup(pJsonNode);
	}
	else
	{
		pDataModel->setup(nullptr);
	}

}