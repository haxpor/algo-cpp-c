#ifndef __STACKLINKEDLIST_H__
#define __STACKLINKEDLIST_H__

#include <type_traits>
#include <algorithm>

/*
====================
Stack with no boundary checking implemented with linked list.
====================
*/
template<typename ItemType>
class StackLinkedList {
public:
                            StackLinkedList(int max=100);
                            ~StackLinkedList();

    /**
     * Push an input item into the stack by copying.
     */
    void                    Push(const ItemType& item);

    /**
     * Pop from statck.
     * Return element by value, but destroy such element managed internally before that.
     */
    ItemType                Pop(void);

    /**
     * Get whether the stack is empty.
     */
    bool                    IsEmpty(void) const;

    /**
     * Provide debugging capability to print all elements inside the stack.
     */
    void                    PrintAllElements(void) const;

private:
    struct Node {
        /** Data of the node **/
        ItemType    data;

        /** Pointer to next node. */
        Node*       next;
    };

    /**
     * Pointer to head node.
     */
    Node                    *head;

    /**
     * Past-last node to indicate empty elements in linked-list.
     */
    Node                    *z;
};

template<typename ItemType>
inline StackLinkedList<ItemType>::StackLinkedList(int max) {
    head = new Node();
    z = new Node();

    // immediately point head to past-last pointer
    // there's no data for this bookkeeping nodes
    head->next = z;

    // last node just points to itself
    // there's no data for this bookkeeping nodes
    z->next = z;
}

template<typename ItemType>
inline StackLinkedList<ItemType>::~StackLinkedList() {
    // remove intermediate nodes
    Node* tmpNode = head->next;
    while (tmpNode != z) {
        Node* next = tmpNode->next;
        delete tmpNode;
        tmpNode = next;
    }

    // remove head and z
    delete head;
    head = nullptr;
    delete z;
    z = nullptr;
}

/* Following two functions provided for convenient in users' use case
 * Might be not all the time users will need move semantics?
 * So the first one below here is provided
 */
template<typename ItemType>
inline void StackLinkedList<ItemType>::Push(const ItemType& item) {
    // create a new node
    Node* newNode = new Node();

    // if it's a class type then we construct a new copy of such object before pushing
    if (std::is_class<ItemType>::value) {
        newNode->data = ItemType(item);
    } else {    // by value
        newNode->data = item;
    }
    newNode->next = head->next;

    // re-route head's next
    head->next = newNode;
}

template<typename ItemType>
inline ItemType StackLinkedList<ItemType>::Pop(void) {
    Node* tmpPopped = head->next;
    head->next = tmpPopped->next;

    ItemType t = tmpPopped->data;   // by copy

    // delete such node
    delete tmpPopped;

    return t;
}

template<typename ItemType>
inline bool StackLinkedList<ItemType>::IsEmpty(void) const {
    return head->next == z;
}

template<typename ItemType>
inline void StackLinkedList<ItemType>::PrintAllElements(void) const {
    if (!IsEmpty()) {
        Node* tmp = nullptr;
        while ((tmp = head->next) != z) {
            std::cout << tmp->data << ", ";
        }
    }
}

#endif /* __STACK_H__ */
