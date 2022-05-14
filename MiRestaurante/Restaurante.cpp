//
// Created by soria on 30/04/2022.
//

#include "Restaurante.h"

Restaurante::Restaurante(const std::string &nombre, const std::string &direccion, int aforoMaximo) : nombre(nombre),
                                                                                                     direccion(
                                                                                                             direccion),
                                                                                                     aforoMaximo(
                                                                                                             aforoMaximo) {
    for(int i=0;i<MAX;++i){
        cocineros[i]= nullptr;
    }

}

Restaurante::~Restaurante() {
    for(int i=0;i<MAX;++i){
        cocineros[i]= nullptr;
    }

}

const std::string &Restaurante::getNombre() const {
    return nombre;
}

void Restaurante::setNombre(const std::string &nombre) {
    Restaurante::nombre = nombre;
}

const std::string &Restaurante::getDireccion() const {
    return direccion;
}

void Restaurante::setDireccion(const std::string &direccion) {
    Restaurante::direccion = direccion;
}

int Restaurante::getAforoMaximo() const {
    return aforoMaximo;
}

void Restaurante::setAforoMaximo(int aforoMaximo) {
    Restaurante::aforoMaximo = aforoMaximo;
}

Restaurante &Restaurante::addCocinero( Persona* p) {

    cocineros[numCocineros++]= p;
    return *this;

}

Restaurante::Restaurante() :Restaurante("---","---",0){

}

Persona *Restaurante::cocineroActivo(std::string dni) {
    Persona *esteEs= nullptr;

    for(int i=0;i<this->getNumCocineros();++i){
        if(this->obtenerCocinero(i+1)->isActivo() && dni==this->obtenerCocinero(i+1)->getDni()){
            esteEs=this->obtenerCocinero(i+1);

        }
    }


    return esteEs;
}

int Restaurante::getNumCocineros() const {
    return numCocineros;
}

Persona *Restaurante::obtenerCocinero(int cual) {

    return cocineros[cual-1];
}
