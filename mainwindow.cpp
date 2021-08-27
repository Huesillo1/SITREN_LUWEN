#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <algorithm>

//Getters & Setters

Cajero& MainWindow::getATM()
{
    return ATM;
}

void MainWindow::setATM(Cajero &value)
{
    ATM = value;
}

int MainWindow::getId() const
{
    return id;
}

void MainWindow::setId(int value)
{
    id = value;
}

//Metodos Propios



//Metodos Form


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), id(0), idTarjeta(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAgregar_Usuario_triggered()
{
    UsuariosWindow *u = new UsuariosWindow;
//    MainWindow *m = this;
    //u->setM(m);
    Cajero *cajero = new Cajero;
    cajero = &ATM;
    u->setCajeroActual(cajero);
    u->show();
}

void MainWindow::on_actionMostrarUsuarios_triggered()
{
    MostrarUsuariosWindow *muw = new MostrarUsuariosWindow;
    Cajero *cajero = new Cajero;
    cajero = &ATM;
    muw->setCajero(cajero);
    muw->llenarTabla(cajero->getUsuarios());
    muw->show();
}

void MainWindow::on_btnRecargar_clicked()
{
    SeleccionUsuarioWindow *s = new SeleccionUsuarioWindow;
    Cajero *cajero = new Cajero;
    int *idCard = new int;
    idCard = &idTarjeta;
    cajero = &ATM;
    s->setCajero(cajero);
    s->setIdTarjeta(idCard);
    s->show();
}

void MainWindow::on_btnComprarTarjeta_clicked()
{
    if(!ATM.isUsuariosEmpty()){
        ComprarTarjetaWindow *c = new ComprarTarjetaWindow;
        Cajero *cajero = new Cajero;
        int *idCard = new int;
        idCard = &idTarjeta;
        cajero = &ATM;
        c->setCajero(cajero);
        c->llenarComboBox(cajero->getUsuarios());
        c->setIdTarjeta(idCard);
        c->show();
    }else{
        QMessageBox::warning(this,"Advertencia","Antes de poder comprar una tarjeta debes registrar al menos un usuario.");
    }

}

void MainWindow::on_btnUniviaje_clicked()
{
    IngresarDineroWindow *i = new IngresarDineroWindow;
    Cajero *cajero = new Cajero;
    int *idActual = new int;
    idActual = &id;
    cajero = &ATM;
    i->setCajero(cajero);
    i->setCantidadPago(10);
    i->setWindowTitle("Pago Univiaje");
    i->setProcedencia("Univiaje");
    i->setIdUniviaje(idActual);
    i->cargarDatos();
    i->show();
}

