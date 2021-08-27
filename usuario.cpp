#include "usuario.h"

Usuario::Usuario():tarjeta(nullptr){ }

Usuario::Usuario(const Usuario &u): tarjeta(u.tarjeta), nombre(u.nombre), apellido(u.apellido), dinero(u.dinero){ }

Tarjeta*& Usuario::getTarjeta()
{
    return tarjeta;
}

void Usuario::setTarjeta(Tarjeta *&value)
{
    tarjeta = value;
}

std::string Usuario::getNombre() const
{
    return nombre;
}

void Usuario::setNombre(const std::string &value)
{
    nombre = value;
}

std::string Usuario::getApellido() const
{
    return apellido;
}

void Usuario::setApellido(const std::string &value)
{
    apellido = value;
}

double Usuario::getDinero() const
{
    return dinero;
}

void Usuario::setDinero(double value)
{
    dinero = value;
}
