#ifndef DIALOGLOADING_H
#define DIALOGLOADING_H

#include <QDialog>
#include "dialogloadingworker.h"

namespace Ui {
class DialogLoading;
}

class DialogLoading : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLoading(QWidget *parent = 0);
    ~DialogLoading();
    void start();

    QStringList m_Lines;

signals:
    void succeeded();
    void failed();

public slots:
    void workerDone();
    void onLineRead(int filePos, QString line);
    void onGotFileSize(int size);
    void onLoadFailed();

private:
    Ui::DialogLoading *ui;
    DialogLoadingWorker workerThread;
};

#endif // DIALOGLOADING_H
