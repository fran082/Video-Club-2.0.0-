#include <iostream>
#include <clocale>

using namespace std;
#include "video.h"
#include "ArchivoVideo.h"

int main()
{   setlocale(LC_ALL,"Spanish");

int opc;
ArchivoVideo obj;
 do{
        system("cls");
        cout<<"------------MENU PELICULAS------------"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"1 - CARGAR REGISTRO DE PELICULA EN ARCHIVO"<<endl;
        cout<<"2 - MOSTRAR ARCHIVO PELICULAS"<<endl;
        cout<<"3 - ALGORITMO DE RECOMENDACION PARA CLIENTES (NECESITO EL ID DE UNA PELICULA COMO EJEMPLO.)"<<endl;
        cout<<"7 - LISTAR PELICULAS POR G�NERO"<<endl;
        cout<<"0 - SALIR DEL PROGRAMA"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: obj.agregarRegistro();
                    break;
            case 2: obj.mostrarRegistros();
                    break;
            case 3: obj.algRecomendacion();
                    break;
            case 0:
                return 0;
                break;
            default:
                cout<<"OPCI�N INCORRECTA"<<endl;
                break;
        }
        cout<<endl;
        system("pause");
    }while(opc!=0);
    return 0;
}

