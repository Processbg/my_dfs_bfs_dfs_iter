#ifndef _MY_QUEUE_HPP_
#define _MY_QUEUE_HPP_

#include "../headers/Queue.h"

template<class T>
inline Queue<T>::Queue()
{}

template<class T>
inline Queue<T>::~Queue()
{}

template<class T>
inline Queue<T>::Queue(const Queue<T>& other){ copy(other); }

template<class T>
inline Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other)
    {
        copy(other);
    }

    return *this;
}

template<class T>
inline void Queue<T>::copy(const Queue<T>& other)
{
    list = other.list;
}

template<class T>
inline void Queue<T>::push_back(const T& value)
{
    list.push_back(value);
}

template<class T>
inline T Queue<T>::pop()
{
    return list.pop_front();
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
    return list.isEmpty();
}

template<class T>
inline size_t Queue<T>::numElements() const
{
    return list.numElements();
}

#endif //!_MY_QUEUE_HPP_