#ifndef MOSTRARUSUARIOSWINDOW_H
#define MOSTRARUSUARIOSWINDOW_H

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

using namespace std;

namespace Ui {
class MostrarUsuariosWindow;
}

class MostrarUsuariosWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MostrarUsuariosWindow(QWidget *parent = nullptr);
    ~MostrarUsuariosWindow();

    Cajero*& getCajero();
    void setCajero(Cajero *&value);

    //Métodos Propios

    void llenarTabla(list<Usuario*> &listUser);

private slots:


private:
    Ui::MostrarUsuariosWindow *ui;
    Cajero *cajero;
};

#endif // MOSTRARUSUARIOSWINDOW_H
