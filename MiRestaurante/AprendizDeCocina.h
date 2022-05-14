//
// Created by soria on 14/05/2022.
//

#ifndef MIRESTAURANTE_APRENDIZDECOCINA_H
#define MIRESTAURANTE_APRENDIZDECOCINA_H

#include <string>
#include "Persona.h"
#include "ConocimientosInsuficientes.h"

class AprendizDeCocina :public Persona{
private:
    int nivel =0;

public:
    AprendizDeCocina(std::string dni, std::string nombre,int nivel);
    AprendizDeCocina(const AprendizDeCocina& orig);
    virtual ~AprendizDeCocina();

    int getNivel() const;
    void setNivel(int nivel);


    virtual Plato* cocinarPlato(std::string nombre,float precio) override;
};


#endif //MIRESTAURANTE_APRENDIZDECOCINA_H
