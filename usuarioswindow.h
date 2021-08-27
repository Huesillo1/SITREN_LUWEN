#ifndef USUARIOSWINDOW_H
#define USUARIOSWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <algorithm>

#include "cajero.h"
#include "usuario.h"

#include "mainwindow.h"

using namespace std;

namespace Ui {
class UsuariosWindow;
}

class UsuariosWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsuariosWindow(QWidget *parent = nullptr);
    ~UsuariosWindow();

    //Getters & Setters

    Cajero*& getCajeroActual();
    void setCajeroActual(Cajero *&);

//    MainWindow *&getM();
//    void setM(MainWindow *&value);

private slots:

    //Metodos Propios

    bool camposLlenos();
//    Usuario *&agregarUsuario();

    void limpiarCampos();

    //Metodos Form

    void on_btnGuardarUsuario_clicked();


private:
    Ui::UsuariosWindow *ui;
    Cajero *cajeroActual;
//    MainWindow *m = new MainWindow;
};

#endif // USUARIOSWINDOW_H
