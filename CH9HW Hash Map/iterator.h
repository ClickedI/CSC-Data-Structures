//copyright 2025
class iterator {
public:

    Entry_Type& operator*() const {
        if (*this == the_parent->end()) {
            throw std::invalid_argument("Attempt to de-reference end()");
        }
        return *the_pos;
    }

    Entry_Type* operator->() const {
        if (*this == the_parent->end()) {
            throw std::invalid_argument("Attempt to de-reference end()");
        }
        return &(*the_pos);
    }

    iterator& operator++() {
        ++the_pos;
        advance();
        return *this;
    }

    iterator operator++(int) {
        iterator temp(*this);
        ++(*this);
        return temp;
    }

    bool operator==(const iterator& other) const {
        return the_index == other.the_index && the_pos == other.the_pos;
    }

    bool operator!=(const iterator& other) const {
        return !operator==(other);
    }

private:

    friend class hash_map<Key_Type, Value_Type>;
    friend class const_iterator;

    void advance() {
        if (the_pos != the_parent->the_buckets[the_index].end()) {
            return;
        } else {
            while (the_index < (the_parent->the_buckets.size() - 1)) {
                the_index++;
                the_pos = the_parent->the_buckets[the_index].begin();
                if (the_pos != the_parent->the_buckets[the_index].end())
                    return;
            }
            the_pos = the_parent->the_buckets[the_index].end();
            return;
        }
    }

    iterator(hash_map<Key_Type, Value_Type>* parent,
             size_t index,
             typename std::list<Entry_Type>::iterator pos):
            the_parent(parent),
            the_index(index),
            the_pos(pos) {}

    hash_map<Key_Type, Value_Type>* the_parent;
    size_t the_index;
    typename std::list<Entry_Type>::iterator the_pos;

};
