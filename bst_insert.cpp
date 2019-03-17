#include "tree_node.h"
#include <assert.h>
#include <iostream>


void insertIntoBST(TreeNode* pRoot, int item)
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
}


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

    insertIntoBST(root, 10);
    insertIntoBST(root, 20);
    insertIntoBST(root, 8);
    insertIntoBST(root, 16);
    insertIntoBST(root, 25);
    insertIntoBST(root, 12);

    //printBinaryTree(root);
    inorderPrintTree(root);
}
