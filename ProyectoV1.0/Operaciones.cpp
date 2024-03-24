/***********************************************************************
 * Module:  Operaciones.cpp
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 10:13:57:PM
 * Purpose: Implementation of the class Operaciones
 ***********************************************************************/

#include "Operaciones.h"
#include "Nodo.cpp"
#include "ListaDoble.cpp"
#include <iomanip>
#include <fstream>
#include "Cuenta.h"
#include "Movimiento.h"
#include "Fecha.h"
#include <ctime>
#include <cmath>

extern double valorcuota=0;
extern ListaDoble<Fecha> fechasDePago;

auto es_valido = [](float& valor_prestamo){
    if(valor_prestamo < 50){
        return false;
    }else{
        return true;
    }
};

auto llenar_movimiento = [](auto&& llenar_movimiento, ListaDoble<Fecha>* fechas_pago,
                            ListaDoble<double>* saldos_iniciales,
                            ListaDoble<double>* saldos_pendientes,
                            ListaDoble<double>* intereses,
                            ListaDoble<double>* capitales,
                            ListaDoble<double>* cuotas_fijas,
                            double interes_mensual, double valor_prestamo_inicial, double valor_prestamo_final,
                            int n_cuotas, int contador, double cuota_fija, double capital,  double interes,
                            int dia, int mes, int ano, int dia_sem) -> void{

    if(contador <= n_cuotas){ //Iteramos el numero de cuotas porque esos seran los registros

        Fecha nueva_Fecha(dia, mes, ano, dia_sem);
        interes = interes_mensual*valor_prestamo_inicial;
        capital = cuota_fija-interes;

        cuotas_fijas->insertar_cola(cuota_fija); //la lista de cuotas fijas siempre tendra el mismo elemento cuota fija

        saldos_iniciales->insertar_cola(valor_prestamo_final); //los saldos iniciales seran los que son antes de hacer el pago

        valor_prestamo_final = valor_prestamo_inicial - capital;

        saldos_pendientes->insertar_cola(valor_prestamo_final); //los saldos finales seran los que resultan de haber pagado el capital

        intereses->insertar_cola(interes); //El interes por cada pago sera la tasa * saldo pendiente en este caso valor inicial

        capitales->insertar_cola(capital);

        fechas_pago->insertar_cola(nueva_Fecha);

        valor_prestamo_inicial = valor_prestamo_final;

        llenar_movimiento(llenar_movimiento,
                          fechas_pago, saldos_iniciales, saldos_pendientes, intereses, capitales, cuotas_fijas,
                          interes_mensual, valor_prestamo_inicial, valor_prestamo_final,
                          n_cuotas, contador + 1, cuota_fija, capital, interes,
                          nueva_Fecha.getDia(), nueva_Fecha.getMes(), nueva_Fecha.getAno(), nueva_Fecha.get_num_dia_semana());

    }
};

auto calcular_cuota_fija = [](double valor_prestamo, int n_cuotas, double tasa_interes){
    double numerador = valor_prestamo * tasa_interes;
    double potencia = pow(1+tasa_interes, (n_cuotas*(-1)));
    double denominador = 1 - potencia;
    double resultado = numerador/denominador;
    return resultado;
};


////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::generarPrestamo()
// Purpose:    Implementation of Operaciones::generarPrestamo()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Operaciones::generarPrestamo(Cuenta& cliente, double valor_prestamo, int n_cuotas, double tasa_interes)
{
    //VALIDAR SI YA HAY UN PRESTAMO

    std::time_t tiempoActual = std::time(nullptr);
    std::tm* fecha = std::localtime(&tiempoActual);
    if(es_valido){

        std::string tipo = "prestamo";

        ListaDoble<Fecha> fechas_pago;
        ListaDoble<double> saldos_iniciales;
        ListaDoble<double> saldos_pendientes;
        ListaDoble<double> intereses;
        ListaDoble<double> capitales;
        ListaDoble<double> cuotas_fijas;

        double cuota_fija = calcular_cuota_fija(valor_prestamo, n_cuotas, tasa_interes);
        valorcuota=cuota_fija;
        int dia = fecha->tm_mday;
        int mes = fecha->tm_mon + 1; // tm_mon comienza desde 0 (enero)
        int ano = fecha->tm_year + 1900; // tm_year cuenta desde 1900
        int dia_sem = fecha->tm_wday;

        Fecha fecha_emision = Fecha(dia, mes, ano, dia_sem);

        double valor = valor_prestamo;

        llenar_movimiento(llenar_movimiento, &fechas_pago, &saldos_iniciales, &saldos_pendientes, &intereses, &capitales, &cuotas_fijas,
                          tasa_interes, valor_prestamo, valor_prestamo, n_cuotas, 1, cuota_fija, 0, 0,
                          dia, mes, ano, dia_sem);
        Movimiento movimiento(tipo,
                              fechas_pago, saldos_iniciales, saldos_pendientes, intereses, capitales, cuotas_fijas,
                              fecha_emision, valor, n_cuotas);

        cliente.movimientos.insertar_cola(movimiento);

        /*fechasDePago=fechas_pago;*/
        //REvisar


    }else{
        printf("No podemos brindar prestamos de menos de 50$.");
    }


}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::generarTabla()
// Purpose:    Implementation of Operaciones::generarTabla()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Operaciones::generarTabla(Movimiento& movimiento, int contador, std::ofstream& archivo)
{
    if(movimiento.tipo == "prestamo"){
        ListaDoble<Fecha>* fechas_pago = &movimiento.fechasPago;
        ListaDoble<double>* saldos_iniciales = &movimiento.saldosIniciales;
        ListaDoble<double>* saldos_pendientes = &movimiento.saldosPendientes;
        ListaDoble<double>* intereses = &movimiento.intereses;
        ListaDoble<double>* capitales = &movimiento.capitales;
        ListaDoble<double>* cuotas_fijas = &movimiento.cuotasFijas;
        Nodo<Fecha>* recorre_fechas_pagos = fechas_pago->get_cabeza();
        Nodo<double>* recorre_saldos_iniciales = saldos_iniciales->get_cabeza();
        Nodo<double>* recorre_saldos_pendientes = saldos_pendientes->get_cabeza();
        Nodo<double>* recorre_intereses = intereses->get_cabeza();
        Nodo<double>* recorre_capitales = capitales->get_cabeza();
        Nodo<double>* recorre_cuotas_fijas = cuotas_fijas->get_cabeza();

        std::cout<<" N   Saldo Inicial   Interes   Capital   Cuota Fija         Fecha de pago            Saldo Final\n";
        std::cout<<"-----------------------------------------------------------------------------------------------\n";
        archivo<<" N   Saldo Inicial   Interes   Capital   Cuota Fija         Fecha de pago            Saldo Final\n";
        archivo<<"-----------------------------------------------------------------------------------------------\n";
        auto recursiva_tabla = [&](auto&& recursiva_tabla)->void{
            Fecha nueva_fecha = recorre_fechas_pagos->get_valor();
            if(contador <= movimiento.numero_registros){
                printf("%2d      ", contador);
                printf("%10.2f    ", recorre_saldos_iniciales->get_valor());
                printf("%6.2f   ", recorre_intereses->get_valor());
                printf("%7.2f      ", recorre_capitales->get_valor());
                printf("%7.2f ", recorre_cuotas_fijas->get_valor());
                printf("%23s\t      ", nueva_fecha.get_fecha().c_str());
                printf("%10.2f\t \t", recorre_saldos_pendientes->get_valor());
                printf("\n\n");
                archivo << std::setw(2) << contador << "      ";
                archivo << std::setw(10) << std::fixed << std::setprecision(2) << recorre_saldos_iniciales->get_valor() << "    ";
                archivo << std::setw(6) << std::fixed << std::setprecision(2) << recorre_intereses->get_valor() << "   ";
                archivo << std::setw(7) << std::fixed << std::setprecision(2) << recorre_capitales->get_valor() << "      ";
                archivo << std::setw(7) << std::fixed << std::setprecision(2) << recorre_cuotas_fijas->get_valor() << " ";
                archivo << std::setw(23) << nueva_fecha.get_fecha().c_str()<< "\t      ";
                archivo << std::setw(10) << std::fixed << std::setprecision(2) << recorre_saldos_pendientes->get_valor() << "\t \t";
                archivo << "\n\n";
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

}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::pagarCuota()
// Purpose:    Implementation of Operaciones::pagarCuota()
// Return:     void
////////////////////////////////////////////////////////////////////////


void Operaciones::pagarCuota(Cuenta& cuenta,Fecha fecha)
{

    double cuota=valorcuota;
    std::string tipo = "pago cuota";
    if (cuota==0){
        std::cout<<"\n La cuenta seleccionada no tiene un prestamo activo \n";
    }else{
        std::cout<<cuota;
        if(cuenta.saldo<cuota){
        std::cout<<"\n Saldo insuficiente para realizar el pago \n";
   }else{
        cuenta.saldo=cuenta.saldo-cuota;
        Movimiento movimiento(tipo,fecha,cuota);
        cuenta.movimientos.insertar_cabeza(movimiento);
        std::cout<<"\n Su nuevo saldo es: \n"<<cuenta.saldo;

        }
    }



}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::depositar()
// Purpose:    Implementation of Operaciones::depositar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Operaciones::depositar(Cuenta& cuenta,Fecha fecha,double monto)
{
   std::string tipo = "deposito";
   cuenta.saldo=cuenta.saldo+monto;
   Movimiento movimiento(tipo,fecha,monto);
   cuenta.movimientos.insertar_cabeza(movimiento);
   std::cout<<"\n Su nuevo saldo es: \n"<<cuenta.saldo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operaciones::retirar()
// Purpose:    Implementation of Operaciones::retirar()
// Return:     void
////////////////////////////////////////////////////////////////////////

bool Operaciones::retirar(Cuenta& cuenta,Fecha fecha,double monto)
{

   std::string tipo = "retiro";
   if (cuenta.saldo<monto){
        std::cout<<"\n Saldo insuficiente para el retiro, ingrese un monto valido \n"<<std::endl;
        return false;
   }else {
        cuenta.saldo=cuenta.saldo-monto;
        Movimiento movimiento(tipo,fecha,monto);
        cuenta.movimientos.insertar_cabeza(movimiento);
        std::cout<<"\n Su nuevo saldo es: \n"<<cuenta.saldo;
        return true;
   }

}
