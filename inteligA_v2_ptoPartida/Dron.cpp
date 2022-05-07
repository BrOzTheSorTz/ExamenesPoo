/*
 * File:   Dron.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:48
 */

#include "Dron.h"

Dron::Dron ( int mat, double cargaMax, std::string tipo, std::string fechaMat ): _matricula ( mat ),
                                                                                 _cargaMaxima ( cargaMax ),
                                                                                 _tipo ( tipo ),
                                                                                 _fechaMatriculacion ( fechaMat )
{ }

Dron::Dron(const Dron& orig): _matricula ( orig._matricula )
                                , _cargaMaxima ( orig._cargaMaxima )
                                , _tipo ( orig._tipo )
                                , _fechaMatriculacion ( orig._fechaMatriculacion )
{}

Dron::~Dron()
{}

void Dron::SetFechaMatriculacion(std::string _fechaMatriculacion) {
    this->_fechaMatriculacion = _fechaMatriculacion;
}

std::string Dron::GetFechaMatriculacion() const {
    return _fechaMatriculacion;
}

void Dron::SetTipo(std::string _tipo) {
    this->_tipo = _tipo;
}

std::string Dron::GetTipo() const {
    return _tipo;
}

void Dron::SetCargaMaxima(double _cargaMaxima) {
    this->_cargaMaxima = _cargaMaxima;
}

double Dron::GetCargaMaxima() const {
    return _cargaMaxima;
}

void Dron::SetMatricula(int _matricula) {
    this->_matricula = _matricula;
}

int Dron::GetMatricula() const {
    return _matricula;
}

float Dron::GetCoste ( int numDias )
{
   return ( 20.0 * numDias );
}

