//
// Created by soria on 30/03/2022.
//

#ifndef POOFUSION_GIT_TORREDECONTROL_H
#define POOFUSION_GIT_TORREDECONTROL_H
#include <string>
#include "Dron.h"

class TorreDeControl {
public:
    static const int TAM=100;
private:
    static int contador;
    int idTorre =0;
    double areaDeControl=0;
    std::string ubicacion= "";
    Dron* drones[TAM];
    int numDrones=0;

public:
    //TorreDeControl();
    TorreDeControl(double _area,std::string _ubicacion,Dron *d);
    TorreDeControl(const TorreDeControl& orig);
    virtual ~TorreDeControl();

    double getAreaDeControl() const;
    void setAreaDeControl(double areaDeControl);

    const std::string &getUbicacion() const;
    void setUbicacion(const std::string &ubicacion);

    int getIdTorre() const;

    int getNumDrones() const;

    TorreDeControl& addDron(Dron *d);
    Dron& obtenerDron(int cual);
    void eliminarDron(int cual);

    Dron* mejorDron();
};


#endif //POOFUSION_GIT_TORREDECONTROL_H
