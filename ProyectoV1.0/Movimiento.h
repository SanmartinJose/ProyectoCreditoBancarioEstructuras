/***********************************************************************
 * Module:  Movimiento.h
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 10:17:59:PM
 * Purpose: Declaration of the class Movimiento
 ***********************************************************************/

#pragma once

#include "Fecha.h"
#include "ListaDoble.h"

class Movimiento
{
public:
   Movimiento();
   Movimiento(std::string, Fecha, double);
   Movimiento(std::string, ListaDoble<Fecha>, ListaDoble<double>, ListaDoble<double>, ListaDoble<double>, ListaDoble<double>, ListaDoble<double>,
              Fecha, double, int numero_registros);
   ~Movimiento();
   void to_String();
    friend class Operaciones;
protected:
private:
   std::string tipo;
   ListaDoble<Fecha> fechasPago;
   ListaDoble<double> saldosIniciales;
   ListaDoble<double> saldosPendientes;
   ListaDoble<double> intereses;
   ListaDoble<double> capitales;
   ListaDoble<double> cuotasFijas;
   int numero_registros;
   Fecha fechaEmision;
   double valor;


};
