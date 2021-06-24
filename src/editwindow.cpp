#include "editwindow.h"
#include "ui_editwindow.h"
#include "search.h"

editwindow::editwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editwindow)
{
    ui->setupUi(this);
    ui->editID->setText(SearchID);
    ui->editFaculty->setText(SearchFaculty);
    ui->editYear->setText(SearchYear);
    ui->editBook->setText(SearchBook);
    ui->editBookSn->setText(SearchBook_Sn);
    QDate date = QDate::currentDate();
    ui->editDate->setDate(date);
}

editwindow::~editwindow()
{
    delete ui;
}

void editwindow::on_editOK_clicked()
{
    QString editId = ui->editID->text();
    QString editFaculty = ui->editFaculty->text();
    QString editYear = ui->editYear->text();
    QString editBook = ui->editBook->text();
    QString editBookSN = ui->editBookSn->text();
    QString editDate = ui->editDate->text();

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    qry.prepare("UPDATE BooksIssued SET ID ='"+editId+"', Faculty = '"+editFaculty+", Year = '"+editYear+"', Book = '"+editBook+"', BookSN = '"+editBookSN+"', Date = '"+editDate+" WHERE Name = '"+SearchName+"' ");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Edited"), tr("Edite"));
    }
    else {
        QMessageBox::critical(this,tr("Error."), qry.lastError().text());
    }
    mydb.close();
    this->close();
}

void editwindow::on_editCancel_clicked()
{
    this->ui->editID->clear();
    this->ui->editFaculty->clear();
    this->ui->editYear->clear();
    this->ui->editBook->clear();
    this->ui->editBookSn->clear();
    this->ui->editDate->clear();

    this->close();
}
