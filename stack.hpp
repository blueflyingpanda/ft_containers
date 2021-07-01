#ifndef STACK_H
#define STACK_H

#include <memory>
#include <limits>
#include <iostream>
#include <string>
#include <exception>
#include "list.hpp"
#include "vector.hpp"
#include <unistd.h>

namespace ft{
	typedef size_t size_type;
	
	template <class T, class Container = ft::vector<T> >
	class stack{
	private:
		Container ctnr;
	public:
		typedef T value_type;
		typedef Container container_type;

		explicit stack (const container_type& cont = container_type()) : ctnr(cont) {}
		stack(const stack &arg) : ctnr(arg.ctnr) {}
		virtual ~stack() {}

		stack &operator=(const stack &rhs){
			ctnr = rhs.ctnr;
			return *this;
		}

		bool empty() const{
			return ctnr.size() == 0;
		}

		size_type size() const{
			return ctnr.size();
		}

		value_type& top(){
			return ctnr.back();
		}
		const value_type& top() const{
			return ctnr.back();
		}

		void push (const value_type& val){
			ctnr.push_back(val);
		}

		void pop(){
			ctnr.pop_back();
		}

		template <class Type, class Cont>
		friend bool	operator==(const stack<Type,Cont> &lhs, const stack<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator!=(const stack<Type,Cont> &lhs, const stack<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator<(const stack<Type,Cont> &lhs, const stack<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator<=(const stack<Type,Cont> &lhs, const stack<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator>(const stack<Type,Cont> &lhs, const stack<Type,Cont> &rhs);

		template <class Type, class Cont>
		friend bool	operator>=(const stack<Type,Cont> &lhs, const stack<Type,Cont> &rhs);
	};

	template <class T, class Container>
	bool	operator==(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
		return lhs.ctnr == rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator!=(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
		return lhs.ctnr != rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator<(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
		return lhs.ctnr < rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator<=(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
		return lhs.ctnr <= rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator>(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
		return lhs.ctnr > rhs.ctnr;
	}
	template <class T, class Container>
	bool	operator>=(const stack<T,Container> &lhs, const stack<T,Container> &rhs){
		return lhs.ctnr >= rhs.ctnr;
	}
}

#endif