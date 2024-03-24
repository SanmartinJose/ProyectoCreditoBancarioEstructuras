/***********************************************************************
 * Module:  Operaciones.h
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 10:13:57:PM
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#pragma once
#include "Cuenta.h"
#include "ListaDoble.h"

class Operaciones
{
public:
   void generarPrestamo(Cuenta&, double, int, double);
   void generarTabla(Movimiento&, int, std::ofstream&);
   void pagarCuota(Cuenta& cuenta,Fecha fecha);
   void depositar(Cuenta& cuenta,Fecha fecha,double monto);
   bool retirar(Cuenta& cuenta,Fecha fecha,double monto);

protected:
private:

};

