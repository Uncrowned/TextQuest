﻿#ifndef SETTINGS_H
#define SETTINGS_H

#include "mainwindow.h"

class Settings : public QObject
{
    Q_OBJECT

public:
    static Settings *instance();
    bool read();
    void flush();

    QColor getColor(int number);
    QVariant getOption(QString option);
    QFont getFont();
    void setOption(QString key, QVariant value);
    void setOption(int number, QColor color);
    void setOption(QFont font);

    const static QString FileName;
    const static QString TextSpeed;
    const static QString Interface;
    const static QString Volume;
    const static QString AutoRead;
    const static QString FullScreen;
    const static QString SkipAfterChoice;
    const static QString SkipUnreadText;
    const static QString Sound;
    const static int ColorCount;
    const static int Width;
    const static int Height;

private:
    QFile *file;
    QMap<QString, QVariant> settings;
    QVector<QColor> colors;
    QFont font;

    static Settings *self;
    explicit Settings();
    Settings(Settings& root);
    Settings& operator = (Settings&);
};
#endif // SETTINGS_H
