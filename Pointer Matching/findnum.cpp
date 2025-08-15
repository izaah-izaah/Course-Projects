//
//  findnum.cpp
//  Homework1
//
//  Created by Izaah Davila-Elizalde on 1/24/24.
//

#include "findnum.h"
#include <iostream>

using namespace std;
//Recursive Pointer Search
int* find_num(int* arr, int size, int num){
    
    for (int i = 0; i < size; i++){
        if (arr[i] == num){
            return &arr[i]; // retuns address
        }
    }
    return nullptr;
}
