///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
# include<cmath>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>
//Español
#include <clocale>
#include <vector>
#include <string>
using namespace std;

#include "video.h"


Video::Video()
{
//    cargarCadena(_nombre,"Se uso un construcor vacío");
    //ctor
}

int Video::tamanioHashtag( int contador){
int c=0;
c=contador;
return c;

}

void Video::cargar(){
cout<<"Título del Film: ";
cargarCadena(_nombre, 50);
cout<<endl;
cout<<"Descripción: ";
cargarCadena(_descripcion, 1500);
cout<<endl;
cout<<"Año de Estreno: ";
cin>>_anioEstreno;
cout<<endl;
cout<<"ID-VIDEO: ";
cin>>_idVideo;
cout<<endl;
cout<<"Stock: ";
cin>>_stock;
cout<<endl;
cout<<"COD-BARRA:  ";
cin>>_codDeBarra;
cout<<endl;
cout<<"Duración ";
cin>>_duracion;
cout<<endl;
/*
std::string hashtag("222");
 std::vector<std::string> vDeHashtag(10);
//int i=0;
  while (true){
cout<<"Ingrese el logLine de a Uno(1):#";

      //  cout<<"#";
 //  std::cin>> _vLogLine[i];
 // cout<<endl;

   std::cin >> hashtag;
    if (hashtag == "-") {
        break;  // Salir del bucle si se ingresa #
    }
    vDeHashtag.push_back(hashtag);
}
for(int i=0;i<10;i++){
    strcpy(_vLogLine, vDeHashtag[i].c_str());

}
*/



    const int columnas = 50;

    std::vector<std::string> vDeHashtag;

    std::string hashtag;
    int i = 0;
    while (true) {
        std::cout << "Ingrese el logLine de a Uno(1):#";
        std::cin >> hashtag;
        if (hashtag == "-") {
            break;  // Salir del bucle si se ingresa #
        }
        // Copiar la cadena de std::string a la matriz de caracteres
        strncpy(_vLogLine[i], hashtag.c_str(), columnas - 1);
        _vLogLine[i][columnas - 1] = '\0'; // Asegurarse de que la cadena esté terminada con nulo
        i++;
    }

    _cantHashtag = i ;

_estado=true;
cout<<endl;


// DimensionChar All(cant_hashtag);

}



void Video::mostrar(){
cout<<"Título del Film: ";
cout<<_nombre;
cout<<endl;
cout<<"Descripción: ";
cout<<_descripcion;
cout<<endl;
cout<<"Año de Estreno: ";
cout<<_anioEstreno;
cout<<"."<<endl;
cout<<"ID-VIDEO: ";
cout<<_idVideo;
cout<<endl;
cout<<"Stock: ";
cout<<_stock;
cout<<".";
cout<<endl;
cout<<"COD-BARRA:  ";
cout<<_codDeBarra;
cout<<endl;
cout<<"Duración ";
cout<<_duracion;
cout<<" mins.";
cout<<endl;
 std::cout << "LogLine: "<<endl;
// DimensionChar Total;
//int tope = Total.getCantidadChar();
    for (int i = 0; i < _cantHashtag; ++i) {
        std::cout <<"#"<< _vLogLine[i] << " ";
    std::cout << std::endl;
    }
_estado=true;
cout<<endl;


}


int Video::getIDVideo(){
return _idVideo;
}


std::vector<std::string> Video::getvLogLine() const {
    std::vector<std::string> copia_string;
    for (int i = 0; i < 10; i++) {
        if (_vLogLine[i] != nullptr) {
            copia_string.push_back(std::string(_vLogLine[i]));
        } else {
            // Si el puntero es nulo, puedes decidir cómo manejarlo, como agregar una cadena vacía o un mensaje de error.
            copia_string.push_back("");  // O puedes lanzar una excepción u otra acción de manejo de errores.
        }
    }
    return copia_string;
}
/*
std::string     Video::getvLogLine() const {

     std::vector<std::string> copia_string;
     for(int i=0;i<10;i++){
        copia_string.push_back(_vLogLine[i]);
     }
 return copia_string;

 }
*/
 int Video::getCantHashtag(){
 return _cantHashtag;
}

void Video::setIDVideo(int id_video){
 _idVideo = id_video;

}

