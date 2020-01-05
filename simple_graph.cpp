#include "simple_graph.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::string;
using std::vector;


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


GraphNode *SimpleGraph::lookupNode(const std::string& nodeID)
{
    auto iter = nodes.find(nodeID);

    if (iter != nodes.end())
        return iter->second;
    else
        return nullptr;       
}
