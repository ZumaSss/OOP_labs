#include "LinkedList.h"

LinkedList::const_iterator::const_iterator() {
    curInList = new Node();
}

LinkedList::const_iterator::const_iterator(LinkedList::Node *node) {
    curInList = node;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator=(const LinkedList::const_iterator &other) {
    curInList = other.curInList;
    return *this;
}

bool LinkedList::const_iterator::operator!=(const LinkedList::const_iterator &other) const {
    return curInList != other.curInList;
}

bool LinkedList::const_iterator::operator==(const LinkedList::const_iterator &other) const {
    return curInList == other.curInList;
}

const value_type &LinkedList::const_iterator::operator*() const {
    return curInList -> value;
}

const value_type *LinkedList::const_iterator::operator->() const {
    return &(curInList -> value);
}

LinkedList::const_iterator &LinkedList::const_iterator::operator++() {
    curInList = curInList -> next;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int) {
    LinkedList::const_iterator it = *this;
    curInList = curInList -> next;
    return it;
}

LinkedList::const_iterator &LinkedList::const_iterator::operator--() {
    curInList = curInList -> prev;
    return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int) {
    LinkedList::const_iterator it = *this;
    curInList = curInList -> next;
    return it;
}

LinkedList::const_iterator LinkedList::const_iterator::operator+(int shift) {
    LinkedList::const_iterator it = *this;
    for (int i = 0; i < shift; ++i) {
        ++it;
    }
    return it;
}

LinkedList::const_iterator LinkedList::const_iterator::operator-(int shift) {
    LinkedList::const_iterator it = *this;
    for (int i = 0; i < shift; ++i) {
        --it;
    }
    return it;
}