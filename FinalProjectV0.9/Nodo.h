/***********************************************************************
 UFA - ESPE
 * Module: Nodo.h
 * Author:
 * Modified:
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

template <typename T>
class Nodo
{
protected:
private:
    T valor;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;
public:
    Nodo(T _valor, Nodo<T>* _siguiente, Nodo<T>* _anterior)
    {
        valor = _valor;
        siguiente = _siguiente;
        anterior = _anterior;
    }

    Nodo(T _valor, Nodo<T>* _siguiente)
    {
        valor = _valor;
        siguiente = _siguiente;
    }

    Nodo()
    {
    }

    ~Nodo()
    {
       // TODO : implement
    }

    T get_valor()
    {
       return valor;
    }

    void set_valor(T new_valor)
    {
       valor = new_valor;
    }

    Nodo<T>* get_siguiente()
    {
       return siguiente;
    }

    void set_siguiente(Nodo<T>* new_siguiente)
    {
       siguiente = new_siguiente;
    }

    Nodo<T>* get_anterior()
    {
       return anterior;
    }

    void set_anterior(Nodo<T>* new_anterior)
    {
       anterior = new_anterior;
    }
};

#endif
