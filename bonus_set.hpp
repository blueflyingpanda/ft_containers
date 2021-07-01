#ifndef B_SET_H
#define B_SET_H

#define MS 28

#include <memory>
#include <limits>
#include <iostream>
#include <string>
#include <exception>
#include "list.hpp"
#include <unistd.h>

namespace ft{
	typedef std::ptrdiff_t difference_type;
	typedef size_t size_type;

	template <class T>
	class setNode 
	{
	private:
		setNode(const setNode &arg);
		setNode &operator=(const setNode &arg);
	public:
		int height;
		T val;
		setNode* parent;
		setNode* left;
		setNode* right;
		bool isSentinel;
		setNode() {isSentinel = false; parent = left = right = NULL; height = 1; }
		~setNode(){}
	};

	//ITERATOR
	template < class T >
	class setIterator{
	protected:
		setNode<T> *currentPtr;
	public:
		typedef T	value_type;
		typedef T&	reference;
		typedef T*	pointer;

		setIterator(){}
		setIterator(const setIterator &arg) : currentPtr(arg.currentPtr) {}
		setIterator(setNode<T> *ptr) : currentPtr(/*const_cast<setNode<KEY, T> *>*/(ptr)) {}
		virtual ~setIterator(){}

		setNode<T> *getCurrentPtr(){
			return currentPtr;
		}

		setIterator &operator=(const setIterator &rhs){
			currentPtr = rhs.currentPtr;
			return *this;
		}

		setIterator	&operator++(){
			setNode<T> *ptr = currentPtr;
			if (ptr == NULL)
				return *this;
			if (ptr->right == NULL)
			{
				for(;ptr->parent && ptr == ptr->parent->right; ptr = ptr->parent);
				ptr = ptr->parent;
			}
			else
			{
				ptr = ptr->right;
				for (;ptr->left;ptr = ptr->left);
			}
			this->currentPtr = ptr;
			return *this;	
		}
		setIterator	operator++(int){
			setIterator tmp = *this;
			++(*this);
			return tmp;
		}
		setIterator	&operator--(){
			setNode<T> *ptr = currentPtr;
			if (ptr == NULL)
				return *this;
			if (ptr->left == NULL)
			{
				for(;ptr->parent && ptr == ptr->parent->left; ptr = ptr->parent);
				ptr = ptr->parent;
			}
			else
			{
				ptr = ptr->left;
				for (;ptr->right;ptr = ptr->right);
			}
			this->currentPtr = ptr;
			return *this;
		}
		setIterator	operator--(int){
			setIterator tmp = *this;
			--(*this);
			return tmp;
		}
		T	&operator*(){
			return currentPtr->val;
		}
		T	*operator->(){
			return &currentPtr->val;
		}

		template < class TYPE, class Compare >
		friend class set;

		template < class TYPE >
		friend bool operator==(const setIterator<TYPE> lhs, const setIterator<TYPE> rhs);

		template < class TYPE >
		friend bool operator!=(const setIterator<TYPE> lhs, const setIterator<TYPE> rhs);

	};

	template < class T >
	bool operator==(const setIterator<T> lhs, const setIterator<T> rhs){
		return lhs.currentPtr == rhs.currentPtr;
	}

	template < class T >
	bool operator!=(const setIterator<T> lhs, const setIterator<T> rhs){
		return lhs.currentPtr != rhs.currentPtr;
	}

	//REVERSE ITERATOR
	template < class T >
	class setReverseIterator{
	protected:
		setNode<T> *currentPtr;
	public:
		typedef T	value_type;
		typedef T&	reference;
		typedef T*	pointer;

		setReverseIterator(){}
		setReverseIterator(const setReverseIterator &arg) : currentPtr(arg.currentPtr) {}
		setReverseIterator(setNode<T> *ptr) : currentPtr(const_cast<setNode<T> *>(ptr)) {}
		virtual ~setReverseIterator(){}

		setReverseIterator &operator=(const setReverseIterator &rhs){
			currentPtr = rhs.currentPtr;
			return *this;
		}

		setReverseIterator	&operator++(){
			setNode<T> *ptr = currentPtr;
			if (ptr == NULL)
				return *this;
			if (ptr->left == NULL)
			{
				for(;ptr->parent && ptr == ptr->parent->left; ptr = ptr->parent);
				ptr = ptr->parent;
			}
			else
			{
				ptr = ptr->left;
				for (;ptr->right;ptr = ptr->right);
			}
			this->currentPtr = ptr;
			return *this;
		}
		setReverseIterator	operator++(int){
			setReverseIterator tmp = *this;
			++(*this);
			return tmp;
		}
		setReverseIterator	&operator--(){
			setNode<T> *ptr = currentPtr;
			if (ptr == NULL)
				return *this;
			if (ptr->right == NULL)
			{
				for(;ptr->parent && ptr == ptr->parent->right; ptr = ptr->parent);
				ptr = ptr->parent;
			}
			else
			{
				ptr = ptr->right;
				for (;ptr->left;ptr = ptr->left);
			}
			this->currentPtr = ptr;
			return *this;
		}
		setReverseIterator	operator--(int){
			setReverseIterator tmp = *this;
			--(*this);
			return tmp;
		}
		T	&operator*(){
			return currentPtr->val;
		}
		T	*operator->(){
			return &currentPtr->val;
		}

		template < class TYPE, class Compare >
		friend class set;

		template < class TYPE >
		friend bool operator==(const setReverseIterator<TYPE> lhs, const setReverseIterator<TYPE> rhs);

		template < class TYPE >
		friend bool operator!=(const setReverseIterator<TYPE> lhs, const setReverseIterator<TYPE> rhs);

	};

	template < class T >
	bool operator==(const setReverseIterator<T> lhs, const setReverseIterator<T> rhs){
		return lhs.currentPtr == rhs.currentPtr;
	}

	template < class T >
	bool operator!=(const setReverseIterator<T> lhs, const setReverseIterator<T> rhs){
		return lhs.currentPtr != rhs.currentPtr;
	}

		template < class T, class Compare = std::less<T> >
	class set
	{
	public:
		typedef T key_type;
		typedef T value_type;
		typedef Compare key_compare;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;

		typedef setIterator<T> iterator;
		// typedef constsetIterator<T> const_iterator;
		typedef setIterator<const T> const_iterator;
		typedef setReverseIterator<T> reverse_iterator;
		typedef setReverseIterator<const T> const_reverse_iterator;
	private:
		int height(setNode<T>* p){
			if (p == lastSentinel)
				return 0;
			return p?p->height:0;
		}
		int balancefactor(setNode<T>* p){
			if (p->isSentinel)
				return 0;
			return height(p->right)-height(p->left);
		}
		void fixheight(setNode<T>* p)
		{
			if (p->isSentinel)
				return;
			int hl = height(p->left);
			int hr = height(p->right);
			p->height = (hl>hr?hl:hr)+1;
		}
		setNode<T>* rotateright(setNode<T>* p) // правый поворот вокруг p
		{
			setNode<T>* q = p->left;
			p->left = q->right;
			q->right = p;
			fixheight(p);
			fixheight(q);
			q->parent = p->parent;
			p->parent = q;
			if (q->parent == NULL)
			{
				root = q;
			}
			return q;
		}

		setNode<T>* rotateleft(setNode<T>* q) // левый поворот вокруг q
		{
			setNode<T>* p = q->right;
			q->right = p->left;
			p->left = q;
			fixheight(q);
			fixheight(p);
			p->parent = q->parent;
			q->parent = p;
			if (p->parent == NULL)
			{
				root = p;
			}
			
			return p;
		}
		setNode<T>* balance(setNode<T>* p) // балансировка узла p
		{
			fixheight(p);
			if( balancefactor(p)==2 )
			{
				if( balancefactor(p->right) < 0 )
					p->right = rotateright(p->right);
				return rotateleft(p);
			}
			if( balancefactor(p)==-2 )
			{
				if( balancefactor(p->left) > 0  )
					p->left = rotateleft(p->left);
				return rotateright(p);
			}
			return p; // балансировка не нужна
		}
		setNode<T>* findmin(setNode<T>* p) const// поиск узла с минимальным ключом в дереве p 
		{
			if (p && (p->isSentinel || (p->left && p->left->isSentinel)))
				return p;
			return p->left?findmin(p->left):p;
		}
		setNode<T>* findmax(setNode<T>* p) // поиск узла с максимальным ключом в дереве p 
		{
			if (p && (p->isSentinel || (p->right && p->right->isSentinel)))
				return p;
			return p->right?findmax(p->right):p;
		}
		setNode<T>* removemin(setNode<T>* p) // удаление узла с минимальным ключом из дерева p
		{
			if(p && (p->left==0 || p->left->isSentinel) )//
				return p->right;
			p->left = removemin(p->left);
			return balance(p);
		}
		setNode<T>* removemax(setNode<T>* p) // удаление узла с максимальным ключом из дерева p
		{
			if(p && (p->right==0 || p->right->isSentinel) )//
				return p->left;
			p->right = removemax(p->right);
			return balance(p);
		}
		setNode<T>* remove(setNode<T>* p, key_type k) //? удаление ключа k из дерева p
		{
			if( !p || p->isSentinel) return 0;
			if( k < p->val )
				p->left = remove(p->left,k);
			else if( k > p->val )
				p->right = remove(p->right,k);
			else //  k == p->key 
			{
				setNode<T>* par = p->parent;
				setNode<T>* q = p->left;
				setNode<T>* r = p->right;
				bzero(p, sizeof(setNode<T>));
				delete p;
				if (!r && !q )//
					return NULL;//
				if( (!r || r == lastSentinel)){
					if (par){
						par->left = q;
						if (q)
							q->parent = par;
					}
					return q;
				}
				setNode<T>* min = findmin(r);
				if (!min->isSentinel){
					min->right = removemin(r);
					min->left = q;
				}
				if (min->right){
					min->right->parent = min;
				}
				if (min->left){
					
					min->left->parent = min;
				}
				min->parent = par;
				return balance(min);
			}
			return balance(p);
		}

		setNode<T>* insertRecursively(setNode<T>* p, setNode<T> *ins, bool direction) // вставка ключа k в дерево с корнем p
		{
			ins->parent = p;//?
			if((!p->left || p->left == firstSentinel) && direction){//!p->left ||
				if (comp(ins->val, p->val))
				{
					bool flag = (p->left);//
					p->left = ins;
					if (flag){//
						ins->left = firstSentinel;
						firstSentinel->parent = ins;
					}
				}
				else if((!p->right || p->right == lastSentinel))
					p->right = ins;
				else
					p->right = insertRecursively(p->right, ins, false);
			}
			else if((!p->right || p->right == lastSentinel) && !direction){//!p->right ||
				if (comp(p->val, ins->val))
				{
					bool flag = (p->right);//
					p->right = ins;
					if (flag){//
						ins->right = lastSentinel;
						lastSentinel->parent = ins;
					}
				}
				else if((!p->left || p->left == firstSentinel))
					p->left = ins;
				else
					p->left = insertRecursively(p->left, ins, true);
			}
			else if (comp(ins->val, p->val))
				p->left = insertRecursively(p->left, ins, true);
			else
				p->right = insertRecursively(p->right, ins, false);
			return balance(p);
		}

		class value_compare
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class set;
			protected:
				std::less<T> comp;
				value_compare (std::less<T> c) : comp(c) {}  // constructed with set's comparison object
			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x, y);
			}
		};

		size_type setSize;
		setNode<T> *root;
		setNode<T> *firstSentinel;
		setNode<T> *lastSentinel;
		key_compare	comp;
		// value_compare vc(std::less<KEY> c);

	public:
		//CONSTRUCTORS
		explicit set() : setSize(0), root(NULL) {
			firstSentinel = new setNode<T>; 
			firstSentinel->isSentinel = true;
			firstSentinel->height = 0;
			lastSentinel = new setNode<T>; 
			lastSentinel->isSentinel = true;
			lastSentinel->height = 0;
		}
		set(const set &arg) : setSize(0), root(NULL){
			firstSentinel = new setNode<T>; 
			firstSentinel->isSentinel = true;
			firstSentinel->height = 0;
			lastSentinel = new setNode<T>; 
			lastSentinel->isSentinel = true;
			lastSentinel->height = 0;
			*this = arg; //operator=
		}//copy

		template <class InputIterator>
  		set (InputIterator first, InputIterator last) : setSize(0), root(NULL){
			firstSentinel = new setNode<T>; 
			firstSentinel->isSentinel = true;
			firstSentinel->height = 0;
			lastSentinel = new setNode<T>; 
			lastSentinel->isSentinel = true;
			lastSentinel->height = 0;
			insert(first, last);
		}
		//DESTRUCTOR
		virtual ~set(){
			if (root)
				clear();
			delete firstSentinel;
			delete lastSentinel;
		}
		//OPERATOR=
		set& operator=(const set &arg){
			clear();
			
			root = NULL;
			setSize = 0;
			comp = arg.comp;
			insert(arg.begin(), arg.end());
			return *this;
		}

		iterator begin(){
			return ++iterator(firstSentinel);
		}
		const_iterator begin() const{
			return const_iterator(reinterpret_cast<setNode<const T>*>(findmin(root)));//reinterpret_cast<setNode<const T>*>
		}
		iterator end(){
			return iterator(lastSentinel);
		}
		const_iterator end() const{
			return const_iterator(reinterpret_cast<setNode<const T>*>(lastSentinel));
		}
		reverse_iterator rbegin(){
			return ++reverse_iterator(lastSentinel);
		}
		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(reinterpret_cast<setNode<const T>*>(findmax(root)));
		}
		reverse_iterator rend(){
			return reverse_iterator(firstSentinel);
		}
		const_reverse_iterator rend() const{
			return const_reverse_iterator(reinterpret_cast<setNode<const T>*>(firstSentinel));
		}
		//CAPACITY
		bool empty() const{
			return setSize == 0;
		}
		size_type size() const{
			return setSize;
		}
		size_type max_size() const{
			size_type distance = std::numeric_limits<difference_type>::max() / MS;
			// size_type amount = std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;//why do we need to divide by two
			return distance;
		}

		//MODIFIERS
		std::pair<iterator, bool> insert (const value_type& val){
			if (setSize == 0){
				root = new setNode<T>;
				root->isSentinel = false;
				root->left = firstSentinel;
				root->right = lastSentinel;
				root->val = val;
				firstSentinel->parent = root;
				lastSentinel->parent = root;
				setSize++;
				return std::pair<iterator, bool>(iterator(root), true);
			}
			else{
				setNode<T> *ins = new setNode<T>;
				ins->val = val;
				ins->isSentinel = false;
				iterator ite = find(ins->val);
				if (ite != end()){ //root->val == ins->val
					delete ins;
					return std::pair<iterator, bool>(iterator(ite), false);
				}
				insertRecursively(root, ins, comp(ins->val, root->val));
				setSize++;
				return std::pair<iterator, bool>(iterator(ins), true);
			}
		}//single
		iterator insert (iterator position, const value_type& val){
			setNode<T> *ins = new setNode<T>;
			ins->val = val;
			ins->isSentinel = false;
			iterator ite = find(ins->val);
			if (ite != end()){ //root->val == ins->val
				delete ins;
				return iterator(ite);
			}
			if (position.currentPtr && (((!position.currentPtr->left || position.currentPtr->left->isSentinel) && comp(ins->val, position.currentPtr->val)) || ((!position.currentPtr->right || position.currentPtr->right->isSentinel) && !comp(ins->val, position.currentPtr->val))))
			{
				if ((position.currentPtr == firstSentinel && !comp(ins->val, position.currentPtr->parent->val)) || (position.currentPtr == lastSentinel && comp(ins->val, position.currentPtr->parent->val))){
					delete ins;
					std::pair<iterator, bool> tmp = insert(val);
					return iterator(tmp.first.currentPtr);
				}
					insertRecursively(position.currentPtr, ins, comp(ins->val, position.currentPtr->val));
					setSize++;
					return iterator(ins);
			}
			else
			{
				delete ins;
				std::pair<iterator, bool> tmp = insert(val);
				return iterator(tmp.first.currentPtr);
			}
		}//with hint!
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last){
			const_iterator it = first;
			for (; it != last; it++)
			{
					insert(value_type(it.currentPtr->val));
			}	
		}//with range
		void erase (iterator position){
			if(setSize == 0)
				return;
			setNode<T> *par = position.currentPtr->parent;
			if (par){
				if (par->right == position.currentPtr)
				{
					par->right = remove(position.currentPtr, position.currentPtr->val);
				}
				else
				{
					par->left = remove(position.currentPtr, position.currentPtr->val);
				}
				while (par != NULL)
				{
					balance(par);
					par = par->parent;
				}
			}
			else
			{
				setNode<T> *l = position.currentPtr->left;
				setNode<T> *r = position.currentPtr->right;

				if (l && l->parent == position.currentPtr)
				{
					l->parent = remove(position.currentPtr, position.currentPtr->val);
					root = l->parent;
				}
				else if(r && r->parent == position.currentPtr)
				{
					r->parent = remove(position.currentPtr, position.currentPtr->val);
					root = r->parent;
				}
				else
				{
					remove(position.currentPtr, position.currentPtr->val);
					root = NULL;
				}
			}
			setSize--;
		}
		size_type erase (const key_type& k){
			iterator tmp = find(k);
			if (tmp == end())
				return 0;
			erase(tmp);
			return 1;
		}
		void erase (iterator first, iterator last){
			for(iterator it = first; it != last;){
				iterator tmp = it++;
				erase(tmp);
			}
		}
		void swap (set& x){
			setNode<T> *tmp;
			size_type size;

			tmp = root;
			root = x.root;
			x.root = tmp;
			tmp = lastSentinel;
			lastSentinel = x.lastSentinel;
			x.lastSentinel = tmp;
			tmp = firstSentinel;
			firstSentinel = x.firstSentinel;
			x.firstSentinel = tmp;
			size = setSize;
			setSize = x.setSize;
			x.setSize = size;
		}
		void clear(){
			if(root)
				erase(begin(), end());
		}

		key_compare key_comp() const {return comp;}
		value_compare value_comp() const {this->value_compare();}

		iterator find(const key_type& k){
			setNode<T> *tmp = root;
			for (; tmp != firstSentinel && tmp != lastSentinel && tmp != NULL;)
			{
				if (k == tmp->val)
				{
					return iterator(tmp);
				}
				if (k < tmp->val)
				{
					tmp = tmp->left;
				}
				else
				{
					tmp = tmp->right;
				}	
			}
			return iterator(lastSentinel);
		}
		const_iterator find(const key_type& k) const{
			setNode<T> *tmp = root;
			for (; tmp != firstSentinel && tmp != lastSentinel && tmp != NULL;)
			{
				if (k == tmp->val)
				{
					return const_iterator(reinterpret_cast<setNode<const T> *>(tmp));
				}
				if (k < tmp->val)
				{
					tmp = tmp->left;
				}
				else
				{
					tmp = tmp->right;
				}	
			}
			return const_iterator(reinterpret_cast<setNode<const T> *>(lastSentinel));
		}
		size_type count (const key_type& k) const{
			if ( find(k) != end())
				return 1;
			else
				return 0;
		}
		iterator lower_bound (const key_type& k){
			iterator tmp = find(k);
			if (tmp != end())
				return tmp;
			iterator f = begin();
			iterator l = end();

			for(;f != l;f++){
				if (comp(k, f.currentPtr->val))
					return f;
			}
			return end();
		}
		const_iterator lower_bound (const key_type& k) const{
			const_iterator tmp = find(k);
			if (tmp != end())
				return tmp;
			const_iterator f = begin();
			const_iterator l = end();

			for(;f != l;f++){
				if (comp(k, f.currentPtr->val))
					return f;
			}
			return end();
		}
		iterator upper_bound (const key_type& k){
			iterator tmp = find(k);
			if (tmp != end())
				return ++tmp;
			iterator f = begin();
			iterator l = end();

			for(;f != l;f++){
				if (comp(k, f.currentPtr->val))
					return f;
			}
			return end();
		}
		const_iterator upper_bound (const key_type& k) const{
			const_iterator tmp = find(k);
			if (tmp != end())
				return ++tmp;
			const_iterator f = begin();
			const_iterator l = end();

			for(;f != l;f++){
				if (comp(k, f.currentPtr->val))
					return f;
			}
			return end();
		}
		std::pair<iterator,iterator>	equal_range (const key_type& k){
			iterator tmp = find(k);
			if (tmp != end()){
				iterator temp = tmp++;
				return std::pair<iterator,iterator>(temp, tmp);
			}
				

			iterator f = begin();
			iterator l = end();

			for(;f != l;f++){
				if (comp(k, f.currentPtr->val)){
					iterator fe = f++;
					return std::pair<iterator,iterator>(fe, f);
				}
			}
			return std::pair<iterator,iterator>(f, f);;
		}
		std::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const{
			const_iterator tmp = find(k);
			if (tmp != end()){
				const_iterator temp = tmp++;
				return std::pair<const_iterator,const_iterator>(temp, tmp);
			}

			const_iterator f = begin();
			const_iterator l = end();

			for(;f != l;f++){
				if (comp(k, f.currentPtr->val)){
					const_iterator fe = f++;
					return std::pair<const_iterator,const_iterator>(fe, f);
				}
			}
			return std::pair<const_iterator,const_iterator>(f, f);;
		}
	};

	template < class T>
	void swap(set<T> &x, set<T> &y)
	{
		x.swap(y);
	}

	template < class T>
	bool operator==(set<T> &x, set<T> &y){
		if (x.size() != y.size()){
			return false;
		}
		setIterator<T> f1 = x.begin();
		setIterator<T> l1 = x.end();
		setIterator<T> f2 = y.begin();
		setIterator<T> l2 = y.end();

		for (; f1 != l1; f1++, f2++)
			if (f1.getCurrentPtr()->val != f2.getCurrentPtr()->val)
				return false;
		return true;
	}

	template <class T>
	bool operator!=(set<T> &x, set<T> &y){
		return !(x == y);
	}

	template <class T, class Compare>
	bool operator<(set<T, Compare> &x, set<T, Compare> &y){

		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class T, class Compare>
	bool operator>(set<T, Compare> &x, set<T, Compare> &y){

		return !(x < y) && !(x == y);
	}

	template <class T, class Compare>
	bool operator>=(set<T, Compare> &x, set<T, Compare> &y){

		return !(x < y);
	}

	template <class T, class Compare>
	bool operator<=(set<T, Compare> &x, set<T, Compare> &y){

		return !(x > y);
	}
}


#endif