#ifndef EDITWINDOW_H
#define EDITWINDOW_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class editwindow;
}

class editwindow : public QDialog
{
    Q_OBJECT

public:
    explicit editwindow(QWidget *parent = nullptr);
    ~editwindow();

private slots:
    void on_editOK_clicked();

    void on_editCancel_clicked();

private:
    Ui::editwindow *ui;
    QSqlDatabase mydb;
};

#endif // EDITWINDOW_H
