#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "iostream"
#include "Fecha.h"

class Persona{
private:
    std::string nombre;
    std::string apellido;
    Fecha fecha_nacimiento;
    std::string cedula;
    std::string correo;
    std::string telefono;
public:
    Persona();
    Persona(std::string, std::string, Fecha, std::string, std::string, std::string);
    std::string getNombre();
    std::string getApellido();
    Fecha getFechaNacimiento();
    std::string getCedula();
    std::string getCorreo();
    std::string getTelefono();
    void setNombre(std::string);
    void setApellido(std::string);
    void setFechaNacimiento(Fecha);
    void setCedula(std::string);
    void setCorreo(std::string);
    void setTelefono(std::string);
};

#endif // PERSONA_H_INCLUDED
