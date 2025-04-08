#ifndef _MY_GRAPH_HPP_
#define _MY_GRAPH_HPP_

#include <stdexcept>
#include <iostream>

#include "../headers/Graph.h"
#include "../headers/Stack.h"

template<class T>
inline Graph<T>::Graph(size_t numverOfVertices): 
    V(numverOfVertices)
{
    adjacencyList.resize(V);
    visited.resize(V);

    for (size_t i = 0; i < V; ++i)
    {
        visited[i] = false;
    }
}

template<class T>
inline Graph<T>::~Graph(){}

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
        V = other.V;
        adjacencyList = other.adjacencyList;
        visited = other.visited;
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

#endif //!_MY_GRAPH_HPP_