#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <limits>
#include <iostream>
#include <string>
#include <exception>
#include "list.hpp"

namespace ft{
	typedef std::ptrdiff_t difference_type;
	typedef size_t size_type;
	
	template < class T >
	class vectorIterator //https://www.cplusplus.com/reference/iterator/#:~:text=An%20iterator%20is%20any%20object,dereference%20(%20*%20)%20operators).&text=But%20other%20kinds%20of%20iterators%20are%20possible.
	{
	private:
		T *currentPtr;
	public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;

		vectorIterator() : currentPtr(NULL) {}
		// vectorIterator(pointer ptr) : currentPtr(ptr) {}
		vectorIterator(const_pointer ptr) : currentPtr(const_cast<pointer>(ptr)) {}
		vectorIterator(const vectorIterator &rhs) : currentPtr(rhs.currentPtr) {}
		virtual ~vectorIterator(){}

		vectorIterator &operator=(const vectorIterator &rhs){
			currentPtr = rhs.currentPtr;
			return *this;
		}

		vectorIterator &operator++(){
			currentPtr++;
			return *this;
		}

		vectorIterator &operator++(int){
			vectorIterator *tmp = this;
			currentPtr++;
			return *tmp;
		}

		vectorIterator &operator--(){
			currentPtr--;
			return *this;
		}

		vectorIterator &operator--(int){
			vectorIterator *tmp = this;
			currentPtr--;
			return *tmp;
		}

		reference operator*(){
			return *currentPtr;
		}

		const_reference operator*() const{
			return *currentPtr;
		}

		pointer operator->(){
			return currentPtr;
		}

		const_pointer operator->() const{
			return currentPtr;
		}

		vectorIterator &operator+=(size_type of){
			currentPtr += of;
			return *this;
		}

		vectorIterator &operator-=(size_type of){
			currentPtr -= of;
			return *this;
		}

		template < class TYPE >
		friend bool operator==(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);

		template < class TYPE >
		friend bool operator!=(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);

		template < class TYPE >
		friend bool operator>(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend bool operator>=(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend bool operator<(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend bool operator<=(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend difference_type operator-(const vectorIterator<TYPE> &lhs, const vectorIterator<TYPE> &rhs);

		template < class TYPE >
		friend class vector;
	};

	template < class T >
	bool operator==(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr == rhs.currentPtr;
	}

	template < class T >
	bool operator!=(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr != rhs.currentPtr;
	}

	template < class T >
	bool operator>(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr > rhs.currentPtr;
	}

	template < class T >
	bool operator>=(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr >= rhs.currentPtr;
	}

	template < class T >
	bool operator<(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr < rhs.currentPtr;
	}

	template < class T >
	bool operator<=(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr <= rhs.currentPtr;
	}

	template < class T >
	vectorIterator<T> operator+(const vectorIterator<T> &lhs, size_type of){
		vectorIterator<T> tmp = lhs;
		return tmp+=of;
	}

	template < class T >
	vectorIterator<T> operator+(size_type of, const vectorIterator<T> &lhs){
		vectorIterator<T> tmp = lhs;
		return tmp+=of;
	}

	template < class T >
	vectorIterator<T> operator-(const vectorIterator<T> &lhs, size_type of){
		vectorIterator<T> tmp = lhs;
		return tmp-=of;
	}

	template < class T >
	difference_type operator-(const vectorIterator<T> &lhs, const vectorIterator<T> &rhs){
		return lhs.currentPtr - rhs.currentPtr;
	}

	template < class ITER >
	class reverseVectorIterator{
	private:
		ITER it;
		reverseVectorIterator();
	public:
		typedef typename ITER::value_type value_type;
		typedef typename ITER::reference reference;
		typedef typename ITER::const_reference const_reference;
		typedef typename ITER::pointer pointer;
		typedef typename ITER::const_pointer const_pointer;
		
		reverseVectorIterator(ITER ite) : it(ite) {}
		reverseVectorIterator(const reverseVectorIterator<ITER> &arg) : it(arg.it) {}
		virtual ~reverseVectorIterator(){}
		reverseVectorIterator<ITER> &operator=(const reverseVectorIterator<ITER> &rhs){
			it = rhs.it;
			return *this;
		}

		reverseVectorIterator<ITER> &operator++(){
			it--;
			return *this;
		}

		reverseVectorIterator<ITER> operator++(int){
			reverseVectorIterator<ITER> tmp(it--);
			return tmp;
		}

		reverseVectorIterator<ITER> &operator--(){
			it++;
			return *this;
		}

		reverseVectorIterator<ITER> operator--(int){
			reverseVectorIterator<ITER> tmp(it++);
			return tmp;
		}

		reference operator*(){
			ITER tmp(it);
			tmp--;
			return *tmp;
		}

		pointer operator->(){
			ITER tmp(it);
			tmp--;
			return tmp.operator->();
		}

		reverseVectorIterator<ITER> &operator+=(size_type of){
			it -= of;
			return *this;
		}

		reverseVectorIterator<ITER> &operator-=(size_type of){
			it += of;
			return *this;
		}

		template < class TYPE >
		friend bool operator==(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);

		template < class TYPE >
		friend bool operator!=(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);

		template < class TYPE >
		friend bool operator>(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend bool operator>=(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend bool operator<(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend bool operator<=(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);
		
		template < class TYPE >
		friend difference_type operator-(const reverseVectorIterator<TYPE> &lhs, const reverseVectorIterator<TYPE> &rhs);

		template < class TYPE >
		friend reverseVectorIterator<TYPE> operator-(const reverseVectorIterator<TYPE> &lhs, size_type of);


		template < class TYPE >
		friend reverseVectorIterator<TYPE> operator+(const reverseVectorIterator<TYPE> &lhs, size_type of);

		template < class TYPE >
		friend reverseVectorIterator<TYPE> operator+(size_type of, const reverseVectorIterator<TYPE> &lhs);

		template < class TYPE >
		friend class vector;
	};

	template < class T >
	bool operator==(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it == rhs.it;
	}

	template < class T >
	bool operator!=(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it != rhs.it;
	}

	template < class T >
	bool operator>(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it > rhs.it;
	}

	template < class T >
	bool operator>=(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it >= rhs.it;
	}

	template < class T >
	bool operator<(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it < rhs.it;
	}

	template < class T >
	bool operator<=(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it <= rhs.it;
	}

	template < class T >
	difference_type operator-(const reverseVectorIterator<T> &lhs, const reverseVectorIterator<T> &rhs){
		return lhs.it - rhs.it;
	}

	template < class T >
	reverseVectorIterator<T> operator-(const reverseVectorIterator<T> &lhs, size_type of){
		reverseVectorIterator<T> tmp(lhs.it + of);
		return tmp;
	}

	template < class T >
	reverseVectorIterator<T> operator+(const reverseVectorIterator<T> &lhs, size_type of){
		reverseVectorIterator<T> tmp(lhs.it - of);
		return tmp;
	}

	template < class T >
	reverseVectorIterator<T> operator+(size_type of, const reverseVectorIterator<T> &lhs){
		reverseVectorIterator<T> tmp(lhs.it - of);
		return tmp;
	}

	template < class T > 
	class vector{
	public:
	//MEMBER TYPES
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;

		typedef vectorIterator<T>  iterator;
		typedef vectorIterator<const T> const_iterator;
		typedef reverseVectorIterator<iterator> reverse_iterator;
		typedef reverseVectorIterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

	private:
		size_type vectorSize;
		size_type vectorCapacity;
		pointer array;
	public:
		//CONSTRUCTORS
		explicit vector() : vectorSize(0), vectorCapacity(0), array(NULL) {} //default
		explicit vector(size_type n, const value_type& val = value_type()) : vectorSize(0), vectorCapacity(0), array(NULL){
			insert(begin(), n, val);
		} //fill
		vector(iterator first, iterator last) : vectorSize(0), vectorCapacity(0), array(NULL){
			insert(begin(), first, last);
		} //range
		vector(const_iterator first, const_iterator last) : vectorSize(0), vectorCapacity(0), array(NULL){
			insert(begin(), first, last);
		} //range
		/*
		template <class InputIterator>
		vector(InputIterator first, InputIterator last) : vectorSize(0), vectorCapacity(0), array(NULL){
			insert(begin(), first, last);
		} //range
		*/
		vector(const vector& x) : vectorSize(0), vectorCapacity(0), array(NULL){
			insert(begin(), x.begin(), x.end());
		} //copy
		//DESTRUCTOR
		virtual ~vector(){ 
			clear();
			std::allocator<T> mem;
			mem.deallocate(array, vectorCapacity);
		}
		//OPERATOR=
		vector& operator=(const vector& x){
			clear();
			insert(begin(), x.begin(), x.end());
			return *this;
		}
		//ITERATOR 
		iterator begin() {return array;}
		const_iterator begin() const {return array;}

		iterator end() {return array + vectorSize;}
		const_iterator end() const {return array + vectorSize;}

		reverse_iterator rbegin() {return reverse_iterator(end());}
		reverse_iterator rend() {return reverse_iterator(begin());}
		reverse_iterator rbegin() const {return const_reverse_iterator(end());}
		reverse_iterator rend() const {return const_reverse_iterator(begin());}
		//CAPACITY
		size_type size() const {return vectorSize;}
		size_type max_size() const {
			size_type distance = std::numeric_limits<difference_type>::max();
			size_type amount = std::numeric_limits<size_type>::max() / sizeof(T);
			return distance < amount ? distance : amount;
		}
		void resize(size_type n,  value_type val = value_type()){
			if (vectorSize == n)
				return;
			if (vectorSize > n){
				for (size_t i = vectorSize - 1; i >= n; i--)
					erase(begin() + i);
			}
			else{
				insert(end(), n - vectorSize, val);
			}
		}

		size_type capacity() const {return vectorCapacity;}
		bool empty() const {return vectorSize == 0;}

		void reserve(size_type n){
			if (vectorCapacity < n){
				std::allocator<T> mem;
				T *tmp = mem.allocate(n);
				for (size_t i = 0; i < vectorSize; i++){
					// tmp[i] = array[i]; 
					mem.construct(&tmp[i], array[i]);
					mem.destroy(&array[i]);
				}
				mem.deallocate(array, vectorCapacity);
				array = tmp;
				vectorCapacity = n;
			}

		}
		//ELEMENT ACCESS
		reference operator[] (size_type n) {return array[n];}
		const_reference operator[] (size_type n) const {return array[n];}
		reference at (size_type n){
			if (n >= vectorSize){
				throw std::out_of_range("Index out of bounds\n");
			}
			return array[n];
		}
		const_reference at (size_type n) const{
			if (n >= vectorSize){
				throw std::out_of_range("Index out of bounds\n");
			}
			return array[n];
		}

		reference front() {return array[0];}
		const_reference front() const {return array[0];}
		reference back() {return array[vectorSize - 1];}
		const_reference back() const {return array[vectorSize - 1];}
		//MODIFIERS
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last){
			clear();
			for (InputIterator i = first; i != last; i++){
				push_back(*i);
			}
		} //range
		void assign(size_type n, const value_type& val){
			clear();
			for (size_type i = 0; i < n; i++){
				push_back(val);
			}
		}//fill

		void push_back(const value_type& val){
			insert(end(), val);
		}

		void pop_back(){
			erase(--end());
		}

		iterator insert(iterator position, const value_type& val){
			size_type i = position.currentPtr - array;
			if (vectorCapacity < vectorSize + 1)
				reserve((vectorSize + 1) * 2);//?
			std::allocator<T> mem;
			for (size_t index = vectorSize; index > i; index--){
				mem.construct(&array[index], array[index - 1]);
				mem.destroy(&array[index - 1]);
				// array[index] = array[index - 1];
			}
			mem.construct(&array[i], val);
			// array[i] = val;
			vectorSize++;
			return position;
		} //single
		void insert(iterator position, size_type n, const value_type& val){
			if (n == 0)
				return;
			size_type i = position.currentPtr - array;
			if (vectorCapacity < vectorSize + n)
				reserve((vectorSize + n) * 2);//?
			std::allocator<T> mem;
			for (size_t index = vectorSize + n - 1; index > i + n - 1; index--){
				// array[index] = array[index - n];
				mem.construct(&array[index], array[index - n]);
				mem.destroy(&array[index - n]);
			}
			for (size_t index = i; index < i + n; index++){
				// array[index] = val;
				mem.construct(&array[index], val);
			}
			vectorSize+=n;	
		} //fill
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last){
			size_type i = position.currentPtr - array;
			size_type offset = last - first;
			if (offset == 0)
				return;
			if (vectorCapacity < vectorSize + offset)
				reserve((vectorSize + offset) * 2);//?
			std::allocator<T> mem;
			for (size_t index = vectorSize + offset - 1; index > i + offset - 1; index--){
				mem.construct(&array[index], array[index - offset]);
				mem.destroy(&array[index - offset]);
			}
			for (size_t index = i; index < i + offset; index++){
				mem.construct(&array[index], *first);
				first++;
			}
			vectorSize+=offset;
		} //range

		iterator erase(iterator position){
			// return erase(position, position + 1);//////////////////////////
			size_type i = position.currentPtr - array;
			std::allocator<T> mem;
			for (size_type index = i; index < vectorSize - 1; index++){
				// array[index] = array[index + 1];
				mem.construct(&array[index], array[index + 1]);
				mem.destroy(&array[index + 1]);
			}
			vectorSize--;
			return position;
			
		}
		iterator erase(iterator first, iterator last){
			size_type i = first.currentPtr - array;
			size_type offset = last.currentPtr - first.currentPtr;
			if (offset == 0)
				return last;
			std::allocator<T> mem;
			for (size_t index = i; index < i + offset; index++)
				mem.destroy(&array[index]);
			for (size_t index = i; index + offset < vectorSize; index++){
				mem.construct(&array[index], array[index + offset]);
				mem.destroy(&array[index + offset]);

			}
			vectorSize -= offset;
			return first;
		}

		void swap(vector& x){
			std::swap(vectorSize, x.vectorSize);
			std::swap(vectorCapacity, x.vectorCapacity);
			std::swap(array, x.array);
		}

		void clear(){
			erase(begin(), end());
		}
	};

	template <class T>
	bool operator==(const vector<T> lhs, const vector<T> rhs){
		if (lhs.size() != rhs.size())
			return false;
		vectorIterator<const T> beginLhs = lhs.begin();
		vectorIterator<const T> beginRhs = rhs.begin();
		vectorIterator<const T> endLhs = lhs.end();
		vectorIterator<const T> endRhs = rhs.end();

		for(;beginLhs != endLhs; beginLhs++, beginRhs++){
			if (*beginLhs != *beginRhs)
				return false;
		}
		return true;
	}

	template <class T>
	bool operator!=(const vector<T> lhs, const vector<T> rhs){
		return !(lhs == rhs);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

	template <class T>
	bool operator<(const vector<T> lhs, const vector<T> rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); //true if the first range compares lexicographically less than the second. false otherwise (including when all the elements of both ranges are equivalent).
	}

	template <class T>
	bool operator>(const vector<T> lhs, const vector<T> rhs){
		return rhs < lhs;
	}

	template <class T>
	bool operator<=(const vector<T> lhs, const vector<T> rhs){
		return lhs < rhs || lhs == rhs;
	}

	template <class T>
	bool operator>=(const vector<T> lhs, const vector<T> rhs){
		return lhs > rhs || lhs == rhs;
	}
	
	template <typename T>
	void swap(vector<T> &x, vector<T> &y){
		x.swap(y);
	}
}

#endif