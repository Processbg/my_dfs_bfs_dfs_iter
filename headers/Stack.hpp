#ifndef _MY_STACK_HPP_
#define _MY_STACK_HPP_

#include <stdexcept>
#include <iostream>

#include "../headers/Stack.h"

template<class T>
inline Stack<T>::Stack(): numberOfElements(0), capacity(1), container(nullptr)
{}

template<class T>
inline Stack<T>::Stack(const Stack<T>& other){ copy(other); }

template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }
    
    return *this;
}

template<class T>
inline Stack<T>::~Stack()
{
    destroy();
}

template<class T>
inline bool Stack<T>::isEmpty() const
{
    return numberOfElements == 0;
}

template<class T>
inline size_t Stack<T>::numElements() const
{
    return numberOfElements;
}

template<class T>
inline void Stack<T>::destroy()
{
    delete[] container;
}

template<class T>
inline void Stack<T>::copy(const Stack<T>& other)
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
inline void Stack<T>::resize(size_t newSize)
{
    T* tmpContainer = new(std::nothrow) T[newSize];
    if (!tmpContainer)
    {
        std::cerr << "Can not allocate memory for tmpContainer in Stack::resize.\n";
        return;
    }

    for (size_t i = 0 ; i < numberOfElements; ++i)
    {
        tmpContainer[i] = container[i];
    }

    container = tmpContainer;
    tmpContainer = nullptr;
    capacity = newSize;
}

template<class T>
inline void Stack<T>::push_back(const T& value)
{
    if (container == nullptr && numberOfElements == 0 && capacity == 1)
    {
        resize(capacity);
        container[numberOfElements] = value;
        ++numberOfElements;
    }
    else if (numberOfElements == capacity)
    {
        capacity = capacity * 2;
        resize(capacity);
        container[numberOfElements] = value;
        ++numberOfElements;
    }
    else if (numberOfElements < capacity)
    {
        container[numberOfElements] = value;
        ++numberOfElements;
    }
}

template<class T>
inline T Stack<T>::pop()
{
    T lastValue = container[numberOfElements - 1];
    --numberOfElements;
    return lastValue;
}

template<class T>
inline T& Stack<T>::operator[](size_t index)
{
    return container[index];
}

template<class T>
inline const T& Stack<T>::operator[](size_t index) const
{
    return container[index];
}

#endif //!_MY_STACK_HPP_
