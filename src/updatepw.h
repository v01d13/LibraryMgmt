#ifndef UPDATEPW_H
#define UPDATEPW_H

#include <QDialog>
#include <QtSql>
#include "adminpanel.h"

namespace Ui {
class updatepw;
}

class updatepw : public QDialog
{
    Q_OBJECT

public:
    explicit updatepw(QWidget *parent = nullptr);
    ~updatepw();

private slots:
    void on_updatePw_clicked();

    void on_updateCancel_clicked();

private:
    Ui::updatepw *ui;
    QSqlDatabase mydb;
};

#endif // UPDATEPW_H
