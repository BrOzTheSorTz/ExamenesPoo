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
    int _matricula=0;
    double _cargaMaxima=0;
    std::string _tipo="";
    std::string _fechaMatriculacion ="";
    
public:
    Dron() = default;
    Dron ( int mat, double cargaMax, std::string tipo, std::string fechaMat );
    Dron(const Dron& orig);
    virtual ~Dron();
    void SetFechaMatriculacion(std::string _fechaMatriculacion);
    std::string GetFechaMatriculacion() const;
    void SetTipo(std::string _tipo);
    std::string GetTipo() const;
    void SetCargaMaxima(double _cargaMaxima);
    double GetCargaMaxima() const;
    void SetMatricula(int _matricula);
    int GetMatricula() const;
    virtual float GetCoste(int numDias);
};

#endif /* DRON_H */

