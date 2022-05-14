//
// Created by soria on 14/05/2022.
//

#include "JefeDeCocina.h"

JefeDeCocina::JefeDeCocina(std::string dni,std::string nombre,int edad,int _estrellas, std::string nombrePlato) :
        Persona(dni,nombre,"No especificado"),estrellasMichelin(_estrellas),nombrePlatoEstrella(nombrePlato){

}

JefeDeCocina::~JefeDeCocina() {

}

JefeDeCocina::JefeDeCocina(const JefeDeCocina &orig) : Persona(orig),estrellasMichelin(orig.estrellasMichelin),nombrePlatoEstrella(orig.nombrePlatoEstrella){

}

int JefeDeCocina::getEstrellasMichelin() const {
    return estrellasMichelin;
}

void JefeDeCocina::setEstrellasMichelin(int estrellasMichelin) {
    JefeDeCocina::estrellasMichelin = estrellasMichelin;
}

const std::string &JefeDeCocina::getNombrePlatoEstrella() const {
    return nombrePlatoEstrella;
}

void JefeDeCocina::setNombrePlatoEstrella(const std::string &nombrePlatoEstrella) {
    JefeDeCocina::nombrePlatoEstrella = nombrePlatoEstrella;
}

Plato *JefeDeCocina::cocinarPlato(std::string nombre, float precio) {
    float auxPrecio =precio;
    if(nombre == this->getNombrePlatoEstrella()){
        auxPrecio=precio*1.2;
    }

    return new Plato(nombre,auxPrecio,"Sin especificar");
}
