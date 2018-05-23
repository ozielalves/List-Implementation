/**
 * @file list.hpp
 * @version 1.0
 * @date May, 19.
 * @author Daniel Guerra and Oziel Alves
 * @title Class ls::list
 * @brief List class's declaration
 */

#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <iostream> // cin,cout
#include <exception> // out_of_range throw
#include <algorithm> //copy
#include <iterator> // ostream_iterator
#include <cstdlib> // size_t
#include <initializer_list> // initializer_list
#include <cassert> // assert
#include <memory> // ==,!= ..

namespace ls{

	template< typename T >
	class List{
		
		private:
			struct Node{

				T data;	//!< Data field.
				Node *prev;	//!< Pointer to the previous node.
				Node *next;	//!< Pointer to the next node.
				
				//! @brief 
				Node(const T & d = T(), Node *p = nullptr, Node *n = nullptr)
					: data(d), prev(p), next(n) {/*empty*/}
			};

			Node *m_head; 	//!< Pointer to the list's head.
			Node *m_tail;	//!< Pointer to the list's tail.
			size_t m_size;	//!< List's size. 
	

		public:

/*------------------------------Auxiliar Classes-----------------------------*/
			class const_iterator{

				public:
					//! @brief const_iterator constructor.
					const_iterator();

					//! @brief Overloads the pointer operator '*'
					//! @details Current node data.  
					const T & operator* () const;
							
					//! @brief Overloads the operator '++' (no parameter usage). ++it.
					const_iterator & operator++ (void);
						
					//! @brief Overloads the operator '++' (parameter usage). it++.
					const_iterator operator++ (int);

					//! @brief Overloads the operator '--' (no parameter usage). --it.
					const_iterator & operator-- (void);

					//! @brief Overloads the operator '--' (parameter usage). it--.
					const_iterator operator-- (int);

					//! @brief Overloads the operator '+' (parameter usage).
					const_iterator operator+ (int);
				
					//! @brief Overloads the operator '-' (parameter usage).
					const_iterator operator- (int);

					//! @brief Overloads the operator '=='.
					bool operator== (const const_iterator & rhs) const;

					//! @brief Overloads the operator '!='.
					bool operator!= (const const_iterator & rhs) const;
					
				protected:

					Node *m_node; //!< Current node when using iterators.

					//! @brief Current node's constructor for const_iterators.
					const_iterator(Node *p) : m_node(p) {}

					friend class List<T>; //!< Makes the class a 'List''s friend to use it's members.
			};
			
			class iterator : public const_iterator{

				public:
					//! @brief iterator's constructor.
					iterator() : const_iterator(){};
								
					//! @brief Overloads the operator '*'. (const)
					const T & operator* () const;
						
					//! @brief Overloads the operator '*'.
					T &operator* ();

					//! @brief Overloads the operator '++' (no parameter usage). ++it.
					iterator & operator++ (void);
					
					//! @brief Overloads the operator '++' (parameter usage). it++.
					iterator operator++ (int);

					//! @brief Overloads the operator '--' (no parameter usage). --it.
					iterator & operator-- (void);

					//! @brief Overloads the operator '--' (parameter usage). it--.
					iterator operator-- (int);

					//! @brief Overloads the operator '+' (parameter usage).
					iterator operator+ (int);

					//! @brief Overloads the operator '-' (parameter usage).
					iterator operator- (int);

				protected:

					//! @brief Current node's constructor for iterator.
					iterator(Node *p) : const_iterator(p) {}

					friend class List<T>; //!< Also make this class a ls:List's friend.
			};
/*--------------------------[I] Special Members------------------------------*/
	
			//! @brief List's normal constructor.
			List();
		
			//! @brief List's normal destructor.
			~List();

			//! @brief List's operator '='.
			List & operator= (const List &);

			//! @brief List's copy constructor.
			List( const List &);


/*-----------------------------[II] Iterators--------------------------------*/
		
			//! @return The list's begin.
			iterator begin();

			//! @brief The list's begin (const).
			const_iterator cbegin() const;
	
			//! @brief The list's end.
			iterator end();

			//! @brief The list's end (const).
			const_iterator cend() const;

/*-------------------------[III] Storage Capacity----------------------------*/

			//! @return The number of elements in the container. 
			size_t size() const;

			//! @brief True if the container contains no elements, and false otherwise.
			bool empty() const;

/*-----------------------------[IV] Modifiers--------------------------------*/

			//! @brief Remove (either logically or physically) all elements from the container.
			void clear();

			//! @return The element at the beginning of the list.
			T& front();
		
			//! @returns The const element at the beginning of the list.
//			const T& front() const;

			//! @return The element at the end of the list.
			T& back();

			//! @return The const element at the end of the list.
//			const T& back() const;

			//! @brief Adds an 'value' to the front of the list.
			void push_front(const T &value);

			//! @brief Adds an 'value' to the end of the list.
			void push_back(const T& value);

			//! @brief Removes The element at the front of the list. 
			void pop_front();

			//! @brief Removes The element at the end of the list.
			void pop_back();

			//! @brief Replaces the content of the list with copies of value x.
			void assign(const T& value);

/*----------------------[IV-a] Modifiers with Iterators----------------------*/

			//! @brief Replaces the content of list with copies from a range [first, last).
			template< class InItr >
			void assign(InItr first, InItr last);
		
			//! @brief Assigns an value from an initializer list to the list.
			void assign(std::initializer_list<T> ilist);

			//! @brief Inserts an value on the specified location.
			iterator insert(const_iterator itr, const T& value);

			//! @brief Inserts an entire initializer list starting on pos.
			iterator insert(const_iterator pos, std::initializer_list<T> ilist);

			//! @brief Erase node existing on specified location.
			iterator erase(const_iterator itr);

			//! @brief Erase nodes existing between range.
			iterator erase(const_iterator first, const_iterator last);

			//! @brief Searchs for the key value on list.
			const_iterator find(const T& value) const;

	};
	
}

#include "list.inl"

#endif
