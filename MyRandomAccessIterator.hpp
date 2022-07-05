/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyRandomAccessIterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cciobanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:39:13 by cciobanu          #+#    #+#             */
/*   Updated: 2022/07/05 17:39:21 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iterator>

namespace ft{

template <class T>
class MyRanfomAccessIterator : public std::iterator<std::random_access_iterator_tag, T>{
	private:
		pointer _ptr;
	public:
		//==============     Constructors          ==============
		MyRandomAccessIterator() : _ptr(nullptr) {}

		MyRandomAccessIterator(pointer x) : _ptr(x) {}

		MyRandomAccessIterator(const MyRandomAccessIterator& rhs) : _ptr(rhs._ptr) {}

		MyRandomAccessIterator & operator=(const MyRandomAccessIterator& rhs){
			if (this != &rhs)
				_ptr = rhs._ptr;
			return *this;
		}

		~MyRandomAccessIterator() {}

		//==============     Pointer operations              ==============

		

		//==============     Arithmetical operations         ==============		


		

};
}