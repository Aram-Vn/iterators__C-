#include <iostream>
#include <vector>

template <typename T>
class Vec
{
public:
    class random_access_itr
    {
    public:
        random_access_itr() : 
            ptr(nullptr),
            c_ptr(nullptr)
        {}

        random_access_itr(T* ptr1) : 
            ptr(ptr1),
            c_ptr(nullptr) 
        {}

        random_access_itr(const T* ptr1) : 
            ptr(nullptr),
            c_ptr(ptr1)
        {}

        random_access_itr&  operator= (const random_access_itr& other) {
            this->ptr = other.ptr;
            return *this;
        }

        //random_access_itr(const T* ptr1) : ptr(const_cast<T*>(ptr1)) {}
 
        T& operator* () {
            return *ptr;
        }

        const T& operator* () const {
            return *c_ptr;
        }

        T* operator-> () {
            return ptr;
        }

        const T* operator-> () const {
            return c_ptr;
        }

        random_access_itr& operator++ () {
            std::cout << "const ++" << std::endl;
            ++ptr;
            return *this;
        }

        random_access_itr operator++ (int) {
            random_access_itr tmp = *this;
            ++ptr;
            return tmp;
        }

        random_access_itr operator+ (const int n) {
            random_access_itr tmp = *this;

            for (int i = 0; i < n; ++i) {
                ++tmp.ptr;
            }

            return tmp;
        }

        random_access_itr operator- (const int n) const {
            random_access_itr tmp = *this;

            for (int i = 0; i < n; ++i) {
                --tmp.ptr;
            }

            return tmp;
        }

        random_access_itr& operator-= (const int n) {
            for (int i = 0; i < n; ++i) {
                --this->ptr;
            }

            return *this;
        }

        random_access_itr& operator+= (const int n) {
            for (int i = 0; i < n; ++i) {
                ++this->ptr;
            }

            return *this;
        }

        bool operator== (const random_access_itr& other) const {
            std::cout << "const" << std::endl;
            return this->c_ptr == other.c_ptr; 
        }

        bool operator== (const random_access_itr& other) {
            std::cout << "not const" << std::endl;
            return this->ptr == other.ptr; 
        }

        bool operator!= (const random_access_itr& other) const {
            return !(this->ptr == other.ptr);
        }

        bool operator> (const random_access_itr& other) const {
            if( this->ptr > other.ptr) {
                return true;
            }

            return false;
        }

        bool operator< (const random_access_itr& other) const {
            return this->ptr < other.ptr;
        }

        T& operator[] (int i) {
            return *(ptr + i);
        }

        const T& operator[] (int i) const {
            random_access_itr tmp = *this;
        
            return *(tmp.c_ptr + i);
        }


    private:
        T* ptr;
        const T* c_ptr;
    };

public:
    Vec (std::initializer_list<T> list) : vec(list) {}

public:
    using r_itr = random_access_itr;
    
    const r_itr c_begin() const {
        return r_itr(vec.data());
    }


    r_itr begin() {
        return r_itr(vec.data());
    }

    const r_itr c_end() const {
        return r_itr(vec.data() + vec.size());
    }


    r_itr end() {
        return r_itr(vec.data() + vec.size());
    }



private:
    std::vector<T> vec;
};

int main () {

    const Vec<int> vec = {1, 2, 3, 4, 5, 6};
    const Vec<int>::r_itr fit = vec.c_begin();

    //fit[0] = 8;

    std::cout << *(fit) << std::endl;

    if(fit == fit) {
       // std::cout << "YES" << std::endl;
    }

 /*   fit = vec.end() - 2;

    for(Vec<int>::r_itr fit1 = vec.begin() + 2; fit1 != fit; ++fit1) {
        std::cout << *fit1 << " ";
    }
    std::cout << std::endl; */

    
}