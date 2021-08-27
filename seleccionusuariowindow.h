#ifndef SELECCIONUSUARIOWINDOW_H
#define SELECCIONUSUARIOWINDOW_H

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
class SeleccionUsuarioWindow;
}

class SeleccionUsuarioWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeleccionUsuarioWindow(QWidget *parent = nullptr);
    ~SeleccionUsuarioWindow();

    Cajero*& getCajero();
    void setCajero(Cajero *&value);

    int*& getIdTarjeta();
    void setIdTarjeta(int*&);

    Usuario*& getUsuarioActual();
    void setUsuarioActual(Usuario*&);

private slots:
    void on_btnValidar_clicked();

    void on_btnBack_clicked();

    void on_btnNext_clicked();

private:
    Ui::SeleccionUsuarioWindow *ui;
    Cajero *cajero;
    Usuario *usuarioActual;
    int *idTarjeta;
};

#endif // SELECCIONUSUARIOWINDOW_H
