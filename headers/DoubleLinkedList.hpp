#ifndef _MY_DOUBLE_LINKED_LIST_HPP_
#define _MY_DOUBLE_LINKED_LIST_HPP_

#include "DoubleLinkedList.h"

template<class T>
inline typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::begin()
{
    return typename DoubleLinkedList<T>::Iterator(first);
}

template<class T>
inline typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end()
{
    return typename DoubleLinkedList<T>::Iterator();
}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator DoubleLinkedList<T>::begin() const
{
    return typename DoubleLinkedList<T>::const_Iterator(first);
}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator DoubleLinkedList<T>::end() const
{
    return typename DoubleLinkedList<T>::const_Iterator();
}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator DoubleLinkedList<T>::cbegin() const
{
    return typename DoubleLinkedList<T>::const_Iterator(first);
}

template<class T>
inline typename DoubleLinkedList<T>::const_Iterator DoubleLinkedList<T>::cend() const
{
    return typename DoubleLinkedList<T>::const_Iterator();
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator DoubleLinkedList<T>::rbegin()
{
    return typename DoubleLinkedList<T>::ReverseIterator(last);
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator DoubleLinkedList<T>::rend()
{
    return typename DoubleLinkedList<T>::ReverseIterator();
}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator DoubleLinkedList<T>::rbegin() const
{
    return typename DoubleLinkedList<T>::const_ReverseIterator(last);
}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator DoubleLinkedList<T>::rend() const
{
    return typename DoubleLinkedList<T>::const_ReverseIterator();
}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator DoubleLinkedList<T>::crbegin() const
{
    return typename DoubleLinkedList<T>::const_ReverseIterator(last);
}

template<class T>
inline typename DoubleLinkedList<T>::const_ReverseIterator DoubleLinkedList<T>::crend() const
{
    return typename DoubleLinkedList<T>::const_ReverseIterator();
}

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList(): numberOfElements(0), first(nullptr), last(nullptr)
{}

template<class T>
inline DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T>& other): numberOfElements(0), first(nullptr), last(nullptr)
{ copy(other); }

template<class T>
inline DoubleLinkedList<T>& DoubleLinkedList<T>::operator=(const DoubleLinkedList<T>& other)
{
    if (this != &other)
    {
        destroy();
        copy(other);
    }

    return *this;
}

template<class T>
inline DoubleLinkedList<T>::~DoubleLinkedList()
{
    destroy();
}

template<class T>
inline void DoubleLinkedList<T>::destroy()
{
    Node* current = first;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    first = nullptr;
    last = nullptr;
}

template<class T>
inline void DoubleLinkedList<T>::copy(const DoubleLinkedList<T>& other)
{
    if (other.first == nullptr)
    {
        first = last = nullptr;
        return;
    }

    first = new Node(other.first->data);
    Node* current = first;
    numberOfElements = 1;
    
    Node* otherCurrent = other.first->next;
    while (otherCurrent != nullptr)
    {
        current->next = new Node(otherCurrent->data);
        current->next->prev = current;
        otherCurrent = otherCurrent->next;
        current = current->next;
        ++numberOfElements;
    }
    last = current;
}

template<class T>
inline void DoubleLinkedList<T>::pop_back()
{
    if (!last) return;

    Node* toRemove = last;
    // make sure that the node before the last has next null
    if (last->prev)
    {
        last->prev->next = nullptr;
    }
    last = last->prev;
    if (!last) first = nullptr;
    delete toRemove;
    --numberOfElements;
}

template<class T>
inline T& DoubleLinkedList<T>::front() { return first->data; }

template<class T>
inline const T& DoubleLinkedList<T>::front() const { return first->data; }

template<class T>
inline void DoubleLinkedList<T>::pop_front()
{
    if (!first) return;

    Node* toRemove = first;
    // make sure that the node after the first has previous null
    if (first->next)
    {
        first->next->prev = nullptr;
    }
    first = first->next;
    if (!first) last = nullptr;
    delete toRemove;
    --numberOfElements;
}

template<class T>
inline T& DoubleLinkedList<T>::back() { return last->data; }

template<class T>
inline const T& DoubleLinkedList<T>::back() const { return last->data; }

template<class T>
inline void DoubleLinkedList<T>::push_back(const T& value)
{
    Node* newNode = new Node(value);
    if (last)
    {
        newNode->prev = last;
        last->next = newNode;
    }
    else
    {
        first = newNode;
    }
    last = newNode;
    ++numberOfElements;
}

template<class T>
inline void DoubleLinkedList<T>::push_front(const T& value)
{
   Node* newNode = new Node(value);
    if (first)
    {
        newNode->next = first;
        first->prev = newNode;
    }
    else
    {
        last = newNode;
    }
    first = newNode;
    ++numberOfElements;
}

template<class T>
inline bool DoubleLinkedList<T>::isEmpty() const
{
    return numberOfElements == 0;
}

template<class T>
inline size_t DoubleLinkedList<T>::numElements() const
{
    return numberOfElements;
}

#endif //!_MY_DOUBLE_LINKED_LIST_HPP_