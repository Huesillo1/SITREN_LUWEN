#include "seleccionusuariowindow.h"
#include "ui_seleccionusuariowindow.h"


//Getters & Setters

Cajero*& SeleccionUsuarioWindow::getCajero()
{
    return cajero;
}

void SeleccionUsuarioWindow::setCajero(Cajero *&value)
{
    cajero = value;
}

Usuario*& SeleccionUsuarioWindow::getUsuarioActual()
{
    return usuarioActual;
}

void SeleccionUsuarioWindow::setUsuarioActual(Usuario *&value)
{
    usuarioActual = value;
}

int *&SeleccionUsuarioWindow::getIdTarjeta()
{
    return idTarjeta;
}

void SeleccionUsuarioWindow::setIdTarjeta(int *&value)
{
    idTarjeta = value;
}


//Métodos Propios



//Métodos Form

SeleccionUsuarioWindow::SeleccionUsuarioWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeleccionUsuarioWindow)
{
    ui->setupUi(this);
    ui->spboxCantidadRecarga->setEnabled(false);
    ui->btnNext->setEnabled(false);
}

SeleccionUsuarioWindow::~SeleccionUsuarioWindow()
{
    delete ui;
}


void SeleccionUsuarioWindow::on_btnValidar_clicked()
{
    Usuario *userAux = cajero->findUsuarioByCard(ui->txtIdTarjeta->text().toInt());
    if(userAux != nullptr){
        ui->spboxCantidadRecarga->setEnabled(true);
        ui->btnNext->setEnabled(true);
        ui->lblNombreUsuario->setText("Hola! " + QString::fromStdString(userAux->getNombre()) + " " + QString::fromStdString(userAux->getApellido()));
        ui->lblSaldoActual->setText("Saldo actual: $" + QString::number(userAux->getTarjeta()->getSaldo()));
        ui->spboxCantidadRecarga->setMaximum(userAux->getDinero());
        usuarioActual = userAux;
    }else{
        QMessageBox::warning(this,"Validacion","No se encontró ningún usuario con una tarjeta del ID ingresado");
        ui->txtIdTarjeta->setText("");
        ui->spboxCantidadRecarga->setEnabled(false);
        ui->btnNext->setEnabled(false);
    }
}

void SeleccionUsuarioWindow::on_btnBack_clicked()
{
    this->close();
}

void SeleccionUsuarioWindow::on_btnNext_clicked()
{
    IngresarDineroWindow *i = new IngresarDineroWindow;
    i->setCajero(cajero);
    i->setProcedencia("Recarga");
    i->setCantidadPago(ui->spboxCantidadRecarga->value());
    i->setIdTarjeta(idTarjeta);
    i->setUsuarioActual(usuarioActual);
    i->cargarDatos();
    i->show();
}

