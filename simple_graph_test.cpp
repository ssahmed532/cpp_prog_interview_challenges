#include <iostream>
#include "simple_graph.h"


int main(void)
{
    SimpleGraph myGraph;

    GraphNode node1("Start", 100);
    GraphNode node2("n1", 200);
    GraphNode node3("n2", 300);
    GraphNode node4("n3", 400);
    GraphNode node5("n4", 500);
    GraphNode node6("Finish", 600);

    myGraph.addEdge(&node1, &node2);
    myGraph.addEdge(&node1, &node4);
    myGraph.addEdge(&node2, &node3);
    myGraph.addEdge(&node4, &node3);
    myGraph.addEdge(&node4, &node5);
    myGraph.addEdge(&node5, &node6);
    myGraph.addEdge(&node2, &node6);

    std::cout << "Order of graph = " << myGraph.order() << '\n';
    std::cout << "Size  of graph = " << myGraph.size()  << '\n';
    std::cout << '\n';

    return 0;
}
