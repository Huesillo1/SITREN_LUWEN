#include "usuarioswindow.h"
#include "ui_usuarioswindow.h"

//Getters & Setters

Cajero*& UsuariosWindow::getCajeroActual()
{
    return cajeroActual;
}

void UsuariosWindow::setCajeroActual(Cajero *&value)
{
    cajeroActual = value;
}

//MainWindow*& UsuariosWindow::getM()
//{
//    return m;
//}

//void UsuariosWindow::setM(MainWindow *&value)
//{
//    m = value;
//}
//Metodos Propios

bool UsuariosWindow::camposLlenos()
{
    return ui->txtNombre->text() != "" && ui->txtApellido->text() != "" && ui->spinBoxDinero->value() != 0.00;
}

void UsuariosWindow::limpiarCampos()
{
    ui->txtNombre->setText("");
    ui->txtApellido->setText("");
    ui->spinBoxDinero->setValue(0.00);
}

//Metodos Forms

UsuariosWindow::UsuariosWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UsuariosWindow)
{
    ui->setupUi(this);
}

UsuariosWindow::~UsuariosWindow()
{
    delete ui;
}


void UsuariosWindow::on_btnGuardarUsuario_clicked()
{
    if(camposLlenos()){
        Usuario *user = new Usuario;
        user->setDinero(ui->spinBoxDinero->value());
        user->setNombre(ui->txtNombre->text().toStdString());
        user->setApellido(ui->txtApellido->text().toStdString());
        cajeroActual->agregarUsuario(user);
        QMessageBox::information(this,"Usuario","Se ha guardado al usuario " + QString::fromStdString(user->getNombre()) + " con éxito.");
        limpiarCampos();
    }else{
        QMessageBox::warning(this,"Usuarios","Debe llenar todos los campos.");
    }
}

