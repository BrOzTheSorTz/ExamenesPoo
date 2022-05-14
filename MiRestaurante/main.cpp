#include <iostream>
#include "Restaurante.h"
#include "AprendizDeCocina.h"
#include "JefeDeCocina.h"

void visualizaCocineros(Restaurante &r){

    for(int i=0;i<r.getNumCocineros();++i){
        JefeDeCocina* aux1=dynamic_cast<JefeDeCocina*>(r.obtenerCocinero(i+1));
        AprendizDeCocina* aux2=dynamic_cast<AprendizDeCocina*>(r.obtenerCocinero(i+1));

        if(aux1!= nullptr){
            std::cout<<"Jefe de Cocina: "<<std::endl;
            std::cout<<"Estrellas: "<<aux1->getEstrellasMichelin()<<std::endl;

        }else if(aux2 != nullptr){
            std::cout<<"Aprendiz de Cocina: "<<std::endl;
            std::cout<<"Nivel: "<<aux2->getNivel()<<std::endl;
        }
        std::cout<<"Dni y Nombre: "<<r.obtenerCocinero(i+1)->getDni()<<" "<<r.obtenerCocinero(i+1)->getNombre()<<std::endl;
    }
}
int main() {

    Restaurante miRestaurante={"MiniBarranco","Avd Madrid",100};

    JefeDeCocina cocinero1 ={"Paquito","12345897A",32,0,"migas"};
    AprendizDeCocina cocinero2 ={"Laura","12345678X",5};

    //Contratamos los cocineros
    miRestaurante.addCocinero(&cocinero1).addCocinero(&cocinero2);
    try {
        Plato *plato = nullptr;

        plato = cocinero1.cocinarPlato("migas", 10);

        std::cout << "El precio final del plato cocinado es: " << plato->getPrecio() << std::endl;


        cocinero1.isActivo() ? std::cout << "Esta listo" << std::endl : std::cout << "No esta listo" << std::endl;
        cocinero2.isActivo() ? std::cout << "Esta listo" << std::endl : std::cout << "No esta listo" << std::endl;

        visualizaCocineros(miRestaurante);

        delete plato;
    }catch (std::logic_error &e){
        std::cerr<<e.what()<<std::endl;

    }catch (ConocimientosInsuficientes &e){
        std::cerr<<e.what()<<std::endl;
    }catch (std::exception &e){
        std::cerr<<e.what()<<std::endl;
    }

    return 0;
}
