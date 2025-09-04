#ifndef LIST_CONST_ITERATOR_H_
#define LIST_CONST_ITERATOR_H_

// Nested class const_iterator
class const_iterator {
  // Give the parent class access to this class
  friend class list<Item_Type>;
  // Data fields
 private:
  /** A pointer to the parent list */
  const list<Item_Type>* parent;
  /** A pointer to the current node */
  typename list<Item_Type>::DNode* current;
  
  // Methods
  /** Construct a const_iterator that references a specific node
      Note: this constructor is private. Only the list class
      can create one from scratch.
      @param my_parent A reference to the list
      @param position A pointer to the current DNode
  */
  const_iterator(const list<Item_Type>* my_parent, DNode* position) :
    parent(my_parent), current(position) {}
 public:
  /** Make a copy of an iterator. Note this is public, others
      may make a copy.
      @param other The iterator that is being copied
  */
  const_iterator(const const_iterator& other) :
    parent(other.parent), current(other.current) {}
  
/** Return a reference to the currently referenced item.
    @return A reference to the currently referenced item
    @throws std::invalid_argument If this const_iterator
                                  is at end
*/
const Item_Type& operator*() const;

/** Return a pointer to the currently referenced item.
    Item_Type must be a class or struct. This restriction
    is enforced by the compiler.
    @return A pointer to the currently referenced item
    @throws std::invalid_argument If this const_iterator
                                  is at end
*/
const Item_Type* operator->() const;
  
  /** Advance the const_iterator forward
      @return a modified version of this const_iterator that now 
      references the next forward position
      @throws std::invalid_argument If this const_iterator is at end
  */
  const_iterator& operator++();
  
  /** Move the const_iterator backward
      @return a modified version of this const_iterator that
      now references the previous position
      @throws std::invalid_argument If this const_iterator is at begin
  */
  const_iterator& operator--();
  
  /** Postfix increment operator
      @return A copy of this const_iterator before being advanced.
  */
  const_iterator operator++(int);
  /** Postfix decrement operator
      @return A copy of this const_iterator before being retarded
  */
  const_iterator operator--(int);
  // Compare for equality
  bool operator==(const const_iterator& other);
  // Not equal
  bool operator!=(const const_iterator& other);
}; // End const_iterator

#endif
