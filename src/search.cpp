#include "search.h"
#include "ui_search.h"

QString SearchName, SearchID, SearchFaculty, SearchYear, SearchBook, SearchBook_Sn, SearchDate, SearchStatus;

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

void search::on_search2_clicked()
{
    QString search = ui->lineEdit_search->text();
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("SELECT * from BooksIssued where Name = '"+search+"' or ID = '"+search+"' or Book = '"+search+"' or Book SN = '"+search+"' or Date = '"+search+"' or Faculty = '"+search+"' or Year = '"+search+"' ");
    qry->exec();
    model->setQuery(*qry);
    ui->tableView_search->setModel(model);
    qDebug() << (model->rowCount());
    mydb.close();
}

void search::on_tableView_search_activated(const QModelIndex &index)
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    QString value = ui->tableView_search->model()->data(index).toString();
    qry.prepare("SELECT Name, Book from BooksIssued where Name= '"+value+"' or Book = '"+value+"'");
    if(qry.exec())
        {
            QString SearchName = qry.value(0).toString();
            QString SearchID = qry.value(1).toString();
            QString SearchFaculty = qry.value(2).toString();
            QString SearchYear = qry.value(3).toString();
            QString SearchBook = qry.value(4).toString();
            QString SearchBook_Sn = qry.value(5).toString();
            QString SearchDate = qry.value(6).toString();
            QString Status = qry.value(7).toString();

        }
    mydb.close();


}

void search::on_delete_2_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    qry.prepare("DELETE FROM BooksIssued WHERE Name = '"+SearchName+"' AND ID = '"+SearchID+"' AND Faculty = '"+SearchFaculty+"' AND Year = '"+SearchYear+"' AND Book = '"+SearchBook+"' AND BookSN = '"+SearchBook_Sn+"' AND Date = '"+SearchDate+"' AND Status = '"+SearchStatus+"' ");
    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Deleted"), tr("Deleted"));
    }
    else {
        QMessageBox::critical(this,tr("Error."), qry.lastError().text());
    }
    mydb.close();
}

void search::on_clearance_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    qry.prepare("UPDATE BooksIssued SET Status = 'False' WHERE Name = '"+SearchName+"' AND ID = '"+SearchID+"' AND Faculty = '"+SearchFaculty+"' AND Year = '"+SearchYear+"' AND Book = '"+SearchBook+"' AND BookSN = '"+SearchBook_Sn+"' AND Date = '"+SearchDate+"' AND Status = '"+SearchStatus+"' ");
    if(qry.exec())
    {
       qry.prepare("UPDATE Inventory SET Quantity = Quantity + 1 WHERE Book = '"+SearchBook+"'");
       QMessageBox::critical(this,tr("Cleared"), tr("Cleared"));
    }
    else {
        QMessageBox::critical(this,tr("Error."), qry.lastError().text());
    }
    mydb.close();
}

void search::on_Edit_clicked()
{
   editwindow edit;
   edit.setModal(true);
   edit.exec();
}
