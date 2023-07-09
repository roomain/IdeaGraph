#include "ColorEditor.h"
#include "ui_ColorEditor.h"

ColorEditor::ColorEditor(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::ColorEditorClass())
{
	ui->setupUi(this);
}

ColorEditor::~ColorEditor()
{
	delete ui;
}
