#ifndef _LIST_HPP_
#define _LIST_HPP_

namespace ls{

	template< typename T >
	class List{
		
		private:
			struct Node{

				T data;		//!< Data field.
				Node *next; //!< Pointer to the next node.
				Node *prev; //!< Pointer to the previous node.
				
				//! @brief 
				Node(const T & d = T(), Node *p = nullptr, Node *n = nullptr)
					: data(d), next(n), prev(p) {}
			};

			Node *m_head; 	//!< Pointer to the list's head.
			Node *m_tail;	//!< Pointer to the list's tail.
			size_t m_size;	//!< List's size. 
	

		public:
			class const_iterator {
				
				//! @brief const_iterator constructor.
				const_iterator(){};

				//! @brief Overloads the pointer operator '*'
				//! @details Current node data.  
				const T & operator* () const; 
				
				//! @brief Overloads the operator '++' (no parameter usage).
				const_iterator & operator++ ();
			
				//! @brief Overloads the operator '++' (parameter usage).
				const_iterator operador++ (int);

				//! @brief Overloads the operator '--' (no parameter usage).
				const_iterator & operator-- ();

				//! @brief Overloads the operator '--' (parameter usage).
				const_iterator operator-- (int);

				//! @brief Overloads the operator '=='.
				bool operator== (const const_iterator & rhs) const;

				//! @brief Overloads the operator '!='.
				bool operator!= (const const_iterator & rhs) const;
			
				protected:
					Node *m_node; //!<

					//! @brief
					const_iterator(Node *p) : current(p);

					friend class List<T>; //!< Makes the class a 'List''s friend to use it's members.

			};

			class iterator : public const_iterator{

				public:
					//! @brief iterator's constructor.
					iterator() : const_iterator(){}
					
					//! @brief Overloads 
					const T & operator* () const;
			
					//! @brief
					Object & operator* ();
					
					//! @brief
					iterator & operator++ ();

					//! @brief
					iterator operator++ (int);

					//! @brief
					iterator & operator-- ();

					//! @brief
					iterator operator-- (int);

				protected:
					//! @brief
					iterator(Node *p) : const_iterator(p);

					friend class List<Object>;

			};

/*--------------------------[I] Special Members------------------------------*/
	
		//! @brief
		List();
		
		//! @brief
		~List();

		//! @brief
		List & operator= (const List &);


/*-----------------------------[II] Iterators--------------------------------*/
		
		//! @brief
		iterator begin();

		//! @brief
		const_iterator cbegin() const;
	
		//! @brief
		iterator end();

		//! @brief
		const_iterator cend() const;

/*-------------------------[III] Storage Capacity----------------------------*/

		//! @return The number of elements in the container. 
		int size() const;

		//! @brief True if the container contains no elements, and false otherwise.
		bool empty() const;

/*-----------------------------[IV] Modifiers--------------------------------*/

		//! @brief Remove (either logically or physically) all elements from the container.
		void clear();
	
		//! @return The element at the beginning of the list.
		T & front();
	
		//! @returns The const element at the beginning of the list.
		const T & front();
	
		//! @return The element at the end of the list
		T & back();

		//! @return The object at the end of the list.
		const T & back();

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

		//! @brief
		template< class InItr >
		void assign(InItr first, InItr last);
		
		//! @brief
		void assign(std::initializer_list<T> ilist);

		//! @brief
		iterator insert(const_iterator itr, const T& value);

		//! @brief
		iterator insert(const_iterator pos, std::initializer_list<T> ilist);

		//! @brief
		iterator erase(const_iterator itr);

		//! @brief
		iterator erase(const_iterator first, const_iterator last);

		//! @brief
		const_iterator find(const T& value) const;

	};
}
