#include <iostream>

int* array;
size_t cap = 0;

void initialize(int cap_) {
    array = new int[cap_]; //array
    cap = cap_;
}

void release() {
    delete[] array;
}

void push_back(int element) {
    int* temp_array = new int[cap];
    for(size_t i=0;i<cap;i++){
        temp_array[i]=array[i];
    }
    
    release();

    array= new int[cap+1];
    for(size_t i=0;i<cap;i++){
        array[i]=temp_array[i];
    }

    array[cap]=element;
    delete[] temp_array;
    cap = cap + 1;


}

int pop_back() {
    // TODO:
    // return last element of array and remove it from array
    // if array is [1,2,3,4] and pop_back() called,
    // then array should be [1,2,3] and pop_back() return 4.
    int* temp_array= new int[cap-1];
    int no_more_element;
    
    for(size_t i=0;i<(cap-1);i++) {
        temp_array[i]=array[i];
    }
    
    no_more_element=array[cap-1];
    release();

    array= new int[cap-1];
    for(size_t i=0;i<(cap-1);i++) {
        array[i]=temp_array[i];
    }
    
    cap = cap - 1;
    delete[] temp_array;
    return no_more_element;

}

int len() {
    return cap;
}

int main() {
    return 0;
}