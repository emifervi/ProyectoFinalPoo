#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
#include "Reserva.h"
#include "Servicio.h"
#include "Fisico.h"
#include "Digital.h"

/*
 * Funcion para buscar el ultimo espacio.
 * Toma como parametros un string y su tamaño.
 * Regresa el indice donde esta el ultimo espacio como tipo entero.
*/
int buscarUltimoEspacio(string str, int tam){
    for(int i=tam-1; i>-1; i--){
        if(str[i]==' '){
            return i;
        }
    }
    return -1;
}
/*
 * Funcion para obtener el entero que esta representando una variable string
 * Toma como parametros un string y su tamaño
 * Regresa el entero que esta siendo representado en el string
*/
int stringToInt(string str, int tam){
    int res=0,n;
    for(int i=0;i<tam;i++){
        n=str[i]-48;
        res+=n*pow(10,tam-1-i);
    }
    return res;
}

int main()
{
    //Declaracion de todas las varibles utilizadas
    string clave, descripcion, sTraduccion, sCosto;
    bool bTraduccion, bExiste;
    int costo, indexSer=0, indexRes=0, ultEspacio, id, duracion, hora, minuto;
    char tipo;
    Hora temp;
    Servicio *arrSer[6];
    Reserva *arrRes[20];
    //Lectura de archivos
    ifstream EntSer, EntRes;
/*
    EntSer.open("Servicios.txt");
    while(EntSer>>clave){
        EntSer>>tipo;
        tipo = toupper(tipo);
        getline(EntSer, descripcion);
        descripcion.erase(0,1);
        //En caso de que sea fisico, debe tener alguno de estos tipos
        if(tipo=='L'||tipo=='R'||tipo=='P'){

            ultEspacio = buscarUltimoEspacio(descripcion, descripcion.length());
            //Si es fisico, la ultima palabra, on este caso numero, es el costo por 30 mins
            sCosto=descripcion.substr(ultEspacio+1);
            descripcion.erase(ultEspacio);
            costo= stringToInt(sCosto, sCosto.length());

            //Crea un apuntador a un objeto tipo Fisico con memoria dinamica, para que luego el arreglo
            // apunte a ese objeto
            Fisico *tmp = new Fisico(clave, descripcion, tipo,costo);
            arrSer[indexSer]= tmp;

            indexSer++;
        }
        //Si es digital, debe tener alguno de estos  tipos
        else if(tipo=='E'||tipo=='D'||tipo=='C'){

            ultEspacio = buscarUltimoEspacio(descripcion,descripcion.length());
            sTraduccion=descripcion.substr(ultEspacio+1);
            if(sTraduccion=="true"){
                bTraduccion=true;
            }
            else if(sTraduccion=="false"){
                bTraduccion=false;
            }
            else{
                cout<<"Advertencia: Servicio numero "<<indexSer+1<<" contiene un valor no conocido para traduccion, falso por default."<<endl;
                bTraduccion=false;
            }
            descripcion.erase(ultEspacio);
            ultEspacio=buscarUltimoEspacio(descripcion,descripcion.length());
            sCosto = descripcion.substr(ultEspacio+1);
            costo = stringToInt(sCosto, sCosto.length());
            descripcion.erase(ultEspacio);
            Digital *tmp = new Digital(clave, descripcion, tipo,costo, bTraduccion);
            arrSer[indexSer]= tmp;
            indexSer++;
        }
        else{
            cout<<"Error: Tipo invalido en servicio con clave "<<clave<<"."<<endl;
        }

    }
    EntRes.close();
    cout<<"Carga de servicios completada."<<endl<<endl;


    for(int i=0;i<indexSer;i++){
        arrSer[i]->muestra();
        cout<<endl;
    }*/

    EntRes.open("Reserva.txt");
    while(EntRes>>clave){
        EntRes>>id>>temp>>duracion;
        bExiste = false;
        for(int i=0;i<indexSer;i++){
            if(arrSer[i].getCveServicio()==clave){
                bExiste= true;
            }
        }
        if(bExiste){
            Reserva *tmp = new Reserva(clave,id,duracion,temp);
            arrRes[indexRes]= tmp;
            indexRes++;
        }
        else{
            cout<<"Error: Clave de servicio "<<clave<<" no esta regsitrada, favor de introducir una clave existente o crear un nuevo servicio con esta clave."<<endl;
        }
    }
    EntRes.close();
    cout<<"Carga de reservas exitosa."
    for(int i=0;i<indexRes;i++){
        arrRes[i]->muestra();
        cout<<endl;
    }

/*
    //Hora a(2, 120);
    //Hora b(2, 30);

    Hora c;
    cin >> c;


    //cout << "A: " << a << endl;
    //cout << "B: " << b << endl;

    cout << "C: " << c << endl;
    /*
    if(a == b){
        cout << "A es igual a B "<< endl;
    }
    if(a <= b){
        cout << "A es menor igual" << endl;
    }
    if(a >= b){
        cout << "A es mayor ingual" << endl;
    }
    b = a + 120;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;

    int i=0, tar;
    string cve, descr;
    char tip, op;
    bool trad = false;

	Servicio *lista[4];
	for(;i<2;i++){
		cout<<"cveServicio Fisico "<<i+1<<endl;
		cin>> cve;
		cout<<"descripcion Fisico "<<i+1<<endl;
		cin>>descr;
		cout<<"tipo"<<i+1<<endl;
		cin>>tip;
		cout<<"tarifa"<<i+1<<endl;
		cin>>tar;
    	Fisico *fisTemp = new Fisico(cve, descr, tip, tar);
		lista[i]= fisTemp;
	}
	for(;i<4;i++){
        trad = false;
		cout<<"cveServicio Digital "<<i+1<<endl;
		cin>> cve;
		cout<<"descripcion Digital "<<i+1<<endl;
		cin>>descr;
		cout<<"tipo "<<i+1<<endl;
		cin>>tip;
		cout<<"tarifa "<<i+1<<endl;
		cin>>tar;
		cout <<"traducido ?" << endl;
		cin>>op;
		if(tolower(op) == 'y' ){
            trad = true;
		}
		Digital *digTemp = new Digital(cve, descr, tip, tar, trad);
		lista[i]= digTemp;
	}

	for(int i=0; i<4;i++){
		lista[i]->muestra();
		if(i < 2){
            cout << "Costo total: " << lista[i]->calculaCosto(c.getHora()*60 + c.getMinuto()) << endl;
		}
		else{
            cout << "Costo total: " << lista[i]->calculaCosto(c.getHora() + c.getMinuto()/60) << endl;
		}
		cout << endl;
	}*/

    return 0;
}
