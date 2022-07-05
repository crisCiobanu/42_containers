/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_iter.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cciobanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:39:13 by cciobanu          #+#    #+#             */
/*   Updated: 2022/07/05 18:02:27 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>

namespace ft{

template <class T>
class my_iter{


	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T* 								pointer;
		typedef T& 								reference;
		typedef std::random_access_iterator_tag	iterator_category;

	private:
		pointer _ptr;

	public:
		//==============     Constructors          ==============
		my_iter() : _ptr(nullptr) {}

		my_iter(pointer x) : _ptr(x) {}

		my_iter(const my_iter& rhs) : _ptr(rhs._ptr) {}

		my_iter & operator=(const my_iter& rhs){
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		~my_iter() {}

		//==============     Pointer like operations          ==============

		reference operator*() const{ return *(this -> _ptr);}

		pointer operator->() const{ return this -> _ptr;}

		reference operator[](const difference_type& offset) const { return this -> _ptr[offset]};


		//==============     Increment / Decrement           ==============		

		my_iter& operator++(){ ++(this -> _ptr); return *this; }

		my_iter operator++(int){ pointer tmp = *this ; ++*this ; return my_iter(tmp); }

		my_iter& operator--(){ --(this -> _ptr); return *this; }

		my_iter operator--(int){ pointer tmp = * this; --*this ; return my_iter(tmp); }
		

		//==============     Arithmetic operations           ==============	

		my_iter& operator+=(const difference_type& n) { this -> _ptr += n; return *this; }

		my_iter operator+(const difference_type& n) { return my_iter(this -> _ptr + n); }

		my_iter& operator-=(const difference_type& n) { this -> _ptr -= n; return *this; }

		my_iter operator-(const difference_type& n) { return my_iter(this -> _ptr - n); }

};
}