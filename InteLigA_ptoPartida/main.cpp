/**
 * @file main.cpp
 * @author jjurado
 *
 * @date 29 de marzo de 2021, 8:30
 */

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "Dron.h"
#include "Paquete.h"
#include "TorreDeControl.h"

using namespace std;
void mostrarPaquete(Paquete &p){
    std::cout<<"Mostramos paquete:   "<<std::endl;
    std::cout<<"====================="<<std::endl;
    std::cout<<"Codigo del paquete: "<<p.GetCodRegistro()<<std::endl;
    if(p.getPortador()== nullptr){
        std::cout<<"EL paquete no tiene ningun dron asignado"<<std::endl;
    }else{
        std::cout<<"Matricula del dron portador: "<<p.getPortador()->GetMatricula()<<std::endl;
        std::cout<<"Diferencia de peso: "<<p.getPortador()->GetCargaMaxima()-p.GetPeso()<<std::endl;

    }
    std::cout<<std::endl;
}
/*
 *
 */
int main(int argc, char** argv) {

   /* Datos para los atributos de los objetos:
    * Torre de control 1:
    *    id: 1
    *    area de control: 100
    *    ubicación: Jaén
    * Dron 1:
    *    matrícula: 10001
    *    cargaMáxima: 10
    *    fecha de matriculación: 21 de enero de 2020
    *    tipo: cuadricóptero
    * Dron 2:
    *    matrícula: 10002
    *    cargaMáxima: 5
    *    fecha de matriculación: 9 de septiembre de 2020
    *    tipo: tricóptero
    * Dron 3:
    *    matrícula: 10003
    *    cargaMáxima: 3
    *    fecha de matriculación: 01 de febrero de 2021
    *    tipo: tricóptero
    * Paquete 1:
    *    código de registro: 201
    *    peso: 4
    *    descripción: Paquete destino Coruña
    * Paquete 2:
    *    código de registro: 202
    *    peso: 3
    *    descripción: Paquete destino Salamanca
    * Paquete 3:
    *    código de registro: 203
    *    peso: 8
    *    descripción: Paquete destino Madrid
    */

   //Creamos 3 objetos de la clase Dron
   Dron d1={10001,10,"cuadricoptero","21 de enero de 2020"};
   Dron d2={10002,5,"tricoptero","9 de septiembre de 2020"};
   Dron d3={10003,3,"tricoptero","01 de febrero de 2020"};
   //Creamos 3 objetos de la clase Paquete
   Paquete p1={201,4,"Paquete destino Coruña"};
   Paquete p2={202,3,"Paquete destino Salamanca"};
   Paquete p3={203,8,"Paquete destino Madrid"};

   //Asignamos a los paquetes drones portadores
   p1.addPortador(d1);
   p2.addPortador(d1);
   p3.addPortador(d1);

   try{
       p3.addPortador(d3);///<Añadimos un dron que no puede con la carga
   }catch (std::invalid_argument &e){

       std::cerr<<e.what()<<std::endl;
   }
   //Creamos una torre de control
    /* Datos para los atributos de los objetos:
     * Torre de control 1:
     *    id: 1
     *    area de control: 100
     *    ubicación: Jaén */

    TorreDeControl t1={100,"Jaen",&d1};///<No hay otra forma de crear torres de control
                                                        ///<Por deñirnos a que puede tener de 1 a 100 drones, es decir, siempre va a tener 1 dron
    t1.addDron(&d2); ///<Añadimos otro dron

    //Creamos otra prueba de control , copiando la anterior
    TorreDeControl t2(t1);// o t2=t1

    //Mostramos todos los paquetes creados
    mostrarPaquete(p1);
    mostrarPaquete(p2);
    mostrarPaquete(p3);

    //Mostramos por consola la matricula del mejor dron de la 2º torre de control
    std::cout<<"La matricula del mejor dron de la torre 2 es: "<<t2.mejorDron()->GetMatricula()
            <<" con una carga maxima de: "<<t2.mejorDron()->GetCargaMaxima()<<std::endl;

    return 0;
 }

