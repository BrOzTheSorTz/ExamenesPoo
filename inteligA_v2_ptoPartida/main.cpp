/**
 * @file main.cpp
 * @author jjurado
 *
 * @date 29 de marzo de 2021, 8:30
 */

#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <limits>

using namespace std;
#include "Paquete.h"
#include "TorredeControl.h"
#include "DronAlquilado.h"
#include "DronAveriado.h"

void muestraPaqueteDron ( Paquete& paramP )
{
   Dron* aux = paramP.GetPortador ();

   std::cout << "Código del paquete: " << paramP.GetCodRegistro () << std::endl
             << "   transportado por el dron: "
             << aux->GetMatricula () << std::endl
             << "   peso libre en el dron: "
             << aux->GetCargaMaxima () - paramP.GetPeso () << std::endl;
   aux = nullptr;
}
void visualizaDrones (TorreDeControl &t){
    for(int i=0;i<t.GetNdrones();++i){
        if(dynamic_cast<DronAlquilado*>(t.GetDron(i))!= nullptr){
            std::cout<<"Dron ALQUILADO:"<<std::endl;
        }else if(dynamic_cast<DronAveriado*>(t.GetDron(i))!= nullptr){
            std::cout<<"Dron AVERIADO:"<<std::endl;
        }else{
            std::cout<<"Dron NORMAL:"<<std::endl;
        }
        std::cout<<"Matricula: "<<t.GetDron(i)->GetMatricula()<<std::endl;
        //Como nos dicen los costes diarios el número de dias son 1
        std::cout<<"Coste diario: "<<t.GetDron(i)->GetCoste(1)<<std::endl;

    }
}
/*
 *
 */
int main(int argc, char** argv) {

    ///FIXME A la hora de crear un Dron de las derivadas como hago para que tenga
    ///todos los datos de la clase padre, el problema es que son muchos datos

    TorreDeControl t1(1, 100, "Jaén");

/* Prueba 1. En la función main, crea dos objetos de la clase DronAveriado
    * y dos objetos de la clase DronAlquilado y añadelos a la torre control t1
    *
    * DATOS PARA LOS NUEVOS OBJETOS:
    * Objetos de clase DronAlquilado:
    *    Empresa: Gremsy
    *    CosteDiario: 5
    *  *****************************
    *    Empresa: Álava
    *    CosteDiario: 15
    *
    * Objetos de clase DronAveriado:
    *    NivelAveria: 2
    *    tasaReparacion: 25
    *    tiempo previsto para la reparación: 5 días
    *  *****************************
    *    NivelAveria: 1
    *    tasaReparacion: 20
    *    tiempo previsto para la reparación: 9 días
*/
    try {
        DronAlquilado alquilado = {"Gremsy", 5};
        DronAveriado averiado = {2, 25, 5};

        t1.addDron(&alquilado);
        t1.addDron(&averiado);


        //Visualizamos los drones de la torre de control
        visualizaDrones(t1);
        Dron* aux =t1.buscaDron(50);
        if(aux!= nullptr){
            std::cout<<"El dron de T cuyo coste es el menor y es menor que 50."<<std::endl;
            std::cout<<"Matricula: "<<aux->GetMatricula()<<std::endl;
            std::cout<<"Coste Diario: "<<aux->GetCoste(1)<<std::endl;

        }

    }catch (std::length_error &e){
        std::cerr<<e.what()<<std::endl;
    }catch (ErrorReparacion &e){
        std::cerr<<e.what()<<std::endl;
    }catch (std::invalid_argument &e){
        std::cerr<<e.what()<<std::endl;
    }








    return 0;
}

