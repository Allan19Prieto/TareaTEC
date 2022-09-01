
#include <iostream>
#include "pagedArray.hpp"
#include "memoryController.hpp"

using namespace std;

//Tenemos el contrusctor..
pagedArray::pagedArray(){
    //Constructor
}

//Cundo utilizamos operator, sobre cargamos un operador, en este caso el []
int &pagedArray::operator[](int index){
    int result;
    int pageID = index / 256;
    int position_in_page = index%256;
    int page_loaded = revisar(pageID);
    if (page_loaded != -1) {

        result=page_loaded;
    }
    else {
        int nueva_pagina = cargar(pageID);
        result = nueva_pagina;
        paginaArray[result].set_veces_usado(0);
    }
    paginaArray[result].suma_veces_usado();
    return paginaArray[result].Array[position_in_page];
}

//Se fija si hay algun espacio libre, sabiendo qeu solo se 
//permiten 6 páginas en l amemoria, lo que se validad aconyinuacion
int pagedArray::check_freeSlot (){
    int i;
    int result = -1;
    int ID;
    for (i=0 ; i<6 ; i++){
        ID= paginaArray[i].optener_identificador();
        if (ID == -1){
            result =i ;
            break;
        }
    }
    return result;
}

//Se carga la memoria y se aplica el algoritmo de remplazo
int pagedArray::cargar (int page_num){
    int freeslot;
    freeslot = check_freeSlot();
    int new_slot;
    if (freeslot != -1){
       paginaArray[freeslot].guardar_Archivo(paginaArray[freeslot].optener_identificador());
        paginaArray[freeslot].pagetoMemory(page_num);
        new_slot = freeslot;
    }
    else{
       int mas_usada1= cambio();
       paginaArray[mas_usada1].guardar_Archivo(paginaArray[mas_usada1].optener_identificador());
        paginaArray[mas_usada1].pagetoMemory(page_num);
        new_slot = mas_usada1;
    }
    return new_slot;
}

//......
int pagedArray::cambio() {
    int veces=0;
    int result = 0;
    int i;
    for (i=0;i<6;i++){
        if (paginaArray[i].get_veces_usado() > veces){
            veces=paginaArray[i].get_veces_usado();
            result=i;
        }
    }
    return result;
}

//Se confirma qeu la pagina qeu se usa tengag el identificador, por decirlo qeu sea la misma,
//hasta qeu llege a alguna qeu ya no lo sea 
int pagedArray::revisar(int pageID){
    int i;
    int result = -1;
    for (i=0;i<6;i++){
        if (paginaArray[i].optener_identificador() == pageID){
            result = i;
            break;
        }
    }
    return result;
}

//Guardamos la pagina para eso utilizamos el identificador
void pagedArray::guardar (){
    int i;
    for (i=0; i<6;i++){
        //tenemos un identificador ID
        paginaArray[i].guardar_Archivo(paginaArray[i].optener_identificador());
    }
}