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
#include <clocale>

using namespace std;

#include "cargarCadena.h"


void cargarCadena(char *pal, int tam ){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}
/*
int DimensionChar::getCantidadChar(){
return _cantidadChar;
}

DimensionChar::DimensionChar{

}

DimensionChar::DimensionChar(int total){

_cantidadChar = total;
}

int DimensionChar::copiarDatoTamanioChar(int grancantidad){

_cantidadChar = grancantidad;
return
}

*/
