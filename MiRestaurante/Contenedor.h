//
// Created by soria on 30/04/2022.
//

#ifndef MIRESTAURANTE_CONTENEDOR_H
#define MIRESTAURANTE_CONTENEDOR_H

#include <stdexcept>

/**
 * Contenedor genérico
 */
 template<typename T>
 class Contenedor{
 public:
     static const int MAX=100;
 private:
     T elementos[MAX];
     int numElementos;
     int tamMaximo =MAX; ///< Creamos esta variable para el caso de que cambie el tamanio maximo
     T vacio ;///< Valor que se utiliza para las posiciones vacias

 public:
     Contenedor(int tamMaximo,T vVacio =T());
     Contenedor(const Contenedor &orig);
     virtual ~Contenedor();
     Contenedor& addElemento(const T& nE);



 };

 template <typename T>
 Contenedor<T>::Contenedor(int tamMaximo, T vVacio): tamMaximo(tamMaximo),vacio(vVacio){
     for(int i=0;i<tamMaximo;++i){
         elementos[i]= vacio;
     }
 }

 template<typename T>
 Contenedor<T>::Contenedor(const Contenedor &orig):numElementos(orig.numElementos),
 tamMaximo(orig.tamMaximo),vacio(orig.vacio){
     for(int i=0;i<numElementos;++i){
         elementos[i]=orig.elementos[i];
     }
     for(int i=numElementos;i<tamMaximo;++i){
         elementos[i]=vacio;
     }
 }
/**
* Destructor
*/
template<typename T>
Contenedor<T>::~Contenedor ()
{ }


/**
 * Añade un nuevo elemento al contenedor
 * @param nE Nuevo elemento
 * @throw std::length_error Si se ha alcanzado el máximo número de elementos
 *        almacenables
 * @return Una referencia al propio contenedor, para permitir encadenar llamadas
 *         a métodos
 */
template<typename T>
Contenedor<T>& Contenedor<T>::addElemento ( const T& nE ) {
    if (numElementos == tamMaximo) {
        throw std::length_error("[Contenedor::addElemento]: espacio insuficiente");
    }

    elementos[numElementos] = nE;
    numElementos++;

    return *this;
}


#endif //MIRESTAURANTE_CONTENEDOR_H
