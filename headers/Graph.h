#ifndef _MY_GRAPH_H_
#define _MY_GRAPH_H_

#include <cstddef>

#include "DoubleLinkedList.h"
#include "Vector.h"
#include "Queue.h"

template<class T>
class Graph
{
public:
    explicit Graph(size_t numberOfVerticies);
    ~Graph();

    void addEdge(const T& u, const T& v);

    void printGrapth() const;
    size_t numVerticies() const;
    T* getParents() const;
    int* getDistances() const;
    bool isConstructedSuccessfully() const;

    friend void recursive_dfs(Graph<T>& graph, const T& start, Vector<T>& order)
    {
        graph.visited[start] = true;
        order.push_back(start);

        typename DoubleLinkedList<T>::const_Iterator iter = graph.adjacencyList[start].begin();
        
        while (iter != graph.adjacencyList[start].end())
        {
            if (!graph.visited[*iter])
            {
                graph.parents[*iter] = start;
                graph.distances[*iter] = graph.distances[start] + 1;
                recursive_dfs(graph, *iter, order);
            }
            ++iter;
        }
    }

    friend void iterative_dfs(Graph<T>& graph, const T& start, Vector<T>& order)
    {
        Vector<T> stack;
        stack.push_back(start);

        while (!stack.isEmpty())
        {
            T v = stack.pop();

            if (!graph.visited[v])
            {
                graph.visited[v] = true;
                order.push_back(v);

                typename DoubleLinkedList<T>::const_ReverseIterator iter = graph.adjacencyList[v].rbegin();
                
                while (iter != graph.adjacencyList[v].rend())
                {
                    if (!graph.visited[*iter])
                    {
                        stack.push_back(*iter);
                        graph.parents[*iter] = v;
                        graph.distances[*iter] = graph.distances[v] + 1;
                    }
                    ++iter;
                }
            }
        }
    }

    friend void iterative_bfs(Graph<T>& graph, const T& start, Vector<T>& order)
    {
        Queue<T> queue;
        queue.enqueue(start);

        while (!queue.isEmpty())
        {
            T v = queue.front();
            queue.dequeue();
            
            if (!graph.visited[v])
            {
                graph.visited[v] = true;
                order.push_back(v);
                
                typename DoubleLinkedList<T>::const_Iterator iter = graph.adjacencyList[v].begin();
                
                while (iter != graph.adjacencyList[v].end())
                {
                    if (!graph.visited[*iter])
                    {
                        queue.enqueue(*iter);
                        graph.parents[*iter] = v;
                        graph.distances[*iter] = graph.distances[v] + 1;
                    }
                    ++iter;
                }
            }
        }
    }

private:
    void destroy();
    Graph(const Graph<T>& other);
    Graph<T>& operator=(const Graph<T>& other); 

    Vector<DoubleLinkedList<T>> adjacencyList;
    bool* visited;
    T* parents;
    int* distances;
    const size_t V;
    bool isValid;
};

#include "Graph.hpp"

#endif //!_MY_GRAPH_H_