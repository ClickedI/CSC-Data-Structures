//copyright 2025

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>


//Include your classes header file(s) below and uncomment.
//#include "myClass.h"
#include "list.h"
class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testList()
    {
        KW::list<int> newList{};
        TS_ASSERT_EQUALS(newList.num_items, 0);
    }

    void testCopyList()
    {
        KW::list<int> newList{};
        newList.push_back(1);
        newList.push_back(2);
        KW::list<int> copy(newList);
        TS_ASSERT_EQUALS(copy.num_items, newList.num_items);
    }

    void testIterator()
    {
        int array[] = {1, 2, 3, 4, 5};
        KW::list<int> newList(array, array+5);
        TS_ASSERT_EQUALS(newList.num_items, 5);
    }

    void testSwap()
    {
        KW::list<int> newList{};
        newList.push_back(1);
        newList.push_back(2);
        KW::list<int> secondList{};
        secondList.push_back(3);
        secondList.push_back(4);
        newList.swap(secondList);
        TS_ASSERT_EQUALS(newList.front(), 3);
        TS_ASSERT_EQUALS(secondList.front(), 1);
    }

    void testOP()
    {
        KW::list<int> newList{};
        newList.push_back(1);
        KW::list<int> secondList{};
        secondList = newList;
        TS_ASSERT_EQUALS(secondList.front(), 1);
    }

    void testPushFront()
    {
        KW::list<int> newList{};
        newList.push_front(1);
        TS_ASSERT_EQUALS(newList.front(), 1);
        newList.push_front(2);
        TS_ASSERT_EQUALS(newList.front(), 2);
;    }

    void testPushBack()
    {
        KW::list<int> newList{};
        newList.push_back(1);
        TS_ASSERT_EQUALS(newList.back(), 1);
        newList.push_back(2);
        TS_ASSERT_EQUALS(newList.back(), 2);
    }

    void testInsert()
    {
        KW::list<int> newList{};
        newList.insert(newList.begin(), 1);
        TS_ASSERT_EQUALS(newList.front(), 1);
        newList.insert(newList.begin(), 2);
        TS_ASSERT_EQUALS(newList.front(), 2);
    }

    void testFront()
    {
        KW::list<int> newList{};
        TS_ASSERT_THROWS(newList.front(), std::invalid_argument);
        newList.push_front(1);
        TS_ASSERT_EQUALS(newList.front(), 1);
    }

    void testBack()
    {
        KW::list<int> newList{};
        TS_ASSERT_THROWS(newList.back(), std::invalid_argument);
        newList.push_back(1);
        TS_ASSERT_EQUALS(newList.back(), 1);
    }

    void testSize()
    {
        KW::list<int> newList{};
        TS_ASSERT_EQUALS(newList.size(), 0);
        newList.push_back(1);
        TS_ASSERT_EQUALS(newList.size(), 1);
    }

    void testEmpty()
    {
        KW::list<int> newList{};
        TS_ASSERT_EQUALS(newList.empty(), true);
        newList.push_back(1);
        newList.pop_front();
        TS_ASSERT_EQUALS(newList.size(), 0);
    }

    void testPopFront()
    {
        KW::list<int> newList{};
        newList.push_front(1);
        newList.push_front(2);
        newList.pop_front();
        TS_ASSERT_EQUALS(newList.size(), 1);
    }

    void testPopBack()
    {
        KW::list<int> newList{};
        newList.push_back(1);
        newList.push_back(2);
        newList.pop_back();
        TS_ASSERT_EQUALS(newList.size(), 1);
    }

    void testRemove()
    {
        KW::list<int> newList{};
        TS_ASSERT_THROWS(newList.remove(newList.begin()), std::invalid_argument);
        newList.push_back(1);
        newList.push_back(2);
        newList.remove(newList.begin());
        TS_ASSERT_EQUALS(newList.size(), 1);
        newList.remove(--newList.end());
        TS_ASSERT_EQUALS(newList.size(), 0);
    }

    void testRemoveIndex()
    {
        int index = 1;
        KW::list<int> newList{};
        TS_ASSERT_THROWS(newList.remove(index), std::invalid_argument);
        newList.push_back(1);
        newList.push_back(1);
        newList.remove(index);
        TS_ASSERT_EQUALS(newList.size(), 0);
    }

    void testFind()
    {
        KW::list<int> newList{};
        newList.push_back(1);
        newList.push_back(2);
        newList.push_back(3);
        auto iter = ++newList.begin();
        TS_ASSERT_EQUALS(newList.find(2), iter);
    }
};
#endif /* NEWCXXTEST_H */

