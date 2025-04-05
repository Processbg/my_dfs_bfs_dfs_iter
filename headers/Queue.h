#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

#include <cstddef>

#include "SingleLinkedList.h"

template<class T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T>& other);
    Queue<T>& operator=(const Queue<T>& other);
    ~Queue();

    void push_back(const T& value);
    T pop();
    bool isEmpty() const;
    size_t numElements() const;
    friend void printQueue(const Queue<T>& queue)
    {
        printSingleLinkedList(queue.list);
    }

private:
    void copy (const Queue<T>& other);

    SingleLinkedList<T> list;
};

#include "Queue.hpp"

#endif //!_MY_QUEUE_H_