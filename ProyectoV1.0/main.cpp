#include <iostream>
#include "Nodo.cpp"
#include "ListaDoble.cpp"
#include "Movimiento.h"
#include "Persona.h"
#include "Cuenta.h"
#include "Operaciones.h"
#include "windows.h"
#include "conio.h"
#include "validaciones.h"
#include "arbolBinario.cpp"
#include "Fecha.h"
#include <ctime>

void mostrarMenuPrincipal(int opcion) {
    system("cls");
    std::cout << "\n--------------SIMULACION PRESTACION BANCARIA-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Crear Cuenta\n";           //CREACION DE CUENTAS

    std::cout << (opcion == 2 ? "> " : "  ") << "Movimientos\n";            //UNA VEZ DENTRO MOSTRAR OTRO MENU
                                                                            //CON LAS OPCIONES DE OPERAR.H

    std::cout << (opcion == 3 ? "> " : "  ") << "Revisar Clientes\n";       //GENERARLO SEGUN HA SIDO INTRODUCIDO
                                                                            //PERO DAR OPCION PARA ORDENAR SEGUN DESEADO

    std::cout << (opcion == 4 ? "> " : "  ") << "Guia de Uso\n";            //MANDAR A LA GUIA
    std::cout << (opcion == 5 ? "> " : "  ") << "Realizar Backup\n";        //LOS BACKUPS
    std::cout << (opcion == 6 ? "> " : "  ") << "Restaurar\n";              //LOS BACKUPS
    std::cout << (opcion == 7 ? "> " : "  ") << "Desarrolladores\n";        //IMAGEN PIXEL
    std::cout << (opcion == 8 ? "> " : "  ") << "Salir\n";
}

void mostrarMenuOperaciones(int opcion){
    system("cls");
    std::cout << "\n--------------OPERE-----------------\n";
    std::cout << "\nSeleccione una opcion:\n\n";
    std::cout << (opcion == 1 ? "> " : "  ") << "Generar Prestamo\n";
    std::cout << (opcion == 2 ? "> " : "  ") << "Revisar Tabla de Amortizacion\n";
    std::cout << (opcion == 3 ? "> " : "  ") << "Pagar Cuota\n";
    std::cout << (opcion == 4 ? "> " : "  ") << "Depositar\n";
    std::cout << (opcion == 5 ? "> " : "  ") << "Retirar\n";
    std::cout << (opcion == 6 ? "> " : "  ") << "Volver atras\n";
}

int main()
{
    std::string nombres;
    std::string apellidos;
    std::string id;
    std::string cedula;
    std::string nCuenta;
    std::string cedula_cuenta;
    std::time_t fechaActual1 = std::time(nullptr);
    std::tm* fechaActualInfo = std::localtime(&fechaActual1);
    double monto;
    bool exito=false;
    Fecha fecha, fechaActual;
    fechaActual.setAno(fechaActualInfo->tm_mday);
    fechaActual.setMes(fechaActualInfo->tm_mon + 1);
    fechaActual.setDia(fechaActualInfo->tm_year + 1900);

    ArbolBinario<Cuenta> arbol_cuentas;
    ArbolBinario<Movimiento>* arbol_movimientos;

    ListaDoble<Persona> lista_personas;
    ListaDoble<Cuenta> lista_cuentas;

    Persona persona;
    Cuenta cuenta;
    Cuenta* cuenta_a_buscar;
    Movimiento movimiento;
    ListaDoble<Movimiento> movimientos;

    Nodo<Persona>* nueva_persona;
    Nodo<Cuenta>* nueva_cuenta;
    Movimiento* nuevo_movimiento;
    ListaDoble<Movimiento> nuevos_movimientos;

    Operaciones operar;
    double a, b, c, interes;

	int opcion = 1;
    char key;

    int opcion2 = 1;
    char key2;

    //CARGA DE LOS ARBOLES (QUE USEN LOS TXT)


    // Obtener el manejador de la consola
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);

    // Ocultar el cursor
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    do {                                                                    //PODRIAMOS USAR TAMBIEN UN CANCELAR QUE LO SAQUE DE UNA OPCION
        mostrarMenuPrincipal(opcion);
        key = _getch();

        switch (key) {
            case 72: // Flecha arriba
                if (opcion > 1) opcion--;
                break;
            case 80: // Flecha abajo
                if (opcion < 8) opcion++;
                break;
            case 13: // Enter
                if (opcion == 1) {

                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    cedula = ingresar_cedula("\nIngresa la cedula:");       //AÑADIR PARAMETRO PARA QUE VALIDE REPETICION (O SEA YA SE CREO)
                                                                            //EN ESTE CASO DEBE SER EL ARBOL PARA QUE HAGA LA BUSQUEDA
                                                                            //O BUSQUEDA HASH EN LISTAS

                    printf("\n");
                    nombres = ingresar_nombre("\nIngrese los nombres:");
                    printf("\n");
                    apellidos = ingresar_nombre("\nIngrese los apellidos:");
                    printf("\n\n");
                    id = generarEtiqueta();
                    printf("\n");

                    persona = Persona(nombres, apellidos, cedula, id);
                    nCuenta = generarNumeroSecuencialCuenta();

                    cuenta = Cuenta(persona, 0, nCuenta, nuevos_movimientos);

                    lista_cuentas.insertar_cabeza(cuenta);
                    arbol_cuentas.insertar(cuenta, 1);
                    arbol_cuentas.imprimirArbol(4);
                    //LLAMADA A LA INSERCION AL TXT DE CUENTAS

            		system("pause");

            		cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                } else if (opcion == 2) {

                    cursorInfo.bVisible = true;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                    do{
                        cedula_cuenta = ingresar_cedula("\nIngresa la cedula:\n");
                        cuenta_a_buscar = arbol_cuentas.buscar(cedula_cuenta);
                        if(cuenta_a_buscar == nullptr){printf("Cuenta no hallada, intente de nuevo.\n");}
                        system("pause");
                    }while(cuenta_a_buscar == nullptr);



                    opcion2 = 1;

                    do {
                        cursorInfo.bVisible = false;
                        SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                        mostrarMenuOperaciones(opcion2);
                        key2 = _getch();

                        switch (key2) {
                            case 72: // Flecha arriba
                                if (opcion2 > 1) opcion2--;
                                break;
                            case 80: // Flecha abajo
                                if (opcion2 < 6) opcion2++;
                                break;
                            case 13: // Enter
                                if (opcion2 == 1) {

                                    // Pedir valor 'a' hasta que cumpla con las condiciones
                                    do {
                                        a = ingresar_reales("Ingrese un nuevo prestamo entre (validos desde 50$): ");
                                        printf("\n");
                                    } while (a < 50);

                                    // Pedir valor 'b' hasta que cumpla con las condiciones
                                    do {
                                        b = ingresarPositivos("Ingrese el numero de cuotas mensuales a pagar (entre 6 a 48): ");
                                        printf("\n");
                                    } while (b < 6 || b > 48);

                                    // Pedir valor 'c' hasta que cumpla con las condiciones
                                    do {
                                        c = ingresar_decimal_positivo("Ingrese un numero entre 1% y 3% para el interes mensual: ");
                                        interes = c / 100;
                                        printf("\n");
                                    } while (c < 1 || c > 3);


                                    operar.generarPrestamo(cuenta, a, b, interes);
                                }
                                else if(opcion2 == 2){

                                    movimientos = cuenta.get_movimientos();
                                    system("pause");
                                    //operar.generarTabla(movimiento, 0,  );
                                }
                                else if(opcion2 == 3){
                                        operar.pagarCuota(cuenta, fechaActual);
                                        printf("\n");
                                        system("pause");



                                }
                                else if(opcion2 == 4){

                                    operar.depositar(cuenta, fechaActual, ingresar_reales("\nIngrese el valor a depositar: \n"));
                                    printf("\n");
                                    system("pause");



                                }
                                else if(opcion2 == 5){
                                    while(exito==false){
                                            exito=operar.retirar(cuenta, fechaActual, ingresar_reales("\nIngrese el valor a retirar: \n"));
                                            printf("\n");
                                            system("pause");
                                            printf("\n");
                                    }

                                }
                                else if(opcion2 == 6){
                                    system("cls");
                                    opcion2 = 7;
                                    break;
                                }
                        }
                    }while(opcion2 != 7);

            		system("pause");

            		cursorInfo.bVisible = false;
                    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

                } else if(opcion==3){
                    printf("\n");


            		system("pause");
                } else if(opcion==4){
                    printf("\n");

            		system("pause");
                } else if(opcion==5){
                    printf("\n");

            		system("pause");
                } else if(opcion==6){
                    printf("\n");

            		system("pause");
                }else if(opcion==7){
					printf("\n");

                    system("pause");
				}else if(opcion==8){
					system("cls");
   					std::cout << "Saliendo del programa." << std::endl;
   					exit(0);
				}
                break;
            default:
                break;
        }
    } while (true);

	system("pause");
	return 0;

}
