#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class window;
}

class window : public QDialog
{
    Q_OBJECT

public:
    explicit window(QWidget *parent = nullptr);
    ~window();

private slots:
    void on_Add_clicked();

    void on_logout_clicked();

    void on_search_clicked();

    void on_refresh_clicked();

    void on_inventory_clicked();

    void on_admin_clicked();

private:
    Ui::window *ui;
    QSqlDatabase mydb;
};

#endif // WINDOW_H
