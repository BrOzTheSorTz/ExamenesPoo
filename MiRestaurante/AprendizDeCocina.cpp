//
// Created by soria on 14/05/2022.
//

#include "AprendizDeCocina.h"

AprendizDeCocina::AprendizDeCocina(std::string dni, std::string nombre, int nivel)
:Persona(dni,nombre,"No Especificado"),nivel(nivel){

}

AprendizDeCocina::AprendizDeCocina(const AprendizDeCocina &orig) :Persona(orig),nivel(orig.nivel){

}

AprendizDeCocina::~AprendizDeCocina() {

}

int AprendizDeCocina::getNivel() const {
    return nivel;
}

void AprendizDeCocina::setNivel(int nivel) {
    AprendizDeCocina::nivel = nivel;
}

Plato *AprendizDeCocina::cocinarPlato(std::string nombre, float precio) {
    if(this->getNivel()<=2){
        throw ConocimientosInsuficientes("[Plato* AprendizDeCocina::cocinarPlato]No tiene nivel suficiente");

    }
    return new Plato(nombre,precio,"Sin especificar");
}
