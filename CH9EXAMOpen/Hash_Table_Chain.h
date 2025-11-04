//copyright 2025
#ifndef HASH_TABLE_CHAIN_H_
#define HASH_TABLE_CHAIN_H_

#include <stdexcept>
#include <cstddef>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <ostream>
#include "hash.h"

namespace KW
{

    template<typename Key_Type, typename Value_Type>
    class hash_map {

    public:

        typedef std::pair<const Key_Type, Value_Type> Entry_Type;

        class iterator;
        class const_iterator;

        hash_map() : hash_fcn(hash<Key_Type>()), num_keys(0), the_table(INITIAL_CAPACITY, nullptr), LOAD_THRESHOLD(3.0), num_deletes(0) {}

        size_t locate(const Key_Type& key) {
            size_t index = hash_fcn(key) % the_table.size();
            while (the_table[index] != NULL
                   && (the_table[index] == DELETED
                       || the_table[index]->first != key))
                index = (index + 1) % the_table.size();
            return index;
        }

        std::pair<iterator, bool> insert(const Entry_Type& entry) {
            double load_factor = double(num_keys + num_deletes) / the_table.size();
            if (load_factor > LOAD_THRESHOLD) {
                rehash();
            }
            size_t index = locate(entry.first);
            if (the_table[index] == NULL) {
                the_table[index] = new Entry_Type(entry);
                num_keys++;
                return std::make_pair(iterator(this, index), true);
            } else {
                return std::make_pair(iterator(this, index), false);
            }
        }

        Value_Type& operator[](const Key_Type& key) {
            std::pair<iterator, bool> ret = insert(Entry_Type(key, Value_Type()));
            return ret.first->second;
        }

        bool erase(const Key_Type& key) {
            size_t index = locate(key);
            if(the_table[index] == nullptr || the_table[index] == DELETED) {
                return false;
            }

            delete the_table[index];
            the_table[index] = DELETED;
            num_deletes++;
            num_keys--;
            return true;
        }

        void rehash() {
            std::vector<Entry_Type*> other_table(the_table.size() * 2, NULL);
            the_table.swap(other_table);
            num_deletes = 0;
            for (size_t i = 0; i < other_table.size(); i++) {
                if ((other_table[i] != NULL) && (other_table[i] != DELETED)) {
                    size_t index = locate(other_table[i]->first);
                    the_table[index] = other_table[i];
                }
            }
        }

        hash_map(const hash_map<Key_Type, Value_Type>& other) :
                hash_fcn(hash<Key_Type>()), num_keys(0),
                the_table(other.the_table.size(), NULL),
                LOAD_THRESHOLD(0.75),
                num_deletes(0) {
            for (size_t i = 0; i < other.the_table.size(); i++) {
                if (other.the_table[i] != NULL && other.the_table[i] != DELETED)
                    insert(Entry_Type(other.the_table[i]->first,
                                      other.the_table[i]->second));
            }
        }

        hash_map<Key_Type, Value_Type>& operator=(const hash_map<Key_Type, Value_Type>& other) {
            if (this != &other) {
                for (size_t i = 0; i < the_table.size(); i++) {
                    if (the_table[i] != NULL && the_table[i] != DELETED) {
                        delete the_table[i];
                    }
                }
                the_table.clear();
                the_table.resize(other.the_table.size(), NULL);
                num_keys = 0;
                num_deletes = 0;
                for (size_t i = 0; i < other.the_table.size(); i++) {
                    if (other.the_table[i] != NULL && other.the_table[i] != DELETED) {
                        insert(Entry_Type(other.the_table[i]->first,
                                          other.the_table[i]->second));
                    }
                }
            }
            return *this;
        }

        ~hash_map() {
            for (size_t i = 0; i < the_table.size(); i++) {
                if (the_table[i] != nullptr && the_table[i] != DELETED) {
                    delete the_table[i];
                }
            }
        }

    private:

        hash<Key_Type> hash_fcn;
        size_t num_keys;
        std::vector<Entry_Type*> the_table;
        static const size_t INITIAL_CAPACITY = 100;
        const double LOAD_THRESHOLD;
        size_t num_deletes;
        static Entry_Type dummy;
        static Entry_Type* const DELETED;
    };

    template<typename Key_Type, typename Value_Type>
    typename hash_map<Key_Type, Value_Type>::Entry_Type
            hash_map<Key_Type, Value_Type>::dummy =
            std::pair<const Key_Type, Value_Type>(
                    Key_Type(), Value_Type());
    template<typename Key_Type, typename Value_Type>
    typename hash_map<Key_Type, Value_Type>::Entry_Type* const
            hash_map<Key_Type, Value_Type>::DELETED =
            &hash_map<Key_Type, Value_Type>::dummy;

} //namespace KW

#endif
