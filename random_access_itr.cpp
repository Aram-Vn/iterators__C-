#include <iostream>
#include <vector>

template <typename T>
class Vec
{
public:
    class const_itr
    {
    public:
        const_itr () : ptr(nullptr) {}

        const_itr (const T* ptr1) : ptr(const_cast<T*>(ptr1)) {}

        const_itr& operator= (const const_itr& other) {
            this->ptr = other.ptr;
            return *this;
        }

        const T& operator* () const {
            return *ptr;
        }

        const T* operator-> () const {
            return ptr;
        }

        const_itr& operator++ () {
            ++ptr;
            return *this;
        }  

        const_itr operator++ (int) {
            const_itr tmp = *this;
            ++ptr;
            return tmp;
        }

        const_itr& operator-- () {
            --ptr;
            return *this;
        }

        const_itr operator-- (int) {
            const_itr tmp = *this;
            --ptr;
            return tmp;
        }

        const_itr operator+ (const int n) const {
            const_itr tmp = *this;
            std::cout << "A" << std::endl;
            for (int i = 0; i < n; ++i) {
                ++tmp.ptr;
            }

            return tmp;
        }

        const_itr operator- (const int n) const {
            const_itr tmp = *this;

            for (int i = 0; i < n; ++i) {
                --tmp.ptr;
            }

            return tmp;
        }

        const_itr& operator+= (const int n) {
            for (int i = 0; i < n; ++i) {
                ++this->ptr;
            }

            return *this;
        }

        const_itr& operator-= (const int n) {
            for (int i = 0; i < n; ++i) {
                --this->ptr;
            }

            return *this;
        }

        bool operator== (const const_itr& other) const {
            return this->ptr == other.ptr;
        }

        bool operator!= (const const_itr& other) const {
            return !(this->ptr == other.ptr);
        }

        bool operator> (const const_itr& other) const {
            return this->ptr > other.ptr;
        }

        bool operator< (const const_itr& other) const {
            return this->ptr < other.ptr;
        }

        bool operator>= (const const_itr& other) const {
            return !(this->ptr < other.ptr);
        }

        bool operator<= (const const_itr& other) const {
            return !(this->ptr > other.ptr);
        }

        const T& operator[] (int i) const{
            return *(ptr + i);
        }


    private:
        T* ptr;
    };

    class random_access_itr
    {
    public:
        random_access_itr() : ptr(nullptr) {}

        random_access_itr(T* ptr1) : ptr(ptr1) {}

        random_access_itr&  operator= (const random_access_itr& other) {
            this->ptr = other.ptr;
            return *this;
        }
 
        T& operator* () {
            return *ptr;
        }

        T* operator-> () {
            return ptr;
        }

        random_access_itr& operator++ () {
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

        bool operator== (const random_access_itr& other) const{
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

    private:
        T* ptr;
    };

public:
    Vec (std::initializer_list<T> list) : vec(list) {}

public:
    using r_itr = random_access_itr;
    using c_itr = const_itr;

    const c_itr c_begin() const {
        return c_itr(vec.data());
    }


    r_itr begin() {
        return r_itr(vec.data());
    }

    const c_itr c_end() const {
        return c_itr(vec.data() + vec.size());
    }


    r_itr end() {
        return r_itr(vec.data() + vec.size());
    }



private:
    std::vector<T> vec;
};

int main () {

    const Vec<int> vec = {1, 2, 3, 4, 5, 6};
    Vec<int>::c_itr fit;

    fit = vec.c_begin();

    std::cout << *(fit + 2) << std::endl;


 /*   fit = vec.end() - 2;

    for(Vec<int>::r_itr fit1 = vec.begin() + 2; fit1 != fit; ++fit1) {
        std::cout << *fit1 << " ";
    }
    std::cout << std::endl; */

    
}
