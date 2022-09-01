#ifndef FUNTION_HPP
#define FUNTION_HPP 

#include <iostream>
#include "pagedArray.hpp"
#include "memoryController.hpp"
//#include "fstream"
using namespace std;

class funtion
{
    public:
    static void quickSort(pagedArray *arr, int start, int end);
    static void insertionSort(pagedArray *arr, int length);
    static void selectionSort(pagedArray *arr, int n);
    static void fileGnerator(int arr[], int size);
    static void BT(pagedArray *pArray, int size, string newfilename);
};
#endif 