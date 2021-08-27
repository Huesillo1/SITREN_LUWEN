#include "comprartarjetawindow.h"
#include "ui_comprartarjetawindow.h"

//Getters & Setters

Cajero *&ComprarTarjetaWindow::getCajero()
{
    return cajero;
}

void ComprarTarjetaWindow::setCajero(Cajero *&value)
{
    cajero = value;
}


//Métodos Propios



//Métodos Forms

ComprarTarjetaWindow::ComprarTarjetaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ComprarTarjetaWindow)
{
    ui->setupUi(this);
}

ComprarTarjetaWindow::~ComprarTarjetaWindow()
{
    delete ui;
}

void ComprarTarjetaWindow::llenarComboBox(list<Usuario*> &listUser)
{
    ui->comboBoxUsuarios->clear();
    int i(0);
    for(auto it = listUser.begin(); it != listUser.end(); it++){
        Usuario *&userAux = *it;
        if(!cajero->isCardActive(userAux)){
            ui->comboBoxUsuarios->insertItem(i,QString::fromStdString(userAux->getNombre()));
            i++;
        }
    }
}


void ComprarTarjetaWindow::on_btnComprar_clicked()
{
    double costoTarjeta = 20.00;
    if(dineroUsuario < costoTarjeta){
        QMessageBox::warning(this,"Pago","No tiene suficiente dinero para pagar la tarjeta.");
    }else{
        IngresarDineroWindow *i = new IngresarDineroWindow;
        i->setCajero(cajero);
        i->setProcedencia("Compra_Tarjeta");
        i->setCantidadPago(costoTarjeta);
        i->cargarDatos();
        i->setIdTarjeta(idTarjeta);
        i->setUsuarioActual(usuarioActual);
        i->show();
    }
}

void ComprarTarjetaWindow::on_comboBoxUsuarios_currentIndexChanged(const QString &arg1)
{
    usuarioActual =  cajero->findUsuario(arg1.toStdString());
    dineroUsuario = usuarioActual->getDinero();
    ui->lblDineroUsuario->setText("Su dinero: $" + QString::number(dineroUsuario));
}

Usuario *&ComprarTarjetaWindow::getUsuarioActual()
{
    return usuarioActual;
}

void ComprarTarjetaWindow::setUsuarioActual(Usuario *&value)
{
    usuarioActual = value;
}

int *&ComprarTarjetaWindow::getIdTarjeta()
{
    return idTarjeta;
}

void ComprarTarjetaWindow::setIdTarjeta(int *&value)
{
    idTarjeta = value;
}
