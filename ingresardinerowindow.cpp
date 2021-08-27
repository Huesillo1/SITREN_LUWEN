#include "ingresardinerowindow.h"
#include "ui_ingresardinerowindow.h"


//Getters & Setters

Cajero*& IngresarDineroWindow::getCajero()
{
    return cajero;
}

void IngresarDineroWindow::setCajero(Cajero *&value)
{
    cajero = value;
}

int IngresarDineroWindow::getCantidadPago() const
{
    return cantidadPago;
}

void IngresarDineroWindow::setCantidadPago(int value)
{
    cantidadPago = value;
}

string IngresarDineroWindow::getProcedencia() const
{
    return procedencia;
}

void IngresarDineroWindow::setProcedencia(const string &value)
{
    procedencia = value;
}

Usuario*& IngresarDineroWindow::getUsuarioActual()
{
    return usuarioActual;
}

void IngresarDineroWindow::setUsuarioActual(Usuario *&u)
{
    usuarioActual = u;
}

int *&IngresarDineroWindow::getIdUniviaje()
{
    return idUniviaje;
}

void IngresarDineroWindow::setIdUniviaje(int *&value)
{
    idUniviaje = value;
}

int *&IngresarDineroWindow::getIdTarjeta()
{
    return idTarjeta;
}

void IngresarDineroWindow::setIdTarjeta(int *&value)
{
    idTarjeta = value;
}

//Métodos Propios

void IngresarDineroWindow::cargarDatos()
{
    ui->lblCantidadPago->setText("A pagar: $" + QString::number(cantidadPago));
    ui->lblCambio->setText("Su cambio: $0.00");
    ui->lblIngreso->setText("Ingresó: $0.00");
}

int IngresarDineroWindow::calcularDinero()
{
    int total(0);
    if(ui->chkbox50->isChecked()){
        total += ui->spbox50->value() * 50;
    }

    if(ui->chkbox20->isChecked()){
        total += ui->spbox20->value() * 20;
    }

    if(ui->chkbox10->isChecked()){
        total += ui->spbox10->value() * 10;
    }

    if(ui->chkbox5->isChecked()){
        total += ui->spbox5->value() * 5;
    }

    if(ui->chkbox2->isChecked()){
        total += ui->spbox2->value() * 2;
    }

    if(ui->chkbox1->isChecked()){
        total += ui->spbox1->value() * 1;
    }

    //ui->lblCantidadPago->setText("A pagar: $" + QString::number(cantidadPago));

    total >= cantidadPago ? ui->btnNext->setEnabled(true) : ui->btnNext->setEnabled(false);

    return total;
}



//Métodos Form


IngresarDineroWindow::IngresarDineroWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::IngresarDineroWindow)
{
    ui->setupUi(this);
    ui->btnNext->setEnabled(false);
    ui->spbox1->setEnabled(false);
    ui->spbox2->setEnabled(false);
    ui->spbox5->setEnabled(false);
    ui->spbox10->setEnabled(false);
    ui->spbox20->setEnabled(false);
    ui->spbox50->setEnabled(false);
    ui->btnCalcular->setVisible(false);
    ui->btnCalcular->setEnabled(false);
    ui->lblNoOlvidarCambio->setVisible(false);
    ui->lblImprimiendoTicket->setVisible(false);
    ui->pbImpresion->setVisible(false);
}

IngresarDineroWindow::~IngresarDineroWindow()
{
    delete ui;
}

void IngresarDineroWindow::on_chkbox50_stateChanged(int arg1)
{
    if(ui->chkbox50->isChecked()){
        ui->spbox50->setEnabled(true);
        ui->spbox50->setValue(1);
        ui->spbox50->setMinimum(1);
    }else{
        ui->spbox50->setEnabled(false);
        ui->spbox50->setMinimum(0);
        ui->spbox50->setValue(0);
    }
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_chkbox20_stateChanged(int arg1)
{
    if(ui->chkbox20->isChecked()){
        ui->spbox20->setEnabled(true);
        ui->spbox20->setValue(1);
        ui->spbox20->setMinimum(1);
    }else{
        ui->spbox20->setEnabled(false);
        ui->spbox20->setMinimum(0);
        ui->spbox20->setValue(0);
    }
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_chkbox10_stateChanged(int arg1)
{
    if(ui->chkbox10->isChecked()){
        ui->spbox10->setEnabled(true);
        ui->spbox10->setValue(1);
        ui->spbox10->setMinimum(1);
    }else{
        ui->spbox10->setEnabled(false);
        ui->spbox10->setMinimum(0);
        ui->spbox10->setValue(0);
    }
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_chkbox5_stateChanged(int arg1)
{
    if(ui->chkbox5->isChecked()){
        ui->spbox5->setEnabled(true);
        ui->spbox5->setValue(1);
        ui->spbox5->setMinimum(1);
    }else{
        ui->spbox5->setEnabled(false);
        ui->spbox5->setMinimum(0);
        ui->spbox5->setValue(0);
    }
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_chkbox2_stateChanged(int arg1)
{
    if(ui->chkbox2->isChecked()){
        ui->spbox2->setEnabled(true);
        ui->spbox2->setValue(1);
        ui->spbox2->setMinimum(1);
    }else{
        ui->spbox2->setEnabled(false);
        ui->spbox2->setMinimum(0);
        ui->spbox2->setValue(0);
    }
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_chkbox1_stateChanged(int arg1)
{
    if(ui->chkbox1->isChecked()){
        ui->spbox1->setEnabled(true);
        ui->spbox1->setValue(1);
        ui->spbox1->setMinimum(1);
    }else{
        ui->spbox1->setEnabled(false);
        ui->spbox1->setMinimum(0);
        ui->spbox1->setValue(0);
    }
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_spbox50_valueChanged(int arg1)
{
    ui->lblIngreso->setText("Ingresó: $" + QString::number(calcularDinero()));
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));

}

void IngresarDineroWindow::on_spbox20_valueChanged(int arg1)
{
    ui->lblIngreso->setText("Ingresó: $" + QString::number(calcularDinero()));
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_spbox10_valueChanged(int arg1)
{
    ui->lblIngreso->setText("Ingresó: $" + QString::number(calcularDinero()));
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_spbox5_valueChanged(int arg1)
{
    ui->lblIngreso->setText("Ingresó: $" + QString::number(calcularDinero()));
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_spbox2_valueChanged(int arg1)
{
    ui->lblIngreso->setText("Ingresó: $" + QString::number(calcularDinero()));
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}

void IngresarDineroWindow::on_spbox1_valueChanged(int arg1)
{
    ui->lblIngreso->setText("Ingresó: $" + QString::number(calcularDinero()));
    ui->lblCambio->setText("Su cambio: $" + QString::number(calcularDinero()-cantidadPago));
}


void IngresarDineroWindow::on_btnNext_clicked()
{
    if(procedencia == "Compra_Tarjeta" || procedencia == "Recarga"){
        if(usuarioActual->getDinero() - cantidadPago < 0){
            QMessageBox::information(this,"Dinero insuficiente","No cuentas con suficiente dinero para pagar");
            return;
        }
    }
    if(calcularDinero()-cantidadPago > 0){
        ui->lblNoOlvidarCambio->setVisible(true);
    }else{
        ui->lblNoOlvidarCambio->setVisible(false);
    }

    ui->lblImprimiendoTicket->setVisible(true);
    ui->pbImpresion->setVisible(true);

    for(int i(1); i < 202000;i++){
        if(i % 2000 == 0){
           ui->pbImpresion->setValue(i/2000);
        }
    }

    if(procedencia == "Compra_Tarjeta"){
    Tarjeta *tarjeta = new Tarjeta;
    *idTarjeta += 1;
    tarjeta->setId(*idTarjeta);
    tarjeta->setSaldo(20);
    usuarioActual->setTarjeta(tarjeta);
    usuarioActual->setDinero(usuarioActual->getDinero()-20);
    QMessageBox::information(this,"Compra Exitosa","Muchas gracias por su compra, se le han bonificado $20\n\t¡Disfrute su tarjeta!");


    }else if(procedencia == "Recarga"){
        int i(0);
        bool exito = false;
        while(i < 5){
            try{
               usuarioActual->getTarjeta()->setSaldo(usuarioActual->getTarjeta()->getSaldo() + cantidadPago);
               usuarioActual->setDinero(usuarioActual->getDinero()-cantidadPago);
               QMessageBox::information(this,"Transfiriendo", "Se está transifiriendo el depósito a su tarjeta");
               exito = true;
               break;
            }catch(exception ex){
                QMessageBox::critical(this,"Error en la transferencia","Transferencia fallida...\nReintentando");
                i++;
                exito = false;
            }
        }
        if(exito){
            QMessageBox::information(this,"Transferencia exitosa", "Su dinero se encuentra en su tarjeta");
        }else{
            QMessageBox::critical(this,"Transferencia fallida", "Algo salió mal... Reintente más tarde");
            QMessageBox::information(this,"Recuerde", "No olvide retirar su dinero");
        }
    }else if(procedencia == "Univiaje"){
        *idUniviaje += 1;
        QMessageBox::information(this,"Univiaje","No olvide retirar su boleto Univiaje, que tenga buen día\n\tID:" + QString::number(*idUniviaje));
    }

    QMessageBox::information(this,"Listo","Por favor cierre todas las ventanas hasta volver al inicio \n Que tenga buen día");
}


