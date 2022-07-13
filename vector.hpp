/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cciobanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:12:48 by cciobanu          #+#    #+#             */
/*   Updated: 2022/07/13 15:04:54 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
#include "iterators.hpp"

namespace ft
{
template <class T, class Allocator = std::allocator<T> >
class vector {
	public:
		typedef	T 													value_type;
		typedef Allocator											allocator_type;
		typedef std::size_t											size_type;
		typedef std::ptrdiff_t										difference_type;
		typedef value_type&											reference;
		typedef const value_type&									const_reference;
		typedef typename Allocator::pointer							pointer;
		typedef typename Allocator::const_pointer					const_pointer;	

		typedef ft::my_iter<value_type>								iterator;
		typedef ft::my_iter<const value_type>						const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		
	private:
		pointer			_first;
		size_type		_size;
		size_type		_cap;
		allocator_type	_alloc;
		
	public:
		//==============     Constructors          ==============
		explicit vector(const allocator_type& alloc = allocator_type()) : _first(nullptr), _size(0), _cap(0), _alloc(alloc){}
		
		explicit vector(size_type n, const_reference val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _cap(n) , _alloc(alloc) {
			reserve(n);
			for (size_type i = 0; i < n; ++i) { 
				_alloc.allocate(_first + i, val);
			}
		}
		
		~vector(){
			for (size_type i = 0; i < _size; ++i){
				_alloc.destroy(_first + i);
			}
			_alloc.deallocate(_first, this -> _cap);		
		}

		//==============     Member functions     ==============

		vector & operator=(const vector& rhs){
			// reserve(rhs._size);
			// for (size_type i = 0; i < rhs._size; )

		}

		void assign(size_type n, const value_type& val){
			
		}

		template< class InputIt >
			void assign(InputIt first , InputIt second){

			}
		
		allocator_type get_allocator() const{

		}

		//==============     Element access       ==============

		reference at( size_type pos ){

		}

		const_reference at( size_type pos ) const {

		}

		reference operator[]( size_type pos ){

		}

		const_reference operator[]( size_type pos ) const {

		} 

		reference front(){

		}

		const_reference front() const {

		}

		reference back() {

		}

		const_reference back() const {

		}

		pointer data(){

		}

		const_pointer data() const {

		}

		//==============     Iterators            ==============

		iterator begin() { return iterator(this -> _first); }

		const_iterator begin() const {return const_iterator(this -> _first); }

		iterator end() { return iterator( _first + _size); }

		const_iterator end() const { return const_iterator(this -> _first + this -> _size); }

		reverse_iterator rbegin() {}

		const_reverse_iterator rbegin() const {}

		reverse_iterator rend() {}

		const_reverse_iterator rend() const {}

		//==============     Capacity             ==============

		bool empty() const { if (this -> _size == 0) return true; return false;}

		size_type size() const { return this -> _size;}

		size_type max_size() const { return Allocator::max_size();}

		void reserve(size_type new_cap) {
			if (new_cap <= this -> _cap) return;
			pointer tmp = _alloc.allocate(new_cap);
			size_type i = 0;
			try{
				std::uninitialized_copy(_first, _first + _size, tmp);
			} catch (...){
				_alloc.deallocate(tmp, new_cap);
				throw;
			}
			for (size_type i = 0; i < this -> _size; ++i){
				_alloc.destroy(_first + i);
			}	
			if (this -> _cap)		
				_alloc.deallocate(_first, this -> _cap);
			_first = tmp;
			_cap = new_cap;
		}

		size_type capacity() const { return this -> _cap;}

		//==============     Modifiers            ==============

		void clear() {

		}

		iterator insert(iterator pos, const_reference value) {

		}

		void insert(iterator pos, size_type count , const_reference value) {

		}

		template< class InputIt >
			void insert( iterator pos , InputIt first, InputIt last) {

			}
		
		iterator erase(iterator pos) {

		}

		iterator erase( iterator first, iterator second ){

		} 

		void push_back(const_reference value){
			if (this -> _size == this -> _cap)
				reserve(this -> _cap == 0 ? 1 : 2 * this -> _size);
			_alloc.construct(this -> _first + this -> _size, value);
			++_size;
		}

		void pop_back() {

		}

		void resize(size_type count, value_type value = value_type()){

		}
		
		void swap( reference rhs) {

		}
};

		//==============     Non member dunctions  ==============

} // namespace ft
