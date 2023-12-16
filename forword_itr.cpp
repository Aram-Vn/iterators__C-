#include <iostream>
#include <vector>

template <typename T>
class Vec
{
public:
    class forword_itr
    {
    public:
        forword_itr() : ptr(nullptr) {}

        forword_itr(T* ptr1) : ptr(ptr1) {}

        forword_itr&  operator= (const forword_itr& other) {
            this->ptr = other.ptr;
            return *this;
        }

        T& operator* () {
            return *ptr;
        }

        T* operator-> () {
            return ptr;
        }

        forword_itr& operator++ () {
            ++ptr;
            return *this;
        }

        forword_itr operator++ (int) {
            forword_itr tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator== (const forword_itr& other) {
            return this->ptr == other.ptr; 
        }

        bool operator!= (const forword_itr& other) {
            return !(this->ptr == other.ptr);
        }

    private:
        T* ptr;
    };

public:
    Vec (std::initializer_list<T> list) : vec(list) {}

public:
    using f_itr = forword_itr;
    
    f_itr begin() {
        return f_itr(vec.data());
    }

    f_itr end() {
        return f_itr(vec.data() + vec.size());
    }



private:
    std::vector<T> vec;
};

int main (){

    Vec<int> vec = {1, 2, 3, 4, 5, 6};
    Vec<int>::f_itr fit;

    fit = vec.end();

    for(Vec<int>::f_itr fit1 = vec.begin(); fit1 != fit; ++fit1) {
        std::cout << *fit1 << " ";
    }
    std::cout << std::endl;
}