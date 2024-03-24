#pragma once

#include "Nodo_Arbol.h"
#include <iostream>

template <typename T>
class ArbolBinario {
private:
    Nodo_Arbol<T>* raiz;

    Nodo_Arbol<T>* insertar(Nodo_Arbol<T>* nodo, T valor, int opcion);
    void inorden(Nodo_Arbol<T>* nodo, int opcion);
    void preorden(Nodo_Arbol<T>* nodo, int opcion);
    void postorden(Nodo_Arbol<T>* nodo, int opcion);

    Nodo_Arbol<T>* encontrarMinimo(Nodo_Arbol<T>* nodo);
    Nodo_Arbol<T>* eliminar(Nodo_Arbol<T>* nodo, T valor, int opcion);

    int altura(Nodo_Arbol<T>* nodo);
    int balance(Nodo_Arbol<T>* nodo);

    Nodo_Arbol<T>* rotacionDerecha(Nodo_Arbol<T>* y);
    Nodo_Arbol<T>* rotacionIzquierda(Nodo_Arbol<T>* x);

    Nodo_Arbol<T>* balancear(Nodo_Arbol<T>* nodo);
    void imprimirNodo(Nodo_Arbol<T>* nodo, int espacio, int opcion);
    void imprimirArbol(Nodo_Arbol<T>* raiz, int espacio);

public:
    ArbolBinario();
    void insertar(T valor, int opcion);
    void recorridoInorden();
    void recorridoPreorden();
    void recorridoPostorden();
    void eliminar(T valor);
    void balancearArbol();
    void imprimirArbol(int opcion);
    T* buscar(std::string valor);
};


