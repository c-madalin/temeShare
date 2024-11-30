#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProiectModern2.h"

class ProiectModern2 : public QMainWindow
{
    Q_OBJECT

public:
    ProiectModern2(QWidget *parent = nullptr);
    ~ProiectModern2();

private:
    Ui::ProiectModern2Class ui;
};
