#ifndef DISKUNITY_H
#define DISKUNITY_H

#include <QObject>

class DiskUnity : public QObject
{
    Q_OBJECT
public:
    explicit DiskUnity(QObject *parent = 0);

    QString FormatDisk(const QString &diskDev);

    /*
        FixUsbDisk will recreate primary table of the usb disk
        and create only one primary partition as fat32 format,
        if the usb stick has muti partition, all partition will be
        delete!!!
    */
    bool FixMBR(const QString& targetDev);

    /*
        GetPartitionDiskDev will return the
    */

    bool EjectDisk(const QString &targetDev);

    static int GetPartitionDiskDev(QString targetDev);
signals:

public slots:

};

class FileListMonitor: public QObject {
    Q_OBJECT
public:
    FileListMonitor(QObject *parent = 0);
    qint64 FinishSize();

public slots:
    void ToNextFile(const QString &file);
    void SetTotalSize(qint64 size);

signals:
    void totalSize(qint64 size);
    void toNextFile(const QString &file);

private:
    qint64 finishSize_;
    qint64 totalSize_;
    QString currentFile_;
    //QStringList desList_;
};


#endif // DISKUNITY_H
