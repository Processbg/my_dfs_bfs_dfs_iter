#ifndef _MY_STACK_H_
#define _MY_STACK_H_

#include <cstddef>

template<class T>
class Stack
{
public:
    Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator=(const Stack<T>& other); 
    ~Stack();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(const T& value);
    T pop();
    bool isEmpty() const;
    size_t numElements() const;
    size_t getCapacity() const;
    void resize(size_t newSize);

private:
    void copy(const Stack<T>& other);
    void destroy();

    T* container;
    size_t numberOfElements;
    size_t capacity;
};

#include "Stack.hpp"

template<class T>
void printStack(const Stack<T>& stack)
{
    std::cout << "Contents of stack is [";
    
    size_t sizeOfStack = stack.numElements();
    for (size_t i = 0; i < sizeOfStack; ++i)
    {
        if (i == sizeOfStack - 1)
        {
            std::cout << stack[i];
            continue;
        }
        std::cout << stack[i] << ", ";
    }
    std::cout << "]\n";
}

#endif // !_MY_STACK_H_