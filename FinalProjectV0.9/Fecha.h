#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <vector>
class Fecha{
private:
    int diaSemana;
    int dia;
    int mes;
    int ano;

public:
    Fecha();
    Fecha(int dias,int dia, int mes, int ano);
    int getDia();
    int getMes();
    int getAno();
    int getDiaSemana();
    void setDia(int);
    void setMes(int);
    void setAno(int);
    void setDiaSemana(int);
    void avanzarDia(Fecha*);
    void generarFechasRecursivo(Fecha* fecha, int numFechas, std::vector<Fecha>& fechasGeneradas);
    std::vector<Fecha> CrearFechas(Fecha fechaInicial, int numFechas);
};

#endif // FECHA_H_INCLUDED
