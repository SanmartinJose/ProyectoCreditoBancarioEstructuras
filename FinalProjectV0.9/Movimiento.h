#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include "ListaDoble.h"
#include "Fecha.h"

class Movimiento{
private:
    ListaDoble<Fecha> fechas_pago;
    ListaDoble<double> saldos_iniciales;
    ListaDoble<double> saldos_pendientes;
    ListaDoble<double> intereses;
    ListaDoble<double> capitales;
    ListaDoble<double> cuotas_fijas;
    double monto_total;
    int n_registros;
public:
    Movimiento();
    Movimiento(ListaDoble<Fecha>&, ListaDoble<double>&, ListaDoble<double>&, ListaDoble<double>&, ListaDoble<double>&,
               ListaDoble<double>&, double, int);
    ListaDoble<Fecha>* getFechas_pago();
    ListaDoble<double>* getSaldos_iniciales();
    ListaDoble<double>* getSaldos_pendientes();
    ListaDoble<double>* getIntereses();
    ListaDoble<double>* getCapitales();
    ListaDoble<double>* getCuotas_fijas();
    double getMonto_total();
    int getNRegistros();
    void setFechas_pago(ListaDoble<Fecha>);
    void setSaldos_iniciales(ListaDoble<double>);
    void setSaldos_pendientes(ListaDoble<double>);
    void setIntereses(ListaDoble<double>);
    void setCapitales(ListaDoble<double>);
    void setCuotas_fijas(ListaDoble<double>);
    void setMonto_total(double);
    void setNRregistros(int);
};

#endif // MOVIMIENTO_H_INCLUDED
