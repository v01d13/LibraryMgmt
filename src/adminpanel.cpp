#include "adminpanel.h"
#include "ui_adminpanel.h"

QString usrname;

adminpanel::adminpanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminpanel)
{
    ui->setupUi(this);
}

adminpanel::~adminpanel()
{
    delete ui;
}

void adminpanel::on_adminload_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery();
    qry->prepare("SELECT Username FROM login");
    qry->exec();
    model->setQuery(*qry);
    ui->comboBoxadmin->setModel(model);
    qDebug() << (model->rowCount());
    mydb.close();
}

void adminpanel::on_comboBoxadmin_currentIndexChanged(const QString &arg1)
{
    QString usrname = ui->comboBoxadmin->currentText();
}

void adminpanel::on_editdel_clicked()
{
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/qt/LibraryManagement/database.db");
    mydb.open();
    QSqlQuery qry;
    qry.prepare("DELETE FROM login WHERE Username = '"+usrname+"'");

    if(qry.exec())
    {
        QMessageBox::critical(this,tr("Delete"), tr("Deleted"));
    }
    else {
        QMessageBox::critical(this,tr("Error."), qry.lastError().text());
    }
}
