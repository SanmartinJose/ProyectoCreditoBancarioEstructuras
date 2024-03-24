/***********************************************************************
 * Module:  Persona.h
 * Author:  DARÍO BENAVIDES
 * Modified: lunes, 29 de enero de 2024 09:42:41:PM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#pragma once
#include <iostream>

class Persona
{
public:
   Persona();
   Persona(std::string, std::string, std::string, std::string);
   ~Persona();
   void to_String();
    friend class Cuenta;
protected:
private:
   std::string nombres;
   std::string apellidos;
   std::string cedula;
   std::string id;
};

