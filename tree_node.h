class TreeNode
{
    public:
        // default constructor
        TreeNode()
        {
            value = (-1);
            pLeft = nullptr;
            pRight = nullptr;
        }

        TreeNode(int item)
        {
            value = item;
            pLeft = nullptr;
            pRight = nullptr;
        }

        int value;
        TreeNode *pLeft;
        TreeNode *pRight;

        bool isLeaf()
        {
            return (pLeft == nullptr) && (pRight == nullptr);
        }
};