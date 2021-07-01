#ifndef LIST_H
#define LIST_H

#include <memory>
#include <limits>
#include <iostream>
#include <string>

namespace ft{
	typedef std::ptrdiff_t difference_type;
	typedef size_t size_type;

	template <class T>
	class Node {
		private:
			Node(const Node &arg);
			Node &operator=(const Node &arg);
		public:
			typedef T value_type;
			Node() : prev(NULL), next(NULL), data(T()) {}
			Node(const value_type &val) : prev(NULL), next(NULL), data(val) {}
			~Node(){}
			Node	*prev;
			Node	*next;
			T	data;
	};

	template < class T >
	class list;

	template < class T >
	class listIterator //https://www.cplusplus.com/reference/iterator/#:~:text=An%20iterator%20is%20any%20object,dereference%20(%20*%20)%20operators).&text=But%20other%20kinds%20of%20iterators%20are%20possible.
	{
	private:
		Node<T> *currentPtr;//в reverse last;
	public:
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;
		// typedef std::ptrdiff_t difference_type;
		// typedef size_t size_type;
		
		listIterator() : currentPtr(NULL) {}
		listIterator(Node<T> *ptr) : currentPtr(ptr) {}
		listIterator(const Node<const T> *ptr) : currentPtr(const_cast<Node<const T> *>(ptr)) {}
		listIterator(const listIterator &rhs) : currentPtr(rhs.currentPtr) {}
		virtual ~listIterator(){}

		listIterator &operator=(const listIterator<T> &rhs){
			currentPtr = rhs.currentPtr;
			return *this;
		}

		listIterator &operator++(){
			currentPtr = currentPtr->next;
			return *this;
		}

		listIterator &operator++(int){
			listIterator *tmp = this;
			currentPtr = currentPtr->next;
			return *tmp;
		}

		listIterator &operator--(){
			currentPtr = currentPtr->prev;
			return *this;
		}

		listIterator &operator--(int){
			listIterator *tmp = this;
			currentPtr = currentPtr->prev;
			return *tmp;
		}

		reference operator*(){
			return currentPtr->data;
		}

		const_reference operator*() const{
			return currentPtr->data;
		}

		pointer operator->(){
			return &currentPtr->data;
		}

		const_pointer operator->() const{
			return &currentPtr->data;
		} 

		template < class TYPE >
		friend bool operator==(const listIterator<TYPE> &lhs, const listIterator<TYPE> &rhs);

		template < class TYPE >
		friend bool operator!=(const listIterator<TYPE> &lhs, const listIterator<TYPE> &rhs);

		template < class TYPE >
		friend class list;

	};

	template < class T >
	bool operator==(const listIterator<T> &lhs, const listIterator<T> &rhs){
		return lhs.currentPtr == rhs.currentPtr;
	}

	template < class T >
	bool operator!=(const listIterator<T> &lhs, const listIterator<T> &rhs){
		return lhs.currentPtr != rhs.currentPtr;
	}

	template < class ITER >
	class reverseListIterator{
	private:
		ITER it;
		reverseListIterator();
	public:
		typedef typename ITER::value_type value_type;
		typedef typename ITER::reference reference;
		typedef typename ITER::const_reference const_reference;
		typedef typename ITER::pointer pointer;
		typedef typename ITER::const_pointer const_pointer;		
		
		reverseListIterator(ITER ite) : it(ite) {}
		reverseListIterator(const reverseListIterator<ITER> &arg) : it(arg.it) {}
		virtual ~reverseListIterator(){}
		reverseListIterator<ITER> &operator=(const reverseListIterator<ITER> &rhs){
			it = rhs.it;
			return *this;
		}

		reverseListIterator<ITER> &operator++(){
			it--;
			return *this;
		}

		reverseListIterator<ITER> operator++(int){
			reverseListIterator<ITER> tmp(it--);
			return tmp;
		}

		reverseListIterator<ITER> &operator--(){
			it++;
			return *this;
		}

		reverseListIterator<ITER> operator--(int){
			reverseListIterator<ITER> tmp(it++);
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

		template < class TYPE >
		friend class list;

		template < class TYPE >
		friend bool operator==(const reverseListIterator<TYPE> &lhs, const reverseListIterator<TYPE> &rhs);

		template < class TYPE >
		friend bool operator!=(const reverseListIterator<TYPE> &lhs, const reverseListIterator<TYPE> &rhs);
	};

		template < class T >
		bool operator==(const reverseListIterator<T> &lhs, const reverseListIterator<T> &rhs){
			return lhs.it == rhs.it;
		}

		template < class T >
		bool operator!=(const reverseListIterator<T> &lhs, const reverseListIterator<T> &rhs){
			return lhs.it != rhs.it;
		}

	template < class T >
	class list{
	public:
		//MEMBER TYPES
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference;
		typedef T* pointer;
		typedef const T* const_pointer;

		typedef listIterator<T>  iterator;
		typedef listIterator<const T> const_iterator;
		typedef reverseListIterator<iterator> reverse_iterator;
		typedef reverseListIterator<const_iterator> const_reverse_iterator;
		// typedef std::ptrdiff_t difference_type;
		// typedef size_t size_type;

		template < class TYPE >
		friend class listIterator;
	
	private:
		size_type listSize;
		Node<T>	*first;
		Node<T>	*last;

		void swapNodes(iterator first, iterator second){//PRIVATE
			if (first.currentPtr == this->first)
				this->first = second.currentPtr;
			first.currentPtr->prev->next = second.currentPtr;
			second.currentPtr->prev = first.currentPtr->prev;
			first.currentPtr->next = second.currentPtr->next;
			second.currentPtr->next = first.currentPtr;
			first.currentPtr->prev = second.currentPtr;
			first.currentPtr->next->prev = first.currentPtr;
		}

		void swapFirstNodes(iterator first, iterator second){//PRIVATE
			if (first.currentPtr == this->first)
				this->first = second.currentPtr;//green
			Node<T> *secondNext = second.currentPtr->next;//purple
			Node<T> *secondPrev = second.currentPtr->prev;//yellow
			Node<T> *firstNext = first.currentPtr->next;//red
			// Node<T> *firstPrev = first.currentPtr->prev;//purple
			second.currentPtr->next = first.currentPtr->next;
			second.currentPtr->prev = first.currentPtr->prev;
			first.currentPtr->next = secondNext;
			first.currentPtr->prev = secondPrev;
			secondNext->next = second.currentPtr;
			secondNext->prev = first.currentPtr;
			secondPrev->next = first.currentPtr;
			firstNext->prev = second.currentPtr;
		}

		void swapLastEvenNodes(iterator first, iterator second){//PRIVATE
			// Node<T> *secondNext = second.currentPtr->next;//purple
			Node<T> *firstPrev = first.currentPtr->prev;//blue
			first.currentPtr->prev->next = second.currentPtr;
			second.currentPtr->prev = firstPrev;
			second.currentPtr->next->prev = first.currentPtr;
			first.currentPtr->prev = second.currentPtr;
			first.currentPtr->next = second.currentPtr->next;
			second.currentPtr->next = first.currentPtr;
		}

		void swapLastOddNodes(iterator first, iterator second){//PRIVATE
			// Node<T> *secondNext = second.currentPtr->next;//purple
			Node<T> *secondPrev = second.currentPtr->prev;//yellow
			// Node<T> *firstNext = first.currentPtr->next;//yellow
			Node<T> *firstPrev = first.currentPtr->prev;//blue
			first.currentPtr->prev->next = second.currentPtr;
			second.currentPtr->prev = firstPrev;
			second.currentPtr->next->prev = first.currentPtr;
			first.currentPtr->prev = secondPrev;
			first.currentPtr->next = second.currentPtr->next;
			second.currentPtr->next = secondPrev;
			secondPrev->next = first.currentPtr;
			secondPrev->prev = second.currentPtr;
		}

		void swapAnyNodes(iterator first, iterator second){//PRIVATE
			// Node<T> *secondNext = second.currentPtr->next;//purple
			Node<T> *secondPrev = second.currentPtr->prev;//yellow
			Node<T> *firstNext = first.currentPtr->next;//red
			Node<T> *firstPrev = first.currentPtr->prev;//blue
			first.currentPtr->prev->next = second.currentPtr;
			second.currentPtr->prev = firstPrev;
			second.currentPtr->next->prev = first.currentPtr;
			first.currentPtr->prev = secondPrev;
			first.currentPtr->next = second.currentPtr->next;
			second.currentPtr->next = firstNext;
			secondPrev->next = first.currentPtr;
			firstNext->prev = second.currentPtr;
		}
		
	public:
		//CONSTRUCTORS https://www.cplusplus.com/reference/list/list/list/ https://en.cppreference.com/w/cpp/language/explicit 
		explicit list () : listSize(0) {
			first = new Node<T>;
			last = first;
		} //empty container constructor
		explicit list (size_type n, const value_type& val = value_type()) : listSize(0){
			first = new Node<T>;
			last = first;
			insert(begin(), n, val);
		} //fill constructor https://www.cplusplus.com/reference/list/list/?kw=list 
		
		list (iterator fst, iterator lst) : listSize(0){
			first = new Node<T>;
			last = first;
			insert(begin(), fst, lst);
		} //range constructor
		list (const_iterator fst, const_iterator lst) : listSize(0){
			first = new Node<T>;
			last = first;
			insert(begin(), fst, lst); 
		} //ft::list<int> flist(21, 42);
		/*
		template <class InputIterator>
		list (InputIterator fst, InputIterator lst) : listSize(0){
			first = new Node<T>;
			last = first;
			insert(begin(), fst, lst);
		} //range constructor
		*/
		list (const list& x) : listSize(0){
			first = new Node<T>;
			last = first;
			for (const_iterator i = x.begin(); i != x.end(); i++){
				push_back(*i);
			}
		} //copy constructor

		//DESTRUCTOR
		virtual ~list(){
			clear();
			erase(iterator(last));
		}

		//OPERATOR=
		list<T> &operator=(const list& x){
			clear();
			for (const_iterator i = x.begin(); i != x.end(); i++){
				push_back(*i);
			}
			return *this;
		}

		//ITERATORS
		
		iterator begin() {
			return iterator(first);
		}

		const_iterator begin() const{
			return const_iterator(reinterpret_cast<const Node<const T> *>(first));
		}

		iterator end(){
			return iterator(last); //SENTINEL
		}

		const_iterator end() const{
			return const_iterator(reinterpret_cast<const Node<const T> *>(last));
		}

		reverse_iterator rbegin(){
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(){
			return reverse_iterator(begin()); //SENTINEL?
		}

		const_reverse_iterator rend() const{
			return const_reverse_iterator(begin());
		}

		//CAPACITY
		bool empty() const{
			return listSize == 0;
		}
		
		size_type size() const{
			return listSize;
		}

		size_type max_size() const{
			size_type distance = std::numeric_limits<difference_type>::max();
			size_type amount = std::numeric_limits<size_type>::max() / (sizeof(Node<T>));
			return distance < amount ? distance : amount;
		}

		//ELEMENT ACCESS
		reference front(){
			return first->data;
		}
		const_reference front() const{
			return first->data;
		}

		reference back(){
			return last->prev->data; //because end is not the last element
		}
		const_reference back() const{
			return last->prev->data; //because end is not the last element
		}

		//MODIFIERS
		iterator erase (iterator position){
			if (listSize == 0){
				delete position.currentPtr;
				return iterator();
			}
			if (first == position.currentPtr)
					first = first->next;
			position.currentPtr->prev->next = position.currentPtr->next;
			position.currentPtr->next->prev = position.currentPtr->prev;
			Node<T> *ret = position.currentPtr->next;
			delete position.currentPtr;
			listSize--;
			return iterator(ret);
		}
		iterator erase (iterator first, iterator last){ //last is not included
			for(iterator tmp = first; tmp != last;){
				iterator temp = tmp;
				tmp++;
				erase(temp);
			}
			return iterator(last.currentPtr);
		}
		void clear(){
			iterator f(first);
			iterator l(last);
			iterator iter = f;
			for(;iter != l;){
				iterator tmp = iter;
				iter++;
				erase(tmp);
			}
		}

		iterator insert(iterator position, const value_type &val){
			Node<T>	*I = new Node<value_type>(val);
			if(listSize == 0){
				first = I;
				last->prev = I;
				last->next = I;
				I->next = last;
				I->prev = last;
			}
			else{
				if (first == position.currentPtr)
					first = I;
				I->next = position.currentPtr;
				I->prev = position.currentPtr->prev;
				position.currentPtr->prev = I;
				I->prev->next = I;
			}
			listSize++;
			return iterator(I);
		}
		void insert (iterator position, size_type n, const value_type& val){
			for(size_type i = 0; i < n; i++){
				insert(position, val);
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator fst, InputIterator lst){
			for(InputIterator tmp = fst; tmp != lst; tmp++){
				insert(position, *tmp);
			}
		}

		void resize (size_type n, value_type val = value_type()){
			if (listSize == n)
				return;
			iterator f(first);
			iterator l(last);
			iterator iter = f;
			if (listSize > n){
				for(size_type i = 0; i < n; i++)
					iter++;
				for(;iter != l;){
					iterator tmp = iter;
					iter++;
					erase(tmp);
				}
			}else{
				insert(l, n - listSize, val);
			}
		}

		void push_front (const value_type& val){
			insert(begin(), val);
		}
		void push_back (const value_type& val){
			insert(end(), val);
		}

		void pop_front(){
			erase(begin());
		}
		void pop_back(){
			erase(--end());
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last){
			clear();
			for (InputIterator i = first; i != last; i++){
				push_back(*i);
			}
		}
		void assign (size_type n, const value_type& val){
			clear();
			for (size_type i = 0; i < n; i++){
				push_back(val);
			}	
		}

		void swap(list& x){
			std::swap(first, x.first);
			std::swap(last, x.last);
			std::swap(listSize, x.listSize);
		}

		//OPERATIONS
		void splice (iterator position, list& x){ //entire list
			splice(position, x, x.begin(), x.end());
		}
		void splice (iterator position, list& x, iterator i){
			iterator it = i;
			it++;
			splice(position, x, i, it);
		}
		void splice (iterator position, list& x, iterator first, iterator last){
			for(;first != last;){
				insert(position, *first);
				iterator tmp = first;
				first++;
				x.erase(tmp);
			}
		}

		void remove (const value_type& val){
			iterator first = begin();
			iterator last = end();
			for(;first != last;){
				if (*first == val){
					iterator tmp = first;
					first++;
					erase(tmp);
				}
				else
					first++;
			}
		}

		template <class Predicate>
		void remove_if (Predicate pred){
			iterator first = begin();
			iterator last = end();
			for(;first != last;){
				if (pred(*first)){
					iterator tmp = first;
					first++;
					erase(tmp);
				}
				else
					first++;
			}
		}

		void unique(){
			if (size() < 2)
				return;
			iterator first = begin();
			iterator next = first;
			next++;
			iterator last = end();
			for(;next != last;){
				if (*first == *next){
					iterator tmp = next;
					next++;
					erase(tmp);
				}else{
					first++;
					next++;
				}
			}
		}
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred){
			if (size() < 2)
				return;
			iterator first = begin();
			iterator next = first;
			next++;
			iterator last = end();
			for(;next != last;){
				if (binary_pred(*next, *first)){
					iterator tmp = next;
					next++;
					erase(tmp);
				}else{
					first++;
					next++;
				}
			}
		}

		void merge (list& x){
			iterator f1 = begin();
			iterator l1 = end();
			iterator f2 = x.begin();
			iterator l2 = x.end();
			for(;f1 != l1;){
				if(f2 != l2 && *f1 > *f2){
					insert(f1, *f2);
					f2++;
				}
				else
					f1++;
			}
			for(;f2 != l2; f2++)
				push_back(*f2);
			x.clear();
		}
		template <class Compare>
		void merge (list& x, Compare comp){
			iterator f1 = begin();
			iterator l1 = end();
			iterator f2 = x.begin();
			iterator l2 = x.end();
			for(;f1 != l1;){
				if(f2 != l2 && comp(*f2, *f1)){
					insert(f1, *f2);
					f2++;
				}
				else
					f1++;
			}
			for(;f2 != l2; f2++)
				push_back(*f2);
			x.clear();
		}

		void sort(){
			if (listSize < 2)
				return;
			size_t len = listSize;
			for(;len > 1; len--){
				iterator first = begin();
				iterator next = first;
				next++;
				for(size_t i = 1; i < len; i++, first++, next++){
					if (*first > *next){
						swapNodes(first, next);
						iterator tmp = first;
						first = next;
						next = tmp;
					}
				}
			}
		}
		template <class Compare>
		void sort (Compare comp){
			if (listSize < 2)
				return;
			size_t len = listSize;
			for(;len > 1; len--){
				iterator first = begin();
				iterator next = first;
				next++;
				for(size_t i = 1; i < len; i++, first++, next++){
					if (comp(*next, *first)){
						swapNodes(first, next);
						iterator tmp = first;
						first = next;
						next = tmp;
					}
				}
			}
		}

		void reverse(){
			iterator f = begin();
			iterator r = end();
			r--;
			size_t count = listSize/2;
			for (size_t i = 0; i < count; i++, f++, r--){
				if (i == 0)
					swapFirstNodes(f, r);
				else if (i == count - 1){
					if (listSize%2 == 0)
						swapLastEvenNodes(f, r);
					else
						swapLastOddNodes(f, r);
				}
				else
					swapAnyNodes(f, r);
				iterator tmp = f;
				f = r;
				r = tmp;
			}
		}
	};

	template <class T>
	bool operator==(const list<T> lhs, const list<T> rhs){
		if (lhs.size() != rhs.size())
			return false;
		listIterator<const T> beginLhs = lhs.begin();
		listIterator<const T> beginRhs = rhs.begin();
		listIterator<const T> endLhs = lhs.end();
		listIterator<const T> endRhs = rhs.end();

		for(;beginLhs != endLhs; beginLhs++, beginRhs++){
			if (*beginLhs != *beginRhs)
				return false;
		}
		return true;
	}

	template <class T>
	bool operator!=(const list<T> lhs, const list<T> rhs){
		return !(lhs == rhs);
	}

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) 
			return false;
		else if (*first1<*first2) 
			return true;
		first1++; 
		first2++;
	}
		return (first2!=last2);
	}

	template <class T>
	bool operator<(const list<T> lhs, const list<T> rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); //true if the first range compares lexicographically less than the second. false otherwise (including when all the elements of both ranges are equivalent).
	}

	template <class T>
	bool operator>(const list<T> lhs, const list<T> rhs){
		return rhs < lhs;
	}

	template <class T>
	bool operator<=(const list<T> lhs, const list<T> rhs){
		return lhs < rhs || lhs == rhs;
	}

	template <class T>
	bool operator>=(const list<T> lhs, const list<T> rhs){
		return lhs > rhs || lhs == rhs;
	}
	
	template <typename T>
	void swap(list<T> &x, list<T> &y){
		x.swap(y);
	}
}

#endif