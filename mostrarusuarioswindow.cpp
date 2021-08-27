#include "mostrarusuarioswindow.h"
#include "ui_mostrarusuarioswindow.h"

//Getters & Setters

Cajero*& MostrarUsuariosWindow::getCajero()
{
    return cajero;
}

void MostrarUsuariosWindow::setCajero(Cajero *&value)
{
    cajero = value;
}

//Métodos propios

void MostrarUsuariosWindow::llenarTabla(list<Usuario*> &listUser)
{
    ui->dgvUsuarios->clear();
    ui->dgvUsuarios->setColumnCount(4);
    ui->dgvUsuarios->setRowCount(listUser.size());
    QStringList headers;
    headers << "Nombre" << "Apellido" << "Dinero" << "Tarjeta";
    ui->dgvUsuarios->setHorizontalHeaderLabels(headers);
    size_t row=0;
    for (auto it = listUser.begin(); it != listUser.end(); it++) {
        Usuario *&u = *it;
        QString nombre = QString::fromStdString(u->getNombre());
        QString apellido = QString::fromStdString(u->getApellido());
        QString dinero = QString::number(u->getDinero());
        QString tarjeta;
        u->getTarjeta() != nullptr ? tarjeta = "SI >> ID:" + QString::number(u->getTarjeta()->getId()) + "  $" + QString::number(u->getTarjeta()->getSaldo()):  tarjeta = "NO";
        ui->dgvUsuarios->setItem(row, 0,new QTableWidgetItem(nombre));
        ui->dgvUsuarios->setItem(row, 1,new QTableWidgetItem(apellido));
        ui->dgvUsuarios->setItem(row, 2, new QTableWidgetItem(dinero));
        ui->dgvUsuarios->setItem(row, 3, new QTableWidgetItem(tarjeta));
        row++;
    }
}

//Métodos Form

MostrarUsuariosWindow::MostrarUsuariosWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MostrarUsuariosWindow)
{
    ui->setupUi(this);

}

MostrarUsuariosWindow::~MostrarUsuariosWindow()
{
    delete ui;
}



