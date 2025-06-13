#ifndef _MY_ITERATOR_HPP_
#define _MY_ITERATOR_HPP_

#include "Iterator.h"

template<class T>
inline DoubleLinkedList<T>::Iterator::Iterator(): current(nullptr) {}

template<class T>
inline DoubleLinkedList<T>::Iterator::Iterator(DoubleLinkedList<T>::Node* node): current(node) {}

template<class T>
inline typename DoubleLinkedList<T>::Iterator& DoubleLinkedList<T>::Iterator::operator++()
{
    if (current)
    {
        current = current->next;
    }

    return *this;
}

template<class T>
inline typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::Iterator::operator++(int)
{
    typename DoubleLinkedList<T>::Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T>
inline typename DoubleLinkedList<T>::Iterator& DoubleLinkedList<T>::Iterator::operator--()
{
    if (current)
    {
        current = current->prev;
    }

    return *this;
}

template<class T>
inline T& DoubleLinkedList<T>::Iterator::operator*()
{
    return current->data;
}

template<class T>
inline bool DoubleLinkedList<T>::Iterator::operator!=(const DoubleLinkedList<T>::Iterator& other) const
{
    return current != other.current;
}

template<class T>
inline bool DoubleLinkedList<T>::Iterator::operator==(const DoubleLinkedList<T>::Iterator& other) const
{
    return !(*this != other);
}

#endif //!_MY_ITERATOR_HPP_