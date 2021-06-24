#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>
#include "mainwindow.h"
#include <QtSql>

namespace Ui {
class addentry;
}

class addentry : public QDialog
{
    Q_OBJECT

public:
    explicit addentry(QWidget *parent = nullptr);
    ~addentry();

private slots:
    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::addentry *ui;
    QSqlDatabase mydb;
};

#endif // ADDENTRY_H
