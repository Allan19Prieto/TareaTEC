#include <iostream>
#include <fstream>
#include "fstream"
#include "funtion.hpp"
#include "pagedArray.hpp"

using namespace std;

void funtion::quickSort(pagedArray *arr, int start, int end) {
    int pivot = arr->operator[]((start + end)/2);
    int i = start, j = end;
    while (i <= j) {
        while ( arr->operator[](i) < pivot)
            i++;
        while ( arr->operator[](j) > pivot)
            j++;
        if ( i <= j) {
            swap(arr->operator[](i++), arr->operator[](j++));
        }
    }
    if ( start < j)
        quickSort(arr, start, j);
    if ( end > i)
        quickSort(arr, i, end);
}

void funtion::insertionSort(pagedArray *arr, int length) {
    for ( int i=1; i< length; i++) {
        int key = arr->operator[](i);
        int j = i-1;
        while ( j>=0 && arr->operator[](j)>key) {
            arr->operator[](j+1) = arr->operator[](j);
            j--;
        }
        arr->operator[](j+1) = key;
    }
}

void funtion::selectionSort(pagedArray *arr, int n) {
    int key;
    for ( int i=0; i<n; i++) {
        key = i;
        for ( int j=i+1; j<n; j++) {
            if ( arr->operator[](j) < arr->operator[](key))
                key = j;
            if ( key != i)
                swap(arr->operator[](key), arr->operator[](i));
        }
    }
}

void funtion::BT(pagedArray *pArray, int tamano_archivo, string newfilename) {
    string filedirection = newfilename;
    ofstream newFile;
    newFile.open(filedirection);
    int i;
    int num;
    string allarray = "";
    string numastring;
    for (i=0;i<tamano_archivo;i++){
        num = pArray->operator[](i);
        numastring = to_string(num);
        allarray = allarray+numastring + ",";
    }
    newFile << allarray;
}

//Tomado de este págiba
//https://github.com/Danicast-c/TEC-DATOSII-pagedArray/blob/master/fileGnerator.cpp

void funtion::fileGnerator(int arr[], int tamano_archivo)
{
    int i;

    int valor=tamano_archivo;

    FILE *archivo;
    archivo = fopen("Convertido.dat", "wb");
    if (archivo) {

        //Pasamos a vinario, y escribimos con el fwrite, le pasamos el tamaño necesario
        fseek(archivo,0,SEEK_SET);
        fwrite(arr, sizeof(int), tamano_archivo  , archivo);

    }
    else {

        cout << "No fue posible crear el archivo" << endl;
    }
    fclose(archivo);



    FILE *archivo1;
    archivo1 = fopen("Convertido.dat", "rb");

    fseek(archivo1, 0, SEEK_END);
    long lsize = ftell(archivo1);
    rewind(archivo1);

    int buffer [lsize/sizeof(int)];
    fread(buffer, sizeof(int),tamano_archivo,archivo1);
    fclose(archivo1);
}
