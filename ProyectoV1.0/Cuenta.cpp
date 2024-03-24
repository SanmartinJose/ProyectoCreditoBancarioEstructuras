/***********************************************************************
 * Module:  Cuenta.cpp
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 09:58:44:PM
 * Purpose: Implementation of the class Cuenta
 ***********************************************************************/

#include "Cuenta.h"

////////////////////////////////////////////////////////////////////////
// Name:       Cuenta::Cuenta()
// Purpose:    Implementation of Cuenta::Cuenta()
// Return:
////////////////////////////////////////////////////////////////////////

Cuenta::Cuenta()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Cuenta::~Cuenta()
// Purpose:    Implementation of Cuenta::~Cuenta()
// Return:
////////////////////////////////////////////////////////////////////////

Cuenta::~Cuenta()
{
   // TODO : implement
}

Cuenta::Cuenta(Persona _persona, double _saldo, std::string _nCuenta, ListaDoble<Movimiento> _movimientos){
    persona = _persona;
    saldo = _saldo;
    nCuenta = _nCuenta;
    movimientos = _movimientos;
}

void Cuenta::to_String(){
    printf("%s      %s      %s      %s      %s      %s\n",
           persona.id.c_str(), persona.nombres.c_str(), persona.apellidos.c_str(), persona.cedula.c_str(), std::to_string(saldo).c_str(),
           nCuenta.c_str());
}

std::string Cuenta::getter_general(int opcion){
    if(opcion == 1){
        return persona.id;
    }
    else if(opcion == 2){
        return persona.nombres;
    }
    else if(opcion == 3){
        return persona.apellidos;
    }
    else if(opcion == 4){
        return persona.cedula;
    }
    else if(opcion == 5){
        return nCuenta;
    }
}

Persona Cuenta::get_persona(){
    return persona;
}

double Cuenta::get_saldo(){
    return saldo;
}


std::string Cuenta::get_nCuenta(){
    return nCuenta;
}

ListaDoble<Movimiento> Cuenta::get_movimientos(){
    return movimientos;
}


