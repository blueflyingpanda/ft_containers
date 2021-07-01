#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <limits>
#include <iostream>
#include <string>
#include <exception>
#include "list.hpp"
#include <unistd.h>

namespace ft{
	typedef size_t size_type;
	
	template <class T, class Container = ft::list<T> >
	class queue{
	private:
		Container ctnr;
	public:
		typedef T value_type;
		typedef Container container_type;

		explicit queue (const container_type& cont = container_type()) : ctnr(cont) {}
		queue(const queue &arg) : ctnr(arg.ctnr) {}
		virtual ~queue() {}

		queue &operator=(const queue &rhs){
			ctnr = rhs.ctnr;
			return *this;
		}

		bool empty() const{
			return ctnr.size() == 0;
		}

		size_type size() const{
			return ctnr.size();
		}
///////////////
		value_type& front(){
			return ctnr.front();
		}
		const value_type& front() const{
			return ctnr.front();
		}

		value_type& back(){
			return ctnr.back();
		}
		const value_type& back() const{
			return ctnr.back();
		}
//////////////////
		void push (const value_type& val){
			ctnr.push_back(val);
		}

		void pop(){
			ctnr.pop_front();
		}

		template <class Type, class Cont>
		friend bool	operator==(const queue<Type,Cont> &lhs, const queue<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator!=(const queue<Type,Cont> &lhs, const queue<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator<(const queue<Type,Cont> &lhs, const queue<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator<=(const queue<Type,Cont> &lhs, const queue<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator>(const queue<Type,Cont> &lhs, const queue<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator>=(const queue<Type,Cont> &lhs, const queue<Type,Cont> &rhs);
	};

	template <class T, class Container>
	bool	operator==(const queue<T,Container> &lhs, const queue<T,Container> &rhs){
		return lhs.ctnr == rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator!=(const queue<T,Container> &lhs, const queue<T,Container> &rhs){
		return lhs.ctnr != rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator<(const queue<T,Container> &lhs, const queue<T,Container> &rhs){
		return lhs.ctnr < rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator<=(const queue<T,Container> &lhs, const queue<T,Container> &rhs){
		return lhs.ctnr <= rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator>(const queue<T,Container> &lhs, const queue<T,Container> &rhs){
		return lhs.ctnr > rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator>=(const queue<T,Container> &lhs, const queue<T,Container> &rhs){
		return lhs.ctnr >= rhs.ctnr;
	}
}

#endif