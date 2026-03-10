#ifndef FILEITEM_H
#define FILEITEM_H

#include <QWidget>

namespace Ui {
class FileItem;
}

class FileItem : public QWidget
{
    Q_OBJECT

public:
    explicit FileItem(QWidget *parent = nullptr);
    ~FileItem();

    //接口
    void setFileName(QString name);
    void setFileType(QString type);
    void setFileSize(int size);
    void setFilePath(QString path);

    QString getFileName();
    QString getFileType();
    int getFileSize();
    QString getFilePath();

private:
    Ui::FileItem *ui;
};

#endif // FILEITEM_H
