#ifndef ARCHIVOVIDEO_H
#define ARCHIVOVIDEO_H
#include "video.h"

class ArchivoVideo
{
    public:

         ArchivoVideo();

         void mostrarRegistros();
         void agregarRegistro();
         int cantidadRegistros();
         Video leerPelicula(int pos);
         int buscarVideo(int d);
         void algRecomendacion();
         void comparacionDeHashtag(Video obj);


        private:
        char nombre[30];
        char bkp[30]="Peliculas.bkp";

};

#endif // ARCHIVOVIDEO_H
