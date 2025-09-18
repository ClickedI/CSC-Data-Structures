//copyright 2025

#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>


//Include your classes header file(s) below and uncomment.
//#include "myClass.h"
#include "circular_list.h"
class newCxxTest : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testList()
    {
        KW::circular_list<int> newList{};
        TS_ASSERT_EQUALS(newList.num_items, 0);
    }

    void testCopyList()
    {
        KW::circular_list<int> lista{};
        lista.push_back(1);
        lista.push_back(2);
        KW::circular_list<int> listb{};
        listb = lista;
        TS_ASSERT_EQUALS(listb.num_items, lista.num_items);
    }

    void testIteratorFullTraversal()
    {
        // 1. Arrange: Create a list with a few items.
        KW::circular_list<int> list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);

        // 2. Act: Try to iterate through the list and count the elements.
        int counter = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            // With the buggy iterator, this loop will never end.
            counter++;
        }

        // 3. Assert: This line will never be reached.
        TS_ASSERT_EQUALS(counter, 3);
    }


    void testSwap()
    {
        KW::circular_list<int> newList{};
        newList.push_back(1);
        newList.push_back(2);
        KW::circular_list<int> secondList{};
        secondList.push_back(3);
        secondList.push_back(4);
        newList.swap(secondList);
        TS_ASSERT_EQUALS(newList.front(), 3);
        TS_ASSERT_EQUALS(secondList.front(), 1);
    }

    void testErase()
    {
        KW::circular_list<int> lista{};
        lista.push_back(1);
        lista.push_back(2);
        lista.erase(lista.begin());
        TS_ASSERT_EQUALS(lista.num_items, 1);
    }

    void testOP()
    {
        KW::circular_list<int> newList{};
        newList.push_back(1);
        KW::circular_list<int> secondList{};
        secondList = newList;
        TS_ASSERT_EQUALS(secondList.front(), 1);
    }

    void testPushFront()
    {
        KW::circular_list<int> newList{};
        newList.push_front(1);
        TS_ASSERT_EQUALS(newList.front(), 1);
        newList.push_front(2);
        TS_ASSERT_EQUALS(newList.front(), 2);
;    }

    void testPushBack()
    {
        KW::circular_list<int> newList{};
        newList.push_back(1);
        TS_ASSERT_EQUALS(newList.back(), 1);
        newList.push_back(2);
        TS_ASSERT_EQUALS(newList.back(), 2);
    }


    void testFront()
    {
        KW::circular_list<int> newList{};
        TS_ASSERT_THROWS(newList.front(), std::invalid_argument);
        newList.push_front(1);
        TS_ASSERT_EQUALS(newList.front(), 1);
    }

    void testBack()
    {
        KW::circular_list<int> newList{};
        TS_ASSERT_THROWS(newList.back(), std::invalid_argument);
        newList.push_back(1);
        TS_ASSERT_EQUALS(newList.back(), 1);
    }

    void testSize()
    {
        KW::circular_list<int> newList{};
        TS_ASSERT_EQUALS(newList.size(), 0);
        newList.push_back(1);
        TS_ASSERT_EQUALS(newList.size(), 1);
    }

    void testEmpty()
    {
        KW::circular_list<int> newList{};
        TS_ASSERT_EQUALS(newList.empty(), true);
        newList.push_back(1);
        newList.pop_front();
        TS_ASSERT_EQUALS(newList.size(), 0);
    }

    void testPopFront()
    {
        KW::circular_list<int> newList{};
        newList.push_front(1);
        newList.push_front(2);
        newList.pop_front();
        TS_ASSERT_EQUALS(newList.size(), 1);
    }

    void testPopBack()
    {
        KW::circular_list<int> newList{};
        TS_ASSERT_THROWS(newList.pop_back(), std::invalid_argument);
        newList.push_back(1);
        newList.push_back(2);
        newList.pop_back();
        TS_ASSERT_EQUALS(newList.size(), 1);
    }

};
#endif /* NEWCXXTEST_H */

