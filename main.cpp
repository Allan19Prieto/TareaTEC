//Recordar para compilar el archivo
// g++ main.cpp function.cpp memoryController.cpp pagedArray.cpp -o paged-sort
// ./paged-sort -i archivostxt/36KB.txt -a IS -o respuesta.txt
#include <iostream>
#include <fstream>
#include "pagedArray.hpp"
#include "funtion.hpp"
#include "memoryController.hpp"
#include "fstream"

using namespace std;

int main(int argc, char *argv[]) {
    //Validación de la entrada....
    if (argc != 7 ) {
        cout << " ***************************\n";
        cout << " ups!! Se presento un problema...!!\n";
        cout << " Recuerda el formato para correr el programa: \n";
        cout << "   paged-sort -i <archivo.txt> -a {QS|IS|SS} -o <archivo_resultado.txt>  \n";
        cout << " ***************************\n";
        return 1;
    }

    //Variable a utilizar
    string archivo_leer = argv[2];
    string parametro_sort = argv[4];
    string archivo_ordenado = argv[6];
    ifstream file_leer;
    string datos;
    int tamano_archivo = 0;
    int cont=0;
    ifstream file_llenar;
    pagedArray pArray;

    //validamos el parametro QS/IS/SS
    if (parametro_sort!="QS" and parametro_sort!="IS" and parametro_sort!="SS") {
        cout << " ups!! Se presento un problema  en el parametro de busqueda...!!\n";
        cout << " Recuerda qeu solo puede ser: QS, IS, SS...\n";
        return 1;
    }

    //Validamos  el nombre del archivo
    file_leer.open(archivo_leer);
    if ( !file_leer) {
        cout << " el archivo a leer no se encuentra con ese formato..\n";
        cout << " Recuenda el formato es: <archivo.txt> ";
        exit(1);
    }

    //Contamos en tamaño del archivo
    while (getline(file_leer, datos, ',')) { 
        tamano_archivo++;
    }
    file_leer.close();

    //llenamos el array con los datos del archivo y usamos el tamaño averiguado
    int array[tamano_archivo];
    file_llenar.open(archivo_leer);
    while (getline(file_llenar, datos, ',')) {
        array[cont] = stoi(datos);
        cont++;
    }
    file_llenar.close();

    //Se genera el archivo con el array y el tamaño qeu se necesita
    funtion::fileGnerator(array, tamano_archivo);

    //Creamos la validación de cual de los algoritmos fue el selecionado
    if ( parametro_sort == "QS") {
        funtion::quickSort(&pArray, 0, tamano_archivo);
    }else if ( parametro_sort == "IS") {
        funtion::insertionSort(&pArray, tamano_archivo);
    }else if ( parametro_sort == "SS") {
        funtion::selectionSort(&pArray, tamano_archivo);
    }

    //Guardamos lo que tenemos en el archivo binario
    pArray.guardar();

    //Pasamos a texto y guardamos con el nombre que indicamos
    funtion::BT(&pArray, tamano_archivo, archivo_ordenado);

    //Eliminamos el archivo almacenado en memoria
    remove("Convertido.dat");

    return 0;
}


