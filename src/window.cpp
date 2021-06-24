#include "window.h"
#include "ui_window.h"
#include "mainwindow.h"
#include "addentry.h"
#include "search.h"
#include "adminpanel.h"
window::window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);
}

window::~window()
{
    delete ui;
}


void window::on_Add_clicked()
{
    addentry a;
    a.setModal(true);
    a.exec();
}

void window::on_logout_clicked()
{

}

void window::on_search_clicked()
{
    search s;
    s.setModal(true);
    s.exec();

}

void window::on_refresh_clicked()
{
    QString Checker = "True";
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("SELECT Name, ID, Faculty, Year, Book, Book SN, Date from BooksIssued where Status <> '"+Checker+"' ");
    qry->exec();
    model->setQuery(*qry);
    ui->mainWindowView->setModel(model);
    qDebug() << (model->rowCount());
    mydb.close();
}

void window::on_inventory_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("SELECT * from Inventory");
    qry->exec();
    model->setQuery(*qry);
    ui->mainWindowView->setModel(model);
    qDebug() << (model->rowCount());
    mydb.close();
}

void window::on_admin_clicked()
{
    if(privilege == 1)
    {
        adminpanel a;
        a.setModal(true);
        a.exec();
    }
    else {
        QMessageBox::critical(this,tr("Access denied"), tr("No special privileges"));
    }
}
