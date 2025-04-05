#ifndef _MY_SINGLE_LINKED_LIST_H_
#define _MY_SINGLE_LINKED_LIST_H_

#include <cstddef>

template<class T>
struct Node
{
    T data;
    Node<T>* next;
    Node(const T& oData): data(oData), next(nullptr) {}
};

template<class T>
class SingleLinkedList
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

    SingleLinkedList();
    SingleLinkedList(const SingleLinkedList<T>& other);
    SingleLinkedList<T>& operator=(const SingleLinkedList<T>& other);
    ~SingleLinkedList();

    T pop_front();
    void push_back(const T& value);
    bool isEmpty() const;
    size_t numElements() const;

private:
    void copy(const SingleLinkedList<T>& other);
    void destroy();

    Node<T>* first;
    Node<T>* last;
    size_t numberOfElements;
};

#include "SingleLinkedList.hpp"

template<class T>
void printSingleLinkedList(const SingleLinkedList<T>& list)
{
    std::cout << "Contents of list is [";

    typename SingleLinkedList<T>::Iterator iterList = list.begin();
    std::cout << *iterList;
    ++iterList;
    while (iterList != list.end())
    {
        std::cout << ", " << *iterList;
        ++iterList;
    }
    std::cout << "]\n";
}

#endif //!_MY_SINGLE_LINKED_LIST_H_