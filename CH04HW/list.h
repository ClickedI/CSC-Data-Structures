//copyright 2025

#ifndef LIST_H_
#define LIST_H_

#include <stdexcept>
#include <cstddef>
#include <utility>

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
        list()
        {
            head = nullptr;
            tail = nullptr;
            num_items = 0;
        }

        /** Construct a copy of a list. */
        list(const list<Item_Type>& other)
        {
            //constructs an empty list
            head = nullptr;
            tail = nullptr;
            num_items = 0;
            //iterates over the original list and adds each element to the list
            for (const_iterator it = other.begin(); it != other.end(); ++it)
            {
                push_back(*it);
            }
        }

        /** Construct a list from a sequence */
        template <typename iterator>
        list(iterator begin, iterator end)
        {
            //initializes an empty list
            head = nullptr;
            tail = nullptr;
            num_items = 0;
            //iterates over the list pushing back every item until it adds them all
            for (iterator it = begin; it != end; ++it)
            {
                push_back(*it);
            }
        }

        /** list destructor. */
        ~list()
        {
            //function that checks if head is null. If it isn't it sets a pointer to the current head, assigns the head to the next node, then deletes the original
            while (head != nullptr)
            {
                DNode* temp = head;
                head = head->next;
                delete temp;
            }
            //sets last tail to nullptr and resets num_items
            tail = nullptr;
            num_items = 0;
        }

        /** Swap this list contents with another one */
        void swap(list<Item_Type>& other)
        {
            std::swap(head, other.head);
            std::swap(tail, other.tail);
            std::swap(num_items, other.num_items);
        }

        /** Assign the contents of one list to another. */
        list<Item_Type>& operator=(const list<Item_Type>& other)
        {
            //utilizes the swap function above to swap two lists
            list<Item_Type> temp(other);
            swap(temp);
            return *this;
        }

        /** Insert an object at the beginning of the list.
            @param item - the item to be added
         */

        /*forms a DNode with the head, if head is null, adds item to tail. If not,
        changes the heads next elements previous element (current head) to point to the new head*/
        void push_front(const Item_Type& item)
        {

            head = new DNode(item, nullptr, head);
            if (head->next != nullptr)
            {
                head->next->prev = head;
            }
            if (tail == nullptr)
            {
                tail = head;
            }
            num_items++;
        }

        /** Insert an object at the end of the list.
            @param item - the item to be added 
         */
        void push_back(const Item_Type& item)
        {
            if (tail != nullptr)
            {
                tail->next = new DNode(item, tail, nullptr);
                tail = tail->next;
                num_items++;
            }
            else
            {
                push_front(item);
            }
        }

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
        iterator insert(iterator pos, const Item_Type& item)
        {
            if (pos.current == head) {
                push_front(item);
                return begin();
            }
            if (pos.current == nullptr) {
                push_back(item);
                return iterator(this, tail);
            }
            DNode* new_node = new DNode(item, pos.current->prev, pos.current);
            pos.current->prev->next = new_node;
            pos.current->prev = new_node;
            num_items++;
            return iterator(this, new_node);
        }

        /*<exercise chapter="4" section="7" type="programming" number="1">*/

        /** Get a reference to the first element in the list.
            This can be used on either side of an assignment.
            @return The first element in the list.
            @throws invaid_argument if the list is empty
         */
        Item_Type& front()
        {
            if (head == nullptr)
            {
                throw std::invalid_argument("list is empty");
            }
            return head->data;
        }

        /** Get a constant reference to first element in the list.
            This can only be used on the right side of an assignment.
            @return The first element in the list.
            @throws invaid_argument if the list is empty
         */
        const Item_Type& front() const
        {
            if (head == nullptr)
            {
                throw std::invalid_argument("list is empty");
            }
            return head->data;
        }

        /*<exercise chapter="1" section="7" type="programming" number="2">*/

        /** Get a reference to the last element in the list.
            This can be used on either side of an assignment.
            @return The last element in the list.
            @throws std::invalid_argument if the list is empty
         */
        Item_Type& back()
        {
            if (head == nullptr)
            {
                throw std::invalid_argument("list is empty");
            }
            return tail->data;
        }

        /** Get a constant reference to the last element in the list.
            This can only be used on the right side of an assgnment.
            @return The last element in the list.
            @throws std::invalid_argument if the list is empty
         */
        const Item_Type& back() const
        {
            if (head == nullptr)
            {
                throw std::invalid_argument("list is empty");
            }
            return tail->data;
        }

        /*</exercise>*/

        /** Query the size of the list
            @return The number of objects in the list 
         */
        int size() const
        {
            return num_items;
        }

        /** Indicate if the list is empty
            @return true if the list is empty
         */
        bool empty() const
        {
            return num_items == 0;
        }

        /** Remove the first item from the list
            @throws std::invalid_argument If the list is empty
         */
        void pop_front()
        {
            if (head == nullptr)
                throw std::invalid_argument("list is empty");
            DNode* removed_node = head;
            head = head->next;
            delete removed_node;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            num_items--;
        }

        /** Remove the last item from the list
            @throws std::invalid_argument If the list is empty
         */
        void pop_back()
        {
            if (tail == nullptr)
                throw std::invalid_argument("list is empty");
            DNode* removed_node = tail;
            tail = tail->prev;
            delete removed_node;
            if (tail != nullptr)
            {
                tail->next = nullptr;
            }
            else
            {
                head = nullptr;
            }
            num_items--;
        }

        /** Remove an item referenced by an iterator
            @param pos An iterator referencing the item to
            be removed
            @return An iterator that referenced the item
            following the item being removed
            @throws std::invalid_argument if the list is empty
                    or if pos references end()
         */
        iterator remove(iterator pos)
        {
            if (pos.current == nullptr)
            {
                throw std::invalid_argument("list is empty");
            }
            iterator return_value = pos;
            ++return_value;
            if (pos.current == head)
            {
                pop_front();
                return return_value;
            }
            if (pos.current == tail)
            {
                pop_back();
                return return_value;
            }
            DNode* removed_node = pos.current;
            removed_node->prev->next = removed_node->next;
            removed_node->next->prev = removed_node->prev;
            delete pos.current;
            return return_value;
        }
        /*<exercise chapter="4" section="7" type="programming" number="4>*/

        /** Remove all occurences of a value from the list
            @param item The value to be removed
         */
        void remove(const Item_Type& item)
        {
            if (head == nullptr)
            {
                throw std::invalid_argument("list is empty");
            }

            iterator iter = begin();
            while (iter!= end())
            {
                if (*iter == item)
                {
                    iter = remove(iter);
                }
                else
                {
                    ++iter;
                }
            }
        }
        /*</exercise>*/

        /*<exercise chapter="4" section="3" type="programming" number="3">*/

        /** Return an iterator to the beginning of the list
            @return an itertor to the beginning of the list
         */
        iterator begin()
        {
            return iterator(this, head);
        }

        /** Return a const_iterator to the beginning of
            the list
            @return a const_iterator to the beginning of
            the list
         */
        const_iterator begin() const
        {
            return const_iterator(this, head);
        }
        /*</exercise>*/

        /** Return an iterator to the end of the list
            @return an iterator to the end of the list
         */
        iterator end()
        {
            return iterator(this, nullptr);
        }

        /** Return a const_iterator to the end of the list
            @return a const_iterator to the end of the list
         */
        const_iterator end() const
        {
            return const_iterator(this, nullptr);
        }
        /**
         * if found the target, return the iterator to the current position.
         * return NULL if the target is not in the list.
         * @param target
         * @return iterator points to the found target; NULL otherwise.
         */
        
        iterator find(const Item_Type& target)
        {
            iterator iter = begin();
            while (iter != end())
            {
                if (*iter == target)
                {
                    return iter;
                }
                ++iter;
            }
            return end();
        }
    }; // End list


} // End namespace KW

#endif
