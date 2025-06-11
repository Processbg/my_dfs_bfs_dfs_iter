#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

#include <stdexcept>
#include <iostream>

#include "../headers/Vector.h"

template<class T>
inline Vector<T>::Vector(): numberOfElements(0), capacity(0), container(nullptr)
{}

template<class T>
inline Vector<T>::Vector(const Vector<T>& other): numberOfElements(0) { copy(other); }

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    
    return *this;
}

template<class T>
inline Vector<T>::~Vector()
{
    destroy();
}

template<class T>
inline bool Vector<T>::isEmpty() const
{
    return numberOfElements == 0;
}

template<class T>
inline size_t Vector<T>::numElements() const
{
    return numberOfElements;
}

template<class T>
inline size_t Vector<T>::getCapacity() const
{
    return capacity;
}

template<class T>
inline void Vector<T>::destroy()
{
    delete[] container;
}

template<class T>
inline void Vector<T>::copy(const Vector<T>& other)
{
    capacity = other.capacity;
    resize(capacity);
    numberOfElements = other.numberOfElements;

    for (size_t i = 0; i < numberOfElements; ++i)
    {
        container[i] = other.container[i];
    }   
}

template<class T>
inline void Vector<T>::resize(size_t newSize)
{
    T* newContainer = new(std::nothrow) T[newSize];
    if (!newContainer)
    {
        std::cerr << "Can not allocate memory for tmpContainer in Stack::resize.\n";
        return;
    }

    for (size_t i = 0 ; i < numberOfElements; ++i)
    {
        newContainer[i] = container[i];
    }

    destroy();
    container = newContainer;
    newContainer = nullptr;
    capacity = newSize;
}

template<class T>
inline void Vector<T>::push_back(const T& value)
{
    if (numberOfElements >= capacity)
    {
        resize(capacity == 0 ? 1 : capacity * 2);
    }

    container[numberOfElements] = value;
    ++numberOfElements;
}

template<class T>
inline T Vector<T>::pop()
{
    T lastValue = container[numberOfElements - 1];
    --numberOfElements;
    return lastValue;
}

template<class T>
inline T& Vector<T>::operator[](size_t index)
{
    return container[index];
}

template<class T>
inline const T& Vector<T>::operator[](size_t index) const
{
    return container[index];
}

#endif //!_MY_VECTOR_HPP_
