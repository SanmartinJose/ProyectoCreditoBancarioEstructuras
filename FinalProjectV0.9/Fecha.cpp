#include "Fecha.h"
#include "utilities.h"
Fecha::Fecha(){

}

Fecha::Fecha(int nuevo_diaSemana,int nuevo_dia, int nuevo_mes, int nuevo_ano){
    diaSemana=nuevo_diaSemana;
    dia = nuevo_dia;
    mes = nuevo_mes;
    ano = nuevo_ano;
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAno(){
    return ano;
}
int Fecha::getDiaSemana(){
    return diaSemana;
}

void Fecha::setDia(int nuevo_dia){
    dia = nuevo_dia;
}

void Fecha::setMes(int nuevo_mes){
    mes = nuevo_mes;
}

void Fecha::setAno(int nuevo_ano){
    ano = nuevo_ano;
}
void Fecha::setDiaSemana(int nuevo_diaSemana){
    diaSemana=nuevo_diaSemana;
}
void Fecha::avanzarDia(Fecha* fecha){
    int dia = fecha->getDia();
    int mes = fecha->getMes();
    int ano = fecha->getAno();

    int diasEnElMes = diasEnMes(mes, ano);

    if (dia = diasEnElMes) {
        if (mes == 12) {
            dia = 1;
            mes = 1;
            ano++;
        } else {
            dia = 1;
            mes++;        }
    } else {
        dia++;
    }

    fecha->setDia(dia);
    fecha->setMes(mes);
    fecha->setAno(ano);
}
void Fecha::generarFechasRecursivo(Fecha* fecha, int numFechas, std::vector<Fecha>& fechasGeneradas) {
    if (numFechas <= 0) {
        return;
    }

    int diaSemana = fecha->getDiaSemana();
    if (diaSemana == 6) { //
        avanzarDia(fecha);
    } else if (diaSemana == 7) {
        avanzarDia(fecha);
        avanzarDia(fecha);
    }

    fechasGeneradas.push_back(*fecha);
    generarFechasRecursivo(fecha, numFechas - 1, fechasGeneradas);
}


