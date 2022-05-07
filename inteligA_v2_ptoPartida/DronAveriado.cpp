//
// Created by soria on 07/05/2022.
//

#include "DronAveriado.h"

float DronAveriado::GetCoste(int numDias) {


    return tasaReparacion*nivelAveria*numDias;
}

DronAveriado::DronAveriado(int _nivelAveria, float _tasaReparacion, int _tiempoPrevistoReparacion) :
Dron(),nivelAveria(_nivelAveria),tasaReparacion(_tasaReparacion),tiempoPrevistoReparacion(_tiempoPrevistoReparacion){

    if(_tiempoPrevistoReparacion<0){
        throw ErrorReparacion("[DronAveriado::DronAveriado()]El tiempo de reparacion no puede ser inferior a 0");
    }
}


DronAveriado::DronAveriado(const DronAveriado &orig):Dron(orig),nivelAveria(orig.nivelAveria),tasaReparacion(orig.tasaReparacion),tiempoPrevistoReparacion(orig.tiempoPrevistoReparacion) {



}
