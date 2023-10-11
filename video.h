#ifndef VIDEO_H
#define VIDEO_H

#include <clocale>
#include <vector>
#include <string>

#include "cargarCadena.h"

class Video
{
    public:
        Video();

       void cargar();
       void mostrar();

       int tamanioHashtag(int contador);

       int getIDVideo();
     //  std::string getvLogLine() const;
       std::vector<std::string> getvLogLine() const;
       int getCantHashtag();

       void setIDVideo(int id_video);

    private:
    char _nombre[50];
    char _descripcion[1500];
    int _anioEstreno;
    int _idVideo;
    int _stock;
    long long _codDeBarra;
    int _duracion;
    ///El objetivo del logLine es seducir al lector de forma muy rápida. Comienzan con # (para los cout)
    char _vLogLine[10][50];
    int _cantHashtag;
    bool _estado;


};

#endif // VIDEO_H
