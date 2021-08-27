#ifndef COMPRARTARJETAWINDOW_H
#define COMPRARTARJETAWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <algorithm>
#include <iostream>
#include <list>

#include "cajero.h"
#include "usuario.h"

#include "mainwindow.h"
#include "ingresardinerowindow.h"


namespace Ui {
class ComprarTarjetaWindow;
}

class ComprarTarjetaWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Métodos Form

    explicit ComprarTarjetaWindow(QWidget *parent = nullptr);
    ~ComprarTarjetaWindow();

    //Métodos Propios

    void llenarComboBox(list<Usuario*> &);

    //Getters & Setters

    Cajero*& getCajero();
    void setCajero(Cajero *&value);

    int*& getIdTarjeta();
    void setIdTarjeta(int*&);

    Usuario*& getUsuarioActual();
    void setUsuarioActual(Usuario*&);

private slots:
    void on_btnComprar_clicked();

    void on_comboBoxUsuarios_currentIndexChanged(const QString &arg1);

private:
    Ui::ComprarTarjetaWindow *ui;
    Cajero *cajero;
    double dineroUsuario;
    int *idTarjeta;
    Usuario *usuarioActual;
};

#endif // COMPRARTARJETAWINDOW_H
