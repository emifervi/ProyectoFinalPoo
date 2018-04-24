#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED
class Servicio{
protected:
    string cveServicio, descripcion;
    char tipo;

public:
    // Constructores
    Servicio();
    Servicio(string servicio, string detalle, char clase);

    // Metodos de acceso y modificacion
    void setCveServicio(string servicio);
    void setDescripcion(string detalle);
    void setTipo(char clase);
    string getCveServicio();
    string getDescripcion();
    char getTipo();

    // Metodos virtuales puros
    virtual void muestra() = 0;
    virtual double calculaCosto(int tiempo) = 0;
};
/*
 * Constructor default
 */
Servicio::Servicio(){
    cveServicio = "";
    descripcion = "";
    tipo = 'X';
}
/*
 * Constructor con paramentros
 */
Servicio::Servicio(string servicio, string detalle, char clase){
    cveServicio = servicio;
    descripcion = detalle;
    tipo = clase;
}

/*
 * Metodo de modificacion de atributo cveServicio
 */
void Servicio::setCveServicio(string servicio){
    cveServicio = servicio;
}
/*
 * Metodo de modificacion de atriburo descripcion
 */
void Servicio::setDescripcion(string detalle){
    descripcion = detalle;
}
/*
 * Metodo de modificacion de atributo tipo
 */
void Servicio::setTipo(char clase){
    tipo = clase;
}

/*
 * Metodo de acceso a atributo cveServicio
 */
string Servicio::getCveServicio(){
    return cveServicio;
}
/*
 * Metodo de acceso de atributo descripcion
 */
string Servicio::getDescripcion(){
    return descripcion;
}
/*
 * Metodo de acceso de atributo tipo
 */
char Servicio::getTipo(){
    return tipo;
}

#endif // SERVICIO_H_INCLUDED
