#ifndef _MY_SINGLE_LINKED_LIST_HPP_
#define _MY_SINGLE_LINKED_LIST_HPP_

#include "../headers/SingleLinkedList.h"

template<class T>
inline SingleLinkedList<T>::Iterator::Iterator(): current(nullptr), previous(nullptr) 
{}

template<class T>
inline SingleLinkedList<T>::Iterator::Iterator(Node<T>* node): current(node), previous(nullptr)
{}

template<class T>
inline typename SingleLinkedList<T>::Iterator& SingleLinkedList<T>::Iterator::operator++()
{
    if (current != nullptr)
    {
        previous = current;
        current = current->next;
    }

    return *this;
}

template<class T>
inline typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::Iterator::operator++(int)
{
    typename SingleLinkedList<T>::Iterator tmp = *this;
    ++*this;
    return tmp;
}

template<class T>
inline T SingleLinkedList<T>::Iterator::operator*()
{
    return current->data;
}

template<class T>
inline bool SingleLinkedList<T>::Iterator::operator!=(const SingleLinkedList<T>::Iterator& other)
{
    return current != other.current;
}

template<class T>
inline bool SingleLinkedList<T>::Iterator::operator==(const SingleLinkedList<T>::Iterator& other)
{
    return !(*this != other);
}

template<class T>
inline typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::begin() const 
{
    return typename SingleLinkedList<T>::Iterator(first);
}

template<class T>
inline typename SingleLinkedList<T>::Iterator SingleLinkedList<T>::end() const
{
    return typename SingleLinkedList<T>::Iterator();
}

template<class T>
inline SingleLinkedList<T>::SingleLinkedList(): numberOfElements(0), first(nullptr), last(nullptr)
{}

template<class T>
inline SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& other){ copy(other); }

template<class T>
inline SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T>& other)
{
    copy(other);

    return *this;
}

template<class T>
inline SingleLinkedList<T>::~SingleLinkedList()
{
    destroy();
}

template<class T>
inline void SingleLinkedList<T>::destroy()
{
    while (first != nullptr)
    {
        Node<T>* toDelete = first;
        first = first->next;
        delete toDelete;
    }
}

template<class T>
inline void SingleLinkedList<T>::copy(const SingleLinkedList<T>& other)
{
    if (this != &other)
    {
        if (other.first == nullptr)
        {
            return;
        }

        first = new Node<T>(other.first->data);
        Node<T>* current = first;
        numberOfElements = 1;

        Node<T>* otherCurrent = other.first->next;
        while (otherCurrent != nullptr)
        {
            current->next = new Node<T>(otherCurrent->data);
            otherCurrent = otherCurrent->next;
            current = current->next;
            ++numberOfElements;
        }
    }
}

template<class T>
inline T SingleLinkedList<T>::pop_front()
{
    Node<T>* toRemove = first;
    T data = toRemove->data;
    first = first->next;
    delete toRemove;
    --numberOfElements;
    return data;
}

template<class T>
inline void SingleLinkedList<T>::push_back(const T& value)
{
    if (!first)
    {
        first = new Node<T>(value);
        last = first;
        ++numberOfElements;
    }
    else if (last == first)
    {
        Node<T>* second = new Node<T>(value);
        first->next = second;
        last = second;
        second = nullptr;
        ++numberOfElements;
    }
    else
    {
        Node<T>* newLast = new Node<T>(value);
        last->next = newLast;
        last = newLast;
        newLast = nullptr;
        ++numberOfElements;
    }
}

template<class T>
inline bool SingleLinkedList<T>::isEmpty() const
{
    return numberOfElements == 0;
}

template<class T>
inline size_t SingleLinkedList<T>::numElements() const
{
    return numberOfElements;
}

#endif //!_MY_SINGLE_LINKED_LIST_HPP_