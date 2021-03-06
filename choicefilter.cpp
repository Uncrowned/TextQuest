﻿#include "choicefilter.h"

ChoiceFilter::ChoiceFilter(QObject *parent) :
    QObject(parent)
{
}

/*virtual*/
bool ChoiceFilter::eventFilter(QObject *obj, QEvent *event)
{
    QPalette palette;
    QLabel *label;

    if (event->type() == QEvent::Enter) {
        label = qobject_cast<QLabel*>(obj);
        palette = label->palette();
        this->usualColor = palette.color(QPalette::Text);
        palette.setColor(label->foregroundRole(), QColor(Qt::cyan));
        label->setPalette(palette);

        return true;
    }

    if (event->type() == QEvent::Leave) {
        label = qobject_cast<QLabel*>(obj);
        palette = label->palette();
        palette.setColor(label->foregroundRole(), this->usualColor);
        label->setPalette(palette);

        return true;
    }
    return false;
}
