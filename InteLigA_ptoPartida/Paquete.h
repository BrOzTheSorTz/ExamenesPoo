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
    Dron *portador= nullptr;
    
public:
    Paquete() = default;
    Paquete(const Paquete& orig);

    Paquete(int codRegistro, double peso, const std::string &descripcion);

    void addPortador(Dron &d);
    Dron& verPortador();
    Dron* getPortador();
    virtual ~Paquete();
    void SetDescripcion(std::string _descripcion);
    std::string GetDescripcion() const;
    void SetPeso(double _peso);
    double GetPeso() const;
    void SetCodRegistro(int _codRegistro);
    int GetCodRegistro() const;
    ///@todo método para desvincular un dron de un paquete para cuando queremos eliminarlo

};

#endif /* PAQUETE_H */

