#include "menuprincipal.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include "utilities.cpp"

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13
using namespace std;


int MenuPrincipal::menu(const char *titulo,const char *opciones[], int n){
int opcionSeleccionada=1;
int tecla;


do{
system("cls");
gotoxy(5,3+opcionSeleccionada);cout<<"--->";
gotoxy(15,2); cout<<titulo;
for(int i =0;i<n;i++){
    gotoxy(10,4+i);
    cout<<i+1<<") "<<opciones[i];
    }
    do{
        tecla = getch();

    }while(tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

    switch(tecla){
        case TECLA_ARRIBA:
        opcionSeleccionada--;
        if(opcionSeleccionada==0){
            opcionSeleccionada=n;
        }
            break;
        case TECLA_ABAJO:
        opcionSeleccionada++;
        if(opcionSeleccionada>n){
            opcionSeleccionada=1;
        }
            break;
        case ENTER:
        repite=false;
            break;
    }

}while(repite);


return opcionSeleccionada;
}

void MenuPrincipal::menuPrincipal(){
    const char *titulo = "Menu Principal";
    const char *opciones[]={"Nuevo prestamo","Generar Tabla","Multiplicar","dividir","salir"};
    int n =5; //numero de opciones
    do{
        opcion=menu(titulo,opciones,n);



    }while(repite);
}
