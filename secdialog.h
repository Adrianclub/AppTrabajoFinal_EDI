#ifndef SECDIALOG_H
#define SECDIALOG_H
#include <QFile>
#include <QDialog>
#include <QScrollBar>
#include <QDateTime>
#include <QtSql/QSqlQuery>//libreria que permite consultas y req. a BD
#include <QtSql/QSqlError>//libreria que permite conocer errores en consultas BD
namespace Ui {
class secDialog;
}

class secDialog : public QDialog
{
    Q_OBJECT

public:
    explicit secDialog(QWidget *parent = nullptr);
    ~secDialog();
    void mostrarTablaEntrega();

private slots:

    void on_pushButton_borrar_clicked();
    void on_pushButton_ver_clicked();
    void on_pushButton_update_clicked();
    void on_pushButton_volver_clicked();

private:
    Ui::secDialog *ui;
};

#endif // SECDIALOG_H
