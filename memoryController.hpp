#ifndef MEMORYCONTROLLER_HPP
#define MEMORYCONTROLLER_HPP 

class memoryController {
    
    public:
    int ID;
    int veces_usado;
    int get_veces_usado();
    void suma_veces_usado();
    void set_veces_usado(int num);

    memoryController();
    int Array[256];
    void pagetoMemory (int page);
    int getPosition(int position);
    void savetoMemory(int id);
    void ID_modify(int new_id);
    int get_ID ();
};
#endif 