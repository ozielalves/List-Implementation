/**
 * @file list.inl
 * @version 1.0
 * @date May, 19.
 * @author Daniel Guerra and Oziel Alves
 * @title Class ls::list inl
 * @brief List class's inl
 */

#include "../include/list.hpp"

namespace ls
{

/*--------------------------[I] Special Members------------------------------*/
	template< typename T >
	List<T>::List(){

		m_head = new Node; //!
		m_tail = new Node; //!
		m_size = 0;

		m_head->next = m_tail; //!
		m_tail->prev = m_head; //!

		m_head->prev = nullptr; //!
		m_tail->next = nullptr; //!
	}

	template< typename T >
	List<T>::~List(){

		clear();
		delete m_head;
		delete m_tail;
	}
/*
	template< typename T >
	typename List<T> & List<T>::operator= ( const List & rhs ){
		m_head = rhs.m_head;
		m_size = rhs.m_size;
		m_tail = rhs.m_tail;

		return *this;
	}

	template< typename T >
	List<T>::List( const List & rhs ){
		m_head = rhs.m_head;
		m_size = rhs.m_size;
		m_tail = rhs.m_tail;
	}
*/
/*-----------------------------[II] Iterators--------------------------------*/
	template< typename T >
	typename List<T>::iterator List<T>::begin(){
		return typename List<T>::iterator(m_head->next);
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::cbegin() const{
		return typename List<T>::const_iterator(m_head->next);
	}

	template< typename T >
	typename List<T>::iterator List<T>::end(){
		return typename List<T>::iterator(m_tail);
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::cend() const{
		return typename List<T>::const_iterator(m_tail);
	}

/*-------------------------[III] Storage Capacity----------------------------*/
	template< typename T >
	size_t List<T>::size() const{

		return m_size;
	}

	template< typename T >
	bool List<T>::empty() const{

		return m_size == 0;
	}

/*-----------------------------[IV] Modifiers--------------------------------*/
	template< typename T >
	void List<T>::clear(){

		Node *temp = m_head->next; //!<
		while(temp != m_tail){
			if( temp->prev != m_head ){
				delete temp->prev;
			}
			temp = temp->next;
		}

		m_size = 0; 
		m_head->next = m_tail;
		m_tail->prev = m_head;
	}

	template< typename T >
	const T& List<T>::front() const{

		return m_head->next->data;
	}

	template< typename T >
	const T& List<T>::back() const{

		return m_tail->prev->data;
	}

	template< typename T >
	void List<T>::push_front(const T & x){

		Node *nn = new Node(x, m_head, m_head->next); //!<
		m_head->next->prev = nn;
		m_head->next = nn;
		m_size++;
		//delete nn;
	}

	template< typename T >
	void List<T>::pop_front(){

		if(m_size > 0){ //! If the list is not empty.
			
			Node *pp = m_head->next;
			pp->next->prev = m_head; //! putting the head value on the poped element place.
			m_head->next = pp->next; //! and then follows like above to the others.
			m_size--;
			delete pp;
		}
	}

	template< typename T >
	void List<T>::push_back(const T &x){ //! Inserts a prev Node.

		Node *nn = new Node(x, m_tail->prev, m_tail);
		m_tail->prev->next = nn;
		m_tail->prev = nn;
		m_size++;
	}

	template< typename T >
	void List<T>::pop_back(){

		if(m_size > 0){ //! If the list is not empty.
			
			Node *pp = m_tail->prev;
			pp->prev->next = m_tail;
			m_tail->prev = pp->prev;
			m_size--;
			delete pp;
		}
	}

	template< typename T >
	void List<T>::assign(const T &value){
		
		Node *pp = m_head;
		while(pp->next != m_tail){
			pp = pp->next;
			pp->data = value; //! Assignment
		}
	}

/*----------------------[IV-a] Modifiers with Iterators----------------------*/
//	template< typename T >
//	void List<T>::assign(std::initializer_list<T> ilist){
//		clear();
//		for(auto i = ilist.begin(); i != ilist.end(); i++){
//			push_back(*i);
//		}
//	}

	// void List<T>::assign( InItr first, InItr last ){
	// 	/*to complete*/
	// }

	// typename List<T>::iterator List<T>::insert( const_iterator itr,
	// 														const T & value ){
	// 	/*to complete*/
	// }

	// typename List<T>::iterator List<T>::insert( const_iterator pos,
	// 														std::initializer_list<T> ilist ){
	// 	/*to complete*/
	// }

	// typename List<T>:iterator List<T>::erase( const_iterator itr ){
	// 	/*to complete*/
	// }

	// typename List<T>:iterator List<T>::erase( const_iterator first,
	// 													const_iterator last ){
	// 	/*to complete*/
	// }

	// typename List<T>::const_iterator List<T>::find( const T & value ) const{
	// 	/*to complete*/
	// }

/*-------------------- Const_Iterators Functions ----------------------*/
	template< typename T >
	List<T>::const_iterator::const_iterator(){ /*empty*/ }

	template< typename T >
	const T & List<T>::const_iterator::operator* ( ) const{
		return m_node->data;
	}

	template< typename T >
	typename List<T>::const_iterator & List<T>::const_iterator::operator++(void){
		m_node = m_node->next;
		return *this;
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::const_iterator::operator++(int){
		const_iterator cpy(m_node);
		m_node = m_node->next;
		return cpy;
	}

	template< typename T >
	typename List<T>::const_iterator & List<T>::const_iterator::operator--(void){
		m_node = m_node->prev;
		return *this;
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::const_iterator::operator--(int){
		const_iterator cpy(m_node);
		m_node = m_node->prev;
		return cpy;
	}

	template< typename T >
	bool List<T>::const_iterator::operator ==(const const_iterator & rhs) const{
		return m_node == rhs->m_node;
	}

	template< typename T >
	bool List<T>::const_iterator::operator !=(const const_iterator& rhs) const{
		return !(*this == rhs);
	}

/*----------------------- Iterators Functions -------------------------*/
	//template< typename T >
	//List<T>::iterator::iterator(){ /*empty*/ }

	template< typename T >
	const T & List<T>::iterator::operator* ( ) const{
		return const_iterator::m_node->data;
	}

	template< typename T >
	T & List<T>::iterator::operator* ( ){
		return const_iterator::m_node->data;
	}

	template< typename T >
	typename List<T>::iterator & List<T>::iterator::operator++ (void){
		const_iterator::m_node = const_iterator::m_node->next;
		return *this;
	}

	template< typename T >
	typename List<T>::iterator List<T>::iterator::operator++ (int){
		iterator cpy(const_iterator::m_node);
		const_iterator::m_node = const_iterator::m_node->next;
		return cpy;
	}

	template< typename T >
	typename List<T>::iterator & List<T>::iterator::operator-- (void){
		const_iterator::m_node = const_iterator::m_node->prev;
		return *this;
	}

	template< typename T >
	typename List<T>::iterator List<T>::iterator::operator-- (int){
		iterator cpy(const_iterator::m_node);
		const_iterator::m_node = const_iterator::m_node->prev;
		return cpy;
	}
}
