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
#include <vector>
#include <string>

using namespace std;

#include "ArchivoVideo.h"
#include "video.h"

 ArchivoVideo::ArchivoVideo(){
            strcpy(nombre , "videos.dat");
        }

void ArchivoVideo::agregarRegistro(){
    Video obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    obj.cargar();
  //  obj.set_Id(ultimoPelicula()+1);
	fwrite(&obj, sizeof (obj), 1, pIng);
	fclose(pIng);
}


int ArchivoVideo::cantidadRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Video);
}


void ArchivoVideo::mostrarRegistros(){
    Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        obj.mostrar();
        /*
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<"----------------------------"<<endl;
            cout<<endl;
        }
        */
	}
	fclose(p);
}


int ArchivoVideo::buscarVideo(int d){
    Video obj;
    int pos=0;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getIDVideo() == d){
            fclose(p);
            ///
            return pos;
        }
        pos++;
	}
	fclose(p);
	return -1;
}


Video ArchivoVideo::leerPelicula(int pos){
    Video obj;
    if(pos<0){
        obj.setIDVideo(-3);
        return obj;
    }
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setIDVideo(-2);
        return obj;
    }
    fseek(p, sizeof obj * pos, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, p);
    fclose(p);
    if(aux==0){
        obj.setIDVideo(-1);
    }
    return obj;
}


void ArchivoVideo::comparacionDeHashtag(Video obj){
Video Film;
ArchivoVideo DataFilm;

int tope = DataFilm.cantidadRegistros();
 std::vector<std::string> vDeHashtagCliente(10);
 std::vector<std::string> vDeHashtagEmpleado(10);
bool advertencia = false;
bool bandera = false;

 vDeHashtagEmpleado =  obj.getvLogLine();
for(int i=0;i<tope;i++){
  Film = DataFilm.leerPelicula(i);
   vDeHashtagCliente = Film.getvLogLine();

    for(int iol=0; iol<obj.getCantHashtag();iol++){
        for(int iol3ro=0;iol3ro<Film.getCantHashtag();iol3ro++){
            if(vDeHashtagEmpleado[iol]  ==  vDeHashtagCliente[iol3ro]){
                cout<<"#"<<vDeHashtagEmpleado[iol]<<"   ";
                advertencia = true;
                bandera= true;

            }

        }

    }
    if(bandera==true){
            cout<<endl;
        Film.mostrar();
        bandera=false;
    }

}

if(advertencia==false){
    cout<<endl;
    cout<<"El algoritmo no tiene películas similares. Empleado, busca convercer al Cliente de probar algo distinto/nuevo";
    cout<<endl;
}

}



void ArchivoVideo::algRecomendacion(){

    Video obj;
    int ID;
    cout<<"INGRESE EL ID A BUSCAR:   ";
    cin>>ID;
    int pos=buscarVideo(ID);
    obj=leerPelicula(pos);
    /*
    if(obj.getIDVideo()>0){
        obj.mostrar();
    }else if(obj.getIDVideo()==-3 || obj.getIDVideo()==-1){
        cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
*/

    ///Comparación de hashtag
    comparacionDeHashtag(obj);

}
