#include "LinkedList.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(test, TestingList) {
    LinkedList newList;
    ASSERT_TRUE(newList.empty());

    EXPECT_ANY_THROW(newList.front());
    EXPECT_ANY_THROW(newList.back());
    EXPECT_ANY_THROW(newList.pop_front());
    EXPECT_ANY_THROW(newList.pop_back());

    newList.push_back(value_type());
    newList.push_back(value_type());
    newList.push_back(value_type());

    EXPECT_EQ(newList.size(), 3);

    newList.push_front(value_type());
    newList.push_front(value_type());
    newList.push_front(value_type());

    EXPECT_EQ(newList.size(), 6);

    newList.clear();
    ASSERT_TRUE(newList.empty());

    newList.push_front(value_type());
    newList.push_front(value_type());
    newList.push_front(value_type());
    newList.push_back(value_type());
    newList.push_back(value_type());
    newList.push_back(value_type());

    newList.pop_back();
    newList.pop_back();
    newList.pop_back();
    newList.pop_back();

    EXPECT_EQ(newList.size(), 2);

    newList.pop_front();
    newList.pop_front();

    ASSERT_TRUE(newList.empty());

    for (int i = 0; i < 20; ++i) {
        newList.push_back(i);
    }

    int val = 0;
    for (LinkedList::iterator it = newList.begin(); it != newList.end(); ++it) {
        EXPECT_EQ(*it, val);
        ++val;
    }

    newList.clear();

    for (int i = 0; i < 20; ++i) {
        newList.push_front(i);
    }

    --val;
    for (LinkedList::iterator it = newList.begin(); it != newList.end(); ++it) {
        EXPECT_EQ(*it, val);
        --val;
    }

    newList.clear();

    for (int i = 0; i < 20; ++i) {
        newList.push_front(i);
    }
    LinkedList secondList = newList;
    EXPECT_TRUE(secondList == newList);
    EXPECT_FALSE(secondList != newList);

    LinkedList moveList = std::move(secondList);
    EXPECT_EQ(moveList, newList);
}

TEST(test, TestingIterators) {
    LinkedList newList;
    for (int i = 0; i < 20; ++i) {
        newList.push_back(i);
    }

    LinkedList::iterator it = newList.begin();
    it = it + 3;
    EXPECT_EQ(*it, 3);

    it = it - 5;
    EXPECT_EQ(*it, 19);

    LinkedList::const_iterator cIt = newList.cbegin();
    it = newList.begin();

    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(*cIt, i);
        EXPECT_EQ(*it, i);

        ++cIt;
        ++it;
    }

    EXPECT_TRUE(newList.end() == it);
    EXPECT_TRUE(newList.cend() == cIt);
}
