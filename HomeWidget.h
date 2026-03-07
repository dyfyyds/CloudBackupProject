#ifndef HOMEWIDGET_H
#define HOMEWIDGET_H

#include <QMouseEvent>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeWidget;
}
QT_END_NAMESPACE

class HomeWidget : public QWidget
{
    Q_OBJECT

protected:
    void guiInit();


public:
    HomeWidget(QWidget *parent = nullptr);
    ~HomeWidget();

    //鼠标拖动事件
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

private slots:
    void on_MiniButton_clicked();

    void on_CloseButton_clicked();

private:
    Ui::HomeWidget *ui;

    //是否拖动
    bool isDrag;
    //位置的差值
    QPointF dval;
};
#endif // HOMEWIDGET_H
