//
// Created by soria on 07/05/2022.
//

#ifndef POOFUSION_GIT_DRONAVERIADO_H
#define POOFUSION_GIT_DRONAVERIADO_H

#include "Dron.h"
#include "ErrorReparacion.h"

class DronAveriado: public Dron{
private:
    int nivelAveria =0;
    float tasaReparacion =0;
    int tiempoPrevistoReparacion =0;

public:
    DronAveriado(int _nivelAveria,float _tasaReparacion,int _tiempoPrevistoReparacion);
    ///En el constructor de copia debemos llamar al constructor de copia
    ///de la clase padre,cuidado!!
    DronAveriado(const DronAveriado &orig);
    virtual float GetCoste(int numDias) override;

};


#endif //POOFUSION_GIT_DRONAVERIADO_H
