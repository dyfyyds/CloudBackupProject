#include "TaskItem.h"
#include "ui_TaskItem.h"

TaskItem::TaskItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TaskItem)
{
    ui->setupUi(this);
}

TaskItem::~TaskItem()
{
    delete ui;
}

void TaskItem::setFileName(QString fileName)
{
    ui->FileName->setText(fileName);
}

void TaskItem::setNodeName(QString nodeName)
{
    ui->NodeName->setText(nodeName);
}

void TaskItem::setTaskType(QString type)
{
    ui->TaskType->setText(type);
}

void TaskItem::setValue(int value)
{
    ui->value->clear();
    ui->value->setText(QString::number(value)+"%");
}

QString TaskItem::getFileName()
{
    return ui->FileName->text();
}

QString TaskItem::getNodeName()
{
    return ui->NodeName->text();
}

QString TaskItem::getTaskType()
{
    return ui->TaskType->text();
}

int TaskItem::getValue()
{
    return ui->value->text().toInt();
}
