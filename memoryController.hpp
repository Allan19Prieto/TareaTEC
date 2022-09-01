#ifndef MEMORYCONTROLLER_HPP
#define MEMORYCONTROLLER_HPP 

class memoryController {
    
    public:
    memoryController();

    int ID;
    int veces_usado;
    int Array[256];
    
    int get_veces_usado();
    int optener_identificador();
    int getPosition(int position);

    void suma_veces_usado();
    void set_veces_usado(int num);
    void pagetoMemory (int page);
    void guardar_Archivo(int id);
    void Cambiar_identificador(int new_id);

    
};
#endif 