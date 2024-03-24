#ifndef OPERAR_H_INCLUDED
#define OPERAR_H_INCLUDED
#include "Cliente.h"
#include "Movimiento.h"
#include "ListaDoble.h"
#include "Fecha.h"
#include <cmath>

auto es_valido = [](float& valor_prestamo){
    if(valor_prestamo < 1000){
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
                            int n_cuotas, int contador, double cuota_fija, double capital,  double interes) -> void{

    if(contador <= n_cuotas){ //Iteramos el numero de cuotas porque esos seran los registros

        interes = interes_mensual*valor_prestamo_inicial;
        capital = cuota_fija-interes; //los capitales seran las cuotas fijas menos los intereses


        cuotas_fijas->insertar_cola(cuota_fija); //la lista de cuotas fijas siempre tendra el mismo elemento cuota fija

        saldos_iniciales->insertar_cola(valor_prestamo_final); //los saldos iniciales seran los que son antes de hacer el pago

        saldos_pendientes->insertar_cola(valor_prestamo_inicial - capital); //los saldos finales seran los que resultan de haber pagado
                                                                                    //la cuota fija
        intereses->insertar_cola(interes); //El interes por cada pago sera la
                                                                            //tasa * saldo pendiente en este caso valor inicial

        capitales->insertar_cola(capital);

        //fechas_pago->insertar_cola(new Fecha); //esto hare luego xdd

        valor_prestamo_final = valor_prestamo_inicial - capital; //ahora mi final sera el inicial menos la cuota fija

        valor_prestamo_inicial = valor_prestamo_final; //mi inicial sera el mismo que mi final

        llenar_movimiento(llenar_movimiento,
                          fechas_pago, saldos_iniciales, saldos_pendientes, intereses, capitales, cuotas_fijas,
                          interes_mensual, valor_prestamo_inicial, valor_prestamo_final,
                          n_cuotas, contador + 1, cuota_fija, capital, interes);

    }
};

auto calcular_cuota_fija = [](double valor_prestamo, int n_cuotas, double tasa_interes){
    double numerador = valor_prestamo * tasa_interes;
    double potencia = pow(1+tasa_interes, (n_cuotas*(-1)));
    double denominador = 1 - potencia;
    double resultado = numerador/denominador;
    return resultado;
};

void generar_prestamo(Cliente&, double, int, double);

void generar_tabla_amortizacion(Movimiento&, int);

void generar_prestamo(Cliente& cliente, double valor_prestamo, int n_cuotas, double tasa_interes){
    if(es_valido){
        ListaDoble<Fecha> fechas_pago;
        ListaDoble<double> saldos_iniciales;
        ListaDoble<double> saldos_pendientes;
        ListaDoble<double> intereses;
        ListaDoble<double> capitales;
        ListaDoble<double> cuotas_fijas;

        double cuota_fija = calcular_cuota_fija(valor_prestamo, n_cuotas, tasa_interes);
        double numeroRedondeado = round(cuota_fija);

        llenar_movimiento(llenar_movimiento, &fechas_pago, &saldos_iniciales, &saldos_pendientes, &intereses, &capitales, &cuotas_fijas,
                          tasa_interes, valor_prestamo, valor_prestamo, n_cuotas, 1, cuota_fija, 0, 0);

        Movimiento movimiento(fechas_pago, saldos_iniciales, saldos_pendientes, intereses, capitales, cuotas_fijas, valor_prestamo,  n_cuotas);

        saldos_iniciales.imprimir();
        printf("\n");
        saldos_pendientes.imprimir();
        printf("\n");
        intereses.imprimir();
        printf("\n");
        capitales.imprimir();
        printf("\n");
        cuotas_fijas.imprimir();
        printf("\n");

        cliente.setMovimiento(movimiento);


    }else{
        printf("No podemos brindar prestamos de menos de 1000$.");
    }

}

void generar_tabla_amortizacion(Movimiento& movimiento, int contador){
    //ListaDoble<Fecha>* aux_fechas_pago;
    ListaDoble<double>* saldos_iniciales = movimiento.getSaldos_iniciales();
    ListaDoble<double>* saldos_pendientes = movimiento.getSaldos_pendientes();
    ListaDoble<double>* intereses = movimiento.getIntereses();
    ListaDoble<double>* capitales = movimiento.getCapitales();
    ListaDoble<double>* cuotas_fijas = movimiento.getCuotas_fijas();

    auto recursiva_tabla = [&](){
        saldos_iniciales->get_cabeza()->get_valor();
        saldos_pendientes->get_cabeza()->get_valor();
        intereses->get_cabeza()->get_valor();
        capitales->get_cabeza()->get_valor();
        cuotas_fijas->get_cabeza()->get_valor();
    };
}

#endif // OPERAR_H_INCLUDED
