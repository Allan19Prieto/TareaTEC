#include <iostream>
#include "memoryController.hpp"
using namespace std;

memoryController::memoryController() {
    Cambiar_identificador(-1);
    set_veces_usado(0);
}

//Tenesmo ls veces qeu pasamos por un apágina
int memoryController::get_veces_usado() {
    return veces_usado;
}

//Contando las veces qeu se utiliza
void memoryController::suma_veces_usado() {
    veces_usado++;
}

//Obtenemos la s veces qeu se usa
void memoryController::set_veces_usado(int num){
    veces_usado=num;
}

//Cambiamos el ID qeu tenia la página
void memoryController::Cambiar_identificador(int new_id){
    ID = new_id;
}

//Optenemos el ID de la página
int memoryController::optener_identificador(){
    return ID;
}

//Nos devuelve la posicion en la que se encuantra la "pagina"
int memoryController::getPosition(int position){
    return Array[position];
}


void memoryController::pagetoMemory (int page){

    FILE *archivo;
    int i;
    //Vamos guardando lo qeu hay en memoria en el archivo qeu se creo intermedio
    archivo = fopen("Convertido.dat", "rb");
    int buffer [256];
    //Funciones por defecto de fssek
    fseek(archivo, sizeof(int)*page*256, SEEK_SET);
    fread(buffer, sizeof(int),256,archivo);
    //array con las dimenciones del archivo, y las necesarias de 256
    for (i=0; i<256 ; i++){
        Array[i] = buffer[i];
    }
    //cambiamos a la pagina qeu estamos utilizando ahora
    Cambiar_identificador(page);
    fclose(archivo);
}

//Guardamos lo que esta la pagina del Id AL ARCHIVO BINARIO
void memoryController::guardar_Archivo(int id){
    if (id != -1) {
        FILE *archivo;
        //Utilizamos r+ para escribir en el archivo
        archivo = fopen("Convertido.dat", "r+");
        fseek(archivo, sizeof(int)*(id * 256), SEEK_SET);
        fwrite(Array, sizeof(int), 256, archivo);
        fclose(archivo);
    }
}

