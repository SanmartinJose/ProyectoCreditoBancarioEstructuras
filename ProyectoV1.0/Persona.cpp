/***********************************************************************
 * Module:  Persona.cpp
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 09:42:41:PM
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
}

Persona::Persona(std::string _nombres, std::string _apellidos, std::string _cedula, std::string _id){
    nombres =  _nombres;
    apellidos = _apellidos;
    cedula = _cedula;
    id = _id;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::~Persona()
{
   // TODO : implement
}

void Persona::to_String(){
    printf("PRUEBA\n");
}

