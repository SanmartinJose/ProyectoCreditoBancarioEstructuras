#include "Cliente.h"

Cliente::Cliente(){

}

Cliente::Cliente(Persona nuevo_persona, double nuevo_saldo, Movimiento nuevo_movimiento){
    persona = nuevo_persona;
    saldo = nuevo_saldo;
    movimiento = nuevo_movimiento;
}

Persona Cliente::getPersona(){
    return persona;
}

double Cliente::getSaldo(){
    return saldo;
}

Movimiento Cliente::getMovimiento(){
    return movimiento;
}

void Cliente::setPersona(Persona nuevo_persona){
    persona = nuevo_persona;
}

void Cliente::setSaldo(double nuevo_saldo){
    saldo = nuevo_saldo;
}

void Cliente::setMovimiento(Movimiento& nuevo_movimiento){
    movimiento = nuevo_movimiento;
}
