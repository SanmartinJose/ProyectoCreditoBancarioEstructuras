#pragma once

#include <iostream>

class Fecha{
private:
    int dia;
    int mes;
    int ano;
    int num_dia_semana;
    std::string fecha;
public:
    Fecha();
    Fecha(int, int, int, int);
    int getDia();
    int getMes();
    int getAno();
    int get_num_dia_semana();
    std::string get_fecha();
    void setDia(int);
    void setMes(int);
    void setAno(int);
    void set_num_dia_semana(int);
    void set_fecha();
};

