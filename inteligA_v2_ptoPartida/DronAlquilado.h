//
// Created by soria on 07/05/2022.
//

#ifndef POOFUSION_GIT_DRONALQUILADO_H
#define POOFUSION_GIT_DRONALQUILADO_H

#include "Dron.h"
#include <string>

class DronAlquilado:public Dron {
private:
    std::string Empresa ="---";
    float costeDiario =0;
public:
    DronAlquilado(const std::string &empresa, float costeDiario);
    DronAlquilado(const DronAlquilado &orig);
    virtual float GetCoste(int numDias) override;

};


#endif //POOFUSION_GIT_DRONALQUILADO_H
