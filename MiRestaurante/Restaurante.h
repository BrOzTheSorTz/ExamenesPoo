//
// Created by soria on 30/04/2022.
//

#ifndef MIRESTAURANTE_RESTAURANTE_H
#define MIRESTAURANTE_RESTAURANTE_H

#include <string>
#include "Persona.h"
#include "Contenedor.h"

class Restaurante{
public:
    static const int MAX=10;
private:
    std::string nombre ="";
    std::string direccion ="";
    int aforoMaximo =0;

    Persona* cocineros[MAX];
    int numCocineros =0;


public:
    Restaurante();
    Restaurante(const std::string &nombre, const std::string &direccion, int aforoMaximo);
    virtual ~Restaurante();
    Restaurante& addCocinero (Persona* p);
    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    const std::string &getDireccion() const;
    void setDireccion(const std::string &direccion);
    int getAforoMaximo() const;
    void setAforoMaximo(int aforoMaximo);
    Persona* obtenerCocinero(int cual);

    int getNumCocineros() const;

    Persona* cocineroActivo(std::string dni);


};


#endif //MIRESTAURANTE_RESTAURANTE_H
