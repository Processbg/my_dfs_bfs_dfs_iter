#include <iostream>

#include "../headers/Vector.h"
#include "../headers/DoubleLinkedList.h"
#include "../headers/Graph.h"
#include "../headers/Queue.h"

template<class T>
void printArray(const T* container, size_t size, const char* name)
{
    std::cout << "\n";
    for (size_t  i = 0 ; i < size; ++i)
    {
        if (i == 0)
        {
            std::cout << i << " has " << name << " " << container[i];
        }
        else
        {
            std::cout << ", " << i << " has " << name << " " << container[i];
        }
    }
    std::cout << "\n";
}

template<class T>
void print(const Vector<T>& container)
{
    size_t numberOfElements = container.numElements();
    for (size_t  i = 0 ; i < numberOfElements; ++i)
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
    Vector<int> vector;
    vector.push_back(12);
    vector.push_back(13567);
    vector.push_back(2);
    vector.push_back(56);
    vector.push_back(1234);

    printVector(vector);

    std::cout << "Pop last value form vector: " << vector.pop() << std::endl;

    printVector(vector);

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
    if (!undirectedGraph1.isConstructedSuccessfully())
    {
        std::cerr << "Could not construct undirectedGraph1.\n";
        return -1;
    }

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

    Vector<int> preOrder1;
    recursive_dfs(undirectedGraph1, 0, preOrder1);
    std::cout << "DFS recursive preorder is:\n";
    print(preOrder1);
    std::cout << "Parents are:\n";
    printArray(undirectedGraph1.getParents(), undirectedGraph1.numVerticies(), "parent");
    std::cout << "Distances are:\n";
    printArray(undirectedGraph1.getDistances(), undirectedGraph1.numVerticies(), "distance");

    Graph<int> undirectedGraph2(10);
    if (!undirectedGraph2.isConstructedSuccessfully())
    {
        std::cerr << "Could not construct undirectedGraph2.\n";
        return -1;
    }

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

    Vector<int> preOrder2;
    iterative_dfs(undirectedGraph2, 0, preOrder2);
    std::cout << "DFS iterative preorder is:\n";
    print(preOrder2);
    std::cout << "Parents are:\n";
    printArray(undirectedGraph2.getParents(), undirectedGraph2.numVerticies(), "parent");
    std::cout << "Distances are:\n";
    printArray(undirectedGraph2.getDistances(), undirectedGraph2.numVerticies(), "distance");

    Graph<int> undirectedGraph3(10);
    if (!undirectedGraph3.isConstructedSuccessfully())
    {
        std::cerr << "Could not construct undirectedGraph3.\n";
        return -1;
    }

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

    Vector<int> preOrder3;
    iterative_bfs(undirectedGraph3, 1, preOrder3);
    std::cout << "BFS preorder is:\n";
    print(preOrder3);
    std::cout << "Parents are:\n";
    printArray(undirectedGraph3.getParents(), undirectedGraph3.numVerticies(), "parent");
    std::cout << "Distances are:\n";
    printArray(undirectedGraph3.getDistances(), undirectedGraph3.numVerticies(), "distance");

    return 0;
}