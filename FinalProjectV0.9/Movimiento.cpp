#include "Movimiento.h"
#include "Fecha.h"

Movimiento::Movimiento(){

}

Movimiento::Movimiento(ListaDoble<Fecha>& nuevo_fechas_pago, ListaDoble<double>& nuevo_saldos_iniciales,
                       ListaDoble<double>& nuevo_saldos_pendientes, ListaDoble<double>& nuevo_intereses,
                       ListaDoble<double>& nuevo_capitales, ListaDoble<double>& nuevo_cuotas_fijas, double nuevo_monto_total, int nuevo_n_registros){
    fechas_pago = nuevo_fechas_pago;
    saldos_iniciales = nuevo_saldos_iniciales;
    saldos_pendientes = nuevo_saldos_pendientes;
    intereses = nuevo_intereses;
    capitales = nuevo_capitales;
    cuotas_fijas = nuevo_cuotas_fijas;
    monto_total = nuevo_monto_total;
    n_registros = nuevo_n_registros;
}

ListaDoble<Fecha>* Movimiento::getFechas_pago(){
    return &fechas_pago;
}

ListaDoble<double>* Movimiento::getSaldos_iniciales(){
    return &saldos_iniciales;
}

ListaDoble<double>* Movimiento::getSaldos_pendientes(){
    return &saldos_pendientes;
}

ListaDoble<double>* Movimiento::getIntereses(){
    return &intereses;
}

ListaDoble<double>* Movimiento::getCapitales(){
    return &capitales;
}

ListaDoble<double>* Movimiento::getCuotas_fijas(){
    return& cuotas_fijas;
}

double Movimiento::getMonto_total(){
    return monto_total;
}

int Movimiento::getNRegistros(){
    return n_registros;
}

void Movimiento::setFechas_pago(ListaDoble<Fecha> nuevo_fechas_pago){
    fechas_pago = nuevo_fechas_pago;
}

void Movimiento::setSaldos_iniciales(ListaDoble<double> nuevo_saldos_iniciales){
    saldos_iniciales = nuevo_saldos_iniciales;
}

void Movimiento::setSaldos_pendientes(ListaDoble<double> nuevo_saldos_pendientes){
     saldos_pendientes = nuevo_saldos_pendientes;
}

void Movimiento::setIntereses(ListaDoble<double> nuevo_intereses){
    intereses = nuevo_intereses;
}

void Movimiento::setCapitales(ListaDoble<double> nuevo_capitales){
    capitales = nuevo_capitales;
}

void Movimiento::setCuotas_fijas(ListaDoble<double> nuevo_cuotas_fijas){
    cuotas_fijas = nuevo_cuotas_fijas;
}

void Movimiento::setMonto_total(double nuevo_monto_total){
    monto_total = nuevo_monto_total;
}

void Movimiento::setNRregistros(int nuevo_n_registros){
    n_registros = nuevo_n_registros;
}
