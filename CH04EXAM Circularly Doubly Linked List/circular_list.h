/*<programming_project chapter="4" number="6">*/
#ifndef CIRCULAR_LIST_H_
#define CIRCULAR_LIST_H_

#include <stdexcept>
#include <cstddef>
#include <iostream>
/** Class circular_list implements a subset of the standard
    list class using a double-linked circular_list.
    @author Koffman and Wolfgang
*/
namespace KW
{
	template<typename Item_Type>
	  class circular_list
	{
	private:
		// Insert definition of nested class DNode here.
#include "DNode.h"
	public:
		// Insert definition of nested class iterator here.
#include "circular_list_iterator.h"
		// Give circular_list access to internal values in iterator.
		friend class iterator;
		// Insert definition of nested class const_iterator here.
#include "circular_list_const_iterator.h"
		// Give circular_list access to internal values in const_iterator.
		friend class const_iterator;

		// Data fields
		/** A reference to the head of the circular_list */
		DNode* head;
		/** The size of the circular_list */
		int num_items;
		// Functions
	public:
		/** Construct an empty circular_list. */
		circular_list(): head(nullptr), num_items(0) {}

		/** Construct a copy of a circular_list. */
		circular_list(const circular_list<Item_Type>& other)
		{
			//constructs an empty list
			head = nullptr;
			num_items = 0;
			//iterates over the original list and adds each element to the list
			for (const_iterator it = other.begin(); it != other.end(); ++it)
			{
				push_back(*it);
			}
		}


		/** Assign the contents of one circular_list to another. */
		circular_list<Item_Type>& operator=(const circular_list<Item_Type>& other)
		{
			if (this == &other) {
				return *this;
			}

			if (head != nullptr) {
				DNode* last = head->prev;
				last->next = nullptr;

				DNode* current = head;
				while (current != nullptr) {
					DNode* next_node = current->next;
					delete current;
					current = next_node;
					num_items--;
				}

				head = nullptr;
			}

			if (other.head == nullptr) {
				return *this;
			}

			DNode* other_current = other.head;
			do {
				push_back(other_current->data);
				other_current = other_current->next;
			} while (other_current != other.head);

			return *this;
		}

		/** Destroy a circular_list. */
		~circular_list()
		{
			if (head == nullptr) {
				return;
			}

			DNode* last = head->prev;
			last->next = nullptr;

			DNode* current = head;
			while (current != nullptr) {
				DNode* next_node = current->next;
				delete current;
				current = next_node;
				num_items--;
			}

			head = nullptr;
		}

		/** Swap this circular_list contents with another one */
		void swap(circular_list<Item_Type>& other) {
			std::swap(head, other.head);
			std::swap(num_items, other.num_items);
		}

		/** Insert an object at the beginning of the circular_list.
			@param item - the item to be added
		*/
		void push_front(const Item_Type& item)
		{
			DNode* new_node  = new DNode(item);
			if (head == nullptr)
			{
				head = new_node;
				new_node->next = new_node;
				new_node->prev = new_node;
				num_items++;
			}
			else
			{
				DNode* last = head->prev;
				new_node -> next = head;
				new_node ->prev = last;
				head->prev = new_node;
				last->next = new_node;
				head = new_node;
				num_items++;
			}
		}

		/** Insert an object at the end of the circular_list.
			@param item - the item to be added
		*/
		void push_back(const Item_Type& item)
		{
			if (head == nullptr)
			{
				push_front(item);
			}
			else
			{
				DNode* new_node  = new DNode(item);
				DNode* last = head->prev;
				new_node->next = head;
				new_node->prev = last;
				head->prev = new_node;
				last->next = new_node;
				num_items++;


			}
		}

		/** Insert an object at a position in the circular_list
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
			if (pos.current == nullptr)
			{
				push_back(item);
				return iterator(this, head->prev, num_items - 1);
			}
			if (pos.current == head) {
				push_front(item);
				return iterator(this, head, 0);
			}
			DNode* new_node = new DNode(item);
			insert(new_node, pos.current);

			return iterator(this, new_node, pos.index);
		}

		/**
			Helper function.  Use this function to insert the node
		Insert a DNode into the circular_list just before the the node pointed to by pos */
		void insert(DNode* new_node, DNode* pos)
		{
			DNode* prev = pos->prev;

			new_node->next = pos;
			new_node->prev = prev;
			prev->next = new_node;
			pos->prev = new_node;
			num_items++;
		}

		/** Get a reference to the first element in the circular_list.
		This can be used on either side of an assignment.
		@return The first element in the circular_list.
		@throws invaid_argument if the circular_list is empty
		*/
		Item_Type& front()
		{
			if (head == nullptr)
			{
				throw std::invalid_argument("list is empty");
			}
			return head->data;
		}

		/** Get a constant reference to first element in the circular_list.
		This can only be used on the right side of an assignment.
		@return The first element in the circular_list.
		@throws invaid_argument if the circular_list is empty
		*/
		const Item_Type& front() const
		{
			if (head == nullptr)
			{
				throw std::invalid_argument("list is empty");
			}
			return head->data;
		}


		/** Get a reference to the last element in the circular_list.
		This can be used on either side of an assignment.
		@return The last element in the circular_list.
		@throws std::invalid_argument if the circular_list is empty
		*/
		Item_Type& back()
		{
			if (head == nullptr)
			{
				throw std::invalid_argument("list is empty");
			}
			return head->prev->data;
		}

		/** Get a constant reference to the last element in the circular_list.
		This can only be used on the right side of an assgnment.
		@return The last element in the circular_list.
		@throws std::invalid_argument if the circular_list is empty
		*/
		const Item_Type& back() const
		{
			if (head == nullptr)
			{
				throw std::invalid_argument("list is empty");
			}
			return head->prev->data;
		}

		/** Query the size of the circular_list
		@return The number of objects in the circular_list
		*/
		int size() const
		{
			return num_items;
		}

		/** Indicate if the circular_list is empty
		@return true if the circular_list is empty
		*/
		bool empty() const
		{
			return num_items == 0;
		}

		/** Remove the first item from the circular_list
		@throws std::invalid_argument If the circular_list is empty
		*/
		void pop_front()
		{
			if (head == nullptr)
				throw std::invalid_argument("list is empty");
			if (num_items == 1)
			{
				DNode* removed_node = head;
				head = nullptr;
				delete removed_node;
			}
			else
			{
				DNode* removed_node = head;
				DNode* last = head->prev;
				DNode* new_head = head->next;

				last->next = new_head;
				new_head->prev = last;

				head = new_head;

				delete removed_node;

			}
			num_items--;
		}

		/** Remove the last item from the circular_list
		@throws std::invalid_argument If the circular_list is empty
		*/
		void pop_back()
		{
			if (head == nullptr)
				throw std::invalid_argument("list is empty");

			if (num_items == 1)
			{
				DNode* removed_node = head;
				head = nullptr;
				delete removed_node;
			}
			else
			{
				DNode* last = head->prev;
				DNode* new_last = last->prev;

				new_last->next = head;
				head->prev = new_last;

				delete last;
			}
			num_items--;
		}


		/** Remove an item referenced by an iterator
		@param pos An iterator referencing the item to
		be removed
		@return An iterator that referenced the item
		following the item being removed
		@throws std::invalid_argument if the circular_list is empty
				or if pos references end()
		*/
		iterator erase(iterator pos)
		{
			if (head == nullptr)
				throw std::invalid_argument("list is empty");

			if (pos.current == nullptr)
				throw std::invalid_argument("cannot reference past end of list");

			if (num_items == 1)
			{
				delete pos.current;
				num_items--;
				head = nullptr;
				return iterator(this, nullptr, 0);
			}

			DNode* removed_node = pos.current;
			DNode* next = pos.current->next;
			DNode* last = pos.current->prev;

			if (removed_node == head) {
				head = next;
			}

			// Reconnect the circular links
			next->prev = last;
			last->next = next;

			delete removed_node;
			num_items--;

			return iterator(this, next, pos.index);
		}

		/** Return an iterator to the beginning of the circular_list
		@return an itertor to the beginning of the circular_list
		*/
		iterator begin()
		{
			return iterator(this, head, 0);
		}

		/** Return a const_iterator to the beginning of
		the circular_list
		@return a const_iterator to the beginning of
		the circular_list
		*/
		const_iterator begin() const
		{
			return const_iterator(this, head,0);
		}

		/** Return an iterator to the end of the circular_list
		@return an iterator to the end of the circular_list
		*/
		iterator end()
		{
			return iterator(this, nullptr, num_items);
		}

		/** Return a const_iterator to the end of the circular_list
		@return a const_iterator to the end of the circular_list
		*/
		const_iterator end() const
		{
			return const_iterator(this, nullptr, num_items);
		}
	};
		// The overload the standard C++ swap function is two swap two linked list
		template <typename Item_Type>
		  void swap(circular_list<Item_Type>& x, circular_list<Item_Type>& y)
		{ x.swap(y); }
}
// End namespace KW

#endif
/*</programming_project>*/

