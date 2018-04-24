#ifndef FISICO_H_INCLUDED
#define FISICO_H_INCLUDED
#include "Servicio.h"
class Fisico : public Servicio{
private:
    double ctoX30Min;

public:
    // Constructores
    Fisico();
    Fisico(string servicio, string detalle, char clase, double tarifa);

    // Metodos de acceso y modificacion
    void setCtoX30Min(double tarifa);
    double getCtoX30Min();

    // Metodos funcionales
    void muestra();
    double calculaCosto(int tiempo);
};
/*
 * Constructor default
 */
Fisico::Fisico() : Servicio(){
    ctoX30Min = 0;
}
/*
 * Constructor con parametros
 */
Fisico::Fisico(string servicio, string detalle, char clase, double tarifa) : Servicio(servicio, detalle, clase){
    ctoX30Min = tarifa;
}

/*
 * Metodo de modificacion de ctoX30Min
 */
void Fisico::setCtoX30Min(double tarifa){
    ctoX30Min = tarifa;
}

/*
 * Metodo de acceso de ctoX30Min
 */
double Fisico::getCtoX30Min(){
    return ctoX30Min;
}


/*
 * Metodo de calcula costo
 * Arguemntos: tiempo total en minutos;
 * Retornos: costo total del servicio
 */
double Fisico::calculaCosto(int tiempo){;
    return ctoX30Min * tiempo;
}

/*
 * Metodo muestra
 */
void Fisico::muestra(){
    cout << "Servicio: " << cveServicio << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Tarifa: " << ctoX30Min << endl;
    //cout << "Costo total: " << calculaCosto(int mins) << endl;
}

#endif // FISICO_H_INCLUDED
