/*
 * File:   Dron.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:48
 */

#include "Dron.h"

Dron::Dron(const Dron& orig): _matricula ( orig._matricula )
                                , _cargaMaxima ( orig._cargaMaxima )
                                , _tipo ( orig._tipo )
                                , _fechaMatriculacion ( orig._fechaMatriculacion )
{}

Dron::~Dron()
{}

Dron& Dron::SetFechaMatriculacion(std::string _fechaMatriculacion) {
    this->_fechaMatriculacion = _fechaMatriculacion;
    return *this;
}

std::string Dron::GetFechaMatriculacion() const {
    return _fechaMatriculacion;
}

Dron& Dron::SetTipo(std::string _tipo) {
    this->_tipo = _tipo;
    return *this;
}

std::string Dron::GetTipo() const {
    return _tipo;
}

Dron& Dron::SetCargaMaxima(double _cargaMaxima) {
    this->_cargaMaxima = _cargaMaxima;
    return *this;
}

double Dron::GetCargaMaxima() const {
    return _cargaMaxima;
}

Dron& Dron::SetMatricula(int _matricula) {
    this->_matricula = _matricula;
    return *this;
}

int Dron::GetMatricula() const {
    return _matricula;
}

Dron::Dron(int matricula, double cargaMaxima, const std::string &tipo, const std::string &fechaMatriculacion)
        : _matricula(matricula), _cargaMaxima(cargaMaxima), _tipo(tipo), _fechaMatriculacion(fechaMatriculacion) {}

