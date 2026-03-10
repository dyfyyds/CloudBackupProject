#ifndef TASKITEM_H
#define TASKITEM_H

#include <QWidget>

namespace Ui {
class TaskItem;
}

class TaskItem : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItem(QWidget *parent = nullptr);
    ~TaskItem();

    //接口
    void setFileName(QString fileName);
    void setNodeName(QString nodeName);
    void setTaskType(QString type);
    void setValue(int value);

    QString getFileName();
    QString getNodeName();
    QString getTaskType();
    int     getValue();

private:
    Ui::TaskItem *ui;
};

#endif // TASKITEM_H
