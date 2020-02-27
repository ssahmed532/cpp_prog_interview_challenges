#include "simple_graph.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

//
// https://medium.com/basecs/going-broad-in-a-graph-bfs-traversal-959bd1a09255
//


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

        std::cout << "Node id:" << node->id;
        if (node->value > 0)
        {
            std::cout << ", value:" << node->value;
        }
        std::cout << ", neighbors count:" << node->neighbors.size() << '\n';

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

    GraphNode nodeA("a");
    GraphNode nodeB("b");
    GraphNode nodeC("c");
    GraphNode nodeD("d");
    GraphNode nodeE("e");
    GraphNode nodeF("f");
    GraphNode nodeG("g");

    myGraph.addEdge(&nodeA, &nodeB);
    myGraph.addEdge(&nodeA, &nodeC);
    myGraph.addEdge(&nodeA, &nodeG);
    myGraph.addEdge(&nodeB, &nodeD);
    myGraph.addEdge(&nodeB, &nodeE);
    myGraph.addEdge(&nodeC, &nodeD);
    myGraph.addEdge(&nodeD, &nodeE);
    myGraph.addEdge(&nodeD, &nodeF);
    myGraph.addEdge(&nodeF, &nodeG);

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
