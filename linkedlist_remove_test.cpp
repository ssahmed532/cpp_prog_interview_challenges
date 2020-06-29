#include "linked_list.h"
#include <cassert>
#include <iostream>


int main(void)
{
    {
        LinkedList myLL;
        assert(myLL.getSize() == 0);

        Node *node1 = myLL.insert(123);
        assert(myLL.getSize() == 1);
        Node *node2 = myLL.insert(456);
        assert(myLL.getSize() == 2);
        Node *node3 = myLL.insert(789);
        assert(myLL.getSize() == 3);
        Node *node4 = myLL.insert(314);
        assert(myLL.getSize() == 4);
        Node *node5 = myLL.insert(786);
        assert(myLL.getSize() == 5);

        auto listSize = myLL.getSize();

        std::cout << "List contents before removal:" << '\n';
        myLL.printToStdOut();

        // remove an item in the *middle* of the list
        auto succeeded = myLL.remove(node4);
        assert(succeeded);
        assert(myLL.getSize() == (listSize - 1));
        std::cout << "List contents *AFTER* removing Node with data:" << node4->getData() << '\n';
        myLL.printToStdOut();

        std::cout << '\n';
        std::cout << '\n';
    }

    {
        LinkedList myLL;
        assert(myLL.getSize() == 0);

        Node *node1 = myLL.insert(123);
        assert(myLL.getSize() == 1);
        Node *node2 = myLL.insert(456);
        assert(myLL.getSize() == 2);
        Node *node3 = myLL.insert(789);
        assert(myLL.getSize() == 3);
        Node *node4 = myLL.insert(314);
        assert(myLL.getSize() == 4);
        Node *node5 = myLL.insert(786);
        assert(myLL.getSize() == 5);

        auto listSize = myLL.getSize();

        std::cout << "List contents before removal:" << '\n';
        myLL.printToStdOut();

        // remove an item in the *middle* of the list
        auto succeeded = myLL.remove(node2);
        assert(succeeded);
        assert(myLL.getSize() == (listSize - 1));
        std::cout << "List contents *AFTER* removing Node with data:" << node2->getData() << '\n';
        myLL.printToStdOut();

        std::cout << '\n';
        std::cout << '\n';
    }

    {
        LinkedList myLL;
        assert(myLL.getSize() == 0);

        Node *node1 = myLL.insert(123);
        assert(myLL.getSize() == 1);
        Node *node2 = myLL.insert(456);
        assert(myLL.getSize() == 2);
        Node *node3 = myLL.insert(789);
        assert(myLL.getSize() == 3);
        Node *node4 = myLL.insert(314);
        assert(myLL.getSize() == 4);
        Node *node5 = myLL.insert(786);
        assert(myLL.getSize() == 5);

        auto listSize = myLL.getSize();

        std::cout << "List contents before removal:" << '\n';
        myLL.printToStdOut();

        // remove the last node in the list
        auto succeeded = myLL.remove(node1);
        assert(succeeded);
        assert(myLL.getSize() == (listSize - 1));
        std::cout << "List contents *AFTER* removing Node with data:" << node1->getData() << '\n';
        myLL.printToStdOut();

        std::cout << '\n';
        std::cout << '\n';
    }

    return 0;
}
