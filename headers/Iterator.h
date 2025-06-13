#ifndef _MY_ITERATOR_H_
#define _MY_ITERATOR_H_

#include "DoubleLinkedList.h"

template<class T>
class DoubleLinkedList<T>::Iterator
{
    friend class DoubleLinkedList<T>::const_Iterator;
public:
    Iterator();
    Iterator(Node* node);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    T& operator*();
    bool operator!=(const Iterator& other) const;
    bool operator==(const Iterator& other) const;
    
private: 
    Node* current;
};

#include "Iterator.hpp"

#endif //!_MY_ITERATOR_H_