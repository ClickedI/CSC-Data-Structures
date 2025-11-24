//copyright 2025
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Hash_Table_Open.h"
#include <string>
#include <sstream>

class newCxxTest : public CxxTest::TestSuite {
public:

    void testHashMap() {
        KW::hash_map<int, std::string> map;
        std::pair<KW::hash_map<int, std::string>::iterator, bool> result1 = map.insert(std::make_pair(1, "one"));
        TS_ASSERT_EQUALS(result1.second, true);  // Insert succeeded
    }

    void testInsert() {
        KW::hash_map<int, std::string> map;
        std::pair<KW::hash_map<int, std::string>::iterator, bool> result1 = map.insert(std::make_pair(1, "one"));
        TS_ASSERT_EQUALS(result1.second, true);  // Insert succeeded
        std::pair<KW::hash_map<int, std::string>::iterator, bool> result2 = map.insert(std::make_pair(2, "two"));
        TS_ASSERT_EQUALS(result2.second, true);
    }

    void testFind() {
        KW::hash_map<int, std::string> map;
        map.insert(std::make_pair(1, "one"));
        KW::hash_map<int, std::string>::iterator it1 = map.find(1);
        TS_ASSERT_EQUALS(it1->second, "one");

        const KW::hash_map<int, std::string>& const_map = map;
        map.insert(std::make_pair(2, "two"));
        KW::hash_map<int, std::string>::const_iterator it2 = const_map.find(2);
        TS_ASSERT_EQUALS(it2->second, "two");
    }

    void testString() {
        KW::hash_map<std::string, std::string> map;
        std::pair<KW::hash_map<std::string, std::string>::iterator, bool> result1 = map.insert(std::make_pair("john", "doe"));
        TS_ASSERT_EQUALS(result1.second, true);
    }

    void testThrows() {
        KW::hash_map<int, std::string> map;
        const KW::hash_map<int, std::string>& const_map = map;
        KW::hash_map<int, std::string>::const_iterator it1 = const_map.end();
        TS_ASSERT_THROWS(it1->second, std::invalid_argument);

        KW::hash_map<int, std::string>::iterator it2 = map.end();
        TS_ASSERT_THROWS(it2->second, std::invalid_argument);


    }

    void testRehash() {
        KW::hash_map<int, int> map;
        for (int i = 0; i < 76; i++) {
            map[i] = i * 2;
        }
        for (int i = 0; i < 76; i++) {
            TS_ASSERT_EQUALS(map[i], i * 2);
        }
    }

    void testErase() {
        KW::hash_map<int, std::string> map;
        TS_ASSERT_EQUALS(map.erase(1), false);
        map.insert(std::make_pair(1, "one"));
        map.insert(std::make_pair(2, "two"));
        map.erase(2);
        TS_ASSERT_EQUALS(map.size(), 1);
    }
};

#endif
