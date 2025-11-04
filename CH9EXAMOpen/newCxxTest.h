//copyright 2025
#ifndef NEWCXXTEST_H
#define NEWCXXTEST_H

#include <cxxtest/TestSuite.h>
#include "Hash_Table_Chain.h"
#include "Person.h"
#include <string>
#include <sstream>

class newCxxTest : public CxxTest::TestSuite {
public:

    void test_hash_map() {
        KW::hash_map<int, int> map;
        TS_ASSERT_EQUALS(map.size(), 0);
        TS_ASSERT(map.empty());
    }

    void test_insert() {
        KW::hash_map<std::string, int> map;
        auto result1 = map.insert(std::make_pair("key1", 100));
        TS_ASSERT(result1.second);
        TS_ASSERT_EQUALS(result1.first->second, 100);

        auto result2 = map.insert(std::make_pair("key1", 200));
        TS_ASSERT(!result2.second);
        TS_ASSERT_EQUALS(result2.first->second, 100);
    }

    void test_operator_brackets() {
        KW::hash_map<std::string, int> map;
        map["test"] = 42;
        TS_ASSERT_EQUALS(map["test"], 42);
        map["test"] = 99;
        TS_ASSERT_EQUALS(map["test"], 99);
    }

    void test_find() {
        KW::hash_map<int, std::string> map;
        map[1] = "one";
        map[2] = "two";

        auto it = map.find(1);
        TS_ASSERT(it != map.end());
        TS_ASSERT_EQUALS(it->second, "one");

        auto it2 = map.find(999);
        TS_ASSERT(it2 == map.end());
    }


    void test_erase() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        map[2] = 20;
        TS_ASSERT_EQUALS(map.size(), 2);

        bool erased = map.erase(1);
        TS_ASSERT(erased);
        TS_ASSERT_EQUALS(map.size(), 1);

        bool erased2 = map.erase(999);
        TS_ASSERT(!erased2);
    }

    void test_rehash() {
        KW::hash_map<int, int> map;
        for (int i = 0; i < 100; i++) {
            map[i] = i * 2;
        }
        for (int i = 0; i < 100; i++) {
            TS_ASSERT_EQUALS(map[i], i * 2);
        }
    }

    void test_begin() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        map[2] = 20;
        map[3] = 30;

        int count = 0;
        for (auto it = map.begin(); it != map.end(); ++it) {
            count++;
            TS_ASSERT(it->second > 0);
        }
        TS_ASSERT_EQUALS(count, 3);
    }

    void test_end() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        const KW::hash_map<int, int>& cmap = map;

        auto it = cmap.begin();
        TS_ASSERT(it != cmap.end());
    }

    void test_copy_constructor() {
        KW::hash_map<int, int> map1;
        map1[1] = 10;
        map1[2] = 20;

        KW::hash_map<int, int> map2(map1);
        TS_ASSERT_EQUALS(map2.size(), 2);
        TS_ASSERT_EQUALS(map2[1], 10);
        TS_ASSERT_EQUALS(map2[2], 20);
    }

    void test_operator_equals() {
        KW::hash_map<int, int> map1;
        map1[1] = 10;

        KW::hash_map<int, int> map2;
        map2 = map1;
        TS_ASSERT_EQUALS(map2[1], 10);
    }

    void test_to_string() {
        KW::hash_map<std::string, int> map;
        map["a"] = 1;
        std::string result = map.to_string();
        TS_ASSERT(result.length() > 0);
    }

    void test_empty_to_string() {
        KW::hash_map<int, int> map;
        std::string result = map.to_string();
        TS_ASSERT_EQUALS(result, "{}");
    }

    void test_hash_Person() {
        KW::hash_map<Person, std::string> map;
        Person p1("John", "Doe", "123", 1990);
        map[p1] = "Test";
        TS_ASSERT_EQUALS(map[p1], "Test");
    }

    void test_age() {
        Person p("John", "Doe", "123", 1990);
        TS_ASSERT_EQUALS(p.age(2020), 30);
    }

    void test_can_vote() {
        Person p1("John", "Doe", "123", 2000);
        TS_ASSERT(p1.can_vote(2020));

        Person p2("Jane", "Doe", "456", 2010);
        TS_ASSERT(!p2.can_vote(2020));
    }

    void test_can_drink() {
        Person p1("John", "Doe", "123", 1995);
        TS_ASSERT(p1.can_drink(2020));

        Person p2("Jane", "Doe", "456", 2005);
        TS_ASSERT(!p2.can_drink(2020));
    }

    void test_is_senior() {
        Person p1("John", "Doe", "123", 1950);
        TS_ASSERT(p1.is_senior(2020));

        Person p2("Jane", "Doe", "456", 2000);
        TS_ASSERT(!p2.is_senior(2020));
    }

    void test_operator_equal_equal() {
        Person p1("John", "Doe", "123", 1990);
        Person p2("John", "Doe", "456", 1995);
        Person p3("Jane", "Doe", "123", 1990);

        TS_ASSERT(p1 == p2);
        TS_ASSERT(p1 != p3);
    }

    void test_set_given_name() {
        Person p;
        p.set_given_name("John");
        p.set_family_name("Doe");
        p.set_birth_year(1990);

        TS_ASSERT_EQUALS(p.get_given_name(), "John");
        TS_ASSERT_EQUALS(p.get_family_name(), "Doe");
        TS_ASSERT_EQUALS(p.get_birth_year(), 1990);
    }

    void test_get_ID() {
        Person p("John", "Doe", "12345", 1990);
        TS_ASSERT_EQUALS(p.get_ID_number(), "12345");
    }

    void test_person_ostream() {
        Person p("Jane", "Smith", "678", 1985);
        std::ostringstream os;
        os << p;
        std::string result = os.str();
        TS_ASSERT(result.find("Jane") != std::string::npos);
        TS_ASSERT(result.find("Smith") != std::string::npos);
        TS_ASSERT(result.find("678") != std::string::npos);
    }

    struct SimpleHashable {
        int val;
        operator size_t() const { return static_cast<size_t>(val); }
    };

    void test_hash_string() {
        hash<std::string> h;
        size_t result = h("test");
        TS_ASSERT(result > 0);
    }

    void test_hash_int() {
        hash<int> h;
        size_t result = h(42);
        TS_ASSERT(result > 0);
    }

    void test_operator_star() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        auto it = map.begin();
        TS_ASSERT_EQUALS((*it).second, 10);
        TS_ASSERT_EQUALS(it->second, 10);
    }

    void test_operator_plus_plus() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        map[2] = 20;
        auto it = map.begin();
        ++it;
        TS_ASSERT(it != map.end());
        auto it2 = map.begin();
        it2++;
        TS_ASSERT(it2 != map.end());
    }




    void test_const_iterator_ops() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        const KW::hash_map<int, int>& cmap = map;
        auto cit = cmap.begin();
        TS_ASSERT_EQUALS((*cit).second, 10);
        TS_ASSERT_EQUALS(cit->second, 10);
    }

    void test_const_iterator_post_increment() {
        KW::hash_map<int, int> map;
        map[1] = 10;
        map[2] = 20;
        const KW::hash_map<int, int>& cmap = map;
        auto cit = cmap.begin();
        cit++;
        TS_ASSERT(cit != cmap.end());
    }

    void test_const_iterator_dereference_end_star() {
        KW::hash_map<int, int> map;
        const KW::hash_map<int, int>& cmap = map;
        auto cit = cmap.end();
        TS_ASSERT_THROWS(*cit, std::invalid_argument);
    }


    void test_size() {
        KW::hash_map<int, int> map;
        for (int i = 0; i < 50; i++) {
            map[i] = i;
        }
        TS_ASSERT_EQUALS(map.size(), 50);
    }

    void test_empty() {
        KW::hash_map<int, int> map;
        TS_ASSERT(map.begin() == map.end());
    }
};

#endif