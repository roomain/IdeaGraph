#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ColorEditorClass; };
QT_END_NAMESPACE

class ColorEditor : public QWidget
{
	Q_OBJECT

public:
	ColorEditor(QWidget *parent = nullptr);
	virtual ~ColorEditor();

private:
	Ui::ColorEditorClass *ui;
};
