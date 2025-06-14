#ifndef _MY_CONST_ITERATOR_HPP_
#define _MY_CONST_ITERATOR_HPP_

#include "ConstIterator.h"

template<class T>
inline DoubleLinkedList<T>::const_Iterator::const_Iterator(): current(nullptr) {}

template<class T>
inline DoubleLinkedList<T>::const_Iterator::const_Iterator(const DoubleLinkedList<T>::Node* node): current(node) {}

template<class T>
inline DoubleLinkedList<T>::const_Iterator::const_Iterator(const DoubleLinkedList<T>::Iterator& it): current(it.current) {}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator& DoubleLinkedList<T>::const_Iterator::operator++()
{
    if (current)
    {
        current = current->next;
    }

    return *this;
}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator DoubleLinkedList<T>::const_Iterator::operator++(int)
{
    typename DoubleLinkedList<T>::const_Iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator& DoubleLinkedList<T>::const_Iterator::operator--()
{
    if (current)
    {
        current = current->prev;
    }

    return *this;
}

template<class T>
inline const T& DoubleLinkedList<T>::const_Iterator::operator*() const
{
    return current->data;
}

template<class T>
inline bool DoubleLinkedList<T>::const_Iterator::operator!=(const DoubleLinkedList<T>::const_Iterator& other) const
{
    return current != other.current;
}

template<class T>
inline bool DoubleLinkedList<T>::const_Iterator::operator==(const DoubleLinkedList<T>::const_Iterator& other) const
{
    return !(*this != other);
}

#endif //!_MY_CONST_ITERATOR_HPP_