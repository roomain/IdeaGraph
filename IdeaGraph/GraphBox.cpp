#include "GraphBox.h"
#include "PreviewBox.h"
#include <qevent.h>

GraphBox::GraphBox(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setMouseTracking(true);

	m_vPreviewInBoxes.push_back(new PreviewBox);
	ui.InputLayout->addWidget(m_vPreviewInBoxes[0]);
	m_vPreviewInBoxes[0]->setVisible(false);

	m_vPreviewOutBoxes.push_back(new PreviewBox);
	ui.OutputLayout->addWidget(m_vPreviewOutBoxes[0]);
	m_vPreviewOutBoxes[0]->setVisible(false);
}

GraphBox::~GraphBox()
{}

void GraphBox::setTitle(const QString& a_title)
{
	ui.lblTitle->setText(a_title);
}


void GraphBox::mouseMoveEvent(QMouseEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}

void GraphBox::mousePressEvent(QMouseEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}

void GraphBox::mouseReleaseEvent(QMouseEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}

void GraphBox::mouseDoubleClickEvent(QMouseEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}

int GraphBox::findInput(const QPoint& a_pos)const
{
	const int iCount = ui.InputLayout->count();
	for (int index = 1; index < iCount; ++index)
	{
		auto pWdg = ui.OutputLayout->itemAt(index)->widget();
		if (pWdg->isVisible() && pWdg->rect().contains(a_pos))
		{
			if (dynamic_cast<PreviewBox*>(pWdg))
				return index;

			if ((a_pos.x() - pWdg->rect().center().x()) < 0)
			{
				return index - 1;
			}
			else
			{
				return index + 1;
			}
		}
	}
	return -1;
}

int GraphBox::findOutput(const QPoint& a_pos)const
{
	const int iCount = ui.OutputLayout->count();
	for (int index = 1; index < iCount; ++index)
	{
		auto pWdg = ui.OutputLayout->itemAt(index)->widget();
		if (pWdg->isVisible() && pWdg->rect().contains(a_pos))
		{
			if (dynamic_cast<PreviewBox*>(pWdg))
				return index;

			if ((a_pos.x() - pWdg->rect().center().x()) < 0)
			{
				return index - 1;
			}
			else
			{
				return index + 1;
			}
		}
	}
	return -1;
}

int GraphBox::dragInternal(const QPoint& a_pos, bool& a_isInput)
{
	int index = -1;
	for (const auto pPrevBox : m_vPreviewInBoxes)
		pPrevBox->setVisible(false);

	for (const auto pPrevBox : m_vPreviewOutBoxes)
		pPrevBox->setVisible(false);

	if (ui.InputLayout->contentsRect().contains(a_pos))
	{
		a_isInput = true;
		if (m_vPreviewInBoxes.size() == 1)
		{
			m_vPreviewInBoxes[0]->setVisible(true);
			index = 0;
		}
		else if (index = findInput(a_pos))
		{
			ui.InputLayout->itemAt(index)->widget()->setVisible(true);
		}
	}
	else if (ui.OutputLayout->contentsRect().contains(a_pos))
	{
		a_isInput = false;
		if (m_vPreviewOutBoxes.size() == 1)
		{
			m_vPreviewOutBoxes[0]->setVisible(true);
			index = 0;
		}
		else if (index = findOutput(a_pos))
		{
			ui.OutputLayout->itemAt(index)->widget()->setVisible(true);
		}
	}
	return index;
}

void GraphBox::dragEnterEvent(QDragEnterEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}

void GraphBox::dragMoveEvent(QDragMoveEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}

void GraphBox::dragLeaveEvent(QDragLeaveEvent* a_pEvent)
{
	for (const auto pPrevInBox : m_vPreviewInBoxes)
		pPrevInBox->setVisible(false);

	for (const auto pPrevOutBox : m_vPreviewOutBoxes)
		pPrevOutBox->setVisible(false);
}

void GraphBox::dropEvent(QDropEvent* a_pEvent)
{
	QPoint ptMouse = a_pEvent->pos();
	//
}