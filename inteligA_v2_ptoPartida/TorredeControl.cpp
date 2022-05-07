/*
 * File:   TorredeControl.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 19:21
 */
#include <stdexcept>

#include "TorredeControl.h"

TorreDeControl::TorreDeControl(int nIdTorre, double nAreaDeControl, std::string nUbicacion) : _idTorre(nIdTorre)
                                                                                              ,_areaDeControl(nAreaDeControl)
                                                                                              , _ubicacion(nUbicacion)
{
    for (int i = 0; i < MAX_DRONES; i++) {
        _drones[i] = nullptr;
    }
}

TorreDeControl::TorreDeControl(const TorreDeControl& orig) : _idTorre(orig._idTorre)
                                                            , _areaDeControl(orig._areaDeControl)
                                                            , _ubicacion(orig._ubicacion)
                                                            , _nDrones(orig._nDrones)
{
    for (int i = 0; i < MAX_DRONES; i++) {
        _drones[i] = orig._drones[i];
    }
}

TorreDeControl::~TorreDeControl() {
}

void TorreDeControl::SetUbicacion(std::string _ubicacion) {
    this->_ubicacion = _ubicacion;
}

std::string TorreDeControl::GetUbicacion() const {
    return _ubicacion;
}

void TorreDeControl::SetAreaDeControl(double _areaDeControl) {
   if ( _areaDeControl < 0 )
   {
      throw std::invalid_argument ( "El área no puede ser negativa" );
   }

   this->_areaDeControl = _areaDeControl;
}

double TorreDeControl::GetAreaDeControl() const {
    return _areaDeControl;
}

void TorreDeControl::SetIdTorre(int _idTorre) {
    this->_idTorre = _idTorre;
}

int TorreDeControl::GetIdTorre() const {
    return _idTorre;
}

int TorreDeControl::GetNdrones() const {
    return _nDrones;
}

Dron* TorreDeControl::GetDron(int cual) const {
   if ( ( cual < 0 ) || ( cual >= _nDrones ) )
   {
      throw std::invalid_argument ( "Índice fuera de rango" );
   }

   return _drones[cual];
}

void TorreDeControl::addDron(Dron* d) {
    if ( _nDrones == MAX_DRONES ) {
        throw std::length_error("No caben más drones");
    }
    _drones[_nDrones] = d;
    _nDrones++;
}

Dron* TorreDeControl::mejorDron() {
    int pos_mejor = 0;
    if (_nDrones > 1) {
        for (int i = 1; i < _nDrones; i++) {
            if (_drones[i]->GetCargaMaxima() > _drones[pos_mejor]->GetCargaMaxima()) {
                pos_mejor = i;
            }
        }
    }
    return _drones[pos_mejor];
}

Dron *TorreDeControl::buscaDron(float coste) {
    Dron* aux = nullptr;

    for(int i=0;i<this->GetNdrones();++i){
        if(this->GetDron(i)->GetCoste(1)<coste){
            coste=this->GetDron(i)->GetCoste(1);
            aux=this->GetDron(i);
        }
    }

    return aux;
}
