#include "simple_graph.h"
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;


class DfsGraphVisitor
{
public:
    // Print out the Graph using DFS algorithm starting from the specified Node
    void printGraph_DFS(GraphNode *fromNode);
private:
    std::vector<string> nodesVisited;
};


// Print out the Graph using DFS algorithm starting from the specified Node
void DfsGraphVisitor::printGraph_DFS(GraphNode *fromNode)
{
    if (fromNode == nullptr)
        return;

    if (std::find(nodesVisited.begin(), nodesVisited.end(), fromNode->id) != nodesVisited.end())
    {
        // we have already visited this Node before
        return;
    }

    // print current Node
    std::cout << "Node id:" << fromNode->id << ", value:" << fromNode->value << ", neighbors count:" << fromNode->neighbors.size() << '\n';

    nodesVisited.emplace_back(fromNode->id);

    for (const auto &neighbor: fromNode->neighbors)
    {
        printGraph_DFS(neighbor.second);
    }
}


int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./simple_graph_dfs_print <ID of starting node>" << '\n';
        return 1;
    }

    const std::string startingNodeID = argv[1];

    SimpleGraph myGraph;

    GraphNode node1("2", 100);
    GraphNode node2("0", 200);
    GraphNode node3("1", 300);
    GraphNode node4("3", 400);

    myGraph.addEdge(&node1, &node2);
    myGraph.addEdge(&node2, &node3);
    myGraph.addEdge(&node3, &node1);
    myGraph.addEdge(&node1, &node4);

    GraphNode *startingNode = myGraph.lookupNode(startingNodeID);
    if (startingNode != nullptr)
    {
        DfsGraphVisitor dfsVisitor;
        dfsVisitor.printGraph_DFS(startingNode);
    }
    else
    {
        std::cerr << "ERROR: Unable to lookup Node with ID=" << startingNodeID << " in myGraph" << '\n';
        return 2;
    }

    return 0;
}
