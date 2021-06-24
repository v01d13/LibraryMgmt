#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>

extern QString usrname;

namespace Ui {
class adminpanel;
}

class adminpanel : public QDialog
{
    Q_OBJECT

public:
    explicit adminpanel(QWidget *parent = nullptr);
    ~adminpanel();

private slots:
    void on_adminload_clicked();

    void on_comboBoxadmin_currentIndexChanged(const QString &arg1);

    void on_editdel_clicked();

private:
    Ui::adminpanel *ui;
    QSqlDatabase mydb;
};

#endif // ADMINPANEL_H
