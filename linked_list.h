




class Node
{
public:
    Node()
    : m_nData(-1), m_pNext(nullptr)
    {
    }

    Node(int data)
    : m_nData(data), m_pNext(nullptr)
    {
    }

    int getData() const
    {
        return m_nData;
    }

    Node* getNext() const
    {
        return m_pNext;
    }

public:
    int m_nData;
    Node* m_pNext;
};



class LinkedList
{
public:
    LinkedList()
    {
        m_pHead = nullptr;
        m_nCount = 0;
    }

    // TODO:
    //      write a destructor

    // TODO:
    //      write a copy constructor

    // Insert the given data item into the List, and return a pointer
    // to the newly created LL Node.
    Node* insert(int data);

    // Remove the specified node from the List
    bool remove(Node* pNode);

    // Get the size of the List (# of items/nodes in it)
    int getSize() const
    {
        return m_nCount;
    }

    // Print the contents of the List to stdout
    void printToStdOut();

private:
    Node* m_pHead;
    int m_nCount;
};
