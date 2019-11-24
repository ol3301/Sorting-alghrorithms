#include "ArrayUtil.h"

void showArr(int* arr){
    for(unsigned int i=0; i<arrLength;++i){
        std::cout << "[" << std::to_string(arr[i]) << "]";
    }
    std::cout << std::endl;
}

int* initArr(){
    int* arr = new int[arrLength];

    for(int i=0; i< arrLength; ++i){
        arr[i] = rand() % 100;
    }

    return arr;
}

std::string showArr (int* l, int* r){
    std::string res;
    for(int* i=l; i < r;++i){
        res+="["+std::to_string(*i)+"]";
    }
    return res;
}