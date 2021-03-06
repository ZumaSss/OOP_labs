#include "LinkedList.h"
#include <stdexcept>

using std::logic_error;

LinkedList::LinkedList() {
    fictNode = new Node();
    fictNode -> prev = fictNode;
    fictNode -> next = fictNode;
}

LinkedList::LinkedList(const LinkedList &other) {
    fictNode = new Node();
    fictNode -> prev = fictNode;
    fictNode -> next = fictNode;
    for (LinkedList::const_iterator it = other.cbegin(); it != other.cend(); ++it) {
        push_back(*it);
    }
}

LinkedList::LinkedList(LinkedList &&other) noexcept {
    fictNode = other.fictNode;
    capacity = other.capacity;
    other.fictNode = nullptr;
    other.capacity = 0;
}

LinkedList::~LinkedList() {
    clear();
    delete fictNode;
}

LinkedList &LinkedList::operator=(const LinkedList &other) {
    if (this == &other) return *this;
    clear();
    for (LinkedList::const_iterator it = other.cbegin(); it != other.cend(); ++it) {
        push_back(*it);
    }
    return *this;
}

LinkedList &LinkedList::operator=(LinkedList &&other) {
    if (this == &other) return *this;
    clear();
    delete fictNode;
    fictNode = other.fictNode;
    other.fictNode = nullptr;
    capacity = other.capacity;
    other.capacity = 0;
    return *this;
}

int LinkedList::size() const {
    return capacity;
}

bool LinkedList::empty() const {
    return capacity == 0;
}

LinkedList::iterator LinkedList::begin() {
    return LinkedList::iterator(fictNode -> next);
}

LinkedList::const_iterator LinkedList::begin() const {
    return LinkedList::const_iterator(fictNode -> next);
}

LinkedList::const_iterator LinkedList::cbegin() const {
    return LinkedList::const_iterator(fictNode -> next);
}

LinkedList::iterator LinkedList::end() {
    return LinkedList::iterator(fictNode);
}

LinkedList::const_iterator LinkedList::end() const {
    return LinkedList::const_iterator(fictNode);
}

LinkedList::const_iterator LinkedList::cend() const {
    return LinkedList::const_iterator(fictNode);
}

value_type &LinkedList::front() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return fictNode -> next -> value;
}

const value_type &LinkedList::front() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return fictNode -> next -> value;
}

value_type &LinkedList::back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return fictNode -> prev -> value;
}

const value_type &LinkedList::back() const {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    return fictNode -> prev -> value;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator position) {
    Node* beforePos = (position - 1).curInList;
    Node* afterPos = (position + 1).curInList;
    beforePos -> next = afterPos;
    afterPos -> prev = beforePos;
    delete position.curInList;
    --capacity;
    return LinkedList::iterator(beforePos);
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator begin, LinkedList::iterator end) {
    LinkedList::iterator it = begin;
    while (it != end) {
        it = erase(it);
    }
    return it;
}

int LinkedList::remove(const value_type &value) {
    int count = 0;
    LinkedList::iterator it = begin();
    while (it != end()) {
        if (*it == value) {
            it = erase(it);
            ++count;
        } else {
            ++it;
        }
    }
    return count;
}

void LinkedList::clear() {
    while (!empty()) {
        pop_back();
    }
}

void LinkedList::pop_back() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    erase(end() - 1);
}

void LinkedList::pop_front() {
    if (empty()) {
        throw std::logic_error("The list is empty!");
    }
    erase(begin());
}

void LinkedList::push_back(const value_type &value) {
    insert(end(), value);
}

void LinkedList::push_front(const value_type &value) {
    insert(begin(), value);
}

LinkedList::iterator LinkedList::insert(LinkedList::iterator before, const value_type &value) {
    Node* last = (before - 1).curInList;
    Node* after = before.curInList;
    Node* toInsert = new Node(value, last, after);
    last -> next = toInsert;
    after -> prev = toInsert;
    ++capacity;
    return LinkedList::iterator(toInsert);
}

LinkedList &LinkedList::operator+=(const LinkedList &other) {
    for (LinkedList::const_iterator it = other.cbegin(); it != other.cend(); ++it) {
        push_back(*it);
    }
    return *this;
}

bool operator!=(const LinkedList &left, const LinkedList &right) {
    return !(left == right);
}

bool operator==(const LinkedList &left, const LinkedList &right) {
    if (&left == &right) return true;
    if (left.size() != right.size()) return false;
    LinkedList::const_iterator it1 = left.cbegin();
    LinkedList::const_iterator it2 = right.cbegin();
    for (; it1 != left.cend() && it2 != right.cend(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    return !(it1 != left.cend() || it2 != right.cend());
}

LinkedList operator+(const LinkedList & left, const LinkedList & right) {
    LinkedList newList;
    if (!left.empty()) {
        for (LinkedList::const_iterator it = left.cbegin(); it != left.cend(); ++it) {
            newList.push_back((*it));
        }
    }
    if (!right.empty()) {
        for (LinkedList::const_iterator it = right.cbegin(); it != right.cend(); ++it) {
            newList.push_back((*it));
        }
    }
    return newList;
}
