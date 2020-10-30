#ifndef TERCERDIALOG_H
#define TERCERDIALOG_H
#include <QtSql/QSqlQuery>//libreria que permite consultas y req. a BD
#include <QtSql/QSqlError>//libreria que permite conocer errores en consultas BD
#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class tercerDialog;
}

class tercerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tercerDialog(QWidget *parent = nullptr);
    ~tercerDialog();
    void insertarUsuario();
    void mostrarTablaUsuario();

private slots:
    void on_pushButton_agregar_clicked();
    void on_pushButton_delete_clicked();
    void on_pushButton_clicked();

private:
    Ui::tercerDialog *ui;
};

#endif // TERCERDIALOG_H
