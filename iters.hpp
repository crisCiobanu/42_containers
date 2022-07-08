#pragma once

#include <iostream>

namespace ft{

	template <class Iter>
class iterator_traits {
	public:	
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;

};

template <class T>
class iterator_traits<T*> {
	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef T* 								pointer;
		typedef T& 								reference;
		typedef std::random_access_iterator_tag	iterator_category;
};

template <class T>
class iterator_traits<const T*> {
	public:
		typedef std::ptrdiff_t					difference_type;
		typedef T 								value_type;
		typedef const T* 						pointer;
		typedef const T& 						reference;
		typedef std::random_access_iterator_tag	iterator_category;
};

template<class T> struct remove_const { typedef T type; };

template<class T> struct remove_const <const T> { typedef T type; };

	template< typename L>
	class RandomAccessIterator
	{
	public:
		typedef	typename iterator_traits<L*>::value_type 	value_type;
		typedef	typename iterator_traits<L*>::pointer	pointer;
		typedef	typename iterator_traits<L*>::reference	reference;
		typedef	typename iterator_traits<L*>::difference_type	difference_type;
		typedef pointer iterator_type;
		//this is for std::functions
		typedef	std::random_access_iterator_tag iterator_category;

		//maybe protected???
	private:
		pointer _ptr;

	public:

		// CONSTRUCTORS
		RandomAccessIterator() : _ptr() {}

		RandomAccessIterator(pointer a) : _ptr(a) {}

		virtual ~RandomAccessIterator() {}

		RandomAccessIterator(const RandomAccessIterator<typename remove_const<value_type>::type > & src) : _ptr(&(*src)) {}

		RandomAccessIterator<value_type> & operator=(RandomAccessIterator<typename remove_const<value_type>::type > const & src) {
			_ptr = &(*src);
			return *this;
		}

		//OPERATORS
		RandomAccessIterator & operator++() {
			++_ptr;
			return *this;
		}

		RandomAccessIterator operator++(int) {
			RandomAccessIterator tmp(*this);
			++_ptr;
			return tmp;
		}

		RandomAccessIterator & operator--() {
			--_ptr;
			return *this;
		}

		RandomAccessIterator  operator--(int) {
			RandomAccessIterator tmp = *this;
			--_ptr;
			return tmp;
		}
		RandomAccessIterator operator+(const difference_type & a) const {
			return _ptr + a;
		}

		RandomAccessIterator operator-(const difference_type & a) const {
			return _ptr - a;
		}

		RandomAccessIterator & operator+=(const difference_type & a) {
			_ptr += a;
			return (*this);
		}

		RandomAccessIterator & operator-=(const difference_type & a) {
			_ptr -= a;
			return (*this);
		}

		pointer operator->() const {
			return _ptr;
		}

		reference operator*() const {
			return *_ptr;
		}

		reference operator[](difference_type n) const {
			return *(_ptr + n);
		}
	};

	public:
	template<typename A, typename B>
		friend bool operator==(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs){
			return &(*lhs) == &(*rhs);


		}

		template<typename A, typename B>
		friend bool operator!=(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs) {
			return &(*lhs) != &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator>(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs) {
			return &(*lhs) > &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator<(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs) {
			return &(*lhs) < &(*rhs);
		}

		template<typename A, typename B>
		friend bool operator<=(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs) {
			return &(*lhs) <= &(*rhs);
		}


		template<typename A, typename B>
		friend bool operator>=(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs) {
			return &(*lhs) >= &(*rhs);
		}

		template<typename A, typename B>
		friend typename vector::template RandomAccessIterator<A>::difference_type operator-(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs){
			return &(*lhs) - &(*rhs);
		}

		template<typename A, typename B>
		friend typename vector::template RandomAccessIterator<A>::difference_type operator+(const vector::template RandomAccessIterator<A> & lhs, const vector::template RandomAccessIterator<B> & rhs){
			return &(*lhs) + &(*rhs);
		}

		template<typename L>
		friend vector::template RandomAccessIterator<L> operator +(const typename vector::template RandomAccessIterator<L>::difference_type & a, const vector::template RandomAccessIterator<L> & iter){
			return	(iter + a);
		}

		template<typename L>
		friend vector::template RandomAccessIterator<L> operator -(const typename vector::template RandomAccessIterator<L>::difference_type & a, const vector::template RandomAccessIterator<L> & iter){
			return	(iter - a);
		}
	
}