#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED

#include "Hora.h"
class Reserva{
private:
    string cveServicio;
    int idUsuario, duracion;
    Hora horaInicio;

public:
    // Constructores
    Reserva();
    Reserva(string serv, int iD, int tiempo, Hora inicio);

    // Metodos de acceso y modificacion.
    void setCveServicio(string serv);
    void setIdUsuario(int iD);
    void setDuracion(int tiempo);
    void setHoraInicio(Hora inicio);
    string getCveServicio();
    int getIdUsuario();
    int getDuracion();
    Hora getHoraInicio();

    // Metodo funcional
    Hora calculaHoraFinal();
    void muestra(); //Para pruebas y debuggear
};
/*
 * Constructor default
 */
Reserva::Reserva(){
    cveServicio = "";
    idUsuario = 0;
    duracion = 0;
    Hora();
}
/*
 * Constructor con parametros
 */
Reserva::Reserva(string serv, int iD, int tiempo, Hora inicio){
    cveServicio = serv;
    idUsuario = iD;
    duracion = tiempo;
    horaInicio = inicio;
}

/*
 * Metodo de modificacion de parametro CveServicio
 */
void Reserva::setCveServicio(string serv){
    cveServicio = serv;
}
/*
 * Metodo de modificacion de parametro idUsuario
 */
void Reserva::setIdUsuario(int iD){
    idUsuario = iD;
}
/*
 * Metodo de modificacion de parametro Duracion
 */
void Reserva::setDuracion(int tiempo){
    duracion = tiempo;
}
/*
 * Metodo de modificacion de parametro horaInicio
 */
void Reserva::setHoraInicio(Hora inicio){
    horaInicio = inicio;
}

/*
 * Metodo de acceso de parametro cveServicio
 */
string Reserva::getCveServicio(){
    return cveServicio;
}
/*
 * Metodo de acceso de parametro idUsuario
 */
int Reserva::getIdUsuario(){
    return idUsuario;
}
/*
 * Metodo de acceso de parametro duracion
 */
int Reserva::getDuracion(){
    return duracion;
}
/*
 * Metodo de acceso de parametro horaInicio
 */
Hora Reserva::getHoraInicio(){
    return horaInicio;
}

/*
 * Metodo que calcula la hora final (hora en la que se termina la reserva).
 * Argumentos: ninguno.
 * Retornos: la hora final (hora inicial + duracion).
 */
Hora Reserva::calculaHoraFinal(){
    return horaInicio + duracion;
}

void Reserva::muestra(){
    cout<<"Reserva:"<<endl;
    cout<<"Servicio: "<<cveServicio<<endl;
    cout<<"ID de usuario: "<<idUsuario<<endl;
    cout<<"Hora de Inicio: "<<horaInicio<<endl;
    cout<<"Duracion: "<<duracion<<endl;
}

#endif // RESERVA_H_INCLUDED
