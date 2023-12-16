#include <iostream>
#include <vector>

template <typename T>
class Vec
{
public:
    class bidirectional_itr
    {
    public:
        bidirectional_itr() : ptr(nullptr) {}

        bidirectional_itr(T* ptr1) : ptr(ptr1) {}

        bidirectional_itr&  operator= (const bidirectional_itr& other) {
            this->ptr = other.ptr;
            return *this;
        }

        T& operator* () {
            return *ptr;
        }

        T* operator-> () {
            return ptr;
        }

        bidirectional_itr& operator++ () {
            ++ptr;
            return *this;
        }

        bidirectional_itr operator++ (int) {
            bidirectional_itr tmp = *this;
            ++ptr;
            return tmp;
        }

        bidirectional_itr& operator-- () {
            --ptr;
            return *ptr;
        }

        bidirectional_itr operator-- (int) {   
            bidirectional_itr tmp = *this;
            --ptr;
            return tmp;
        }


        bool operator== (const bidirectional_itr& other) {
            return this->ptr == other.ptr; 
        }

        bool operator!= (const bidirectional_itr& other) {
            return !(this->ptr == other.ptr);
        }

    private:
        T* ptr;
    };

public:
    Vec (std::initializer_list<T> list) : vec(list) {}

public:
    using b_itr = bidirectional_itr;
    
    b_itr begin() {
        return b_itr(vec.data());
    }

    b_itr end() {
        return b_itr(vec.data() + vec.size());
    }



private:
    std::vector<T> vec;
};

int main (){

    Vec<int> vec = {1, 2, 3, 4, 5, 6};
    Vec<int>::b_itr fit;

    fit = vec.end();

    for(Vec<int>::b_itr fit1 = vec.begin(); fit1 != fit; ++fit1) {
        std::cout << *fit1 << " ";
    }
    std::cout << std::endl;
}