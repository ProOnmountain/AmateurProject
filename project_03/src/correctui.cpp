#include "correctui.h"
#include "ui_correctui.h"

CorrectUI::CorrectUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CorrectUI)
{
    ui->setupUi(this);
}

CorrectUI::~CorrectUI()
{
    delete ui;
}
