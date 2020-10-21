#include "tercerdialog.h"
#include "ui_tercerdialog.h"
#include <QDebug>

tercerDialog::tercerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tercerDialog)
{
    ui->setupUi(this);
}

tercerDialog::~tercerDialog()
{
    delete ui;
}

void tercerDialog::insertarUsuario()
{
    QString consulta;
    consulta.append("INSERT INTO usuarios("

                    "usuario ,"
                    "paswword )"
                    "VALUES( "
                    "'"+ui->lineEdit_Usuario->text()+"',"
                    ""+ui->lineEdit_password->text()+""

                     ");");
    QSqlQuery insertar;
    insertar.prepare(consulta);
    if (insertar.exec()){
        qDebug()<<"El usuario se inserto en tabla";
    }else{
        qDebug()<<"ERROR "<<insertar.lastError();
    }
}

void tercerDialog::mostrarTablaUsuario()
{
    QString consulta;
    consulta.append("SELECT * FROM usuarios ");


    QSqlQuery consultar;
    consultar.prepare(consulta);
    if (consultar.exec()){
        qDebug()<<"La consulta fue correcta";
    }else{
        qDebug()<<"ERROR  de consulta"<<consultar.lastError();
    }

    int fila = 0;
    ui->tableWidget_usuario->setRowCount(0);//limpia la tabla
    while (consultar.next()){

        ui->tableWidget_usuario->insertRow(fila);
        ui->tableWidget_usuario->setItem(fila,0,new QTableWidgetItem(consultar.value(1).toByteArray().constData()));
        ui->tableWidget_usuario->setItem(fila,1,new QTableWidgetItem(consultar.value(2).toByteArray().constData()));

        fila ++;

    }

}

void tercerDialog::on_pushButton_agregar_clicked()
{
    insertarUsuario();

}

void tercerDialog::on_pushButton_delete_clicked()
{
    QString consulta;
    consulta.append("DELETE FROM usuarios"";");

    QSqlQuery borrar;
    borrar.prepare(consulta);
    if (borrar.exec()){
        qDebug()<<"El usuario se borro en tabla";
    }else{
        qDebug()<<"ERROR "<<borrar.lastError();
    }
  mostrarTablaUsuario();
}


void tercerDialog::on_pushButton_clicked()
{
     mostrarTablaUsuario();
}
