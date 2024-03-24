/***********************************************************************
 UFA - ESPE
 * Module:  ListaDoble.h
 * Author: Benavidez Ruben, Sanmartin Jose
 * Modified:
 * Purpose: Declaracion de clase ListaDoble
 *************************************s**********************************/
#include "Fecha.h"

auto validar_festividad = [](int& mes_a_validar, int& dia_a_validar, int& dia_semana_a_validar, int& ano_a_validar){
    if(ano_a_validar == 2023){
        if(mes_a_validar == 12 && dia_a_validar == 25 && dia_semana_a_validar == 1){ //navidad
            dia_semana_a_validar = 2;
            dia_a_validar = 26;
        }
    }else if(ano_a_validar == 2024){
        if(mes_a_validar == 1 && dia_a_validar == 1 && dia_semana_a_validar == 1){ //ano nuevo
            dia_semana_a_validar = 2;
            dia_a_validar = 2;
        }else if((mes_a_validar == 2 && dia_a_validar == 12 && dia_semana_a_validar == 1) || //carnaval
                 (mes_a_validar == 2 && dia_a_validar == 13 && dia_semana_a_validar == 2)){
            dia_semana_a_validar = 3;
            dia_a_validar = 14;
        }else if(mes_a_validar == 3 && dia_a_validar == 29 && dia_semana_a_validar == 5){ //viernes santo
            dia_semana_a_validar = 1;
            dia_a_validar = 1;
            mes_a_validar = 4;
        }else if(mes_a_validar == 5 && dia_a_validar == 3 && dia_semana_a_validar == 5){ //dia del trabajo
            dia_semana_a_validar = 1;
            dia_a_validar = 6;
        }else if(mes_a_validar == 5 && dia_a_validar == 24 && dia_semana_a_validar == 5){ //batalla de pichincha
            dia_semana_a_validar = 1;
            dia_a_validar = 27;
        }else if(mes_a_validar == 8 && dia_a_validar == 9 && dia_semana_a_validar == 5){ //primer grito de independencia
            dia_semana_a_validar = 1;
            dia_a_validar = 12;
        }else if(mes_a_validar == 10 && dia_a_validar == 11 && dia_semana_a_validar == 5){ //independencia de guayaquil
            dia_semana_a_validar = 1;
            dia_a_validar = 14;
        }else if((mes_a_validar == 11 && dia_a_validar == 1 && dia_semana_a_validar == 5) ||
                 (mes_a_validar == 11 && dia_a_validar == 4 && dia_semana_a_validar == 1)){ //dia difuntos E independencia de cuenca
            dia_semana_a_validar = 2;
            dia_a_validar = 5;
        }else if(mes_a_validar == 12 && dia_a_validar == 25 && dia_semana_a_validar == 3){ //navidad
            dia_semana_a_validar = 4;
            dia_a_validar = 26;
        }
    }else if(ano_a_validar == 2025){
        if(mes_a_validar == 1 && dia_a_validar == 1 && dia_semana_a_validar == 3){ //ano nuevo
            dia_semana_a_validar = 4;
            dia_a_validar = 2;
        }else if((mes_a_validar == 3 && dia_a_validar == 3 && dia_semana_a_validar == 1) || //carnaval
                 (mes_a_validar == 3 && dia_a_validar == 4 && dia_semana_a_validar == 2)){
            dia_semana_a_validar = 5;
            dia_a_validar = 3;
        }else if(mes_a_validar == 4 && dia_a_validar == 18 && dia_semana_a_validar == 5){ //viernes santo
            dia_semana_a_validar = 1;
            dia_a_validar = 21;
        }else if(mes_a_validar == 5 && dia_a_validar == 2 && dia_semana_a_validar == 5){ //dia del trabajo
            dia_semana_a_validar = 1;
            dia_a_validar = 5;
        }else if(mes_a_validar == 5 && dia_a_validar == 23 && dia_semana_a_validar == 5){ //batalla de pichincha
            dia_semana_a_validar = 1;
            dia_a_validar = 26;
        }else if(mes_a_validar == 8 && dia_a_validar == 11 && dia_semana_a_validar == 1){ //primer grito de independencia
            dia_semana_a_validar = 2;
            dia_a_validar = 12;
        }else if(mes_a_validar == 10 && dia_a_validar == 10 && dia_semana_a_validar == 5){ //independencia de guayaquil
            dia_semana_a_validar = 1;
            dia_a_validar = 13;
        }else if((mes_a_validar == 11 && dia_a_validar == 3 && dia_semana_a_validar == 1) ||
                 (mes_a_validar == 11 && dia_a_validar == 4 && dia_semana_a_validar == 2)){ //dia difuntos E independencia de cuenca
            dia_semana_a_validar = 3;
            dia_a_validar = 5;
        }else if(mes_a_validar == 12 && dia_a_validar == 25 && dia_semana_a_validar == 4){ //navidad
            dia_semana_a_validar = 5;
            dia_a_validar = 26;
        }
    }

    //2025

};

auto escribir_fecha = [](int d, int m, int a, int ds){
    std::string dia_semana;
    if(ds == 1){
        dia_semana = "Lunes";
    }else if(ds == 2){
        dia_semana = "Martes";
    }else if(ds == 3){
        dia_semana = "Miercoles";
    }else if(ds == 4){
        dia_semana = "Jueves";
    }else if(ds == 5){
        dia_semana = "Viernes";
    }else if(ds == 6){
        dia_semana = "Sabado";
    }else if(ds == 7){
        dia_semana = "Domingo";
    }
    std::string strD = std::to_string(d);
    std::string strM = std::to_string(m);
    std::string strA = std::to_string(a);
    std::string resultado = dia_semana + " " + strD + "/" + strM + "/" + strA;
    return resultado;
};

Fecha::Fecha(){

}

Fecha::Fecha(int nuevo_dia, int nuevo_mes, int nuevo_ano, int nuevo_num_dia_semana){
    int cont_dias = -1;
    nuevo_num_dia_semana = nuevo_num_dia_semana - 1;
    if(nuevo_ano % 4 == 0){
        //MES ENERO
        if(nuevo_mes == 1){ //Dom(nuevo_dia) = [1-31]
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            if(cont_dias == 30){
                nuevo_dia = nuevo_dia - 1;
            }else{
                nuevo_dia = 1;
                while(nuevo_dia <= 29){
                    if(nuevo_num_dia_semana == 7){
                        nuevo_num_dia_semana = 1;
                    }else{
                        nuevo_num_dia_semana++;
                    }
                    nuevo_dia++;
                    cont_dias++;
                    if(cont_dias == 30){
                        nuevo_dia = nuevo_dia - 1;
                        nuevo_mes = 2;
                        break;
                    }
                }
                if(cont_dias == 29){
                    nuevo_dia = 1;
                    nuevo_mes = 3;
                    if(nuevo_num_dia_semana == 7){
                        nuevo_num_dia_semana = 1;
                    }else{
                        nuevo_num_dia_semana++;
                    }
                }
            }
            auto validar_finde = [&](){
                if(nuevo_dia == 31 && nuevo_num_dia_semana == 6 && nuevo_mes == 1){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 2;
                    nuevo_mes = 2;
                }else if(nuevo_dia == 31 && nuevo_num_dia_semana == 7 && nuevo_mes == 1){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 1;
                    nuevo_mes = 2;
                }else if(nuevo_dia == 28 && nuevo_num_dia_semana == 6 && nuevo_mes == 2){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 1;
                    nuevo_mes = 3;
                }else if(nuevo_dia == 29 && nuevo_num_dia_semana == 6 && nuevo_mes == 2){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 2;
                    nuevo_mes = 3;
                }else if(nuevo_dia == 29 && nuevo_num_dia_semana == 7 && nuevo_mes == 2){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 1;
                    nuevo_mes = 3;
                }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                }
            };
            validar_finde();
        }



        //MES FEBRERO
        else if(nuevo_mes == 2){ //Dom(nuevo_dia) = [1-29]
            while(nuevo_dia <= 29){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            nuevo_dia = 1;
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
                if(cont_dias == 30){
                    nuevo_dia = nuevo_dia - 1;
                    nuevo_mes = 3;
                    break;
                }
            }
            auto validar_finde = [&](){
                if(nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    nuevo_dia = 1;
                    nuevo_mes = 4;
                    nuevo_num_dia_semana = 1;
                }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                }
            };
            validar_finde();


            //MESES DE 31 DIAS
        }else if(nuevo_mes == 3 || nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 8 ||
                 nuevo_mes == 10 || nuevo_mes == 12){
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            if(cont_dias == 30){
                nuevo_dia = nuevo_dia - 1;
            }else{
                nuevo_dia = 1;
                while(nuevo_dia <= 30){
                    if(nuevo_num_dia_semana == 7){
                        nuevo_num_dia_semana = 1;
                    }else{
                        nuevo_num_dia_semana++;
                    }
                    nuevo_dia++;
                    cont_dias++;
                    if(cont_dias == 30){
                        nuevo_dia = nuevo_dia - 1;
                        if(nuevo_mes == 12){
                            nuevo_mes = 1;
                            nuevo_ano++;
                        }else{
                            nuevo_mes++;
                        }
                        break;
                    }
                }
            }
            auto validar_finde = [&](){
                if((nuevo_mes == 3 || nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 8 || nuevo_mes == 10 || nuevo_mes == 12) && nuevo_dia == 31 && nuevo_num_dia_semana == 6){
                    if(nuevo_mes == 12){
                        nuevo_mes = 1;
                        nuevo_ano++;
                    }
                    else{
                        nuevo_mes++;
                    }
                    nuevo_dia = 2;
                    nuevo_num_dia_semana = 1;
                }else if((nuevo_mes == 3 || nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 8 ||
                 nuevo_mes == 10 || nuevo_mes == 12) && nuevo_dia == 31 && nuevo_num_dia_semana == 7){
                    if(nuevo_mes == 12){
                        nuevo_mes = 1;
                        nuevo_ano++;
                    }else{
                        nuevo_mes++;
                    }
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else if(nuevo_mes == 8 && nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    nuevo_mes++;
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else if((nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11)
                          && nuevo_dia == 29 && nuevo_num_dia_semana == 6){
                    nuevo_mes++;
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else if((nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11)
                          && nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    nuevo_mes++;
                    nuevo_dia = 2;
                    nuevo_num_dia_semana = 1;
                 }else if((nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11)
                          && nuevo_dia == 30 && nuevo_num_dia_semana == 7){
                    nuevo_mes++;
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                 }
            };
            validar_finde();

            //MESES 30 DIAS
        }else if(nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11){
            while(nuevo_dia <= 30){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            nuevo_dia = 1;
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
                if(cont_dias == 30){
                    nuevo_dia = nuevo_dia - 1;
                    nuevo_mes++;
                    break;
                }
            }
            auto validar_finde = [&](){
                if((nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 10 || nuevo_mes == 12) &&
                   nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    if(nuevo_mes == 12){
                        nuevo_mes = 1;
                        nuevo_ano++;
                    }
                    else{
                        nuevo_mes++;
                    }
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                }
            };
            validar_finde();
        }



    }else{ //NO BISIESTO
        //MES ENERO
        if(nuevo_mes == 1){ //Dom(nuevo_dia) = [1-31]
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            if(cont_dias == 30){
                nuevo_dia = nuevo_dia - 1;
            }else{
                nuevo_dia = 1;
                while(nuevo_dia <= 28){
                    if(nuevo_num_dia_semana == 7){
                        nuevo_num_dia_semana = 1;
                    }else{
                        nuevo_num_dia_semana++;
                    }
                    nuevo_dia++;
                    cont_dias++;
                    if(cont_dias == 30){
                        nuevo_dia = nuevo_dia - 1;
                        nuevo_mes = 2;
                        break;
                    }
                }
                if(cont_dias == 28){
                    nuevo_dia = 2;
                    nuevo_mes = 3;
                    if(nuevo_num_dia_semana == 7){
                        nuevo_num_dia_semana = 2;
                    }else{
                        nuevo_num_dia_semana = nuevo_num_dia_semana + 2;
                    }
                }
            }
            auto validar_finde = [&](){
                if(nuevo_dia == 31 && nuevo_num_dia_semana == 6 && nuevo_mes == 1){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 2;
                    nuevo_mes = 2;
                }else if(nuevo_dia == 31 && nuevo_num_dia_semana == 7 && nuevo_mes == 1){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 1;
                    nuevo_mes = 2;
                }else if(nuevo_dia == 27 && nuevo_num_dia_semana == 6 && nuevo_mes == 2){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 1;
                    nuevo_mes = 3;
                }else if(nuevo_dia == 28 && nuevo_num_dia_semana == 6 && nuevo_mes == 2){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 2;
                    nuevo_mes = 3;
                }else if(nuevo_dia == 28 && nuevo_num_dia_semana == 7 && nuevo_mes == 2){
                    nuevo_num_dia_semana = 1;
                    nuevo_dia = 1;
                    nuevo_mes = 3;
                }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                }
            };
            validar_finde();
        }



        //MES FEBRERO
        else if(nuevo_mes == 2){ //Dom(nuevo_dia) = [1-29]
            while(nuevo_dia <= 28){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            nuevo_dia = 1;
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
                if(cont_dias == 30){
                    nuevo_dia = nuevo_dia - 1;
                    nuevo_mes = 3;
                    break;
                }
            }
            auto validar_finde = [&](){
                if(nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    nuevo_dia = 1;
                    nuevo_mes = 4;
                    nuevo_num_dia_semana = 1;
                }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                }
            };
            validar_finde();


            //MESES DE 31 DIAS
        }else if(nuevo_mes == 3 || nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 8 ||
                 nuevo_mes == 10 || nuevo_mes == 12){
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            if(cont_dias == 30){
                nuevo_dia = nuevo_dia - 1;
            }else{
                nuevo_dia = 1;
                while(nuevo_dia <= 30){
                    if(nuevo_num_dia_semana == 7){
                        nuevo_num_dia_semana = 1;
                    }else{
                        nuevo_num_dia_semana++;
                    }
                    nuevo_dia++;
                    cont_dias++;
                    if(cont_dias == 30){
                        nuevo_dia = nuevo_dia - 1;
                        if(nuevo_mes == 12){
                            nuevo_mes = 1;
                            nuevo_ano++;
                        }else{
                            nuevo_mes++;
                        }
                        break;
                    }
                }
            }
            auto validar_finde = [&](){
                if((nuevo_mes == 3 || nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 8 ||
                 nuevo_mes == 10 || nuevo_mes == 12) && nuevo_dia == 31 && nuevo_num_dia_semana == 6){
                    if(nuevo_mes == 12){
                        nuevo_mes = 1;
                        nuevo_ano++;
                    }
                    else{
                        nuevo_mes++;
                    }
                    nuevo_dia = 2;
                    nuevo_num_dia_semana = 1;
                }else if((nuevo_mes == 3 || nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 8 ||
                 nuevo_mes == 10 || nuevo_mes == 12) && nuevo_dia == 31 && nuevo_num_dia_semana == 7){
                    if(nuevo_mes == 12){
                        nuevo_mes = 1;
                        nuevo_ano++;
                    }else{
                        nuevo_mes++;
                    }
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else if(nuevo_mes == 8 && nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    nuevo_mes++;
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else if((nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11)
                          && nuevo_dia == 29 && nuevo_num_dia_semana == 6){
                    nuevo_mes++;
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else if((nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11)
                          && nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    nuevo_mes++;
                    nuevo_dia = 2;
                    nuevo_num_dia_semana = 1;
                 }else if((nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11)
                          && nuevo_dia == 30 && nuevo_num_dia_semana == 7){
                    nuevo_mes++;
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                 }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                 }
            };
            validar_finde();

            //MESES 30 DIAS
        }else if(nuevo_mes == 4 || nuevo_mes == 6 || nuevo_mes == 9 || nuevo_mes == 11){
            while(nuevo_dia <= 30){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
            }
            nuevo_dia = 1;
            while(nuevo_dia <= 31){
                if(nuevo_num_dia_semana == 7){
                    nuevo_num_dia_semana = 1;
                }else{
                    nuevo_num_dia_semana++;
                }
                nuevo_dia++;
                cont_dias++;
                if(cont_dias == 30){
                    nuevo_dia = nuevo_dia - 1;
                    nuevo_mes++;
                    break;
                }
            }
            auto validar_finde = [&](){
                if((nuevo_mes == 5 || nuevo_mes == 7 || nuevo_mes == 10 || nuevo_mes == 12) &&
                   nuevo_dia == 30 && nuevo_num_dia_semana == 6){
                    if(nuevo_mes == 12){
                        nuevo_mes = 1;
                        nuevo_ano++;
                    }
                    else{
                        nuevo_mes++;
                    }
                    nuevo_dia = 1;
                    nuevo_num_dia_semana = 1;
                }else{
                    if(nuevo_num_dia_semana == 6){
                        nuevo_dia = nuevo_dia + 2;
                        nuevo_num_dia_semana = 1;
                    }else if(nuevo_num_dia_semana == 7){
                        nuevo_dia = nuevo_dia + 1;
                        nuevo_num_dia_semana = 1;
                    }
                }
            };
            validar_finde();
        }
    }
    validar_festividad(nuevo_mes, nuevo_dia, nuevo_num_dia_semana, nuevo_ano);
    dia = nuevo_dia;
    mes = nuevo_mes;
    ano = nuevo_ano;
    num_dia_semana = nuevo_num_dia_semana;
    set_fecha();
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

std::string Fecha::get_fecha(){
    return fecha;
}

int Fecha::get_num_dia_semana(){
    return num_dia_semana;
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

void Fecha::set_num_dia_semana(int nuevo_num_dia_semana){
    num_dia_semana = nuevo_num_dia_semana;
}

void Fecha::set_fecha(){
    fecha = escribir_fecha(getDia(), getMes(), getAno(), get_num_dia_semana());
}
