#include "LinkedList.h"

LinkedList::iterator::iterator() {
    curInList = new Node();
}

LinkedList::iterator::iterator(LinkedList::Node *node) {
    curInList = node;
}

LinkedList::iterator &LinkedList::iterator::operator=(const LinkedList::iterator &other) {
    curInList = other.curInList;
    return *this;
}

bool LinkedList::iterator::operator!=(const LinkedList::iterator &other) const {
    return curInList != other.curInList;
}

bool LinkedList::iterator::operator==(const LinkedList::iterator &other) const {
    return curInList == other.curInList;
}

value_type &LinkedList::iterator::operator*() {
    return curInList -> value;
}

value_type *LinkedList::iterator::operator->() {
    return &(curInList -> value);
}

LinkedList::iterator &LinkedList::iterator::operator++() {
    curInList = curInList -> next;
    return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int) {
    LinkedList::iterator it = *this;
    curInList = curInList -> next;
    return it;
}

LinkedList::iterator &LinkedList::iterator::operator--() {
    curInList = curInList -> prev;
    return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
    LinkedList::iterator it = *this;
    curInList = curInList -> prev;
    return it;
}

LinkedList::iterator LinkedList::iterator::operator+(int shift) { //?
    LinkedList::iterator it = *this;
    for (int i = 0; i < shift; ++i) {
        ++it;
    }
    return it;
}

LinkedList::iterator LinkedList::iterator::operator-(int shift) { //?
    LinkedList::iterator it = *this;
    for (int i = 0; i < shift; ++i) {
        --it;
    }
    return it;
}
