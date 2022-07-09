/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cciobanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:18:48 by cciobanu          #+#    #+#             */
/*   Updated: 2022/07/08 17:53:34 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft{

//==============     PAIR         ==============

template <class T1, class T2>
struct pair{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	//==============     Constructors          ==============

	pair() : first(), second() { }

	pair(const T1& a, const T2& b) : first(a), second(b) { }

	template <class U1, class U2>
	pair(const pair<U1, U2> &rhs) : first(rhs.first), second(rhs.second) { }

	pair & operator=(const pair &rhs){
		this -> first = rhs.first;
		this -> second = rhs.second;
		return (*this);
	}
};

//==============     Comparison operations           ==============	

template <class T1, class T2>
bool operator==(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs){ return lhs.first == rhs.first && lhs.second == rhs.second; }

template <class T1, class T2>
bool operator!=(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs){ return !(lhs == rhs); }

template <class T1, class T2>
bool operator<(const pair<T1, T2> & lhs, const pair<T1, T2> & rhs){ return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

//==============     make_pair           ==============	

template <class T1, class T2>
pair<T1, T2> make_pair (T1 x, T2 y) { return pair<T1, T2>(x, y); }

};


//==============     LEXICOGRAPHICAL COMPARE       ==============

template <class InpIter1, class InpIter2>
bool lexicographical_compare (InpIter1 first1, InpIter1 last1, InpIter2 first2, InpIter2 last2) {
	while (first1 != last1){
		if (first2 == last2 || *first2 < *first1) return false;
		else if (*first1 < *first2) return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <class InpIter1, class InpIter2, class Compare>
bool lexicographical_compare (InpIter1 first1, InpIter1 last1, InpIter2 first2, InpIter2 last2, Compare comp){
	while (first1 != last1){
		if (first2 == last2 || comp(*first2, *first1)) return false;
		else if (comp(*first1, *first2)) return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

//==============     EQUAL        ==============

template <class InpIter1, class InpIter2>
bool equal (InpIter1 first1, InpIter1 last1, InpIter2 first2) {
	while (first1 != last1){
		if (!(*first1 == *first2)) return false;
		++first1;
		++first2;
	}
	return true;
}

template <class InpIter1, class InpIter2, class BinaryPredicate>
bool equal (InpIter1 first1, InpIter1 last1, InpIter2 first2, BinaryPredicate pred) {
	while (first1 != last1){
		if (!pred(*first1, *first2)) return false;
		++first1;
		++first2;
	}
	return true;
}

//==============     EQUAL        ==============

template<bool Cond, class T = void> struct enable_if {};
template<class T> struct enable_if<true, T> { typedef T type; };

//==============     IS INTEGRAL        ==============

template<class T, bool v>
struct integral_constant {
	static const bool value = v;
	typedef T value_type;
	typedef integral_constant type;
	operator value_type() const { return value; }
};

template <class T> struct is_integral				: public ft::integral_constant<T, false> {};
template <> struct is_integral<bool>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<char>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<signed char>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned char>		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<wchar_t>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<char16_t>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<short>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned short>		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<int>					: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned int>		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<long>				: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned long> 		: public ft::integral_constant<bool, true> {};
template <> struct is_integral<long long>			: public ft::integral_constant<bool, true> {};
template <> struct is_integral<unsigned long long>	: public ft::integral_constant<bool, true> {};