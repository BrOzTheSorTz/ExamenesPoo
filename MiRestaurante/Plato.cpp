//
// Created by soria on 14/05/2022.
//

#include "Plato.h"

Plato::Plato(std::string _nombre, float _precio, std::string _alergenos) :
nombre(_nombre),precio(_precio),alergenos(_alergenos){

}

Plato::~Plato() {

}

const std::string &Plato::getNombre() const {
    return nombre;
}

void Plato::setNombre(const std::string &nombre) {
    Plato::nombre = nombre;
}

float Plato::getPrecio() const {
    return precio;
}

void Plato::setPrecio(float precio) {
    Plato::precio = precio;
}

const std::string &Plato::getAlergenos() const {
    return alergenos;
}

void Plato::setAlergenos(const std::string &alergenos) {
    Plato::alergenos = alergenos;
}
