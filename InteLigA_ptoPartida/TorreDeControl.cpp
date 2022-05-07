//
// Created by soria on 30/03/2022.
//

#include "TorreDeControl.h"
#include <stdexcept>

/**
 * @brief Inicializamos la variable estatica
 * @post Nos permite Asignar un ID
 */
int TorreDeControl::contador =0;

/**
 * @brief Constructor parametrizado
 * @param _area Area de control
 * @param _ubicacion Ubicacion de la torre de control
 */
TorreDeControl::TorreDeControl(double _area, std::string _ubicacion,Dron *d)
:areaDeControl(_area),ubicacion(_ubicacion){
    ++contador;
    idTorre=contador;


    drones[numDrones]=d;
    ++numDrones;

    for(int i=1;i<TAM;++i){
        drones[i]= nullptr;
    }
}
/**
 * @brief Constructor de copia
 * @param orig
 */
TorreDeControl::TorreDeControl(const TorreDeControl &orig) : areaDeControl(orig.areaDeControl),ubicacion(orig.ubicacion),numDrones(orig.numDrones){
    ++contador;
    idTorre=contador;

    for(int i=0;i<TAM;++i){
        if(i<orig.numDrones){
            drones[i] = orig.drones[i];
        }else{
            drones[i]= nullptr;
        }
    }
}
/**
 * @brief Constructor por defecto
 */
/*TorreDeControl::TorreDeControl() {
    ++contador;
    idTorre=contador;

    for(int i=0;i<TAM;++i){
        drones[i]= nullptr;
    }

}*/

double TorreDeControl::getAreaDeControl() const {
    return areaDeControl;
}

void TorreDeControl::setAreaDeControl(double areaDeControl) {
    if(areaDeControl<0){
        throw std::invalid_argument("El area de control no puede ser negativa!");
    }
    TorreDeControl::areaDeControl = areaDeControl;
}

const std::string &TorreDeControl::getUbicacion() const {
    return ubicacion;
}

void TorreDeControl::setUbicacion(const std::string &ubicacion) {
    TorreDeControl::ubicacion = ubicacion;
}

TorreDeControl::~TorreDeControl() {
    for(int i=0;i<TAM;++i){
        drones[i]=nullptr;
    }

}

TorreDeControl &TorreDeControl::addDron(Dron *d) {
    if(numDrones==TAM){
        throw std::length_error("No se pueden admitir a más drones");
    }
    drones[numDrones]=d;
    ++numDrones;
    return *this; ///<Para poder encadenar metodos
}

int TorreDeControl::getIdTorre() const {
    return idTorre;
}

Dron &TorreDeControl::obtenerDron(int cual) {
    if(cual<1 || cual >TAM){
        throw std::invalid_argument("No se puede acceder al dron porque introduciste un indice incorrecto");
    }
    return *drones[cual-1];
}

void TorreDeControl::eliminarDron(int cual) {

    if(cual<1 || cual >numDrones){
        throw std::invalid_argument("No se puede acceder al dron porque introduciste un indice incorrecto");
    }
    drones[cual-1]= nullptr;
    for(int i= cual-1;i<numDrones-1;++i){
        drones[i]=drones[i+1];
    }
    drones[numDrones-1]=nullptr; ///<Porque lo hemos asignado en el antepenultimo lugar

}

int TorreDeControl::getNumDrones() const {
    return numDrones;
}

Dron *TorreDeControl::mejorDron() {
    Dron* mejor= drones[0];///<Suponemos que el mejor es el primero


    for(int i=1;i<numDrones;++i){
        if(drones[i]->GetCargaMaxima()>mejor->GetCargaMaxima()){
            mejor=drones[i];
        }
    }
    return mejor;
}
