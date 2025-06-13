#ifndef _MY_DOUBLE_LINKED_LIST_HPP_
#define _MY_DOUBLE_LINKED_LIST_HPP_

#include "../headers/DoubleLinkedList.h"

template<class T>
inline DoubleLinkedList<T>::Iterator::Iterator(): current(nullptr), previous(nullptr) 
{}

template<class T>
inline DoubleLinkedList<T>::Iterator::Iterator(DoubleLinkedList<T>::Node* node): current(node), previous(nullptr)
{}

template<class T>
inline typename DoubleLinkedList<T>::Iterator& DoubleLinkedList<T>::Iterator::operator++()
{
    if (current != nullptr)
    {
        previous = current;
        current = current->next;
    }

    return *this;
}

template<class T>
inline typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::Iterator::operator++(int)
{
    typename DoubleLinkedList<T>::Iterator tmp = *this;
    ++*this;
    return tmp;
}

template<class T>
inline T& DoubleLinkedList<T>::Iterator::operator*()
{
    return current->data;
}

template<class T>
inline const T& DoubleLinkedList<T>::Iterator::operator*() const
{
    return current->data;
}

template<class T>
inline bool DoubleLinkedList<T>::Iterator::operator!=(const DoubleLinkedList<T>::Iterator& other)
{
    return current != other.current;
}

template<class T>
inline bool DoubleLinkedList<T>::Iterator::operator==(const DoubleLinkedList<T>::Iterator& other)
{
    return !(*this != other);
}

template<class T>
inline typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::begin() const 
{
    return typename DoubleLinkedList<T>::Iterator(first);
}

template<class T>
inline typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end() const
{
    return typename DoubleLinkedList<T>::Iterator();
}

template<class T>
inline DoubleLinkedList<T>::ReverseIterator::ReverseIterator(): current(nullptr), next(nullptr){}

template<class T>
inline DoubleLinkedList<T>::ReverseIterator::ReverseIterator(DoubleLinkedList<T>::Node* node): current(node), next(nullptr){}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator& DoubleLinkedList<T>::ReverseIterator::operator++()
{
    if (current != nullptr)
    {
        next = current;
        current = current->prev;
    }

    return *this;
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator DoubleLinkedList<T>::ReverseIterator::operator++(int)
{
    typename DoubleLinkedList<T>::ReverseIterator tmp = *this;
    ++*this;
    return tmp;
}

template<class T>
inline T& DoubleLinkedList<T>::ReverseIterator::operator*()
{
    return current->data;
}

template<class T>
inline const T& DoubleLinkedList<T>::ReverseIterator::operator*() const
{
    return current->data;
}

template<class T>
inline bool DoubleLinkedList<T>::ReverseIterator::operator!=(const DoubleLinkedList<T>::ReverseIterator& other)
{
    return current != other.current;
}

template<class T>
inline bool DoubleLinkedList<T>::ReverseIterator::operator==(const DoubleLinkedList<T>::ReverseIterator& other)
{
    return !(*this != other);
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator DoubleLinkedList<T>::rbegin() const 
{
    return typename DoubleLinkedList<T>::ReverseIterator(last);
}

template<class T>
inline typename DoubleLinkedList<T>::ReverseIterator DoubleLinkedList<T>::rend() const
{
    return typename DoubleLinkedList<T>::ReverseIterator();
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