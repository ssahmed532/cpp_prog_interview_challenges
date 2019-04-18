#include "tree_node.h"
#include <assert.h>
#include <iostream>


int main(void)
{
    TreeNode* root = nullptr;

    root = new TreeNode(15);

    TreeNode::insertIntoBST(root, 10);
    TreeNode::insertIntoBST(root, 20);
    TreeNode::insertIntoBST(root, 8);
    TreeNode::insertIntoBST(root, 18);
    TreeNode::insertIntoBST(root, 25);
    TreeNode::insertIntoBST(root, 12);
    TreeNode::insertIntoBST(root, 16);
    TreeNode::insertIntoBST(root, 19);
    TreeNode::insertIntoBST(root, 30);

    //printBinaryTree(root);
    //inorderPrintTree(root);

    bool found = false;
    int key = 0;

    key = 23;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 30;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 8;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 13;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 16;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 19;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 20;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 5;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    key = 10;
    found = TreeNode::searchKeyInBST(root, key);
    if (found)
        std::cout << "Key " << key << " found in BST" << '\n';
    else
        std::cerr << "Key " << key << " NOT FOUND in BST" << '\n';

    return 0;
}
