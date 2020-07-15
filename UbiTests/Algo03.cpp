/*  C++ Algorithms 3

    Given the struct Vertex, representing vertices in a graph, write a function DFVisit() that traverses the graph and fills
    the vector result with all connected vertices in Depth First order. Write a comment with the time complexity of your implementation.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

struct Vertex
{
    std::vector<Vertex*> m_adjacent;
};



void DFVisit(Vertex* v, std::vector<Vertex*>& result)
{
    static std::unordered_map<Vertex*, bool> visited;
    for (std::vector<Vertex*>::iterator it = v->m_adjacent.begin(); it != v->m_adjacent.end(); ++it)
    {
        if (!visited[*it])
        {
            visited[*it] = true;
            result.push_back(*it);
            DFVisit(*it, result);
        }
    }
}

void main(int argc, char* argv[])
{
    Vertex a, b, c, d;
    a.m_adjacent.push_back(&b);
    b.m_adjacent.push_back(&c);
    c.m_adjacent.push_back(&d);
    d.m_adjacent.push_back(&b);

    std::vector<Vertex*> visited;
    DFVisit(&d, visited);

    std::cout << "Number of visited vertices: " << visited.size() << std::endl;
}

