#include "linked_list.h"


int main(void)
{
    LinkedList myLL;

    Node* node1 = myLL.insert(123);
    Node* node2 = myLL.insert(456);
    Node* node3 = myLL.insert(789);
    Node* node4 = myLL.insert(314);
    Node* node5 = myLL.insert(786);

    myLL.printToStdOut();

    return 0;
}
