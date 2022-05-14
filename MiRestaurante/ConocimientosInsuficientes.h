//
// Created by soria on 14/05/2022.
//

#ifndef MIRESTAURANTE_CONOCIMIENTOSINSUFICIENTES_H
#define MIRESTAURANTE_CONOCIMIENTOSINSUFICIENTES_H

#include <stdexcept>

class ConocimientosInsuficientes:public std::logic_error{
public:
    ConocimientosInsuficientes(std::string error="Ha ocurrido un error"): std::logic_error(error){};
    ConocimientosInsuficientes(const ConocimientosInsuficientes &orig): std::logic_error(orig){};
    virtual ~ConocimientosInsuficientes() noexcept=default;

};

#endif //MIRESTAURANTE_CONOCIMIENTOSINSUFICIENTES_H
