#include "simple_graph.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


// Print out the Graph using BFS algorithm starting from the specified Node
void printGraph_BFS(GraphNode *fromNode)
{
    if (fromNode == nullptr)
        return;

    queue<GraphNode *> nodesToVisit;

    nodesToVisit.emplace(fromNode);

    vector<string> nodesVisited;

    while (!nodesToVisit.empty())
    {
        auto node = nodesToVisit.front();

        if (std::find(nodesVisited.begin(), nodesVisited.end(), node->id) != nodesVisited.end())
        {
            nodesToVisit.pop();
            continue;
        }

        std::cout << "Node id:" << node->id << ", value:" << node->value << ", neighbors count:" << node->neighbors.size() << '\n';

        nodesVisited.emplace_back(node->id);

        for (const auto &n: node->neighbors)
        {
            nodesToVisit.emplace(n.second);
        }

        nodesToVisit.pop();
    }
}


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./simple_graph_bfs_print <ID of starting node>" << '\n';
        return 1;
    }

    const std::string startingNodeID = argv[1];

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

    GraphNode *startingNode = myGraph.lookupNode(startingNodeID);
    if (startingNode != nullptr)
    {
        printGraph_BFS(startingNode);
    }
    else
    {
        std::cerr << "ERROR: Unable to lookup Node with ID=" << startingNodeID << " in myGraph" << '\n';
        return 2;
    }

    return 0;
}
