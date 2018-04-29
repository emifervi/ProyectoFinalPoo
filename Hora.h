#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

class Hora{
private:
    int hora, minuto;
public:
    // Constructores
    Hora();
    Hora(int hora, int minuto);

    // Métodos de acceso y modificación.
    int getHora();
    int getMinuto();
    void setHora(int hora);
    void setMinuto(int minuto);

    //Sobrecarga de operadores
    bool operator <= (Hora a);
    bool operator >= (Hora a);
    bool operator == (Hora a);
    Hora operator + (int m);
    friend ostream& operator<<(ostream &os, Hora a);
    friend istream& operator>>(istream &is, Hora &a);
};
/*
 * Constructor default
 */
Hora::Hora(){
    hora = 0;
    minuto = 0;
}
/*
 * Constructor con parametros.
 */
Hora::Hora(int hora, int minuto){

    // Maneja la situación en la que los minutos son mayores a 59
    if(minuto > 59){
        this->hora = hora + (minuto / 60);
        this->minuto = (minuto % 60);
    }
    else{
        this->hora = hora;
        this->minuto = minuto;
    }
    if (hora > 23){
        cout << "WARNING : Hora inválida" << endl;
    }
}

/*
 * Metodo de acceso al atributo hora
 */
void Hora::setHora(int hora){
    this->hora = hora;
    if (hora > 23){
        cout << "WARNING : Hora inválida" << endl;
    }
}
/*
 * Metodo de acceso al atributo minuto
 */
void Hora::setMinuto(int minuto){
    this->minuto = minuto;
    if(minuto > 59){
        hora += (minuto / 60);
        minuto = (minuto % 60);
    }
}

/*
 * Metodo de modificacion al atributo hora
 */
int Hora::getHora(){
    return hora;
}
/*
 * Metodo de acceso al atributo minuto
 */
int Hora::getMinuto(){
    return minuto;
}

/*
 * Sobrecarga de operador <=
 */
bool Hora::operator<=(Hora a){
    if (minuto + hora*3600 <= a.hora*3600 + a.minuto){
        return true;
    }
    else{
        return false;
    }
}
/*
 * Sobrecarga de operador >=
 */
bool Hora::operator>=(Hora a){
    if (minuto + hora*3600 >= a.hora*3600 + a.minuto){
        return true;
    }
    else{
        return false;
    }
}
/*
 * Sobrecarga de operador ==
 */
bool Hora::operator==(Hora a){
    if (minuto + hora*3600 == a.hora*3600 + a.minuto){
        return true;
    }
    else{
        return false;
    }
}
/*
 * Sobrecarga de operador +
 */
Hora Hora::operator+(int m){
    Hora b;
    b.hora = hora;
    b.minuto = minuto + m;
    if(b.minuto > 59){
        b.hora += (b.minuto / 60);
        b.minuto = (b.minuto % 60);
    }
    return b;
}
/*
 * Sobrecarga de operador <<
 */
ostream& operator<<(ostream &os, Hora a){
    os << a.hora << ":";
    if(a.minuto < 10){
        os << "0" << a.minuto;
    }
    else{
        os << a.minuto;
    }
}
/*
 * Sobrecarga de operador >>
 */
istream& operator>>(istream &is, Hora &a){
    is >> a.hora;
    cin.ignore();
    is >> a.minuto;

    if (a.minuto > 59){
        a.hora += a.minuto / 60;
        a.minuto = a.minuto % 60;
    }
}

#endif // HORA_H_INCLUDED
