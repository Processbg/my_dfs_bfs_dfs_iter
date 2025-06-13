#ifndef _MY_CONST_REVERSE_ITERATOR_H_
#define _MY_CONST_REVERSE_ITERATOR_H_

#include "DoubleLinkedList.h"

template<class T>
class DoubleLinkedList<T>::const_ReverseIterator
{
public:
    const_ReverseIterator();
    const_ReverseIterator(const Node* node);
    const_ReverseIterator(const ReverseIterator& it);
    const_ReverseIterator& operator++();
    const_ReverseIterator operator++(int);
    const_ReverseIterator& operator--();
    const T& operator*() const;
    bool operator!=(const const_ReverseIterator& other) const;
    bool operator==(const const_ReverseIterator& other) const;

private:
    const Node* current;
};

#include "constReverseIterator.hpp"

#endif //!_MY_CONST_REVERSE_ITERATOR_H_