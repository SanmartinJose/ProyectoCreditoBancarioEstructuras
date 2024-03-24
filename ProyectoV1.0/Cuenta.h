/***********************************************************************
 * Module:  Cuenta.h
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 09:58:44:PM
 * Purpose: Declaration of the class Cuenta
 ***********************************************************************/

#pragma once

#include "Persona.h"
#include "ListaDoble.h"
#include "Movimiento.h"

class Cuenta
{
public:
    Cuenta();
    Cuenta(Persona, double, std::string, ListaDoble<Movimiento>);
    ~Cuenta();
    Persona get_persona();
    double get_saldo();
    std::string get_nCuenta();
    ListaDoble<Movimiento> get_movimientos();
    Cuenta get_this();
    void to_String();
    template <typename U>
    friend class ArbolBinario;
    friend class Persona;
    friend class Operaciones;
protected:
private:
    Persona persona;
    double saldo;
    std::string nCuenta;
    ListaDoble<Movimiento> movimientos;
    std::string getter_general(int);
    void getter_dato_general(int);
};
