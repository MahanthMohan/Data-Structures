#include "singlylinkedlist.h"
#include "stack.h"
#include "queue.h"
#include "currency.h"
#include "dollar.h"

/**
 * Name: Mahanth Mohan
 * Class: CIS 22C
 * Section: 051Z
 * Lab: #3
 * Has the main runner to demonstrate the working of the SinglyLinkedList,
 * Queue, and Stack ADTs.
 * */
int main() {
    // Constructs an array with 20 dollar objects
    Currency* currs[] = {new Dollar("dollar", 57.12), new Dollar("dollar", 23.44), new Dollar("dollar", 87.43),
                         new Dollar("dollar", 68.99), new Dollar("dollar", 111.22), new Dollar("dollar", 44.55),
                         new Dollar("dollar", 77.77), new Dollar("dollar", 18.36), new Dollar("dollar", 543.21),
                         new Dollar("dollar", 20.21), new Dollar("dollar", 345.67), new Dollar("dollar", 36.18),
                         new Dollar("dollar", 48.48), new Dollar("dollar", 101.00), new Dollar("dollar", 11.00),
                         new Dollar("dollar", 21), new Dollar("dollar", 51), new Dollar("dollar", 1),
                         new Dollar("dollar", 251), new Dollar("dollar", 151)};

    SinglyLinkedList* linked_list = new SinglyLinkedList();
    Stack* st = new Stack();
    Queue* queue = new Queue();

    std::cout << "A) Added first 7 objects into LinkedList" << std::endl;
    // Adds the first 7 objects in reverse order
    for (int i = 0; i < 7; i++) {
        linked_list->appendCurrency(currs[6 - i]);
    }

    std::string currName = "dollar";
    int foundIndex1 = linked_list->seqSearch(new Dollar("dollar", 87.43));
    int foundIndex2 = linked_list->seqSearch(new Dollar("dollar", 44.56));
    std::cout << "B) Search for $87.43 and $44.56" << std::endl;
    std::cout << "Found $87.43 at index " << foundIndex1 << std::endl;
    std::cout << "Found $44.56 at index " << foundIndex2 << std::endl;
    
    std::cout << "C) Removing node at $111.22 and index 2 node" << std::endl;
    linked_list->removeCurrency(new Dollar("dollar", 111.22));
    std::cout << "D) " << linked_list->printList() << std::endl;

    int nodeIdx = 2;
    Currency* removed = linked_list->removeCurrency(2);
    std::cout << linked_list->printList() << std::endl;

    std::cout << "E) Adding 4 objects #9 to # 12" << std::endl;
    for (int i = 0; i < 4; i++) {
        int lstIdx = (i + 9) % 5;
        Currency* cur = currs[i];
        linked_list->addCurrency(currs[i], lstIdx);
    }

    std::cout << "F) Removing 2 objects at indexes mod 6 and mod 7" << std::endl;
    int currencyCount = linked_list->countCurrency();
    linked_list->removeCurrency(currencyCount % 6);
    linked_list->removeCurrency(currencyCount % 7);
    std::cout << "G) " << linked_list->printList() << std::endl;

    std::cout << std::endl;
    std::cout << "A) Pushing 7 objects from array 13 onto stack" << std::endl;
    for (int i = 0; i < 7; i++) {
        st->push(currs[13 + i]);
    }

    Currency* peekResult = st->peek();
    std::cout << "B) Peek Result: " << peekResult->toString() << std::endl;

    std::cout << "C) Performing 3 pop() on stack" << std::endl;
    st->pop();
    st->pop();   
    st->pop();

    std::cout << "D) " << st->printStack() << std::endl;
    std::cout << "E) Push 5 more objects onto stack" << std::endl;
    for (int k = 0; k < 5; k++) {
        st->push(currs[k]);
    }

    std::cout << "F) pop() 2 times in succession" << std::endl;
    st->pop();
    st->pop();
    std::cout << "G) " << st->printStack() << std::endl;
    std::cout << std::endl;

    std::cout << "A) enqueue() 7 objects onto the queue" << std::endl;
    int objectCount = 0;
    for (int i = 5; i < 20 && objectCount < 7; i++) {
        if (i % 2) {
            queue->enqueue(currs[i]);
            objectCount += 1;
        }
    }

    std::cout << "B) peekFront() and peekRear() on the queue" << std::endl;
    Currency* frontQueue = queue->peekFront();
    Currency* rearQueue = queue->peekRear();
    std::cout << frontQueue->toString() << std::endl;
    std::cout << rearQueue->toString() << std::endl;

    std::cout << "C) 2 dequeue()'s in succession" << std::endl;
    queue->dequeue();
    queue->dequeue();
    std::cout << "D) " << queue->printQueue() << std::endl;
    std::cout << "E) enqueue() 5 more objects" << std::endl;
    for (int i = 0; i < 5; i++) {
        queue->enqueue(currs[10 + i]);
    }

    std::cout << "F) 3 dequeue()'s in succession" << std::endl;
    queue->dequeue();
    queue->dequeue();
    queue->dequeue();
    std::cout << "G) " << queue->printQueue() << std::endl;

    std::cout << "Tested operations on LinkedList, Queue, and Stack" << std::endl;
}