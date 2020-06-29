




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

    Node* insert(int data);

    void printToStdOut();

private:
    Node* m_pHead;
    int m_nCount;
};
