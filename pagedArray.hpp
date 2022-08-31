#ifndef PAGEDARRAY_HPP
#define PAGEDARRAY_HPP 

#include "memoryController.hpp"

class pagedArray {

    public:
    pagedArray();
    //int &operator[] (int index);
    int cambio();
    int &operator[] (int index);
    int check_Page (int PageID);
    int page_loader (int page_num);
    int check_freeSlot ();
    memoryController paginaArray [6]; 
    void saveAll ();
};
#endif 