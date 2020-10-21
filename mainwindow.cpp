#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "secdialog.h"

#include <QDateTime>
#include <QDebug>
bool control= false;
int cont =0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//funcion constructora setea todo lo que aparece en cuerpo



{
    ui->setupUi(this);
    ui->lcdNumber->setFrameStyle(QFrame::NoFrame);
    timer2 = new QTimer (this);
    connect (timer2, SIGNAL ( timeout ()),this,SLOT (fTimer()));

    qDebug()<<"Aplicacion iniciada...";
    QString nombre;
    nombre.append("baseDatos1.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");//le otorga a db los drives
    db.setDatabaseName(nombre);
    //crea o abre base dato ( retorna bool)
    if(db.open()){
        qDebug()<<"Base de datos conectada..";
    }else{
        qDebug()<<" ERROR Base de datos NO conectada..";
    }
    crearTablaUsuarios();
    crearTablaEntregas();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearTablaUsuarios()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS usuarios("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "usuario VARCHAR(100),"
                    "paswword  VARCHAR(100) "
                     ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if (crear.exec()){
        qDebug()<<"La tabla usuario existe o se creo correctamente";
    }else{
        qDebug()<<"ERROR "<<crear.lastError();
    }
}

void MainWindow::crearTablaEntregas()
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS entregas("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "

                    "usuario VARCHAR(100),"
                    "cliente VARCHAR(100),"
                    "tiempo INTEGER NOT NULL "
                     ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if (crear.exec()){
        qDebug()<<"La tabla entregas existe o se creo correctamente";
    }else{
        qDebug()<<"ERROR en crear tabla "<<crear.lastError();
    }
}

void MainWindow::insertarEntrega()
{
    {
        QString consulta;
        consulta.append("INSERT INTO entregas"

                        "(usuario, cliente, tiempo ) "

                        "VALUES "

                        "('"+ui->lineEdit_usuario->text()+"',"
                        "'"+ui->lineEdit_3_cliente->text()+ "',"
                        " 88);"

                        );
        QSqlQuery insertar;
        insertar.prepare(consulta);
        if (insertar.exec()){
            qDebug()<<"La entrega se inserto en tabla";
        }else{
            qDebug()<<"ERROR  en carga entregas"<<insertar.lastError();
        }
    }
}






void MainWindow::fTimer(){
    ui->lcdNumber->display (cont++);
    ui->label_3->setText(QDateTime::currentDateTime().toString());
}




void MainWindow::on_pushButton_ingreso_clicked()
{/*
    QString username = ui->lineEdit_usuario->text();
    QString idUsuario = ui->lineEdit_2_password->text();
       if  ((username=="B" && idUsuario== "B")||
                 (username=="Adm" && idUsuario== "Adm")){

           QMessageBox::information(this,"Login", "Ingreso de usuario correcto ");
           control = true;

          }
           else {
               QMessageBox::warning(this,"Login", "Ingreso  usuario incorrecto");
                }
       if (username=="Adm" && idUsuario== "Adm"){
           secDialog secunDialg;//crea un objeto segundadialogo(ventana)
           secunDialg.exec();}


*/

    int cantidad;
    Usuario usuario(ui->lineEdit_usuario->text(),ui->lineEdit_2_password->text());
    QString consulta;
    consulta.append(QString("SELECT count (*) FROM usuarios"

                    "WHERE  "

                    "usuario LIKE '"+ui->lineEdit_usuario->text()+"' AND password LIKE '"+ui->lineEdit_2_password->text()+"'; "
                   ));



   //. arg( usuario.contrasenya() .arg(usuario.nombre())



    QSqlQuery consultar;
    consultar.prepare(consulta);
    if (consultar.exec()){
        qDebug()<<"La consulta se realizo en tabla usuarios";
    }else{
        qDebug()<<"ERROR  en consulta a usuarios"<<consultar.lastError();
    }
    consultar.next();
    cantidad = consultar.value(0).toInt();
    if(cantidad == 0){
        QMessageBox::warning(this,"Login", "Ingreso  usuario incorrecto");
    }else {
         QMessageBox::information(this,"Login", "Ingreso de usuario correcto ");
         control = true;

      }

         if (ui->lineEdit_usuario->text()=="Adm" && control==true){
             secDialog secunDialg;//crea un objeto segundadialogo(ventana)
             secunDialg.exec();}




}















void MainWindow::on_pushButton_clean_clicked()
{
    control = false;
    cont=0;
    ui->lineEdit_2_password->clear();
    ui->lineEdit_3_cliente->clear();
    ui->lineEdit_usuario->clear();
    ui->lcdNumber->display(cont);
}


void MainWindow::on_pushButton_timer_clicked()
{
    if (control==true){
        if (timer2->isActive()){
                timer2->stop();
                ui->pushButton_timer->setText("Tiempo entrega");
                insertarEntrega();

                 }else{
                      timer2->start(600);
                      ui->pushButton_timer->setText("En proceso");
                         }
        }else{
             QMessageBox::warning(this,"Timer", "Debe registrarse");
        }
}
