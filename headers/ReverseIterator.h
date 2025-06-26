#ifndef _MY_REVERSE_ITERATOR_H_
#define _MY_REVERSE_ITERATOR_H_

#include "DoubleLinkedList.h"

template<class T>
class DoubleLinkedList<T>::ReverseIterator
{
    friend class DoubleLinkedList<T>::const_ReverseIterator;
public:
    ReverseIterator();
    ReverseIterator(Node* node);

    ReverseIterator& operator++();
    ReverseIterator operator++(int);
    ReverseIterator& operator--();

    T& operator*();
    bool operator!=(const ReverseIterator& other) const;
    bool operator==(const ReverseIterator& other) const;
private:
    Node* current;
};

#include "ReverseIterator.hpp"

#endif //!_MY_REVERSE_ITERATOR_H_