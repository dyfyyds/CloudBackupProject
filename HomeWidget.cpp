#include "HomeWidget.h"
#include "./ui_HomeWidget.h"
#include "QGraphicsDropShadowEffect"
#include "FileItem.h"
#include "TaskItem.h"

#include <QFileDialog>

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


    // //文件列表为两列
    // ui->FilesTree->setColumnCount(2);
    // //修改列名
    // ui->FilesTree->setHeaderLabels(QStringList() << "文件" << "路径");
    ui->FilesTree->setHeaderHidden(true);
}

void HomeWidget::eventInit()
{
    connect(ui->Upload,&QPushButton::clicked,this,[=](){on_change_stackedWidget(0);});
    connect(ui->Download,&QPushButton::clicked,this,[=](){on_change_stackedWidget(1);});
    connect(ui->TaskList,&QPushButton::clicked,this,[=](){on_change_stackedWidget(2);});
    connect(ui->NodeList,&QPushButton::clicked,this,[=](){on_change_stackedWidget(3);});
}

HomeWidget::HomeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomeWidget)
{
    ui->setupUi(this);

    guiInit();
    eventInit();

    on_change_stackedWidget(0);


    TestValue();

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

void HomeWidget::TestValue()
{
    QListWidgetItem* item = new QListWidgetItem(ui->DownloadingListWidget);
    TaskItem *task = new TaskItem(ui->DownloadingListWidget);

    task->setFileName("1.txt");
    task->setNodeName("本地节点1");
    task->setTaskType("上传");
    task->setValue(50);

    ui->DownloadingListWidget->addItem(item);
    ui->DownloadingListWidget->setItemWidget(item,task);
}

void HomeWidget::on_MiniButton_clicked()
{
    showMinimized();
}


void HomeWidget::on_CloseButton_clicked()
{
    close();
}


void HomeWidget::on_change_stackedWidget(int index)
{
    ui->stackedWidget->setCurrentIndex(index);

    static int oldIndex = 0;

    switch(index)
    {
    case 0:
        ui->Upload->setStyleSheet(ui->Upload->styleSheet()+"#Upload:active{background-color:rgb(16, 84, 166);}");
        break;
    case 1:
        ui->Download->setStyleSheet(ui->Download->styleSheet()+"#Download:active{background-color:rgb(16, 84, 166);}");
        break;
    case 2:
        ui->TaskList->setStyleSheet(ui->TaskList->styleSheet()+"#TaskList:active{background-color:rgb(16, 84, 166);}");
        break;
    case 3:
        ui->NodeList->setStyleSheet(ui->NodeList->styleSheet()+"#NodeList:active{background-color:rgb(16, 84, 166);}");
        break;
    }

    if (oldIndex == index)  return;
    switch(oldIndex)
    {
    case 0:
        ui->Upload->setStyleSheet(ui->Upload->styleSheet().remove("#Upload:active{background-color:rgb(16, 84, 166);}"));
        break;
    case 1:
        ui->Download->setStyleSheet(ui->Download->styleSheet().remove("#Download:active{background-color:rgb(16, 84, 166);}"));
        break;
    case 2:
        ui->TaskList->setStyleSheet(ui->TaskList->styleSheet().remove("#TaskList:active{background-color:rgb(16, 84, 166);}"));
        break;
    case 3:
        ui->NodeList->setStyleSheet(ui->NodeList->styleSheet().remove("#NodeList:active{background-color:rgb(16, 84, 166);}"));
        break;
    }

    oldIndex = index;
}


void HomeWidget::on_CheckFile_clicked()
{

    ui->FilesTree->clear();
    QStringList fileList = QFileDialog::getOpenFileNames();



    for(auto& file : fileList)
    {
        QFileInfo info(file);

        QTreeWidgetItem* fileItem = new QTreeWidgetItem(ui->FilesTree);
        FileItem* item = new FileItem();
        item->setFileName(info.fileName());
        item->setFileType(info.suffix());
        item->setFileSize(info.size());
        item->setFilePath(info.filePath());

        fileItem->setSizeHint(0,item->sizeHint());

        ui->FilesTree->setItemWidget(fileItem,0,item);
    }

    ui->CheckFileStackedWidget->setCurrentIndex(1);
}


void HomeWidget::on_comboBox_currentIndexChanged(int index)
{
    ui->RemoteStackedWidget->setCurrentIndex(1);
    ui->RemoteName->setText(ui->comboBox->currentText());
}


void HomeWidget::on_EnterUploadButton_clicked()
{
    //上传逻辑
    ui->FilesTree->clear();
    ui->CheckFileStackedWidget->setCurrentIndex(0);
}


void HomeWidget::on_CancleUploadButton_clicked()
{
    ui->FilesTree->clear();
    ui->CheckFileStackedWidget->setCurrentIndex(0);
}

