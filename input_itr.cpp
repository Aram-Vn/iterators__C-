#include  <iostream>
#include <vector>
#include <initializer_list>

template <typename T>
class vector
{
public:
    class iterator
    {
    public:
        explicit iterator(T* ptr1) : ptr(ptr1) {}

        const T& operator* () {
            return *ptr;
        }

        const T* operator-> () {
            return ptr;
        } 

        const iterator& operator= (const iterator& other) {
            this->ptr = other.ptr;
            return *this;
        }

        iterator& operator++ () {
            ++ptr;
            return *this;
        }

        iterator operator++ (int) {
            iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator== (const iterator& other) {
            return this->ptr == other.ptr;
        }

        bool operator!= (const iterator& other) {
            return !(this->ptr == other.ptr);
        }    
        
        private:
        T* ptr;
    };
public:
    using itr = iterator;
    
    itr begin() {
        return itr(vec.data()); 
    }
    
    itr end() {
        return itr(vec.data() + vec.size());
    }
    
    vector(std::initializer_list<T> list) : vec(list) {}

private:
    std::vector<T> vec;
};

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    for(vector<int>::itr it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
