//
// Created by soria on 30/04/2022.
//

#include "Persona.h"

Persona::Persona(const std::string &dni, const std::string &nombre, const std::string &apellidos) : dni(dni),
                                                                                                    nombre(nombre),
                                                                                                    apellidos(
                                                                                                            apellidos) {}

Persona::~Persona() {

}

const std::string &Persona::getDni() const {
    return dni;
}



const std::string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const std::string &nombre) {
    Persona::nombre = nombre;
}

const std::string &Persona::getApellidos() const {
    return apellidos;
}

void Persona::setApellidos(const std::string &apellidos) {
    Persona::apellidos = apellidos;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    Persona::edad = edad;
}

bool Persona::isActivo() const {
    return activo;
}

void Persona::setActivo(bool activo) {
    Persona::activo = activo;
}
