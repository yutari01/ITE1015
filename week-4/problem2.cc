#include <iostream>

template <typename T>

struct dynamic_array {
    T* pointer = nullptr;
    size_t cap=0;


public:
    dynamic_array(size_t cap)
    : cap(cap) {
        this->pointer =new T[cap];
        
    }

    void push_front(const T& element) {
        T* temp_ = new T[cap];
        
        for(size_t i=0;i<cap;i++) {
            temp_[i]=pointer[i];

        }

        delete[] pointer;
        pointer= new T[cap+1];

        for(size_t i=0;i<cap;i++) {
            pointer[i+1]=temp_[i];

        }
        pointer[0]=element;
        
        cap = cap+1;
        
        delete[] temp_;
 
    }

    void push_back(const T& element) {
        T* temp_ = new T[cap];
        
        for(size_t i=0;i<cap;i++) {
            temp_[i]=pointer[i];

        }

        delete[] pointer;
        pointer= new T[cap+1];

        for(size_t i=0;i<cap;i++) {
            pointer[i]=temp_[i];

        }
        pointer[cap]=element;
        
        cap = cap + 1;
        
        delete[] temp_;
    

    }

    T pop_front() {
        T* temp_ = new T[cap];
        
        for(size_t i=0;i<cap;i++) {
            temp_[i]=pointer[i];

        }

        T pop = pointer[0];
        
        delete[] pointer;
        pointer= new T[cap-1];

        for(size_t i=0;i<cap-1;i++) {
            pointer[i]=temp_[i+1];
        }
        
       
        cap = cap-1;
        
        delete[] temp_;
        
        return pop;
    }

    T pop_back() {
        T* temp_ = new T[cap];
        
        for(size_t i=0;i<cap;i++) {
            temp_[i]=pointer[i];

        }

        T pop = pointer[cap-1];
        
        delete[] pointer;
        pointer= new T[cap-1];

        for(size_t i=0;i<cap-1;i++) {
            pointer[i]=temp_[i];
        }
        
       
        cap = cap-1;
        
        delete[] temp_;
        
        return pop;

    }

    ~dynamic_array() {
        delete[] this->pointer;
    }
};

int main() {
    return 0;
}
