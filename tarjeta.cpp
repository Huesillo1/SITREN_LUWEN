#include "tarjeta.h"

Tarjeta::Tarjeta(): id(0), saldo(0){ }

Tarjeta::Tarjeta(const Tarjeta &t): id(t.id), saldo(t.saldo){ }

int Tarjeta::getId() const
{
    return id;
}

void Tarjeta::setId(int value)
{
    id = value;
}

double Tarjeta::getSaldo() const
{
    return saldo;
}

void Tarjeta::setSaldo(double value)
{
    saldo = value;
}
