#include <iostream>

template<typename T>
class Iterator{
private:
    T* memory;


public:
    Iterator(T* temp)
    : memory(temp) {}
    Iterator& operator++() {
        memory++;
        return *this;
    }

    Iterator& operator++(int a) {
        memory++;
        return *this;
    }

    T operator*(void) {
        return * memory;
    }
};


template <typename T>
class Vector {
private:
    T* steam;
    int _size_;
    int _cap_;


public:

    typedef Iterator<T> iterator;

    Vector()
    : steam(nullptr), _size_(0), _cap_(1) {
        steam = new T[_cap_];

    }

    Vector(int size)
    : steam(nullptr), _size_(size), _cap_(1 + size) {
        steam = new T[_cap_];

    }

    Vector(int size, T what)
    : steam(nullptr), _size_(size), _cap_(1 + size) {
        steam = new T[_cap_];
        for(int i = 0; i < _size_; i++)
            steam[i] = what;

    } 
    
    ~Vector() {delete[] steam;}

    int capacity() 
    {
        return _cap_;
    }

    int size() 
    {
        return _size_;
    }
    
    bool empty() {
        if(size() != 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void clear() {
        _size_ = 0;
    }

    void erase(int del_num) {
        T* temp = new T[_cap_];

        for(int i=0; i < size(); i++) 
        {
            temp[i] = steam[i];
        }

        steam = new T[_cap_];

        for(int i=0; i < del_num; i++)
        {
            steam[i] = temp[i];
        }

        for(int i= del_num; i < size()-1; i++) 
        {
            steam[i] = temp[i+1];
        }
        _size_  = _size_ - 1;
        delete[] temp;
    }

    void push_back(T& input) {
        if(_size_ >= _cap_) 
        {
            _cap_ = _cap_ * 2;

            T* temp = new T[_cap_];
            for(int_fast16_t i=0; i < size(); i++) 
            {
                temp[i] = steam[i];
            }
            steam = new T[_cap_];
            
            for(int i=0; i < size(); i++) 
            {
                steam[i] = temp[i];
            }
            steam[_size_] = input;
            
            delete[] temp;
        }

        else
        {
            steam[_size_] = input;
        }

        _size_ = _size_ + 1;
    }

    void pop_back() 
    {
        _size_ = _size_ - 1;
        steam[_size_-1] = 0;
    }

    T& operator[](int number) 
    {
        return steam[number];
    }

    T* insert(int index, T& num) {
        if(_size_ >= _cap_)
            _cap_ = _cap_*2;
        
        T* temp = new T[_cap_];
        for(int i=0; i < size(); i++) 
            temp[i] = steam[i];
        
        steam = new T[_cap_];
        for(int i =0; i < index ; i++)
            steam[i] = temp[i];
        steam[index] = num;
        for(int i = index+1; i < size()+1; i++)
            steam[i] = temp[i-1];
        
        _size_++;
        delete[] temp;
        return steam + index;
    }





    void resize(int resize_num) {
         _size_ = resize_num;
    }

    iterator begin() 
    {
        return steam;
    }

    iterator end() 
    {
        return steam + _size_;
    }

    T& front() 
    {
        return steam[0];
    }

    T& back() {
        return steam[_size_ -1];
    }
    


    Vector& operator=(const Vector &same) {
        _size_ = same._size_;
        _cap_ = same._cap_;

        steam = new T[_cap_];

        for(int i = 0; i < _size_ ; i++) 
        {
            steam[i] = same.steam[i];
        }
        
        return *this;
    }

    void assign(int count, const T& newone) {
        if(count >= _cap_) 
        {
            _cap_ = count*2;
        }
        steam = new T[_cap_];
        for(int i = 0;  i < count ; i++)
            steam[i] = newone;
        _size_ = count;
    }


    friend std::ostream& operator<<(std::ostream& out, Vector<T>& vector){
        for(int i =0 ; i < vector.size();i++)
        {
            out << vector[i] << ", ";
        }
        std::cout << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Vector<T>& vector){
        T temp;
        in >> temp;
        vector.push_back(temp);
        return in;
    }
};
