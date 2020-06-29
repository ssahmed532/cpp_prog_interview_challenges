#include "linked_list.h"
#include <cassert>


int main(void)
{
    LinkedList myLL;
    assert(myLL.getSize() == 0);

    Node* node1 = myLL.insert(123);
    assert(myLL.getSize() == 1);
    Node* node2 = myLL.insert(456);
    assert(myLL.getSize() == 2);
    Node* node3 = myLL.insert(789);
    assert(myLL.getSize() == 3);
    Node* node4 = myLL.insert(314);
    assert(myLL.getSize() == 4);
    Node* node5 = myLL.insert(786);
    assert(myLL.getSize() == 5);

    myLL.printToStdOut();

    return 0;
}
