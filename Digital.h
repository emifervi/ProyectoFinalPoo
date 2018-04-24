#ifndef DIGITAL_H_INCLUDED
#define DIGITAL_H_INCLUDED
#include "Servicio.h"

class Digital : public Servicio{
private:
    double costoXHr;
    bool traduccion;

public:
    // Constructores
    Digital();
    Digital(string servicio, string detalle, char clase, double tarifa, bool trad);

    // Metodos de acceso y modificacion
    void setCostoXHr(double tarifa);
    void setTraduccion(bool trad);
    double getCostoXHr();
    bool getTraduccion();

    // Metodos funcionales
    void muestra();
    double calculaCosto(int tiempo);
};

/*
 * Constructor default
 */
Digital::Digital() : Servicio(){
    costoXHr = 0;
    traduccion = true;
}
/*
 * Constructor con paramentros
 */
Digital::Digital(string servicio, string detalle, char clase, double tarifa, bool trad) : Servicio(servicio, detalle, clase){
    costoXHr = tarifa;
    traduccion = trad;
}

/*
 * Metodo de modificacion de costoXHr
 */
void Digital::setCostoXHr(double tarifa){
    costoXHr = tarifa;
}
/*
 * Metodo de modificacion de traduccion
 */
void Digital::setTraduccion(bool trad){
    traduccion = trad;
}

/*
 * Metodo de acceso a costoXHr
 */
double Digital::getCostoXHr(){
    return costoXHr;
}
/*
 * Metodo de acceso a traduccion
 */
bool Digital::getTraduccion(){
    return traduccion;
}

/*
 * Metodo de calcula costo
 * Arguemntos: tiempo total en horas;
 * Retornos: costo total del servicio
 */
double Digital::calculaCosto(int tiempo){

    if(traduccion){
        return costoXHr * tiempo * 1.25;
    }
    else{
        return costoXHr * tiempo;
    }
}

/*
 * metodo muestra
 */
void Digital::muestra(){
    cout << "Servicio: " << cveServicio << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Tarifa: " << costoXHr << endl;
    if(traduccion){
        cout << "Traduccion: Si" << endl;
    }
    else{
        cout << "Traduccion: No" << endl;
    }
    //cout << "Costo total: " << calculaCosto(int hr) << endl;
}

#endif // DIGITAL_H_INCLUDED
