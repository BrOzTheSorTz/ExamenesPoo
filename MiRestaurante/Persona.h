//
// Created by soria on 30/04/2022.
//

#ifndef MIRESTAURANTE_PERSONA_H
#define MIRESTAURANTE_PERSONA_H


#include <string>
#include "Plato.h"

class Persona {
private:
    std::string dni ="";
    std::string nombre ="";
    std::string apellidos = "";
    int edad =0;
    bool activo = true;
public:
    Persona()=default;
    Persona(const std::string &dni, const std::string &nombre, const std::string &apellidos);
    virtual ~Persona();

    const std::string &getDni() const;
    const std::string &getNombre() const;
    void setNombre(const std::string &nombre);
    const std::string &getApellidos() const;
    void setApellidos(const std::string &apellidos);
    int getEdad() const;
    void setEdad(int edad);

    bool isActivo() const;

    void setActivo(bool activo);

    virtual Plato* cocinarPlato(std::string nombre,float precio)=0;
};


#endif //MIRESTAURANTE_PERSONA_H
