#include "cajero.h"

Cajero::Cajero(): univiajes(0){ }

Cajero::Cajero(const Cajero &c): usuarios(c.usuarios), univiajes(c.univiajes){ }

//Getters & Setters

std::list<Usuario*>& Cajero::getUsuarios()
{
    return usuarios;
}

void Cajero::setUsuarios(std::list<Usuario*> &value)
{
    usuarios = value;
}


//METODOS USUARIOS

void Cajero::agregarUsuario(Usuario *&u)
{
    usuarios.push_back(u);
}

void Cajero::agregarDinero(double &d, Usuario *&u)
{
    u->setDinero(u->getDinero() + d);
}

void Cajero::ordenarPorNombre()
{
    usuarios.sort([](const Usuario *u1, const Usuario *u2){ return u1 < u2; });
}

void Cajero::ordenarPorSaldo()
{
    usuarios.sort([](const Usuario *u1, const Usuario *u2){ return u1->getDinero() < u2->getDinero(); });
}

void Cajero::ordenarPorIdTarjeta()
{
    usuarios.sort([](Usuario *u1, Usuario *u2){ return u1->getTarjeta() < u2->getTarjeta(); });
}

bool Cajero::isUsuariosEmpty()
{
    return usuarios.empty();
}

Usuario* Cajero::findUsuario(std::string name)
{
    for(auto it = usuarios.begin(); it != usuarios.end(); it++){
        Usuario *&u = *it;
        if(u->getNombre() == name){
            return u;
        }
    }
    return nullptr;
}

Usuario* Cajero::findUsuarioByCard(int id)
{
    for(auto it = usuarios.begin(); it != usuarios.end(); it++){
        Usuario *&u = *it;
        if(u->getTarjeta() != nullptr){
            if(u->getTarjeta()->getId() == id){
                return u;
            }
        }
    }
    return nullptr;
}

void Cajero::eliminarUsuario(std::string name)
{
    if(!isUsuariosEmpty()){
        usuarios.remove_if([name](const Usuario *u){ return name == u->getNombre(); });
//        for(auto it = usuarios.begin(); it != usuarios.end(); it++){
//            Usuario *&u = *it;
//        }
    }
}

//METODOS TARJETAS

void Cajero::comprarTarjeta(Usuario *&u, Tarjeta *&t)
{
    u->setTarjeta(t);
}

void Cajero::agregarSaldo(double &s, Tarjeta *&t)
{
    t->setSaldo(t->getSaldo() + s);
}

double Cajero::consultarSaldoTarjeta(Usuario *&u)
{
    return u->getTarjeta()->getSaldo();
}

bool Cajero::isCardActive(Usuario *&u)
{
    if(u->getTarjeta() != nullptr){
        return true;
    }
    return false;
}
