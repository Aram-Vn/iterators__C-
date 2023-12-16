#include <iostream>
#include <vector>

template <typename T>
class Vec
{
public:
    class random_access_itr
    {
    public:
        random_access_itr() : ptr(nullptr) {}

        random_access_itr(T* ptr1) : ptr(ptr1) {}
       
        random_access_itr(const T* ptr1) : ptr(const_cast<T*>(ptr1)) {}


        random_access_itr& operator= (const random_access_itr& other) {
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

        random_access_itr operator+ (const int n) const {
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
            return this->ptr == other.ptr;
        }

        bool operator!= (const random_access_itr& other) const {
            return !(this->ptr == other.ptr);
        }

        bool operator> (const random_access_itr& other) const {
            return this->ptr > other.ptr;
        }

        bool operator< (const random_access_itr& other) const {
            return this->ptr < other.ptr;
        }

        T& operator[] (int i) {
            std::cout << "N" << std::endl;            
            return *(ptr + i);
        }

        const T& operator[] (int i) const {
            std::cout << "C" << std::endl;
            return *(ptr + i);
        }

    private:
        T* ptr;
    };

public:
    Vec(std::initializer_list<T> list) : vec(list) {}

public:
    using r_itr = random_access_itr;

    r_itr begin() const {
        return r_itr(vec.data());
    }

    r_itr end() const {
        return r_itr(vec.data() + vec.size());
    }

    void print() const{
        for(auto a : vec) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<T> vec;
};

int main() {
    const Vec<int> vec = {1, 2, 3, 4, 5, 6};
    Vec<int>::r_itr fit = vec.begin();

    fit[0] = 8;

    vec.print();

    Vec<int> v = {5, 4, 3, 2, 1};
    Vec<int>::r_itr fit1 = v.begin() + 1;

    fit1[0] = 55;
    std::cout << fit1[0] << std::endl;

    return 0;
}
