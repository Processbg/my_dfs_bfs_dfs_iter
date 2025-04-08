#ifndef _MY_GRAPH_H_
#define _MY_GRAPH_H_

#include <cstddef>

#include "DoubleLinkedList.h"
#include "Stack.h"
#include "Queue.h"

template<class T>
class Graph
{
public:
    Graph(size_t numberOfVerticies);
    Graph(const Graph<T>& other);
    Graph<T>& operator=(const Graph<T>& other); 
    ~Graph();

    void addEdge(const T& u, const T& v);
    void printGrapth() const;
    size_t numVerticies() const;

    friend void recursive_dfs(Graph<T>& graph, const T& start, Stack<T>& order)
    {
        graph.visited[start] = true;
        order.push_back(start);

        typename DoubleLinkedList<T>::Iterator iter = graph.adjacencyList[start].begin();
        
        while (iter != graph.adjacencyList[start].end())
        {
            if (!graph.visited[*iter])
            {
                recursive_dfs(graph, *iter, order);
            }
            ++iter;
        }
    }

    friend void iterative_dfs(Graph<T>& graph, const T& start, Stack<T>& order)
    {
        Stack<T> stack;
        stack.push_back(start);

        while (!stack.isEmpty())
        {
            T v = stack.pop();

            if (!graph.visited[v])
            {
                graph.visited[v] = true;
                order.push_back(v);

                typename DoubleLinkedList<T>::ReverseIterator iter = graph.adjacencyList[v].rbegin();
                
                while (iter != graph.adjacencyList[v].rend())
                {
                    if (!graph.visited[*iter])
                    {
                        stack.push_back(*iter);
                    }
                    ++iter;
                }
            }
        }
    }

    friend void iterative_bfs(Graph<T>& graph, const T& start, Stack<T>& order)
    {
        Queue<T> queue;
        queue.push_back(start);

        while (!queue.isEmpty())
        {
            T v = queue.pop();
            
            if (!graph.visited[v])
            {
                graph.visited[v] = true;
                order.push_back(v);
                
                typename DoubleLinkedList<T>::Iterator iter = graph.adjacencyList[v].begin();
                
                while (iter != graph.adjacencyList[v].end())
                {
                    if (!graph.visited[*iter])
                    {
                        queue.push_back(*iter);
                    }
                    ++iter;
                }
            }
        }
    }

private:
    void copy(const Graph<T>& other);

    Stack<DoubleLinkedList<T>> adjacencyList;
    Stack<bool> visited;
    const size_t V;
};

#include "Graph.hpp"

#endif //!_MY_GRAPH_H_