#include <iostream>
#include "memoryController.hpp"
using namespace std;

memoryController::memoryController() {
    ID_modify(-1);
    set_veces_usado(0);
}

int memoryController::get_veces_usado() {
    return veces_usado;
}

void memoryController::suma_veces_usado() {
    veces_usado++;
}

void memoryController::set_veces_usado(int num){
    veces_usado=num;
}

void memoryController::ID_modify(int new_id){
    ID = new_id;
}

int memoryController::get_ID (){
    return ID;
}

int memoryController::getPosition(int position){
    return Array[position];
}

void memoryController::pagetoMemory (int page){
    FILE *archivo;
    int i;
    archivo = fopen("Convertido.dat", "rb");
    int buffer [256];
    fseek(archivo, sizeof(int)*page*256, SEEK_SET);
    fread(buffer, sizeof(int),256,archivo);
    for (i=0; i<256 ; i++){
        Array[i] = buffer[i];
    }
    ID_modify(page);
    fclose(archivo);
}

void memoryController::savetoMemory(int id){
    if (id != -1) {
        FILE *archivo;
        //Utilizamos r+ para escribir en el archivo
        archivo = fopen("Convertido.dat", "r+");
        fseek(archivo, sizeof(int)*(id * 256), SEEK_SET);
        fwrite(Array, sizeof(int), 256, archivo);
        fclose(archivo);
    }
}

