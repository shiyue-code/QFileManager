#include "sy_lineedit.h"

#include <QPainter>
#include <QIcon>
#include <QPaintEvent>

SY_LineEdit::SY_LineEdit(QWidget *parent) : QLineEdit(parent)
{

}

void SY_LineEdit::paintEvent(QPaintEvent *evt)
{
    QLineEdit::paintEvent(evt);
    QIcon icon = windowIcon();

    QPainter painter(this);
    icon.paint(&painter, 0, 0, 35, 35);

    evt->accept();
}
