#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include "editwindow.h"

extern QString SearchName, SearchID, SearchFaculty, SearchYear, SearchBook, SearchBook_Sn, SearchDate, SearchStatus;

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();

private slots:
    void on_search2_clicked();

    void on_tableView_search_activated(const QModelIndex &index);

    void on_delete_2_clicked();

    void on_clearance_clicked();

    void on_Edit_clicked();

private:
    Ui::search *ui;
    QSqlDatabase mydb;
};

#endif // SEARCH_H
