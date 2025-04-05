#ifndef _MY_GRAPH_HPP_
#define _MY_GRAPH_HPP_

#include <stdexcept>
#include <iostream>

#include "../headers/Graph.h"
#include "../headers/Stack.h"

template<class T>
inline Graph<T>::Graph(size_t numverOfVertices): 
    V(numverOfVertices),
    visited(nullptr),
    isValid(true)
{
    adjacencyList.resize(V);

    visited = new(std::nothrow) bool[V];
    if (!visited)
    {
        std::cerr << "Can not allocate memory for visited in Graph.\n";
        isValid = false;
        return;
    }

    for (size_t i = 0; i < V; ++i)
    {
        visited[i] = false;
    }
}

template<class T>
inline bool Graph<T>::isConstructedSuccessfully() const
{
    return isValid;
}

template<class T>
inline void Graph<T>::destroy()
{
    delete[] visited;
    visited = nullptr;
}

template<class T>
inline Graph<T>::~Graph(){ destroy(); }

template<class T>
inline Graph<T>::Graph(const Graph<T>& other){ copy(other); }

template<class T>
inline Graph<T>& Graph<T>::operator=(const Graph<T>& other)
{
    copy(other);

    return *this;
}

template<class T>
inline void Graph<T>::copy(const Graph<T>& other)
{
    if (this != &other)
    {
        adjacencyList = other.adjacencyList;
    } 
}

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
        typename SingleLinkedList<T>::Iterator iter = adjacencyList[i].begin();
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

#endif //!_MY_GRAPH_HPP_