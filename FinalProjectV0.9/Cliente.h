#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Persona.h"
#include "Movimiento.h"

class Cliente{
private:
    Persona persona;
    double saldo;
    Movimiento movimiento;
public:
    Cliente();
    Cliente(Persona, double, Movimiento);
    Persona getPersona();
    double getSaldo();
    Movimiento getMovimiento();
    void setPersona(Persona);
    void setSaldo(double);
    void setMovimiento(Movimiento&);
};

#endif // CLIENTE_H_INCLUDED
