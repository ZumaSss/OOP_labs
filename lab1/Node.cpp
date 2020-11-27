#include "LinkedList.h"

LinkedList::Node::Node() {
    value = value_type();
}

LinkedList::Node::Node(value_type val) {
    value = val;
}

LinkedList::Node::Node(value_type val, LinkedList::Node* _prev, LinkedList::Node* _next) {
    value = val;
    prev = _prev;
    next = _next;
}