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
				
				//! @brief
				const_iterator();

				//! @brief
				const Object & operator* () const; 
				
				//! @brief
				const_iterator & operator++ ();
			
				//! @brief
				const_iterator operador++ (int);

				//! @brief
				const_iterator & operator-- ();

				//! @brief
				const_iterator operator-- (int);

				//! @brief
				bool operator== (const const_iterator & rhs) const;

				//! @brief
				bool operator!= (const const_iterator & rhs) const;
			
				protected:
					Node *current; //!<

					//! @brief
					const_iterator(Node *p) : current(p);

					friend class List<Object>;
			};

			class iterator : public const_iterator{

				public:
					//! @brief
					iterator() : const_iterator(){}
					
					//! @brief
					const Object & operator* () const;
			
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

		//! @brief
		int size() const;

		//! @brief
		bool empty() const;

/*-----------------------------[IV] Modifiers--------------------------------*/

		//! @brief
		void clear();
	
		//! @brief
		T & front();
	
		//! @brief
		const T & front();
	
		//! @brief
		T & back();

		//! @brief
		cont T & back();

		//! @brief
		void push_front(const T &value);

		//! @brief
		void push_back(const T& value);

		//! @brief
		void pop_front();

		//! @brief
		void pop_back();

		//! @brief
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
