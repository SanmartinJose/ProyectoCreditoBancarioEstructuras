/***********************************************************************
 * Module:  Movimiento.cpp
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 10:17:59:PM
 * Purpose: Implementation of the class Movimiento
 ***********************************************************************/

#include "Movimiento.h"
#include "Fecha.h"
#include "ListaDoble.cpp"

////////////////////////////////////////////////////////////////////////
// Name:       Movimiento::Movimiento()
// Purpose:    Implementation of Movimiento::Movimiento()
// Return:
////////////////////////////////////////////////////////////////////////

Movimiento::Movimiento()
{
}

Movimiento::Movimiento(std::string _tipo, ListaDoble<Fecha> _fechasPago,
                       ListaDoble<double> _saldosIniciales, ListaDoble<double> _saldosPendientes,
                       ListaDoble<double> _intereses, ListaDoble<double> _capitales, ListaDoble<double> _cuotasFijas,
                       Fecha _fechaEmision, double _valor, int _numero_registros){
    tipo = _tipo;
    fechaEmision = _fechaEmision;
    valor = _valor;
    fechasPago = _fechasPago;
    saldosIniciales = _saldosIniciales;
    saldosPendientes = _saldosPendientes;
    intereses = _intereses;
    capitales = _capitales;
    cuotasFijas = _cuotasFijas;
    numero_registros = _numero_registros;
}

Movimiento::Movimiento(std::string _tipo, Fecha _fechaEmision, double _valor){
    tipo = _tipo;
    fechaEmision = _fechaEmision;
    valor = _valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Movimiento::~Movimiento()
// Purpose:    Implementation of Movimiento::~Movimiento()
// Return:
////////////////////////////////////////////////////////////////////////

Movimiento::~Movimiento()
{
   // TODO : implement
}


void Movimiento::to_String(){


    if(tipo == "prestamo"){
        Nodo<Fecha>* recorre_fechas_pagos = fechasPago.get_cabeza();
        Nodo<double>* recorre_saldos_iniciales = saldosIniciales.get_cabeza();
        Nodo<double>* recorre_saldos_pendientes = saldosPendientes.get_cabeza();
        Nodo<double>* recorre_intereses = intereses.get_cabeza();
        Nodo<double>* recorre_capitales = capitales.get_cabeza();
        Nodo<double>* recorre_cuotas_fijas = cuotasFijas.get_cabeza();
        int contador = 0;
        auto recursiva_tabla = [&](auto&& recursiva_tabla)->void{
            Fecha nueva_fecha = recorre_fechas_pagos->get_valor();
            if(contador <= numero_registros){

                printf("%2d      ", contador);
                printf("%10.2f    ", recorre_saldos_iniciales->get_valor());
                printf("%6.2f   ", recorre_intereses->get_valor());
                printf("%7.2f      ", recorre_capitales->get_valor());
                printf("%7.2f ", recorre_cuotas_fijas->get_valor());
                printf("%23s\t      ", nueva_fecha.get_fecha().c_str());
                printf("%10.2f\t \t", recorre_saldos_pendientes->get_valor());
                printf("\n\n");

                if(recorre_saldos_iniciales->get_siguiente() == nullptr){
                    return;
                }

                recorre_saldos_iniciales = recorre_saldos_iniciales->get_siguiente();
                recorre_intereses = recorre_intereses->get_siguiente();
                recorre_capitales = recorre_capitales->get_siguiente();
                recorre_cuotas_fijas = recorre_cuotas_fijas->get_siguiente();
                recorre_saldos_pendientes = recorre_saldos_pendientes->get_siguiente();
                recorre_fechas_pagos = recorre_fechas_pagos->get_siguiente();
                contador++;

                recursiva_tabla(recursiva_tabla);
            }
        };
        recursiva_tabla(recursiva_tabla);
    }
    else{


    }



}
