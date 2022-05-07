/* 
 * File:   Paquete.h
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:49
 */

#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>
#include "Dron.h"

class Paquete {
private:
    int _codRegistro = 0;
    double _peso = 0;
    std::string _descripcion = "";
    Dron* _portador = nullptr;
public:
    Paquete() = default;
    Paquete(const Paquete& orig);
    virtual ~Paquete();
    void SetDescripcion(std::string _descripcion);
    std::string GetDescripcion() const;
    void SetPeso(double _peso);
    double GetPeso() const;
    void SetCodRegistro(int _codRegistro);
    int GetCodRegistro() const;
    Dron* GetPortador() const;
    void SetPortador(Dron* dron);
};

#endif /* PAQUETE_H */

