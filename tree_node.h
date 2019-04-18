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

        void debugPrint();

        // insert a new key into a given BST
        static bool insertIntoBST(TreeNode* pRoot, int item);

        /**
         * @brief      search for the specified key in the BST
         *
         * @param      pRoot  The root of the BST
         * @param[in]  key    The key to search for
         *
         * @return     { description_of_the_return_value }
         */
        static bool searchKeyInBST(TreeNode* pRoot, int key);
};
