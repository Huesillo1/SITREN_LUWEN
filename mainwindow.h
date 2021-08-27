#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <algorithm>

#include "usuarioswindow.h"
#include "mostrarusuarioswindow.h"
#include "seleccionusuariowindow.h"
#include "comprartarjetawindow.h"

#include "cajero.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //GETTERS & SETTERS

    Cajero& getATM();
    void setATM(Cajero &value);

    int getId() const;
    void setId(int value);


    //METODOS PROPIOS



    //METODOS FORM
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionAgregar_Usuario_triggered();

    void on_actionMostrarUsuarios_triggered();

    void on_btnRecargar_clicked();

    void on_btnComprarTarjeta_clicked();

    void on_btnUniviaje_clicked();

private:
    Ui::MainWindow *ui;
    Cajero ATM;
    int id, idTarjeta;
};
#endif // MAINWINDOW_H
