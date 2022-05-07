/*
 * File:   Paquete.cpp
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 18:49
 */
#include <stdexcept>

#include "Paquete.h"

Paquete::Paquete(const Paquete& orig): _codRegistro ( orig._codRegistro )
                                       , _peso ( orig._peso )
                                       , _descripcion ( orig._descripcion ) {
}

Paquete::~Paquete() {
}

void Paquete::SetDescripcion(std::string _descripcion) {
    this->_descripcion = _descripcion;
}

std::string Paquete::GetDescripcion() const {
    return _descripcion;
}

void Paquete::SetPeso(double _peso) {
    this->_peso = _peso;
}

double Paquete::GetPeso() const {
    return _peso;
}

void Paquete::SetCodRegistro(int _codRegistro) {
    this->_codRegistro = _codRegistro;
}

int Paquete::GetCodRegistro() const {
    return _codRegistro;
}

Dron* Paquete::GetPortador() const{
    return _portador;
}

/**
 * @brief Asigna un dron para transportar el paquete
 * @param dron Dron que se quiere asignar
 * @pre dron tiene que tener una dirección de memoria de un objeto válido
 * @post El paquete queda asignado al dron que se pasa como parámetro
 * @throw std::invalid_argument Si el dron no tiene capacidad de cargar con el
 *        paquete
 */
void Paquete::SetPortador(Dron* dron) {
    if(_peso > dron->GetCargaMaxima()){
        throw std::invalid_argument ( "[Paquete::setDron]: el paquete supera la carga máxima del dron");
    }
    this->_portador = dron;
}