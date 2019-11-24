#include <set>
#include "SortingAlgorithms.h"

//Сортировка пузырьком
void bubblesort(int* arr, unsigned int length) {
    bool b = true;

    while (b){
        b = false;
        for(unsigned int i=0; i+1 < length; ++i){
            int first = arr[i];
            int second = arr[i+1];

            if(first > second){
                std::swap(arr[i], arr[i+1]);
                b = true;
            }
        }
        --length;
    }
}

//Шейкерная сортировка
void shakersort(int* arr, unsigned int length){
    bool b = true;

    int* begin=arr-1;
    int* end = &arr[length];

    while(b){
        b = false;

        ++begin;
        for(int* i = begin; i<end; ++i){
            if(*i > *(i+1)){
                std::swap(*i,*(i+1));
                b=true;
            }
        }

        showArr(arr);
        if(!b) break;

        --end;

        for(int* i=end; i > begin; --i){
            if(*i < *(i-1)){
                std::swap(*i, *(i-1));
                b = true;
            }
        }
        showArr(arr);

    }
}

//Сортировка расческой
void combsort(int* arr, unsigned int length){
    int step = length/2;

    while(step > 1){
        for(unsigned int i=step; i+1 < length; ++i){
            if(arr[i] > arr[i+1]){
                std::swap(arr[i], arr[i+1]);
            }
        }
        --step;
    }

    bubblesort(arr,length);
}

//Сортировка вставками
void insertionsort(int* arr, unsigned int length){
    for(unsigned int i=1; i < length; ++i){
        int j =i;

        while(j > 0 && arr[j-1] > arr[j]){
            std::swap(arr[j-1], arr[j]);
            --j;
        }
    }
}

//Сортировка деревом
void treesort(int* arr, unsigned int length){
    std::multiset<int > set;

    for(unsigned int i =0;i< length; ++i) {
        set.insert(arr[i]);
    }

    for(int q:set){
        *arr = q, ++arr;
    }
}