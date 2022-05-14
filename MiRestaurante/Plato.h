//
// Created by soria on 14/05/2022.
//

#ifndef MIRESTAURANTE_PLATO_H
#define MIRESTAURANTE_PLATO_H


#include <string>

class Plato {
private:
    std::string nombre ="--";
    float precio =0;
    std::string alergenos ="--";
public:
    Plato()=default;
    Plato(std::string _nombre,float _precio,std::string _alergenos);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    float getPrecio() const;

    void setPrecio(float precio);

    const std::string &getAlergenos() const;

    void setAlergenos(const std::string &alergenos);

    virtual ~Plato();

};


#endif //MIRESTAURANTE_PLATO_H
