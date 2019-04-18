#include "tree_node.h"


bool IsUniValTree(TreeNode *pRoot)
{
    if (nullptr == pRoot)
        return false;

    if ((nullptr == pRoot->pLeft) && (nullptr == pRoot->pRight))
        return true;

    if (pRoot->pLeft && pRoot->pRight &&
        (pRoot->value == pRoot->pLeft->value) &&
        (pRoot->value == pRoot->pRight->value))
        return true;

    if (pRoot->pLeft && !pRoot->pRight)
    {
        return (pRoot->value == pRoot->pLeft->value);
    }
    else if (pRoot->pRight && !pRoot->pLeft)
    {
        return (pRoot->value == pRoot->pRight->value);
    }
    
    return false;
}
