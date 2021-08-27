#ifndef CAJERO_H
#define CAJERO_H
#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

#include"usuario.h"

class Cajero
{
public:
    private:
    std::list<Usuario*> usuarios;
    int univiajes;
public:
    Cajero();
    Cajero(const Cajero&);
    std::list<Usuario*>& getUsuarios();
    void setUsuarios(std::list<Usuario*> &value);

    Cajero& operator = (const Cajero &c){
        usuarios = c.usuarios;
        univiajes = c.univiajes;
        return *this;
    }

    //Metodos usuarios

    void agregarUsuario(Usuario*&);
    void agregarDinero(double&, Usuario*&);

    void ordenarPorNombre();
    void ordenarPorSaldo();
    void ordenarPorIdTarjeta();

    bool isUsuariosEmpty();

    Usuario* findUsuario(std::string);

    Usuario* findUsuarioByCard(int id);

    void eliminarUsuario(std::string);



    //Metodos tarjeta

    void comprarTarjeta(Usuario*&,Tarjeta*&);

    void agregarSaldo(double&,Tarjeta*&);

    double consultarSaldoTarjeta(Usuario*&);

    bool isCardActive(Usuario*&);
};

#endif // CAJERO_H
