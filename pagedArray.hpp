#ifndef PAGEDARRAY_HPP
#define PAGEDARRAY_HPP 

#include "memoryController.hpp"

class pagedArray {

    public:
    pagedArray();
    int cambio();
    int &operator[] (int index);
    int revisar (int PageID);
    int cargar (int page_num);
    int check_freeSlot ();
    void guardar ();
    memoryController paginaArray [6]; 
};
#endif 