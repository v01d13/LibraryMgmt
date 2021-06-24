#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window.h"

int privilege;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOkLogin_clicked()
{
    QString username = ui->loginusername->text();
    QString password = ui->loginpassword->text();

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    class window w;

    if(qry.exec("select * from login where Username = '"+username +"' and Password = '"+password +"'"))
    {
        w.setModal(true);
        w.exec();
        privilege = 2;
    }
    else if(username == "Admin" && password == "admin1313")
    {
        w.setModal(true);
        w.exec();
        privilege = 1;
    }

    else if(username == "Guest" && password == "")
    {
       privilege = 3;
    }

    else
    {
        privilege = 0;
        QMessageBox::information(this, "Error", "Login Error, Check your inputs.");
    }

    mydb.close();

}

