#ifndef _MY_DOUBLE_LINKED_LIST_H_
#define _MY_DOUBLE_LINKED_LIST_H_

#include <cstddef>

template<class T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const T& oData): data(oData), next(nullptr), prev(nullptr) {}
};

template<class T>
class DoubleLinkedList
{
public:
    class Iterator
    {
    public:
        Iterator();
        Iterator(Node<T>* node);

        Iterator& operator++();
        Iterator operator++(int);
        T operator*();
        bool operator!=(const Iterator& other);
        bool operator==(const Iterator& other);

    private: 
        Node<T>* current;
        Node<T>* previous;
    };

    Iterator begin() const;
    Iterator end() const;

    class ReverseIterator
    {
    public:
        ReverseIterator();
        ReverseIterator(Node<T>* node);

        ReverseIterator& operator++();
        ReverseIterator operator++(int);
        T operator*();
        bool operator!=(const ReverseIterator& other);
        bool operator==(const ReverseIterator& other);
    private:
        Node<T>* current;
        Node<T>* next;
    };

    ReverseIterator rbegin() const;
    ReverseIterator rend() const;

    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList<T>& other);
    DoubleLinkedList<T>& operator=(const DoubleLinkedList<T>& other);
    ~DoubleLinkedList();

    T pop_front();
    T pop_back();
    void push_back(const T& value);
    void push_front(const T& value);
    bool isEmpty() const;
    size_t numElements() const;

private:
    void copy(const DoubleLinkedList<T>& other);
    void destroy();

    Node<T>* first;
    Node<T>* last;
    size_t numberOfElements;
};

#include "DoubleLinkedList.hpp"

template<class T>
void printDoubleLinkedList(const DoubleLinkedList<T>& list)
{
    std::cout << "Contents of list is [";

    typename DoubleLinkedList<T>::Iterator iterList = list.begin();
    std::cout << *iterList;
    ++iterList;
    while (iterList != list.end())
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

    typename DoubleLinkedList<T>::ReverseIterator iterList = list.rbegin();
    std::cout << *iterList;
    ++iterList;
    while (iterList != list.rend())
    {
        std::cout << ", " << *iterList;
        ++iterList;
    }
    std::cout << "]\n";
}

#endif //!_MY_DOUBLE_LINKED_LIST_H_