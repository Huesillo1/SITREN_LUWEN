#ifndef TARJETA_H
#define TARJETA_H


class Tarjeta
{
private:
    int id, saldo;
public:
    Tarjeta();
    Tarjeta(const Tarjeta&);

    int getId() const;
    void setId(int value);

    double getSaldo() const;
    void setSaldo(double value);

    Tarjeta& operator = (const Tarjeta& t){
        id = t.id;
        saldo = t.saldo;
        return *this;
    }

    bool operator < (const Tarjeta &t){
        return id < t.id;
    }

    bool operator <= (const Tarjeta &t){
        return id <= t.id;
    }

    bool operator > (const Tarjeta &t){
        return id > t.id;
    }

    bool operator >= (const Tarjeta &t){
        return id >= t.id;
    }

    bool operator != (const Tarjeta &t){
        return id != t.id;
    }

    bool operator == (const Tarjeta &t){
        return id == t.id;
    }
};

#endif // TARJETA_H
