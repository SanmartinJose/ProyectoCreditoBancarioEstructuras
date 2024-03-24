#include <iostream>
#include "menuprincipal.cpp"
#include "Operar.h"
#include "validaciones.h"
#include "Cliente.h"
#include "ListaDoble.h"
#include "Fecha.h"

int main(){
   /* MenuPrincipal menu;
    menu.menuPrincipal();*/
    Fecha fecha;
    fecha=new Fecha(1,29,04,2023));
    fecha.avanzarDia(&FechaE);

    // Imprimimos la fecha después de avanzar
    std::cout << "Fecha después de avanzar un día: " << Fecha.getDia() << "/" << Fecha.getMes() << "/" << Fecha.getAno() << std::endl;
    return 0;


}
