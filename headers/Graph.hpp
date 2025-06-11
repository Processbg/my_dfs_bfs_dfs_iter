#ifndef _MY_GRAPH_HPP_
#define _MY_GRAPH_HPP_

#include <stdexcept>
#include <iostream>

#include "../headers/Graph.h"
#include "../headers/Vector.h"

template<class T>
inline Graph<T>::Graph(size_t numverOfVertices): 
    V(numverOfVertices)
    ,isValid(true)
    ,visited(nullptr)
    ,distances(nullptr)
    ,parents(nullptr)
{
    adjacencyList.resize(V);

    visited = new(std::nothrow) bool[V];
    if (!visited)
    {
        std::cerr << "Can not allocate memory for visited in default constructor of Graph.\n";
        isValid = false;
        return;
    }

    for (size_t i = 0; i < V; ++i)
    {
        visited[i] = false;
    }

    distances = new(std::nothrow) int[V];
    if (!distances)
    {
        std::cerr << "Can not allocate memory for distances in default constructor of Graph.\n";
        isValid = false;
        delete[] visited;
        visited = nullptr;
        return;
    }

    for (size_t i = 0; i < V; ++i)
    {
        distances[i] = 0;
    }

    parents = new(std::nothrow) T[V];
    if (!parents)
    {
        std::cerr << "Can not allocate memory for parent in default constructor of Graph.\n";
        isValid = false;
        delete[] visited;
        visited = nullptr;
        delete[] distances;
        distances = nullptr;
        return;
    }
}

template<class T>
inline void Graph<T>::destroy()
{
    delete[] visited;
    visited = nullptr;

    delete[] distances;
    distances = nullptr;

    delete[] parents;
    parents = nullptr;
}

template<class T>
inline bool Graph<T>::isConstructedSuccessfully() const
{
    return isValid;
}

template<class T>
inline Graph<T>::~Graph(){ destroy(); }

template<class T>
inline void Graph<T>::addEdge(const T& u, const T& v)
{
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

template<class T>
inline void Graph<T>::printGrapth() const
{
    for (size_t i = 0; i < V; ++i)
    {
        std::cout << "Edge between vertex " << i << " and ";
        typename DoubleLinkedList<T>::Iterator iter = adjacencyList[i].begin();
        std::cout << *iter;
        ++iter;
        while (iter != adjacencyList[i].end())
        {
            std::cout << ", " << *iter;
            ++iter;
        }
        std::cout << "\n";
    }
}

template<class T>
inline size_t Graph<T>::numVerticies() const
{
    return V;
}

template<class T>
inline T* Graph<T>::getParents() const
{
    return parents;
}

template<class T>
inline int* Graph<T>::getDistances() const
{
    return distances;
}

#endif //!_MY_GRAPH_HPP_