#include "tree_node.h"
#include <assert.h>
#include <iostream>


void TreeNode::debugPrint()
{
    std::cout << "Node value: " << value << " ";
    if (pLeft != nullptr)
        std::cout << ", left child exists, ";
    else
        std::cout << ", left child non-existent, ";

    if (pRight != nullptr)
        std::cout << ", right child exists, ";
    else
        std::cout << ", right child non-existent, ";
}


void TreeNode::insertIntoBST(TreeNode* pRoot, int item)
{
    assert(pRoot != nullptr);

    if (item < pRoot->value)
    {
        if (pRoot->pLeft == nullptr)
        {
            TreeNode* leftChild = new TreeNode(item);
            pRoot->pLeft = leftChild;
        }
        else
        {
            // recurse into left child node
            insertIntoBST(pRoot->pLeft, item);
        }
    }
    else if (item > pRoot->value)
    {
        if (pRoot->pRight == nullptr)
        {
            TreeNode* rightChild = new TreeNode(item);
            pRoot->pRight = rightChild;
        }
        else
        {
            // recurse into right child node
            insertIntoBST(pRoot->pRight, item);
        }
    }
    else
    {
        std::cerr << "Item with value " << item << " already exists in the Tree" << '\n';
    }
}
