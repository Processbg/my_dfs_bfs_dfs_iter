#ifndef _MY_VECTOR_H_
#define _MY_VECTOR_H_

#include <cstddef>

template<class T>
class Vector
{
public:
    Vector();
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other); 
    ~Vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(const T& value);
    T pop();
    bool isEmpty() const;
    size_t numElements() const;
    size_t getCapacity() const;
    void resize(size_t newSize);

private:
    void copy(const Vector<T>& other);
    void destroy();

    T* container;
    size_t numberOfElements;
    size_t capacity;
};

#include "Vector.hpp"

template<class T>
void printVector(const Vector<T>& vector)
{
    std::cout << "Contents of vector is [";
    
    size_t sizeOfVector = vector.numElements();
    for (size_t i = 0; i < sizeOfVector; ++i)
    {
        if (i == sizeOfVector - 1)
        {
            std::cout << vector[i];
            continue;
        }
        std::cout << vector[i] << ", ";
    }
    std::cout << "]\n";
}

#endif // !_MY_VECTOR_H_