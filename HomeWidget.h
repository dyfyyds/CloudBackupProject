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
    void eventInit();


public:
    HomeWidget(QWidget *parent = nullptr);
    ~HomeWidget();

    //鼠标拖动事件
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;

    void TestValue();

private slots:
    void on_MiniButton_clicked();

    void on_CloseButton_clicked();


    void on_CheckFile_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_EnterUploadButton_clicked();

    void on_CancleUploadButton_clicked();

private:
    void on_change_stackedWidget(int index);

private:
    Ui::HomeWidget *ui;

    //是否拖动
    bool isDrag;
    //位置的差值
    QPointF dval;
};
#endif // HOMEWIDGET_H
