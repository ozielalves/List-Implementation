/**
 * @file list.inl
 * @version 1.0
 * @date May, 19.
 * @author Daniel Guerra and Oziel Alves
 * @title Class ls::list inl
 * @brief List class's inl
 */

#include "../include/list.hpp"

template< typename T >
List<T>::List(){

	m_head = new Node; //!
	m_tail = new Node; //!
	m_size = 0;
	m_head->next = m_tail; //!
	m_tail->prev = m_head; //!
}

template< typename T >
List<T>::~List(){

	clear();
	delete m_head;
	delete m_tail;
}

template< typename T >
size_t List<T>::size() const{

	return m_size;
}

template< typename T >
bool List<T>::empty() const{

	return m_size == 0;
}

template< typename T >
void List<T>::clear(){

	Node *copy1 = m_head->next; //!<
	while(copy1 != m_tail){

		Node *copy2 = copy1;
		copy1 = copy->next;
		delete copy2;
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

	Node *nn = new Node(x, m_head->next, m_head); //!<
	m_head->next->prev = nn;
	m_head->next = nn;
	m_size++
	//delete nn;
}

template< typename T >
void List<T>::pop_front(){

	if(m_size > 0){ //! If the list is not empty.
		
		Node *pp = m_head->next;
		pp->next->prev = m_head; //! putting the head value on the poped element place.
		m_head->next = pp->next  //! and then follows like above to the others.
		m_size--;
		delete pp;
	}
}

template< typename T >
void List<T>::push_back(const T &x){ //! Inserts a prev Node.

	Node nn = new Node(x, m_tail, m_Tail->prev);
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

template< typename T >
void List<T>assign(std::initializer_list<T> ilist){
	clear();
	for(auto i = ilist.begin(); i != ilist.end(); i++){
		push_back(*i);
	}
}

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

