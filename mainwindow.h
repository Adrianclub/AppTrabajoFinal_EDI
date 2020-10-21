#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QDialog>
#include <QMainWindow>
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "usuario.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearTablaUsuarios();
    void crearTablaEntregas();
    void insertarEntrega();


public slots:
    void fTimer();


private slots:
    void on_pushButton_ingreso_clicked();

    void on_pushButton_clean_clicked();

    void on_pushButton_timer_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer2;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
