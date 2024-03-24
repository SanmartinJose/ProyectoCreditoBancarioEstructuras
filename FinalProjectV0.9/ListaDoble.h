/***********************************************************************
 UFA - ESPE
 * Module:  ListaDoble.h
 * Author:
 * Modified:
 * Purpose: Declaracion de clase ListaDoble
 *************************************s**********************************/
#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <iostream>
#include "Nodo.h"
#include "Fecha.h"

template <typename T>
class ListaDoble
{
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
public:
    ListaDoble(Nodo<T>* _cabeza){
        cabeza = _cabeza;
    }

    ListaDoble(){
        cabeza = nullptr;
    }

    Nodo<T>* get_cabeza(){
        return cabeza;
    }

    Nodo<T>* get_cola(){
        return cola;
    }

    void set_cabeza(Nodo<T>* nueva_cabeza){
        cabeza = nueva_cabeza;
    }

    void set_cola(Nodo<T>* nueva_cola){
        cola = nueva_cola;
    }

    /*void insertar_por_cabeza(T valor){
        Nodo<T>* nuevo_nodo;
        if(esta_vacia()){
            nuevo_nodo = new Nodo<T>(valor, nullptr, nullptr);
            cabeza = nuevo_nodo;
        }
        else{
            nuevo_nodo = new Nodo<T>(valor, nullptr, cola);
            cola->set_siguiente(nuevo_nodo);
        }
        cola = nuevo_nodo;
    }*/

    void insertar_cola(T valor){
        Nodo<T>* nuevo_nodo;
        if(esta_vacia()){
            nuevo_nodo = new Nodo<T>(valor, nullptr, nullptr);
            cabeza = nuevo_nodo;
        }
        else{
            nuevo_nodo = new Nodo<T>(valor, nullptr, cola);
            cola->set_siguiente(nuevo_nodo);
        }
        cola = nuevo_nodo;
    }

    void imprimir(){
        Nodo<T>* aux = cabeza;
        std::cout<<"\n";
        while(aux!=nullptr){
            printf("%.2f", aux->get_valor());
            printf("\t");
            //std::cout << aux->get_valor() << "\t";
            aux = aux->get_siguiente();
        }
    }

    void eliminar(T valor){
        Nodo<T>* aux = cabeza;
        while(aux!=nullptr){
            if(valor == aux->get_valor()){
                aux->get_anterior()->set_siguiente(aux->get_siguiente());
                aux->get_siguiente()->set_anterior(aux->get_anterior());
                break;
            }
            aux = aux->get_siguiente();
        }
    }

    void insertar_entre(T valor_busq, T valor){
        Nodo<T>* aux = cabeza;
        bool encontrado = false;
        while(aux!=nullptr){
            if(valor_busq == aux->get_valor()){
                encontrado = true;
                Nodo<T>* nuevo = new Nodo<T>(valor,aux->get_siguiente(), aux);
                aux->set_siguiente(nuevo);
                if(aux != cola){
                    aux->get_siguiente()->set_anterior(nuevo);
                }
                break;
            }
            aux = aux->get_siguiente();
        }
        if(encontrado==false)printf("\n No se encontro el dato en la lista");
    }

    bool esta_vacia(){
        return (cabeza == nullptr);
    }

};

#endif // LISTADOBLE_H_INCLUDED
