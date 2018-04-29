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

/*
 * Funcion para saber si una clave dada existe y pertenece a un servicio dentro del arreglo
 * Toma como parametros el arreglo de servicios, su tamaño y la clave a encontrar
 * Regresa verdadero si encuentra el servicio y falso si no lo encuentra.
*/
bool existeServicio(Servicio *arrSer[], int tam, string clave){
    for(int i=0;i<tam;i++){
        if(arrSer[i]->getCveServicio()==clave){
            return true;
        }
    }

    return false;
}

/*
 * Funcion para saber si una horario dado es real, esta dentro de las 24 horas del dia.
 * Toma como parametros la hora a  validar.
 * Regresa verdadero si la hora es valida y falso si no lo es.
*/
bool validarHora(Hora hr){
    Hora tmp(23,59), tmp2(0,0);
    if(hr <= tmp && hr >= tmp2){
        return true;
    }
    else{
        return false;
    }

}
/*
 * Funcion para mostrar todos los servicios registrados.
 * Recibe como parametros el arreglo de servicios y su tamaño
 * no regresa algun valor.
*/
void consultaServicios(Servicio *arrSer[], int tam){
    //Por cada exitente llama al metodo muestra.
    for(int i=0;i<tam;i++){
    cout<<"Servicio "<<i+1<<": "<<endl;
    arrSer[i]->muestra();
    cout<<endl;
    }
    //Si el arreglo no tiene datos, se informa al usuario
    if(tam==0){
        cout<<"No existen servicios registrados."<<endl;
    }
}

/*
 * Funcion para mostrar todos las reservas registrados.
 * Recibe como parametros el arreglo de reservas y su tamaño
 * No regresa algun valor.
*/
void consultaReservaciones(Reserva *arrRes[], int tam){
    //Por cada exitente llama al metodo muestra.
    for(int i=0;i<tam;i++){
        cout<<"Reserva "<<i+1<<": "<<endl;
        arrRes[i]->muestra();
        cout<<endl;
    }
    //Si el arreglo no tiene datos, se informa al usuario
    if(tam==0){
        cout<<"No existen reservas registradas."<<endl;
    }
}


/*
 * Funcion para mostrar las reservas a un servicio dado, identificado por su clave.
 * Recibe como parametros el arreglo de reservas, su tamaño y la clave del servicio
 * que se busca.
 * No regresa algun valor.
*/
void consultaPorClave(Reserva *arrRes[], int tam, string clave){
    bool bHay=false;
    for(int i=0;i<tam;i++){
        if(arrRes[i]->getCveServicio() == clave){
            bHay=true;
            arrRes[i]->muestra();
            cout<<endl;
        }
    }
    if(!bHay){
        cout<<"No existen reservas para ese servicio."<<endl;
    }
}

/*
 * Funcion para mostrar las reservas que tienen un horario de inico dado.
 * Recibe como parametros el arreglo de reservas, su tamaño y la hora buscada.
 * No regresa algun valor.
*/
void consultaPorHora(Reserva *arrRes[], int tam, Hora hInicio){
    bool bHay=false;
    for(int i=0;i<tam;i++){
        if(arrRes[i]->getHoraInicio()==hInicio){
            bHay=true;
            arrRes[i]->muestra();
            cout<<endl;
        }
    }
    if(!bHay){
        cout<<"No existen reservas con esa hora de inicio."<<endl;
    }

}

/*
 * Funcion para validar si un horario ingresado se empalma con los existentes de un servicio.
 * Recibe como parametros el arreglo de servicios, su tamaño, la clave del servicio que se busca,
 *  el  horario inicial de la reserva  que se quiere hacer y la duracion de la reserva.
 * Regresa verdadero si el horario se empalma con  los existentes o falso si no se empalma.
*/
bool validaEmpalmeHorario(Reserva *arrRes[], int tam, Hora hr,int dur, string clave ){
    //Para que se empalmen, la hora inicial o final deben estar entre la hora de inicio y final de las ya registradas,
    // o que empiece antes y termine despues.
    for(int i=0;i<tam;i++){
        if(arrRes[i]->getCveServicio()==clave){
            if(arrRes[i]->calculaHoraFinal() >= hr&& hr+dur>= arrRes[i]->getHoraInicio() ){
                return true;
            }
        }
    }
    return  false;
}

double mostrarCostoDeRenta(Servicio *arrSer[],int tam, string clave, int duracion){
    for(int i=0;i<tam;i++){
        if(arrSer[i]->getCveServicio() == clave){
            return arrSer[i]->calculaCosto(duracion);
        }
    }
    return 0;
}


int main()
{
    //Declaracion de todas las varibles utilizadas
    string clave, descripcion, sTraduccion, sCosto;
    bool bTraduccion, bExiste, bHoraValida, bEmpalme, bReservaValida;
    int costo, indexSer=0, indexRes=0, ultEspacio, id, duracion, hora, minuto;
    char tipo, op,  op2;
    Hora temp,hSalida;
    Servicio *arrSer[6];
    Reserva *arrRes[20];
    //Lectura de archivos
    ifstream EntSer, EntRes;
    //Para actualizar las reservas  al terminar.
    ofstream SalRes;

    //Preguntar al usuario nombre de archivo de servicios
    cout<<"Teclea el nombre del archivo donde se encuentren los servicios:"<<endl;
    cin>>clave;
    //Lectura de Servicios
    EntSer.open(clave.c_str());
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
            //Si el string le verdadero o falso asigna el valor correspondiente, si no asigna falso y avisa
            // al usuario que el valor no es valido.
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
            //Calcular el valor de costo que dice el string.
            costo = stringToInt(sCosto, sCosto.length());
            descripcion.erase(ultEspacio);
            //Crea un objeto tipo digital y lo asigna a la direccion correspondiente del arreglo.
            Digital *tmp = new Digital(clave, descripcion, tipo,costo, bTraduccion);
            arrSer[indexSer]= tmp;
            indexSer++;
        }
        else{
            cout<<"Error: Tipo invalido en servicio con clave "<<clave<<"."<<endl;
        }

    }
    EntRes.close();
    cout<<"Carga de servicios completada."<<endl;

    //Preguntar al usuario nombre de archivo de reservas
    cout<<"Teclea el nombre del archivo donde se encuentren las reservas:"<<endl;
    cin>>clave;
    //Lectura de Reservas
    EntRes.open(clave.c_str());
    while(EntRes>>clave){
        EntRes>>id>>temp>>duracion;
        //Validar que la clave dada existe en el arreglo de servicios
        bExiste = existeServicio(arrSer,indexSer,clave);
        bHoraValida = validarHora(temp);
        //Si existe, agregarla al arreglo de reservas, si no, notificar al usuario que
        // existe un error.
        if(bExiste){
            if(bHoraValida){
                //Reserva registrada con datos validados.
                Reserva *tmp = new Reserva(clave,id,duracion,temp);
                arrRes[indexRes]= tmp;
                indexRes++;
            }
            else{
                cout<<"Hora no es valida, verifique hora de reserva "<<indexRes +1<<", definida como 00:00 por default."<<endl;
                //Si la clave existe, la hora se pone como 00:00 ya que la hora dada no es valida
                temp.setHora(0);
                temp.setMinuto(0);

                //Se registra reservacion con hora default
                Reserva *tmp = new Reserva(clave,id,duracion,temp);
                arrRes[indexRes]= tmp;
                indexRes++;
            }
        }
        else{
            //Si la clave no existe, no se registra la reservacion, sin importar si la hora es valida o no.
            cout<<"Error: Clave de servicio "<<clave<<" no esta regsitrada, favor de introducir una clave existente o crear un nuevo servicio con esta clave. (Reservacion no registrada)"<<endl;
        }
    }
    EntRes.close();
    cout<<"Carga de reservas completada."<<endl;

    //Menu principal
    do{
        //Mensaje de menu principal
        cout<<endl<<"Selecciona una opcion del menu."<<endl;
        cout<<"a) Consultar lista de servicios."<<endl;
        cout<<"b) Consultar la lista de reservaciones."<<endl;
        cout<<"c) Consultar las reservas de un servicio dado."<<endl;
        cout<<"d) Consulta las reservas de una hora específica."<<endl;
        cout<<"e) Hacer una reservación."<<endl;
        cout<<"f) Terminar."<<endl;
        cin>>op;

        cout<<endl;

        switch(toupper(op)){

        //Opcion que muestra todos los servicios registrados
        case 'A':
            consultaServicios(arrSer,indexSer);
            break;

        //Opcion que muestra todos las reservas registrados
        case 'B':
            consultaReservaciones(arrRes,indexRes);
            break;

        //Opcion que muestra las reservas con una clave de servicios dada
        case 'C':
            cout<<"Teclea la clave del servicio."<<endl;
            cin>>clave;
            cout<<endl;
            consultaPorClave(arrRes,indexRes,clave);
            break;

        //Opcion que muestra las reservas con una hora dada
        case 'D':
            cout<<"Teclea la hora que busca, separando la hora y minuto por dos puntos ':'."<<endl;
            cin>>temp;
            bHoraValida= validarHora(temp);
            //Solo se hace  un if porque regresa al menu directamente, no hay necesidad  de implementar
            // un while o do-while que obligue al usuario a esta opcion.
            if(bHoraValida){
                consultaPorHora(arrRes,indexRes,temp);
            }
            else{
                cout<<"Hora dada es invalida, intente nuevamente."<<endl;
            }
            break;

        //Opcion que registra una reservación nueva, si existe espacio para registrarla
        case 'E':
            if(indexRes<20){
                do{
                    cout<<"Teclea la clave del servicio al cual desea hacer reservacion. (Para regresar al menu principal teclee '-1')"<<endl;
                    cin>>clave;
                    cout<<endl;
                    bExiste = existeServicio(arrSer, indexSer, clave);
                    if(!bExiste && clave!="-1"){
                        cout<<"La clave del servicio es incorrecta, intentelo de nuevo."<<endl<<endl;
                    }
                }while(!bExiste && clave!= "-1");

                //Al igual que la opcion D, no hay necesidad de implementar un loop ya que el usuario regresa
                // al menu directamente, no ha ingresado mas datos.
                if(clave!="-1"){

                    //Al ya haber ingresado otros datos ya validados, se espera que el usuario de una hora valida,
                    // por esto aqui si se implementa un do-while hasta que el usuario de una hora valida.
                    do{


                        do{
                            cout<<endl<<"Teclea el horaio de inicio, separando hora y minuto con dos puntos ':'"<<endl;
                            cin>>temp;
                            bHoraValida= validarHora(temp);
                            if(!bHoraValida){
                                cout<<"Hora dada excede las 24 horas del dia, intentelo de nuevo."<<endl;
                            }
                        }while(!bHoraValida);

                        cout<<endl<<"Teclea la duracion de la reserva"<<endl;
                        cin>>duracion;

                        bEmpalme= validaEmpalmeHorario(arrRes,indexRes,temp,duracion,clave);

                        if(bEmpalme){
                            do{
                                cout<<"El servicio ya es rentado a esa hora, desea introducir otra hora o duracion? (s/n)"<<endl;
                                cin>>op2;

                                if(op2=='n'){
                                    bEmpalme=false;
                                    bReservaValida=false;
                                }
                                else if(op2=='s'){

                                }else{
                                    cout<<"Opcion invalida."<<endl;
                                }

                            }while(op2!= 'n' && op2!= 's');

                        }
                        else{
                            bReservaValida=true;
                        }
                    }while(bEmpalme);

                    if(bReservaValida){

                        cout<<"Teclea el ID del usuario."<<endl;
                        cin>>id;

                        //Se registra la reservacion en el arreglo
                        Reserva *tmp = new Reserva(clave,id,duracion,temp);
                        arrRes[indexRes]= tmp;
                        indexRes++;
                        cout<<"Reserva registrada correctamente con un costo de $"<<mostrarCostoDeRenta(arrSer,indexSer,clave,duracion)<<"."<<endl;
                    }

                }
            }
            //Si no queda espacio en el arreglo, se notifica al usuario y no se registran nuevas reservas
            else{
                cout<<"Ya no se pueden registrar mas reservaciones por falta de espacio."<<endl;
            }
            break;

        //Opcion que termina el programa
        case 'F':
            break;

        //Cualquier otra opcion es invalida.
        default:
            cout<<"Opción inválida, intente nuevamente."<< endl;
        }

    }while(toupper(op)!='F');

    cout<<"Teclea el nombre del archivo a donde se guardaran las reservas:"<<endl;
    cin>>clave;

    SalRes.open(clave.c_str());
    for(int i=0; i<indexRes; i++){
        SalRes<<arrRes[i]->getCveServicio()<<" "<<arrRes[i]->getIdUsuario()<<" "<<arrRes[i]->getHoraInicio()<<" "<<arrRes[i]->getDuracion()<<endl;
    }
    cout<<"Las reservas  se guardaron existosamente en el archivo de nombre "<<clave<<endl;


    return 0;
}
