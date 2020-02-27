#include <string>
#include <map>
#include <vector>


class GraphNode
{
public:
    const std::string id;
    const int value;

    std::map<std::string, GraphNode *> neighbors;

    GraphNode(const std::string nodeID, int nodeValue)
    : id(nodeID), value(nodeValue)
    {}
    GraphNode(const std::string nodeID)
    : id(nodeID), value(0)
    {}
};
