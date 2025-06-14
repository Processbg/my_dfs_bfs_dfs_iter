#ifndef _MY_DOUBLE_LINKED_LIST_H_
#define _MY_DOUBLE_LINKED_LIST_H_

#include <cstddef>

template<class T>
class DoubleLinkedList
{
private:
    struct Node;

    void copy(const DoubleLinkedList<T>& other);
    void destroy();

    Node* first;
    Node* last;
    size_t numberOfElements;
public:
    class Iterator;
    class const_Iterator;

    Iterator begin();
    Iterator end();
    const_Iterator begin() const;
    const_Iterator end() const ;
    const_Iterator cbegin() const;
    const_Iterator cend() const;

    class ReverseIterator;
    class const_ReverseIterator;

    ReverseIterator rbegin();
    ReverseIterator rend();
    const_ReverseIterator rbegin() const;
    const_ReverseIterator rend() const;
    const_ReverseIterator crbegin() const;
    const_ReverseIterator crend() const;

    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList<T>& other);
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);
    ~DoubleLinkedList();

    T& front();
    const T& front() const;
    void pop_front();
    T& back();
    const T& back() const;
    void pop_back();
    void push_back(const T& value);
    void push_front(const T& value);
    bool isEmpty() const;
    size_t numElements() const;
};

#include "Node.h"

#include "Iterator.h"
#include "ConstIterator.h"

#include "ReverseIterator.h"
#include "ConstReverseIterator.h"

#include "DoubleLinkedList.hpp"

template<class T>
void printDoubleLinkedList(const DoubleLinkedList<T>& list)
{
    std::cout << "Contents of list is [";

    typename DoubleLinkedList<T>::const_Iterator iterList = list.cbegin();
    std::cout << *iterList;
    ++iterList;
    while (iterList != list.cend())
    {
        std::cout << ", " << *iterList;
        ++iterList;
    }
    std::cout << "]\n";
}

template<class T>
void printReverseDoubleLinkedList(const DoubleLinkedList<T>& list)
{
    std::cout << "Contents of reversed list is [";

    typename DoubleLinkedList<T>::const_ReverseIterator iterList = list.crbegin();
    std::cout << *iterList;
    ++iterList;
    while (iterList != list.crend())
    {
        std::cout << ", " << *iterList;
        ++iterList;
    }
    std::cout << "]\n";
}

#endif //!_MY_DOUBLE_LINKED_LIST_H_