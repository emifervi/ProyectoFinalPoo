#include <iostream>
using namespace std;
#include "Reserva.h"
#include "Servicio.h"
#include "Fisico.h"
#include "Digital.h"

int main()
{

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
    cout << "B: " << b << endl;*/
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
	}

    return 0;
}