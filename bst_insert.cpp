#include "tree_node.h"
#include <assert.h>
#include <iostream>


void printBinaryTree(TreeNode* pRoot)
{
    if (pRoot != nullptr)
        std::cout << pRoot->value << '\n';

    if (pRoot->pLeft != nullptr)
    {
        std::cout << '/' << '\n';
        printBinaryTree(pRoot->pLeft);
    }

    if (pRoot->pRight != nullptr)
    {
        std::cout << '\\' << '\n';
        printBinaryTree(pRoot->pRight);
    }
}


void inorderPrintTree(TreeNode* pRoot)
{
    if (nullptr == pRoot)
        return;

    inorderPrintTree(pRoot->pLeft);
    std::cout << pRoot->value << " ";
    inorderPrintTree(pRoot->pRight);
}


int main(void)
{
    TreeNode* root = nullptr;

    root = new TreeNode(15);

    TreeNode::insertIntoBST(root, 15);
    TreeNode::insertIntoBST(root, 15);
    TreeNode::insertIntoBST(root, 15);
    TreeNode::insertIntoBST(root, 10);
    TreeNode::insertIntoBST(root, 10);
    TreeNode::insertIntoBST(root, 20);
    TreeNode::insertIntoBST(root, 8);
    TreeNode::insertIntoBST(root, 16);
    TreeNode::insertIntoBST(root, 25);
    TreeNode::insertIntoBST(root, 12);
    TreeNode::insertIntoBST(root, 12);
    TreeNode::insertIntoBST(root, 8);
    TreeNode::insertIntoBST(root, 16);
    TreeNode::insertIntoBST(root, 25);

    //printBinaryTree(root);
    inorderPrintTree(root);
}
