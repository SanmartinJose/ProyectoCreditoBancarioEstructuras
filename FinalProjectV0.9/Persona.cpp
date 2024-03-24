#include "Persona.h"

Persona::Persona(){

}

Persona::Persona(std::string nuevo_nombre, std::string nuevo_apellido, Fecha nuevo_fecha_nacimiento, std::string nuevo_cedula, std::string nuevo_correo, std::string nuevo_telefono){
    nombre = nuevo_nombre;
    apellido = nuevo_apellido;
    fecha_nacimiento = nuevo_fecha_nacimiento;
    cedula = nuevo_cedula;
    correo = nuevo_correo;
    telefono = nuevo_telefono;
}

std::string Persona::getNombre(){
    return nombre;
}

std::string Persona::getApellido(){
    return apellido;
}

Fecha Persona::getFechaNacimiento(){
    return fecha_nacimiento;
}

std::string Persona::getCedula(){
    return cedula;
}

std::string Persona::getCorreo(){
    return correo;
}

std::string Persona::getTelefono(){
    return telefono;
}

void Persona::setNombre(std::string nuevo_nombre){
    nombre = nuevo_nombre;
}

void Persona::setApellido(std::string nuevo_apellido){
    apellido = nuevo_apellido;
}

void Persona::setFechaNacimiento(Fecha nuevo_fecha_nacimiento){
    fecha_nacimiento = nuevo_fecha_nacimiento;
}

void Persona::setCedula(std::string nuevo_cedula){
    cedula = nuevo_cedula;
}

void Persona::setCorreo(std::string nuevo_correo){
    correo = nuevo_correo;
}

void Persona::setTelefono(std::string nuevo_telefono){
    telefono = nuevo_telefono;
}
