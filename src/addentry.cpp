#include "addentry.h"
#include "ui_addentry.h"
#include <QMessageBox>

addentry::addentry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addentry)
{
    ui->setupUi(this);
    QDate date = QDate::currentDate();
    ui->date->setDate(date);
}

addentry::~addentry()
{
    delete ui;
}

void addentry::on_ok_clicked()
{
    QString statUs = "False";
    QString name = ui->lineEdit_name->text();
    QString id = ui->lineEdit_id->text();
    QString faculty = ui->lineEdit_faculty->text();
    QString year = ui->lineEdit_year->text();
    QString book = ui->lineEdit_book->text();
    QString booksn = ui->lineEdit_sn->text();
    QString date = ui->date->text();

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    qry.prepare("SELECT COUNT(*) FROM BooksIssued WHERE Name = '"+name+"' AND ID = '"+id+"' AND Status <> 'True' ");
    qry.exec();
    int row = 0;
    if(qry.next())
        {
        row = qry.value(0).toInt();
        }
    mydb.close();
    mydb.open();
    if(row < 2)
    {

            if(qry.exec("INSERT INTO BooksIssued(Name, ID, Faculty, Year, Book, BookSN, Date, Status) VALUES ('"+name+"', '"+id+"', '"+faculty+"','"+year+"',  '"+book+"', '"+booksn+"', '"+date+"', '"+statUs+"')"))
            {
                QMessageBox::critical(this,tr("Save"), tr("Saved"));
                qry.prepare("UPDATE Inventory SET Quantity = Quantity - 1 WHERE Book = '"+book+"'");
                qry.exec();
            }
            else {
                QMessageBox::critical(this,tr("Error."), qry.lastError().text());
            }
    }

    else
    {
        QMessageBox::critical(this,tr("Eligbility"), tr("Already Issued 2 Books."));
    }
    mydb.close();
    this->close();

}

void addentry::on_cancel_clicked()
{
    this->ui->lineEdit_name->clear();
    this->ui->lineEdit_id->clear();
    this->ui->lineEdit_faculty->clear();
    this->ui->lineEdit_year->clear();
    this->ui->lineEdit_book->clear();
    this->ui->lineEdit_sn->clear();
    this->ui->date->clear();

    this->close();

}
