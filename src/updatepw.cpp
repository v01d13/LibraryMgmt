#include "updatepw.h"
#include "ui_updatepw.h"

updatepw::updatepw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updatepw)
{
    ui->setupUi(this);
}

updatepw::~updatepw()
{
    delete ui;
}

void updatepw::on_updatePw_clicked()
{
    QString updatedPw = ui->lineEditUpdatePw->text();
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    qry.prepare("UPDATE login SET Password = '"+updatedPw+"' WHERE Username = '"+usrname+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Updated"), tr("Updated"));
        this->close();
    }
    else {
        QMessageBox::critical(this,tr("Error."), qry.lastError().text());
        this->ui->lineEditUpdatePw->clear();
    }
}

void updatepw::on_updateCancel_clicked()
{
    this->ui->lineEditUpdatePw->clear();
    this->close();
}
