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

		clear( );
		delete m_head;
		delete m_tail;
	}

	template< typename T >
	List<T> & List<T>::operator= ( const List & rhs ){
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
			if( temp->next == m_tail ){
				delete temp;
				break;
			}
			temp = temp->next;
		}

		m_size = 0; 
		m_head->next = m_tail;
		m_tail->prev = m_head;

		m_head->prev = nullptr;
		m_tail->next = nullptr;
	}

	template< typename T >
	T& List<T>::front(){
		return m_head->next->data;
	}
/*
	template< typename T >
	const T& List<T>::front() const{
		return m_head->next->data;
	}
*/
	template< typename T >
	T& List<T>::back(){
		return m_tail->prev->data;
	}
/*
	template< typename T >
	const T& List<T>::back() const{
		return m_tail->prev->data;
	}
*/
	template< typename T >
	void List<T>::push_front(const T & x){

		Node *nn = new Node(x, m_head, m_head->next); //!<
		m_head->next->prev = nn;
		m_head->next = nn;
		m_size++;
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
	template< typename T >
	void List<T>::assign(std::initializer_list<T> ilist){
		clear( );
		for(auto i = ilist.begin(); i != ilist.end(); i++){
			push_back(*i);
		}
		m_size = ilist.end() - ilist.begin();
				
	}

	template< typename T >
	template< class InItr >
	void List<T>::assign( InItr first, InItr last ){
		clear( );

		while( first != last ){
			push_back(*first);
			first++;
			m_size++;
		}
		m_size = m_size/2;
	}

	template< typename T >
	typename List<T>::iterator List<T>::insert( const_iterator itr,
 												const T & value ){
		Node *no = new Node(value, itr.m_node->prev, itr.m_node);
		itr.m_node->prev->next = no;
		itr.m_node->prev = no;
		m_size++;

		return List<T>::iterator(itr.m_node);
	}

	template< typename T >
	typename List<T>::iterator List<T>::insert( const_iterator pos,
												std::initializer_list<T> ilist ){
		for(auto oziel = ilist.begin(); oziel != ilist.end(); oziel++){
			Node *no = new Node(*oziel, pos.m_node->prev, pos.m_node);
			pos.m_node->prev->next = no;
			pos.m_node->prev = no;
			
			m_size++;
		}
		
		return List<T>::iterator(pos.m_node);
	}

	template< typename T >
	typename List<T>::iterator List<T>::erase( const_iterator itr ){
		auto target = itr.m_node;
		itr.m_node->prev->next = itr.m_node->next;
		itr.m_node->next->prev = itr.m_node->prev;
		delete target;

		m_size--;
		return List<T>::iterator(itr.m_node);
	}

	template< typename T >
	typename List<T>::iterator List<T>::erase( const_iterator first,
												const_iterator last ){
		first.m_node->prev->next = last.m_node;
		last.m_node->prev = first.m_node->prev;
		while( first != last ){
			auto target = first.m_node;
			m_size--;
			first++;
			delete target;
		}

		return List<T>::iterator(last.m_node);
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::find( const T & value ) const{
		Node *temp = m_head->next;
		while( temp != m_tail ){
			if( temp.data == value ){
				return List<T>::const_iterator(temp->next);
			}
			temp = temp->next;
		}

		return cend();
	}

/*-------------------- Const_Iterators Functions ----------------------*/
	template< typename T >
	List<T>::const_iterator::const_iterator(){ /*empty*/ }

	template< typename T >
	const T & List<T>::const_iterator::operator* ( ) const{
		return m_node->data;
	}

	// ++it
	template< typename T >
	typename List<T>::const_iterator & List<T>::const_iterator::operator++(void){
		m_node = m_node->next;
		return *this;
	}

	// it++
	template< typename T >
	typename List<T>::const_iterator List<T>::const_iterator::operator++(int){
		const_iterator cpy(m_node);
		m_node = m_node->next;
		return cpy;
	}

	// --it
	template< typename T >
	typename List<T>::const_iterator & List<T>::const_iterator::operator--(void){
		m_node = m_node->prev;
		return *this;
	}

	// it--
	template< typename T >
	typename List<T>::const_iterator List<T>::const_iterator::operator--(int){
		const_iterator cpy(m_node);
		m_node = m_node->prev;
		return cpy;
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::const_iterator::operator+ (int x){
		for(int i=0; i < x; i++){
			m_node = m_node->next;
		}
	
		return m_node;
	}

	template< typename T >
	typename List<T>::const_iterator List<T>::const_iterator::operator- (int x){
		for(int i =0; i < x; i++){
			m_node = m_node->prev;
		}

		return m_node;
	}

	template< typename T >
	bool List<T>::const_iterator::operator==(const const_iterator & rhs) const{
		return m_node == rhs.m_node;
	}

	template< typename T >
	bool List<T>::const_iterator::operator!=(const const_iterator& rhs) const{
		return !(*this == rhs);
	}


/*----------------------- Iterators Functions -------------------------*/
	template< typename T >
	const T & List<T>::iterator::operator* ( ) const{
		return const_iterator::m_node->data;
	}

	template< typename T >
	T & List<T>::iterator::operator* ( ){
		return const_iterator::m_node->data;
	}

	// ++it
	template< typename T >
	typename List<T>::iterator & List<T>::iterator::operator++ (void){
		const_iterator::m_node = const_iterator::m_node->next;
		return *this;
	}

	// it++
	template< typename T >
	typename List<T>::iterator List<T>::iterator::operator++ (int){
		iterator cpy(const_iterator::m_node);
		const_iterator::m_node = const_iterator::m_node->next;
		return cpy;
	}

	// --it
	template< typename T >
	typename List<T>::iterator & List<T>::iterator::operator-- (void){
		const_iterator::m_node = const_iterator::m_node->prev;
		return *this;
	}

	// it--
	template< typename T >
	typename List<T>::iterator List<T>::iterator::operator-- (int){
		iterator cpy(const_iterator::m_node);
		const_iterator::m_node = const_iterator::m_node->prev;
		return cpy;
	}

	template< typename T >
	typename List<T>::iterator List<T>::iterator::operator+ (int x){
		
		for(int i=0; i < x; i++){
			const_iterator::m_node = const_iterator::m_node->next;
		}		
		return const_iterator::m_node;
	}

	template< typename T >
	typename List<T>::iterator List<T>::iterator::operator-(int x){
		
		for(int i=0; i < x; i++){
			const_iterator::m_node = const_iterator::m_node->prev;
		}

		return const_iterator::m_node;
	}

}
