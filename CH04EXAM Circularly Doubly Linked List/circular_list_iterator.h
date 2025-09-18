#ifndef CIRCULAR_LIST_ITERATOR_H_
#define CIRCULAR_LIST_ITERATOR_H_

// Nested class iterator
class iterator {
  // Give the parent class access to this class.
  friend class circular_list<Item_Type>;
  // Data fields
 private:
  /** A reference to the parent circular_list */
  circular_list<Item_Type>* parent;
  /** A pointer to the current DNode */
  typename circular_list<Item_Type>::DNode* current;
  /** Index of the current position */
  size_t index;
  // Member functions
  /** Constructs an iterator that references a specific DNode.
      Note: this constructor is private. Only the circular_list class
      can create one from scratch.
      @param my_parent A reference to the circular_list
      @param position A pointer to the current DNode
  */

  iterator(circular_list<Item_Type>* my_parent, DNode* position, size_t the_index) :
    parent(my_parent), current(position), index(the_index) {}

 public:
  /** Returns a reference to the currently referenced item.
      @return A reference to the currently referenced item
      @throws std::invalid_argument if this iterator is at end
  */
    Item_Type& operator*() const {
      if (current == NULL)
          throw std::invalid_argument
            ("Attempt to dereference end()");
      return current->data;
  }


/** Return a pointer to the currently referenced item.
    Item_Type must be a class or struct. This restriction
    is enforced by the compiler.
    @return A pointer to the currently referenced item
    @throws std::invalid_argument If this iterator
                                  is at end
*/
    Item_Type* operator->() const {
      if (current == NULL)
          throw std::invalid_argument
            ("Attempt to dereference end()");
      return &(current->data);
  }


  /** Advance the iterator forward
      @return a modified version of this iterator that now
      references the next forward position
      @throws std::invalid_argument If this iterator is at end
  */
    iterator& operator++() {
      if (current == NULL)
          throw std::invalid_argument("Attempt to advance past end()");
      current = current->next;
      index++;
        if (index == parent->num_items) {
            current = nullptr;
        }
      return *this;
  }

  /** Move the iterator backward
      @return a modified version of this iterator that
      now references the previous position
      @throws std::invalid_argument If this iterator is at begin
  */
    iterator& operator--() {
      if (current == parent->head)
          throw std::invalid_argument("Attempt to move before begin()");
      if (current == NULL) // Past last element.
          current = parent->head->prev;
      else
          current = current->prev;
      return *this;
  }
  /** Postfix increment operator
      @return A copy of this iterator before being advanced.
  */
    iterator operator++(int) {
      // Make a copy of the current value.
      iterator return_value = *this;
      // Advance self forward.
      ++(*this);
      // Return old value.
      return return_value; /* Return the value prior to increment */
  }
  /** Postfix decrement operator
      @return A copy of this iterator before being retarded
  */
    iterator operator--(int) {
      // Make a copy of the current value.
      iterator return_value = *this;
      // Move self backward.
      --(*this);
      // Return old value.
      return return_value; /* Return the value prior to decrement */
  }
  // Compare for equality
    bool operator==(const iterator& other) {
      return current == other.current && parent == other.parent;
  }

  // Not equal
    bool operator!=(const iterator& other) {
      return !(*this == other);
  }
}; // End iterator

#endif
