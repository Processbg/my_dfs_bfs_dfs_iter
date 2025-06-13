#ifndef _MY_CONST_ITERATOR_H_
#define _MY_CONST_ITERATOR_H_

#include "DoubleLinkedList.h"

template<class T>
class DoubleLinkedList<T>::const_Iterator
    {
    public:
        const_Iterator();
        const_Iterator(const Node* node);
        const_Iterator(const Iterator& it);

        const_Iterator& operator++();
        const_Iterator operator++(int);
        const_Iterator& operator--();
        const T& operator*() const;
        bool operator!=(const const_Iterator& other) const;
        bool operator==(const const_Iterator& other) const;
    private: 
        const Node* current;
    };

    #include "constIterator.hpp"

    #endif //!_MY_CONST_ITERATOR_H_