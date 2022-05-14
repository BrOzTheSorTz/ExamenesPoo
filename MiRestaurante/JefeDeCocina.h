//
// Created by soria on 14/05/2022.
//

#ifndef MIRESTAURANTE_JEFEDECOCINA_H
#define MIRESTAURANTE_JEFEDECOCINA_H


#include <string>
#include "Persona.h"

class JefeDeCocina :public Persona{
private:
    int estrellasMichelin =0;
    std::string nombrePlatoEstrella ="---";

public:
    JefeDeCocina()=delete;//No me interesa
    JefeDeCocina(std::string dni,std::string nombre,int edad,int _estrellas,std::string nombrePlato);
    JefeDeCocina(const JefeDeCocina &orig);
    virtual ~JefeDeCocina();

    int getEstrellasMichelin() const;
    void setEstrellasMichelin(int estrellasMichelin);
    const std::string &getNombrePlatoEstrella() const;
    void setNombrePlatoEstrella(const std::string &nombrePlatoEstrella);

    virtual Plato* cocinarPlato(std::string nombre,float precio) override;
};


#endif //MIRESTAURANTE_JEFEDECOCINA_H
