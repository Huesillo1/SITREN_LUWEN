#ifndef INGRESARDINEROWINDOW_H
#define INGRESARDINEROWINDOW_H

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

namespace Ui {
class IngresarDineroWindow;
}

class IngresarDineroWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Métodos Form
    explicit IngresarDineroWindow(QWidget *parent = nullptr);
    ~IngresarDineroWindow();

    //Getters & Setters

    Cajero*& getCajero();
    void setCajero(Cajero *&value);

    int getCantidadPago() const;
    void setCantidadPago(int value);

    string getProcedencia() const;
    void setProcedencia(const string &value);

    Usuario*& getUsuarioActual();
    void setUsuarioActual(Usuario*&);

    int*& getIdUniviaje();
    void setIdUniviaje(int*&);

    int*& getIdTarjeta();
    void setIdTarjeta(int*&);

    //Métodos Propios

    void cargarDatos();


private slots:

    //Métodos Propios

    int calcularDinero();

    //Métodos Form

    void on_chkbox50_stateChanged(int arg1);

    void on_chkbox20_stateChanged(int arg1);

    void on_chkbox10_stateChanged(int arg1);

    void on_chkbox5_stateChanged(int arg1);

    void on_chkbox2_stateChanged(int arg1);

    void on_chkbox1_stateChanged(int arg1);

    void on_spbox50_valueChanged(int arg1);

    void on_spbox20_valueChanged(int arg1);

    void on_spbox10_valueChanged(int arg1);

    void on_spbox5_valueChanged(int arg1);

    void on_spbox2_valueChanged(int arg1);

    void on_spbox1_valueChanged(int arg1);

    void on_btnNext_clicked();

private:
    Ui::IngresarDineroWindow *ui;
    Cajero *cajero;
    int cantidadPago;
    string procedencia;
    Usuario *usuarioActual;
    int *idUniviaje, *idTarjeta;
};

#endif // INGRESARDINEROWINDOW_H
