#ifndef _MY_DOUBLE_LINKED_LIST_H_
#define _MY_DOUBLE_LINKED_LIST_H_

#include <cstddef>

template<class T>
class DoubleLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(const T& oData): data(oData), next(nullptr), prev(nullptr) {}
    };

    void copy(const DoubleLinkedList<T>& other);
    void destroy();

    Node* first;
    Node* last;
    size_t numberOfElements;
public:
    class Iterator
    {
    public:
        Iterator();
        Iterator(Node* node);

        Iterator& operator++();
        Iterator operator++(int);
        const T& operator*() const;
        T& operator*();
        bool operator!=(const Iterator& other);
        bool operator==(const Iterator& other);

    private: 
        Node* current;
        Node* previous;
    };

    Iterator begin() const;
    Iterator end() const;

    class ReverseIterator
    {
    public:
        ReverseIterator();
        ReverseIterator(Node* node);

        ReverseIterator& operator++();
        ReverseIterator operator++(int);
        const T& operator*() const;
        T& operator*();
        bool operator!=(const ReverseIterator& other);
        bool operator==(const ReverseIterator& other);
    private:
        Node* current;
        Node* next;
    };

    ReverseIterator rbegin() const;
    ReverseIterator rend() const;

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