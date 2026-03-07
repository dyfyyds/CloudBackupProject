#include "HomeWidget.h"
#include "./ui_HomeWidget.h"
#include "QGraphicsDropShadowEffect"

void HomeWidget::guiInit()
{

    //设置无边框
    setWindowFlag(Qt::FramelessWindowHint);

    //讲窗口设置透明背景
    setAttribute(Qt::WA_TranslucentBackground);

    //为主窗口设置内部阴影
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect(this);

    //模糊半径 偏移 颜色
    shadow->setBlurRadius(10);
    shadow->setOffset(0);
    shadow->setColor(QColor(0x00,0x00,0x00,255));

    setGraphicsEffect(shadow);

    // 为docker栏设置阴影
    QGraphicsDropShadowEffect* docker = new QGraphicsDropShadowEffect();

    //模糊半径 偏移 颜色
    docker->setBlurRadius(10);
    docker->setOffset(0);
    docker->setColor(QColor(0x22,0xAA,0xAA,255));
    ui->DockerArea->setGraphicsEffect(docker);


}

HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

    guiInit();
}

HomeWidget::~HomeWidget()
{
    delete ui;
}

void HomeWidget::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        //更新拖动状态
        isDrag = true;

        //获取鼠标与窗口位置差值
        dval = ev->globalPosition() - pos();
    }
}

void HomeWidget::mouseMoveEvent(QMouseEvent *ev)
{
    if(isDrag)
    {
        //移动窗口
        move((ev->globalPosition() - dval).toPoint());
    }
}

void HomeWidget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        isDrag = false;
    }
}

void HomeWidget::on_MiniButton_clicked()
{
    showMinimized();
}


void HomeWidget::on_CloseButton_clicked()
{
    close();
}

