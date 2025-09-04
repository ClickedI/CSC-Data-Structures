#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>
#include <cstddef>

/** Class list implements a subset of the standard
    list class using a double-linked list.
    @author Koffman and Wolfgang
 */
namespace KW {

    template<typename Item_Type>
    class list {
    private:
        // Insert definition of nested class DNode here.
#include "DNode.h"
    public:
        // Insert definition of nested class iterator here.
#include "list_iterator.h"
        // Give list access to internal values in iterator.
        friend class iterator;
        // Insert definition of nested class const_iterator here.
#include "list_const_iterator.h"
        // Give list access to internal values in const_iterator.
        friend class const_iterator;

        // Data fields
        /** A reference to the head of the list */
        DNode* head;
        /** A reference to the end of the list */
        DNode* tail;
        /** The size of the list */
        int num_items;
        // Functions
    public:

        /** Construct an empty list. */
        list();

        /** Construct a copy of a list. */
        list(const list<Item_Type>& other);

        /** Construct a list from a sequence */
        template <typename iterator>
        list(iterator begin, iterator end);

        /** list destructor. */
        ~list();

        /** Swap this list contents with another one */
        void swap(list<Item_Type>& other);

        /** Assign the contents of one list to another. */
        list<Item_Type>& operator=(const list<Item_Type>& other);

        /** Insert an object at the beginning of the list.
            @param item - the item to be added 
         */
        void push_front(const Item_Type& item);

        /** Insert an object at the end of the list.
            @param item - the item to be added 
         */
        void push_back(const Item_Type& item);

        /** Insert an object at a position in the list
            indicated by an iterator.  The new item is
            inserted before the position indicated by
            the iterator.
            @param pos The iterator that references the 
                       position where the item is to be
                       inserted.
            @param item The item to be inserted
            @return An iterator that references the inserted
                    item.
         */
        iterator insert(iterator pos, const Item_Type& item);
		
        /*<exercise chapter="4" section="7" type="programming" number="1">*/

        /** Get a reference to the first element in the list.
            This can be used on either side of an assignment.
            @return The first element in the list.
            @throws invaid_argument if the list is empty
         */
        Item_Type& front();

        /** Get a constant reference to first element in the list.
            This can only be used on the right side of an assignment.
            @return The first element in the list.
            @throws invaid_argument if the list is empty
         */
        const Item_Type& front() const;

        /*<exercise chapter="1" section="7" type="programming" number="2">*/

        /** Get a reference to the last element in the list.
            This can be used on either side of an assignment.
            @return The last element in the list.
            @throws std::invalid_argument if the list is empty
         */
        Item_Type& back();

        /** Get a constant reference to the last element in the list.
            This can only be used on the right side of an assgnment.
            @return The last element in the list.
            @throws std::invalid_argument if the list is empty
         */
        const Item_Type& back() const;
        /*</exercise>*/

        /** Query the size of the list
            @return The number of objects in the list 
         */
        int size() const;

        /** Indicate if the list is empty
            @return true if the list is empty
         */
        bool empty() const;

        /** Remove the first item from the list
            @throws std::invalid_argument If the list is empty
         */
        void pop_front();

        /** Remove the last item from the list
            @throws std::invalid_argument If the list is empty
         */
        void pop_back();

        /** Remove an item referenced by an iterator
            @param pos An iterator referencing the item to
            be removed
            @return An iterator that referenced the item
            following the item being removed
            @throws std::invalid_argument if the list is empty
                    or if pos references end()
         */
        iterator remove(iterator pos);
        /*<exercise chapter="4" section="7" type="programming" number="4>*/

        /** Remove all occurences of a value from the list
            @param item The value to be removed
         */
        void remove(const Item_Type& item);
        /*</exercise>*/

        /*<exercise chapter="4" section="3" type="programming" number="3">*/

        /** Return an iterator to the beginning of the list
            @return an itertor to the beginning of the list
         */
        iterator begin();

        /** Return a const_iterator to the beginning of
            the list
            @return a const_iterator to the beginning of
            the list
         */
        const_iterator begin();
        /*</exercise>*/

        /** Return an iterator to the end of the list
            @return an iterator to the end of the list
         */
        iterator end();

        /** Return a const_iterator to the end of the list
            @return a const_iterator to the end of the list
         */
        const_iterator end() const;
        /**
         * if found the target, return the iterator to the current position.
         * return NULL if the target is not in the list.
         * @param target
         * @return iterator points to the found target; NULL otherwise.
         */
        
        iterator find(const Item_Type& target);
    }; // End list

    
} // End namespace KW

#endif
