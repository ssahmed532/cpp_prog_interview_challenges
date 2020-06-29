#include "linked_list.h"
#include <cassert>
#include <iostream>
#include <stdexcept>


Node* LinkedList::insert(int data)
{
    Node* pNewNode = new Node(data);

    pNewNode->m_pNext = m_pHead;
    m_pHead = pNewNode;

    ++m_nCount;

    return pNewNode;
}


bool LinkedList::remove(Node* pNode)
{
    if (nullptr == pNode)
        throw std::invalid_argument("Node to remove is null");

    // The node to remove is at the head of the list: handle separately
    if (pNode == m_pHead)
    {
        assert(pNode->getData() == m_pHead->getData());
        m_pHead = m_pHead->getNext();
        --m_nCount;

        return true;
    }

    // scan the list to find the location of the specified node
    Node* current = m_pHead;
    bool found = false;
    while (current != nullptr)
    {
        if (current->getNext() == pNode)
        {
            found = true;
            break;
        }

        current = current->getNext();
    }

    if (found)
    {
        assert(pNode->getData() == current->getNext()->getData());
        current->m_pNext = current->m_pNext->m_pNext;
        --m_nCount;

        return true;
    }

    return false;
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
