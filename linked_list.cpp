#include "linked_list.h"
#include <iostream>


Node* LinkedList::insert(int data)
{
    Node* pNewNode = new Node(data);

    pNewNode->m_pNext = m_pHead;
    m_pHead = pNewNode;

    ++m_nCount;

    return pNewNode;
}


void LinkedList::printToStdOut()
{
    std::cout << "There are " << m_nCount << " items in the LinkedList" << '\n';

    Node* currentNode = m_pHead;
    while (currentNode != nullptr)
    {
        std::cout << currentNode->getData() << " ";

        currentNode = currentNode->getNext();
    }
    std::cout << '\n';
}
