#include "graph_node.h"
#include <map>


//
// A Simple Graph:
//  - loops are not permitted
//  - multiple edges are not permitted
//  - edges are directed
//
class SimpleGraph
{
public:

    // map of all Nodes in this graph:
    //      node ID -> Node
    std::map<std::string, GraphNode *> nodes;
    std::multimap<GraphNode *, GraphNode *> edges;


    void addEdge(GraphNode *fromNode, GraphNode *toNode);

    // order of graph => # of nodes/vertices in this Graph
    // (size of vertex set)
    unsigned int order() const
    {
        return nodes.size();
    }

    // size of the graph => # of edges in this Graph
    // (size of edge set)
    unsigned int size() const
    {
        return edges.size();
    }

    void debugPrint(GraphNode *fromNode);

};
