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

        hash_map() : hash_fcn(), num_keys(0), the_buckets(INITIAL_CAPACITY), LOAD_THRESHOLD(3.0) {}

        hash_map(const hash_map<Key_Type, Value_Type>& other)
                : hash_fcn(), num_keys(0), the_buckets(other.the_buckets.size()), LOAD_THRESHOLD(3.0) {
            for (size_t i = 0; i < other.the_buckets.size(); i++) {
                for (typename std::list<Entry_Type>::const_iterator pos = other.the_buckets[i].begin();
                     pos != other.the_buckets[i].end(); ++pos) {
                    insert(*pos);
                }
            }
        }

        hash_map<Key_Type, Value_Type>& operator=(const hash_map<Key_Type, Value_Type>& other) {
            if (this != &other) {
                the_buckets.clear();
                the_buckets.resize(other.the_buckets.size());
                num_keys = 0;

                for (size_t i = 0; i < other.the_buckets.size(); i++) {
                    for (typename std::list<Entry_Type>::const_iterator pos = other.the_buckets[i].begin();
                         pos != other.the_buckets[i].end(); ++pos) {
                        insert(*pos);
                    }
                }
            }
            return *this;
        }

        ~hash_map() {}

        std::pair<iterator, bool> insert(const Entry_Type& entry) {
            double load_factor = double(num_keys) / the_buckets.size();
            if (load_factor > LOAD_THRESHOLD) {
                rehash();
            }

            size_t index = hash_fcn(entry.first) % the_buckets.size();

            typename std::list<Entry_Type>::iterator pos = the_buckets[index].begin();
            while (pos != the_buckets[index].end() && pos->first != entry.first)
                ++pos;
                if (pos == the_buckets[index].end()) {
                    the_buckets[index].push_back(Entry_Type(entry));
                    num_keys++;
                    return std::make_pair(iterator(this, index, --(the_buckets[index].end())), true);
                } else {
                    return std::make_pair(iterator(this, index, pos), false);
                }
            }

        iterator find(const Key_Type& key) {
            size_t index = hash_fcn(key) % the_buckets.size();

            typename std::list<Entry_Type>::iterator pos = the_buckets[index].begin();
            while (pos != the_buckets[index].end()) {
                if (pos->first == key) {
                    return iterator(this, index, pos);
                }
                ++pos;
            }
            return end();
        }

        const_iterator find(const Key_Type& key) const {
            size_t index = hash_fcn(key) % the_buckets.size();

            typename std::list<Entry_Type>::const_iterator pos = the_buckets[index].begin();
            while (pos != the_buckets[index].end()) {
                if (pos->first == key) {
                    return const_iterator(this, index, pos);
                }
                ++pos;
            }
            return end();
        }

        Value_Type& operator[](const Key_Type& key) {
            std::pair<iterator, bool> result = insert(Entry_Type(key, Value_Type()));
            return result.first->second;
        }

        bool erase(const Key_Type& key) {
            size_t index = hash_fcn(key) % the_buckets.size();

            typename std::list<Entry_Type>::iterator pos = the_buckets[index].begin();
            while (pos != the_buckets[index].end()) {
                if (pos->first == key) {
                    the_buckets[index].erase(pos);
                    num_keys--;
                    return true;
                }
                ++pos;
            }
            return false;
        }

        iterator begin() {
            for (size_t i = 0; i < the_buckets.size(); i++) {
                if (!the_buckets[i].empty()) {
                    return iterator(this, i, the_buckets[i].begin());
                }
            }
            return end();
        }

        const_iterator begin() const {
            for (size_t i = 0; i < the_buckets.size(); i++) {
                if (!the_buckets[i].empty()) {
                    return const_iterator(this, i, the_buckets[i].begin());
                }
            }
            return end();
        }

        iterator end() {
            return iterator(this, the_buckets.size() - 1, the_buckets[the_buckets.size() - 1].end());
        }

        const_iterator end() const {
            return const_iterator(this, the_buckets.size() - 1, the_buckets[the_buckets.size() - 1].end());
        }

        size_t size() const {
            return num_keys;
        }

        bool empty() const {
            return num_keys == 0;
        }

        std::string to_string() const {
            std::ostringstream result;
            result << "{";
            const_iterator itr = begin();
            if (itr != end()) {
                result << "[" << itr->first << ", " << itr->second << "]";
                ++itr;
                while (itr != end()) {
                    result << ", [" << itr->first << ", " << itr->second << "]";
                    ++itr;
                }
            }
            result << "}";
            return result.str();
        }

#include "iterator.h"
#include "const_iterator.h"

    private:

        void rehash() {
            std::vector<std::list<Entry_Type> > old_buckets = the_buckets;

            the_buckets.clear();
            the_buckets.resize(2 * old_buckets.size());
            num_keys = 0;

            for (size_t i = 0; i < old_buckets.size(); i++) {
                typename std::list<Entry_Type>::iterator pos = old_buckets[i].begin();
                while (pos != old_buckets[i].end()) {
                    insert(*pos);
                    ++pos;
                }
            }
        }

        hash<Key_Type> hash_fcn;
        size_t num_keys;
        std::vector<std::list<Entry_Type> > the_buckets;
        static const size_t INITIAL_CAPACITY = 20;
        const double LOAD_THRESHOLD;

    };

} //namespace KW

#endif
