#ifndef _MY_CONST_REVERSE_ITERATOR_HPP_
#define _MY_CONST_REVERSE_ITERATOR_HPP_

#include "constReverseIterator.h"

template<class T>
inline DoubleLinkedList<T>::const_ReverseIterator::const_ReverseIterator(): current(nullptr) {}

template<class T>
inline DoubleLinkedList<T>::const_ReverseIterator::const_ReverseIterator(const DoubleLinkedList<T>::Node* node):
    current(node) {}

template<class T>
inline DoubleLinkedList<T>::const_ReverseIterator::const_ReverseIterator(const DoubleLinkedList<T>::ReverseIterator& it):
    current(it.current) {}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator& DoubleLinkedList<T>::const_ReverseIterator::operator++()
{
    if (current)
    {
        current = current->prev;
    }

    return *this;
}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator DoubleLinkedList<T>::const_ReverseIterator::operator++(int)
{
    typename DoubleLinkedList<T>::const_ReverseIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator& DoubleLinkedList<T>::const_ReverseIterator::operator--()
{
    if (current)
    {
        current = current->next;
    }

    return *this;
}

template<class T>
inline const T& DoubleLinkedList<T>::const_ReverseIterator::operator*() const
{
    return current->data;
}

template<class T>
inline bool DoubleLinkedList<T>::const_ReverseIterator::operator!=(const DoubleLinkedList<T>::const_ReverseIterator& other) const
{
    return current != other.current;
}

template<class T>
inline bool DoubleLinkedList<T>::const_ReverseIterator::operator==(const DoubleLinkedList<T>::const_ReverseIterator& other) const
{
    return !(*this != other);
}

#endif //!_MY_CONST_REVERSE_ITERATOR_HPP_