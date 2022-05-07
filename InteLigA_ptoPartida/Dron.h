/* 
 * File:   Dron.h
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:48
 */

#ifndef DRON_H
#define DRON_H

#include <string>

class Dron {
    
    
private:
    int _matricula = 0;
    double _cargaMaxima = 0;
    std::string _tipo = "";
    std::string _fechaMatriculacion = "";
    
public:
    Dron() = default;

    Dron(int matricula, double cargaMaxima, const std::string &tipo, const std::string &fechaMatriculacion);

    Dron(const Dron& orig);
    virtual ~Dron();
    Dron& SetFechaMatriculacion(std::string _fechaMatriculacion);
    std::string GetFechaMatriculacion() const;
    Dron& SetTipo(std::string _tipo);
    std::string GetTipo() const;
    Dron& SetCargaMaxima(double _cargaMaxima);
    double GetCargaMaxima() const;
    Dron& SetMatricula(int _matricula);
    int GetMatricula() const;
};

#endif /* DRON_H */

