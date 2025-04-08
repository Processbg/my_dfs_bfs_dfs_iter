#include <iostream>

#include "../headers/Stack.h"
#include "../headers/DoubleLinkedList.h"
#include "../headers/Graph.h"
#include "../headers/Queue.h"

template<class T>
void print(const Stack<T>& container)
{
    size_t numberOfElements = container.numElements();
    for(size_t  i = 0 ; i < numberOfElements; ++i)
    {
        if (i == 0)
        {
            std::cout << container[i];
        }
        else
        {
            std::cout << ", " << container[i];
        }
    }
    std::cout << "\n";
}

int main()
{
    Stack<int> stack;
    stack.push_back(12);
    stack.push_back(13567);
    stack.push_back(2);
    stack.push_back(56);
    stack.push_back(1234);

    printStack(stack);

    std::cout << "Pop last value form stack: " << stack.pop() << std::endl;

    printStack(stack);

    DoubleLinkedList<int> list;
    list.push_back(456);
    list.push_back(23);
    list.push_back(4);
    list.push_back(34567);
    list.push_back(11);

    printDoubleLinkedList(list);

    std::cout << "Pop first value form list: " << list.pop_front() << std::endl;
    std::cout << "Pop last value form list: " << list.pop_back() << std::endl;

    printDoubleLinkedList(list);

    list.push_front(10);
    list.push_front(0);

    printDoubleLinkedList(list);

    printReverseDoubleLinkedList(list);

    Queue<int> queue;

    queue.push_back(31);
    queue.push_back(10);
    queue.push_back(0);
    queue.push_back(156);
    queue.push_back(9876);

    printQueue(queue);

    std::cout << "Pop first value from queue: " << queue.pop() << std::endl;

    printQueue(queue);

    Graph<int> undirectedGraph1(10);

    undirectedGraph1.addEdge(0,1);
    undirectedGraph1.addEdge(0,2);
    undirectedGraph1.addEdge(1,4);
    undirectedGraph1.addEdge(1,2);
    undirectedGraph1.addEdge(1,3);
    undirectedGraph1.addEdge(3,5);
    undirectedGraph1.addEdge(5,6);
    undirectedGraph1.addEdge(5,8);
    undirectedGraph1.addEdge(5,7);
    undirectedGraph1.addEdge(7,8);
    undirectedGraph1.addEdge(8,9);

    undirectedGraph1.printGrapth();

    Stack<int> v1;
    recursive_dfs(undirectedGraph1, 0, v1);
    print(v1);

    Graph<int> undirectedGraph2(10);

    undirectedGraph2.addEdge(0,1);
    undirectedGraph2.addEdge(0,2);
    undirectedGraph2.addEdge(1,4);
    undirectedGraph2.addEdge(1,2);
    undirectedGraph2.addEdge(1,3);
    undirectedGraph2.addEdge(3,5);
    undirectedGraph2.addEdge(5,6);
    undirectedGraph2.addEdge(5,8);
    undirectedGraph2.addEdge(5,7);
    undirectedGraph2.addEdge(7,8);
    undirectedGraph2.addEdge(8,9);

    Stack<int> v2;
    iterative_dfs(undirectedGraph2, 0, v2);
    print(v2);

    Graph<int> undirectedGraph3(10);

    undirectedGraph3.addEdge(0,1);
    undirectedGraph3.addEdge(0,2);
    undirectedGraph3.addEdge(1,4);
    undirectedGraph3.addEdge(1,2);
    undirectedGraph3.addEdge(1,3);
    undirectedGraph3.addEdge(3,5);
    undirectedGraph3.addEdge(5,6);
    undirectedGraph3.addEdge(5,8);
    undirectedGraph3.addEdge(5,7);
    undirectedGraph3.addEdge(7,8);
    undirectedGraph3.addEdge(8,9);

    Stack<int> v3;
    iterative_bfs(undirectedGraph3, 1, v3);
    print(v3);

    return 0;
}