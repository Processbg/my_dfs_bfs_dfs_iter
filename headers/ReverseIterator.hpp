#ifndef _MY_REVERSE_ITERATOR_HPP_
#define _MY_REVERSE_ITERATOR_HPP_

#include "ReverseIterator.h"

template<class T>
inline DoubleLinkedList<T>::ReverseIterator::ReverseIterator(): current(nullptr){}

template<class T>
inline DoubleLinkedList<T>::ReverseIterator::ReverseIterator(DoubleLinkedList<T>::Node* node): current(node){}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator& DoubleLinkedList<T>::ReverseIterator::operator++()
{
    if (current)
    {
        current = current->prev;
    }

    return *this;
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator DoubleLinkedList<T>::ReverseIterator::operator++(int)
{
    typename DoubleLinkedList<T>::ReverseIterator tmp = *this;
    ++(*this);
    return tmp;
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator& DoubleLinkedList<T>::ReverseIterator::operator--()
{
    if (current)
    {
        current = current->next;
    }

    return *this;
}

template<class T>
inline T& DoubleLinkedList<T>::ReverseIterator::operator*()
{
    return current->data;
}

template<class T>
inline bool DoubleLinkedList<T>::ReverseIterator::operator!=(const DoubleLinkedList<T>::ReverseIterator& other) const
{
    return current != other.current;
}

template<class T>
inline bool DoubleLinkedList<T>::ReverseIterator::operator==(const DoubleLinkedList<T>::ReverseIterator& other) const
{
    return !(*this != other);
}

#endif //!_MY_REVERSE_ITERATOR_H_