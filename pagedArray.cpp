
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
    int page_loaded = check_Page(pageID);
    if (page_loaded != -1) {

        result=page_loaded;
    }
    else {
        int nueva_pagina = page_loader(pageID);
        result = nueva_pagina;
        paginaArray[result].set_veces_usado(0);
    }
    paginaArray[result].suma_veces_usado();
    return paginaArray[result].Array[position_in_page];
}

int pagedArray::check_Page(int pageID){
    int i;
    int result = -1;
    for (i=0;i<6;i++){
        if (paginaArray[i].get_ID() == pageID){
            result = i;
            break;
        }
    }
    return result;
}

int pagedArray::check_freeSlot (){
    int i;
    int result = -1;
    int ID;
    for (i=0 ; i<6 ; i++){
        ID= paginaArray[i].get_ID();
        if (ID == -1){
            result =i ;
            break;
        }
    }
    return result;
}

int pagedArray::page_loader (int page_num){
    int freeslot;
    freeslot = check_freeSlot();
    int new_slot;
    if (freeslot != -1){
       paginaArray[freeslot].savetoMemory(paginaArray[freeslot].get_ID());
        paginaArray[freeslot].pagetoMemory(page_num);
        new_slot = freeslot;
    }
    else{
       int mas_usada1= cambio();
       paginaArray[mas_usada1].savetoMemory(paginaArray[mas_usada1].get_ID());
        paginaArray[mas_usada1].pagetoMemory(page_num);
        new_slot = mas_usada1;
    }
    return new_slot;
}

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

void pagedArray::saveAll (){
    int i;
    for (i=0; i<6;i++){
        //tenemos un identificador ID
        paginaArray[i].savetoMemory(paginaArray[i].get_ID());
    }
}