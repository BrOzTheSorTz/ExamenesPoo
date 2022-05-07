/* 
 * File:   TorredeControl.h
 * Author: Juanma
 *
 * Created on 4 de abril de 2021, 19:21
 */

#ifndef TORREDECONTROL_H
#define TORREDECONTROL_H

#include "Dron.h"
#include "Paquete.h"


class TorreDeControl {
    
public: 
    static const int MAX_DRONES = 1000;

private:
    int _idTorre = 0;
    double _areaDeControl = 0;
    std::string _ubicacion = "";
    Dron* _drones[MAX_DRONES];
    int _nDrones = 0;
    
public:
    TorreDeControl() = default;
    TorreDeControl( int nIdTorre, double nAreaDeControl, std::string nUbicacion );
    TorreDeControl(const TorreDeControl& orig);
    virtual ~TorreDeControl();
    void SetUbicacion(std::string _ubicacion);
    std::string GetUbicacion() const;
    void SetAreaDeControl(double _areaDeControl);
    double GetAreaDeControl() const;
    void SetIdTorre(int _idTorre);
    int GetIdTorre() const;
    int GetNdrones() const;
    Dron* GetDron(int cual) const;
    void addDron(Dron* d);
    Dron* mejorDron();
    Dron* buscaDron(float coste);

};

#endif /* TORREDECONTROL_H */

