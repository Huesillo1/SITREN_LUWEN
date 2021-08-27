#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include "tarjeta.h"

class Usuario
{
private:
    Tarjeta *tarjeta;
    std::string nombre, apellido;
    double dinero;
public:
    Usuario();
    Usuario(const Usuario&);

    Tarjeta*& getTarjeta();
    void setTarjeta(Tarjeta *&value);

    std::string getNombre() const;
    void setNombre(const std::string &value);

    std::string getApellido() const;
    void setApellido(const std::string &value);

    double getDinero() const;
    void setDinero(double value);

    Usuario& operator = (const Usuario &u){
        tarjeta = u.tarjeta;
        dinero = u.dinero;
        nombre = u.nombre;
        apellido = u.apellido;
        return *this;
    }

    bool operator < (const Usuario u){
        return nombre < u.nombre;
    }

    bool operator <= (const Usuario u){
        return nombre <= u.nombre;
    }
    bool operator > (const Usuario u){
        return nombre > u.nombre;
    }

    bool operator >= (const Usuario u){
        return nombre >= u.nombre;
    }
    bool operator == (const Usuario u){
        return nombre == u.nombre;
    }
    bool operator != (const Usuario u){
        return nombre != u.nombre;
    }
};

#endif // USUARIO_H
