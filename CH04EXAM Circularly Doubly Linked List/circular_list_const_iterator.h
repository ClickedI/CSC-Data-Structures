#ifndef CIRCULAR_LIST_CONST_ITERATOR_H_
#define CIRCULAR_LIST_CONST_ITERATOR_H_

// Nested class const_iterator
class const_iterator {
  // Give the parent class access to this class.
  friend class circular_list<Item_Type>;
  // Data fields
 private:
  /** A reference to the parent circular_list */
  const circular_list<Item_Type>* parent;
  /** A pointer to the current DNode */
  typename circular_list<Item_Type>::DNode* current;
  /** Index of the current position */
  size_t index;
  // Member functions
  /** Constructs an const_iterator that references a specific DNode.
      Note: this constructor is private. Only the circular_list class
      can create one from scratch.
      @param my_parent A reference to the circular_list
      @param position A pointer to the current DNode
  */

  const_iterator(const circular_list<Item_Type>* my_parent, DNode* position, size_t the_index) :
    parent(my_parent), current(position), index(the_index) {}

 public:
  /** Returns a reference to the currently referenced item.
      @return A reference to the currently referenced item
      @throws std::invalid_argument if this const_iterator is at end
  */
   const Item_Type& operator*() const {
      if (current == NULL)
          throw std::invalid_argument
            ("Attempt to dereference end()");
      return current->data;
  }


/** Return a pointer to the currently referenced item.
    Item_Type must be a class or struct. This restriction
    is enforced by the compiler.
    @return A pointer to the currently referenced item
    @throws std::invalid_argument If this const_iterator
                                  is at end
*/
    const Item_Type* operator->() const {
      if (current == NULL)
          throw std::invalid_argument
            ("Attempt to dereference end()");
      return &(current->data);
  }


  /** Advance the const_iterator forward
      @return a modified version of this const_iterator that now
      references the next forward position
      @throws std::invalid_argument If this const_iterator is at end
  */
    const_iterator& operator++() {
       if (current == NULL)
           throw std::invalid_argument("Attempt to advance past end()");
       current = current->next;
       index++;
       if (index == parent->num_items) {
           current = nullptr;
       }
       return *this;
   }

  /** Move the const_iterator backward
      @return a modified version of this const_iterator that
      now references the previous position
      @throws std::invalid_argument If this const_iterator is at begin
  */
    const_iterator& operator--() {
    if (index == 0) {
        throw std::invalid_argument("Attempt to move before begin() iterator");
    }
    if (current == nullptr) { // If we are at end(), move to the last element
        current = parent->head->prev;
    } else {
        current = current->prev;
    }
    index--;
    return *this;
  }
  /** Postfix increment operator
      @return A copy of this const_iterator before being advanced.
  */
    const_iterator operator++(int) {
       const_iterator temp = *this;
       ++(*this);
       return temp;
   }
  /** Postfix decrement operator
      @return A copy of this const_iterator before being retarded
  */
    const_iterator operator--(int) {
      // Make a copy of the current value.
      iterator return_value = *this;
      // Move self backward.
      --(*this);
      // Return old value.
      return return_value; /* Return the value prior to decrement */
  }
  // Compare for equality
    bool operator==(const const_iterator& other) {
      return current == other.current && parent == other.parent;
  }

  // Not equal
    bool operator!=(const const_iterator& other) {
      return !(*this == other);
  }
}; // End const_iterator

#endif
