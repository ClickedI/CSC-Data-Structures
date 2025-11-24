//copyright 2025

/** The const_iterator class */
    class const_iterator {
      /*<exercise chapter="9" type="programming-project" number="5">*/
    public:

      /** Convert from an iterator to a const_iterator */
      const_iterator(const iterator& other)
              : the_parent(other.the_parent), the_index(other.the_index) {}

      /** De-reference an const_iterator */
      Entry_Type& operator*() const {
        if (*this == the_parent->end()) {
          throw std::invalid_argument("Attempt to de-reference end()");
        }
        return *(the_parent->the_table[the_index]);
      }

      Entry_Type* operator->() const {
        if (*this == the_parent->end()) {
          throw std::invalid_argument("Attempt to de-reference end()");
        }
        return the_parent->the_table[the_index];
      }


      /** Prefix increment operator */
      const_iterator& operator++() {
        ++the_index;
        advance();
        return *this;
      }

      /** Postfix increment operator */
      const_iterator operator++(int) {
        const_iterator temp(*this);
        ++(*this);
        return temp;
      }

      /** Equality operator */
      bool operator==(const const_iterator& other) const {
        return the_parent == other.the_parent && the_index == other.the_index;
      }
      /** Inequality operator */
      bool operator!=(const const_iterator& other) const {
        return !operator==(other);
      }

    private:

      // The Map is our friend
      friend class hash_map<Key_Type, Value_Type>;

      /** Advance the iterator to the next position */
      void advance() {
        while (the_index < the_parent->the_table.size()
               && (the_parent->the_table[the_index] == nullptr
                   || the_parent->the_table[the_index] == DELETED)) {
          the_index++;
                   }
      }

      /** Construct an const_iterator starting at a given position
	  in the hash table */
      const_iterator(const hash_map<Key_Type, Value_Type>* parent, size_t index) :
      the_parent(parent), the_index(index) {}

      /** Pointer to the map containing the iterator */
      const hash_map<Key_Type, Value_Type>* const the_parent;

      /** The index of the current position */
      size_t the_index;


    }; // End const_iterator
