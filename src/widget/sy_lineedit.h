#ifndef SY_LINEEDIT_H
#define SY_LINEEDIT_H

#include <QLineEdit>

class SY_LineEdit : public QLineEdit
{
public:
    SY_LineEdit(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent * evt) override;
};

#endif // SY_LINEEDIT_H
