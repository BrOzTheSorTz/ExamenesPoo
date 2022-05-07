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
                                       , _descripcion ( orig._descripcion )
                                       , portador(orig.portador){
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

/**
 * @brief Añadimos un dron portador de un paquete
 * @param d Dron portador
 * @throws invalid_argument Si la carga del dron no supera al peso del paquete
 */
void Paquete::addPortador(Dron &d) {

    if (_peso > d.GetCargaMaxima()) {
        throw std::invalid_argument("El dron seleccionado no puede soportar la carga del paquete");
    }
    portador = &d;

}

Dron &Paquete::verPortador() {
    return *portador;
}

Paquete::Paquete(int codRegistro, double peso, const std::string &descripcion) : _codRegistro(codRegistro), _peso(peso),
                                                                                 _descripcion(descripcion) {}

Dron *Paquete::getPortador() {
    return portador;
}

