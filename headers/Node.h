#ifndef _MY_NODE_H_
#define _MY_NODE_H_

#include "DoubleLinkedList.h"

template<class T>
struct DoubleLinkedList<T>::Node
{
    T data;
    Node* next;
    Node* prev;
    Node(const T& oData): data(oData), next(nullptr), prev(nullptr) {}
};

#endif // !_MY_NODE_H_