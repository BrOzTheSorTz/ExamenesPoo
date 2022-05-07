//
// Created by soria on 07/05/2022.
//

#ifndef POOFUSION_GIT_ERRORREPARACION_H
#define POOFUSION_GIT_ERRORREPARACION_H

#include <stdexcept>

class ErrorReparacion:public std::invalid_argument{
public:
    ErrorReparacion(std::string error ="Ha ocurrido un error!"):
    std::invalid_argument(error){};
    virtual ~ErrorReparacion() noexcept=default;//Tambien se puede poner igual a 0

};

#endif //POOFUSION_GIT_ERRORREPARACION_H
