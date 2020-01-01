#include "simple_graph.h"
#include <cassert>
#include <iostream>
#include <queue>

using std::queue;


void SimpleGraph::addEdge(GraphNode *fromNode, GraphNode *toNode)
{
    assert(fromNode != nullptr);
    assert(toNode != nullptr);

    // check if a loop edge is being added
    if (fromNode == toNode)
    {
        std::cerr << "ERROR: Loops are not permitted" << '\n';
        return;
    }

    if (nodes.find(fromNode->id) == nodes.end())
        nodes.emplace(fromNode->id, fromNode);

    if (nodes.find(toNode->id) == nodes.end())
        nodes.emplace(toNode->id, toNode);

    // check if a duplicate of an existing edge is being added
    auto ret = edges.equal_range(fromNode);
    for (auto it = ret.first; it != ret.second; it++)
    {
        if (it->second == toNode)
        {   
            std::cerr << "ERROR: Multiple Edges are not permitted" << '\n';
            return;
        }
    }

    edges.emplace(fromNode, toNode);
    std::cout << "Added an edge from node " << fromNode->id << " to node " << toNode->id << '\n';

    // Update the neighbors map
    fromNode->neighbors.emplace(toNode->id, toNode);

    //std::cout << "Node " << fromNode->id << " has " << fromNode->neighbors.size() << " neighboring nodes" << '\n';
}


void SimpleGraph::debugPrint(GraphNode *fromNode)
{
    queue<GraphNode *> nodesToVisit;

    nodesToVisit.emplace(fromNode);

    while (!nodesToVisit.empty())
    {
        auto node = nodesToVisit.front();

        std::cout << "Node id:" << node->id << ", value:" << node->value << ", neighbors count:" << node->neighbors.size() << '\n';

        for (const auto &n: node->neighbors)
        {
            nodesToVisit.emplace(n.second);
        }

        nodesToVisit.pop();
    }
}
