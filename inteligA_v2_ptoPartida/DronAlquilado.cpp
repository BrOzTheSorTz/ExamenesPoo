//
// Created by soria on 07/05/2022.
//

#include "DronAlquilado.h"

float DronAlquilado::GetCoste(int numDias) {


    return costeDiario*numDias ;
}

DronAlquilado::DronAlquilado(const std::string &empresa, float costeDiario) : Dron(),Empresa(empresa),
                                                                              costeDiario(costeDiario) {}

DronAlquilado::DronAlquilado(const DronAlquilado &orig) :Dron(orig),Empresa(orig.Empresa),costeDiario(orig.costeDiario){

}
