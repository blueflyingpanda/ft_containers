#ifndef MAP_H
#define MAP_H

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

	//NODE
	template <class KEY, class T>
	class treeNode 
	{
	private:
		treeNode(const treeNode &arg);
		treeNode &operator=(const treeNode &arg);
	public:
		int height;
		std::pair<KEY,T>	pair;
		treeNode* parent;
		treeNode* left;
		treeNode* right;
		bool isSentinel;
		treeNode() {isSentinel = false; parent = left = right = NULL; height = 1; }
		~treeNode() {}
	};

	//ITERATOR
	template < class KEY, class T >
	class mapIterator{
	protected:
		treeNode<KEY, T> *currentPtr;
		treeNode<KEY, T> *getCurrentPtr(){
			return currentPtr;
		}
	public:
		typedef T	value_type;
		typedef T&	reference;
		typedef T*	pointer;

		mapIterator(){}
		mapIterator(const mapIterator &arg) : currentPtr(arg.currentPtr) {}
		mapIterator(treeNode<KEY, T> *ptr) : currentPtr(/*const_cast<treeNode<KEY, T> *>*/(ptr)) {}
		// mapIterator(treeNode<KEY, T> *ptr, bool f) {
		// 	if (!f)
		// 		currentPtr = /*reinterpret_cast<treeNode<KEY, T> *>*/(ptr);
		// }
		virtual ~mapIterator(){}

		mapIterator &operator=(const mapIterator &rhs){
			currentPtr = rhs.currentPtr;
			return *this;
		}

		mapIterator	&operator++(){
			treeNode<KEY, T> *ptr = currentPtr;
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
		mapIterator	operator++(int){
			mapIterator tmp = *this;
			++(*this);
			return tmp;
		}
		mapIterator	&operator--(){
			treeNode<KEY, T> *ptr = currentPtr;
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
		mapIterator	operator--(int){
			mapIterator tmp = *this;
			--(*this);
			return tmp;
		}
		std::pair<KEY, T>	&operator*(){
			return currentPtr->pair;
		}
		std::pair<KEY, T>	*operator->(){
			return &currentPtr->pair;
		}

		template < class K, class TYPE, class Compare >
		friend class map;

		template < class K, class TYPE >
		friend bool operator==(const mapIterator<K, TYPE> lhs, const mapIterator<K, TYPE> rhs);

		template < class K, class TYPE >
		friend bool operator!=(const mapIterator<K, TYPE> lhs, const mapIterator<K, TYPE> rhs);

	};

	template < class KEY, class T >
	bool operator==(const mapIterator<KEY, T> lhs, const mapIterator<KEY, T> rhs){
		return lhs.currentPtr == rhs.currentPtr;
	}

	template < class KEY, class T >
	bool operator!=(const mapIterator<KEY, T> lhs, const mapIterator<KEY, T> rhs){
		return lhs.currentPtr != rhs.currentPtr;
	}

	//REVERSE ITERATOR
	template < class KEY, class T >
	class mapReverseIterator{
	protected:
		treeNode<KEY, T> *currentPtr;
	public:
		typedef T	value_type;
		typedef T&	reference;
		typedef T*	pointer;

		mapReverseIterator(){}
		mapReverseIterator(const mapReverseIterator &arg) : currentPtr(arg.currentPtr) {}
		mapReverseIterator(treeNode<KEY, T> *ptr) : currentPtr(const_cast<treeNode<KEY, T> *>(ptr)) {}
		virtual ~mapReverseIterator(){}

		mapReverseIterator &operator=(const mapReverseIterator &rhs){
			currentPtr = rhs.currentPtr;
			return *this;
		}

		mapReverseIterator	&operator++(){
			treeNode<KEY, T> *ptr = currentPtr;
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
		mapReverseIterator	operator++(int){
			mapReverseIterator tmp = *this;
			++(*this);
			return tmp;
		}
		mapReverseIterator	&operator--(){
			treeNode<KEY, T> *ptr = currentPtr;
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
		mapReverseIterator	operator--(int){
			mapReverseIterator tmp = *this;
			--(*this);
			return tmp;
		}
		std::pair<KEY, T>	&operator*(){
			return currentPtr->pair;
		}
		std::pair<KEY, T>	*operator->(){
			return &currentPtr->pair;
		}

		template < class K, class TYPE, class Compare >
		friend class map;

		template < class K, class TYPE >
		friend bool operator==(const mapReverseIterator<K, TYPE> lhs, const mapReverseIterator<K, TYPE> rhs);

		template < class K, class TYPE >
		friend bool operator!=(const mapReverseIterator<K, TYPE> lhs, const mapReverseIterator<K, TYPE> rhs);

	};

	template < class KEY, class T >
	bool operator==(const mapReverseIterator<KEY, T> lhs, const mapReverseIterator<KEY, T> rhs){
		return lhs.currentPtr == rhs.currentPtr;
	}

	template < class KEY, class T >
	bool operator!=(const mapReverseIterator<KEY, T> lhs, const mapReverseIterator<KEY, T> rhs){
		return lhs.currentPtr != rhs.currentPtr;
	}
	/*
	// template < class KEY, class T >
	// class constMapIterator : public mapIterator<KEY, T>{
	// public:
	// 	constMapIterator() {}
	// 	constMapIterator(const constMapIterator &arg) {
	// 		this->currentPtr = arg.currentPtr;
	// 	}
	// 	constMapIterator(treeNode<KEY, T> *ptr) {
	// 		this->currentPtr = const_cast<treeNode<KEY, T> *>(ptr); 
	// 	}
	// 	~constMapIterator() {}
	// 	constMapIterator &operator=(const constMapIterator &rhs){
	// 		this->currentPtr = rhs.currentPtr;
	// 		return *this;
	// 	}
	// 	std::pair<KEY, T>	*operator->(){
	// 		return &this->currentPtr->pair;
	// 	}
	// };
	*/
	template < class KEY, class T, class Compare = std::less<KEY> >
	class map
	{
	public:
		typedef KEY key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;

		typedef mapIterator<KEY, T> iterator;
		// typedef constMapIterator<KEY, T> const_iterator;
		typedef mapIterator<KEY, const T> const_iterator;
		typedef mapReverseIterator<KEY, T> reverse_iterator;
		typedef mapReverseIterator<KEY, const T> const_reverse_iterator;
	private:
		int height(treeNode<KEY, T>* p){
			if (p == lastSentinel)
				return 0;
			return p?p->height:0;
		}
		int balancefactor(treeNode<KEY, T>* p){
			if (p->isSentinel)
				return 0;
			return height(p->right)-height(p->left);
		}
		void fixheight(treeNode<KEY, T>* p)
		{
			if (p->isSentinel)
				return;
			int hl = height(p->left);
			int hr = height(p->right);
			p->height = (hl>hr?hl:hr)+1;
		}
		treeNode<KEY, T>* rotateright(treeNode<KEY, T>* p) // правый поворот вокруг p
		{
			treeNode<KEY, T>* q = p->left;
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

		treeNode<KEY, T>* rotateleft(treeNode<KEY, T>* q) // левый поворот вокруг q
		{
			treeNode<KEY, T>* p = q->right;
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
		treeNode<KEY, T>* balance(treeNode<KEY, T>* p) // балансировка узла p
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
		treeNode<KEY, T>* findmin(treeNode<KEY, T>* p) const// поиск узла с минимальным ключом в дереве p 
		{
			if (p && (p->isSentinel || (p->left && p->left->isSentinel)))
				return p;
			return p->left?findmin(p->left):p;
		}
		treeNode<KEY, T>* findmax(treeNode<KEY, T>* p) // поиск узла с максимальным ключом в дереве p 
		{
			if (p && (p->isSentinel || (p->right && p->right->isSentinel)))
				return p;
			return p->right?findmax(p->right):p;
		}
		treeNode<KEY, T>* removemin(treeNode<KEY, T>* p) // удаление узла с минимальным ключом из дерева p
		{
			if(p && (p->left==0 || p->left->isSentinel) )//
				return p->right;
			p->left = removemin(p->left);
			return balance(p);
		}
		treeNode<KEY, T>* removemax(treeNode<KEY, T>* p) // удаление узла с максимальным ключом из дерева p
		{
			if(p && (p->right==0 || p->right->isSentinel) )//
				return p->left;
			p->right = removemax(p->right);
			return balance(p);
		}
		treeNode<KEY, T>* remove(treeNode<KEY, T>* p, key_type k) //? удаление ключа k из дерева p
		{
			if( !p || p->isSentinel) return 0;
			if( k < p->pair.first )
				p->left = remove(p->left,k);
			else if( k > p->pair.first )
				p->right = remove(p->right,k);
			else //  k == p->key 
			{
				treeNode<KEY, T>* par = p->parent;
				treeNode<KEY, T>* q = p->left;
				treeNode<KEY, T>* r = p->right;
				bzero(p, sizeof(treeNode<KEY, T>));
				delete p;
				if (!r && !q )//
					return NULL;//
				if( !r ){
					if (par){
						par->left = q;
						if (q)
							q->parent = par;
					}
					return q;
				}
				treeNode<KEY, T>* min = findmin(r);
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

		treeNode<KEY, T>* insertRecursively(treeNode<KEY, T>* p, treeNode<KEY, T> *ins, bool direction) // вставка ключа k в дерево с корнем p
		{
			ins->parent = p;//?
			if((!p->left || p->left == firstSentinel) && direction){//!p->left ||
				if (comp(ins->pair.first, p->pair.first))
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
				if (comp(p->pair.first, ins->pair.first))
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
			else if (comp(ins->pair.first, p->pair.first))
				p->left = insertRecursively(p->left, ins, true);
			else
				p->right = insertRecursively(p->right, ins, false);
			return balance(p);
		}

		class value_compare
		{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
			protected:
				std::less<KEY> comp;
				value_compare (std::less<KEY> c) : comp(c) {}  // constructed with map's comparison object
			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		};

		size_type mapSize;
		treeNode<KEY, T> *root;
		treeNode<KEY, T> *firstSentinel;
		treeNode<KEY, T> *lastSentinel;
		key_compare	comp;
		// value_compare vc(std::less<KEY> c);

	public:
		//CONSTRUCTORS
		explicit map() : mapSize(0), root(NULL) {
			firstSentinel = new treeNode<KEY, T>; 
			firstSentinel->isSentinel = true;
			firstSentinel->height = 0;
			lastSentinel = new treeNode<KEY, T>; 
			lastSentinel->isSentinel = true;
			lastSentinel->height = 0;
		}
		map(const map &arg) : mapSize(0), root(NULL){
			firstSentinel = new treeNode<KEY, T>; 
			firstSentinel->isSentinel = true;
			firstSentinel->height = 0;
			lastSentinel = new treeNode<KEY, T>; 
			lastSentinel->isSentinel = true;
			lastSentinel->height = 0;
			*this = arg; //operator=
		}//copy

		template <class InputIterator>
  		map (InputIterator first, InputIterator last) : mapSize(0), root(NULL){
			firstSentinel = new treeNode<KEY, T>; 
			firstSentinel->isSentinel = true;
			firstSentinel->height = 0;
			lastSentinel = new treeNode<KEY, T>; 
			lastSentinel->isSentinel = true;
			lastSentinel->height = 0;
			insert(first, last);
		}
		//DESTRUCTOR
		virtual ~map(){
			if (root)
				clear();
			delete firstSentinel;
			delete lastSentinel;
		}
		//OPERATOR=
		map& operator=(const map &arg){
			clear();
			
			root = NULL;
			mapSize = 0;
			comp = arg.comp;
			insert(arg.begin(), arg.end());
			return *this;
		}

		iterator begin(){
			return ++iterator(firstSentinel);
		}
		const_iterator begin() const{
			return const_iterator(reinterpret_cast<treeNode<KEY, const T>*>(findmin(root)));//reinterpret_cast<treeNode<KEY, const T>*>
		}
		iterator end(){
			return iterator(lastSentinel);
		}
		const_iterator end() const{
			return const_iterator(reinterpret_cast<treeNode<KEY, const T>*>(lastSentinel));
		}
		reverse_iterator rbegin(){
			return ++reverse_iterator(lastSentinel);
		}
		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(reinterpret_cast<treeNode<KEY, const T>*>(findmax(root)));
		}
		reverse_iterator rend(){
			return reverse_iterator(firstSentinel);
		}
		const_reverse_iterator rend() const{
			return const_reverse_iterator(reinterpret_cast<treeNode<KEY, const T>*>(firstSentinel));
		}
		//CAPACITY
		bool empty() const{
			return mapSize == 0;
		}
		size_type size() const{
			return mapSize;
		}
		size_type max_size() const{
			size_type distance = std::numeric_limits<difference_type>::max();
			size_type amount = std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;//why do we need to divide by two
			return distance < amount ? distance : amount;
		}
		//ACCESS
		mapped_type& operator[] (const key_type& k){
			iterator tmp = find(k);
			if (tmp != end())
				return tmp.currentPtr->pair.second;
			else
			{
				std::pair<iterator, bool> ite = insert(std::make_pair(k, mapped_type()));
				return ite.first.currentPtr->pair.second;
			}
		}
		//MODIFIERS
		std::pair<iterator, bool> insert (const value_type& val){
			if (mapSize == 0){
				root = new treeNode<KEY, T>;
				root->isSentinel = false;
				root->left = firstSentinel;
				root->right = lastSentinel;
				root->pair = val;
				firstSentinel->parent = root;
				lastSentinel->parent = root;
				mapSize++;
				return std::pair<iterator, bool>(iterator(root), true);
			}
			else{
				treeNode<KEY, T> *ins = new treeNode<KEY, T>;
				ins->pair = val;
				ins->isSentinel = false;
				iterator ite = find(ins->pair.first);
				if (ite != end()){ //root->pair.first == ins->pair.first
					delete ins;
					return std::pair<iterator, bool>(iterator(ite), false);
				}
				insertRecursively(root, ins, comp(ins->pair.first, root->pair.first));
				mapSize++;
				return std::pair<iterator, bool>(iterator(ins), true);
			}
		}//single
		iterator insert (iterator position, const value_type& val){
			treeNode<KEY, T> *ins = new treeNode<KEY, T>;
			ins->pair = val;
			ins->isSentinel = false;
			iterator ite = find(ins->pair.first);
			if (ite != end()){ //root->pair.first == ins->pair.first
				delete ins;
				return iterator(ite);
			}
			if (position.currentPtr && (((!position.currentPtr->left || position.currentPtr->left->isSentinel) && comp(ins->pair.first, position.currentPtr->pair.first)) || ((!position.currentPtr->right || position.currentPtr->right->isSentinel) && !comp(ins->pair.first, position.currentPtr->pair.first))))
			{
				if ((position.currentPtr == firstSentinel && !comp(ins->pair.first, position.currentPtr->parent->pair.first)) || (position.currentPtr == lastSentinel && comp(ins->pair.first, position.currentPtr->parent->pair.first))){
					delete ins;
					std::pair<iterator, bool> tmp = insert(val);
					return iterator(tmp.first.currentPtr);
				}
					insertRecursively(position.currentPtr, ins, comp(ins->pair.first, position.currentPtr->pair.first));
					mapSize++;
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
			// iterator prev = iterator(first.currentPtr, false);
			for (; it != last; it++)
			{
				// if (it != first){
				// 	insert(prev, std::pair<KEY, T>(it.currentPtr->pair.first, it.currentPtr->pair.second));
				// 	prev++;
				// }
				// else
					insert(std::pair<KEY, T>(it.currentPtr->pair.first, it.currentPtr->pair.second));
			}	
		}//with range
		void erase (iterator position){
			if(mapSize == 0)
				return;
			treeNode<KEY, T> *par = position.currentPtr->parent;
			if (par){
				if (par->right == position.currentPtr)
				{
					par->right = remove(position.currentPtr, position->first);
				}
				else
				{
					par->left = remove(position.currentPtr, position->first);
				}
				while (par != NULL)
				{
					balance(par);
					par = par->parent;
				}
			}
			else
			{
				treeNode<KEY, T> *l = position.currentPtr->left;
				treeNode<KEY, T> *r = position.currentPtr->right;

				if (l && l->parent == position.currentPtr)
				{
					l->parent = remove(position.currentPtr, position->first);
					root = l->parent;
				}
				else if(r && r->parent == position.currentPtr)
				{
					r->parent = remove(position.currentPtr, position->first);
					root = r->parent;
				}
				else
				{
					remove(position.currentPtr, position->first);
					root = NULL;
				}
			}
			mapSize--;
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
		void swap (map& x){
			treeNode<KEY, T> *tmp;
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
			size = mapSize;
			mapSize = x.mapSize;
			x.mapSize = size;
		}
		void clear(){
			if(root)
				erase(begin(), end());
		}

		key_compare key_comp() const {return comp;}
		value_compare value_comp() const {this->value_compare();}

		iterator find(const key_type& k){
			treeNode<KEY, T> *tmp = root;
			for (; tmp != firstSentinel && tmp != lastSentinel && tmp != NULL;)
			{
				if (k == tmp->pair.first)
				{
					return iterator(tmp);
				}
				if (k < tmp->pair.first)
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
			treeNode<KEY, T> *tmp = root;
			for (; tmp != firstSentinel && tmp != lastSentinel && tmp != NULL;)
			{
				if (k == tmp->pair.first)
				{
					return const_iterator(reinterpret_cast<treeNode<KEY, const T> *>(tmp));
				}
				if (k < tmp->pair.first)
				{
					tmp = tmp->left;
				}
				else
				{
					tmp = tmp->right;
				}	
			}
			return const_iterator(reinterpret_cast<treeNode<KEY, const T> *>(lastSentinel));
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
				if (comp(k, f->first))
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
				if (comp(k, f->first))
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
				if (comp(k, f->first))
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
				if (comp(k, f->first))
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
				if (comp(k, f->first)){
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
				if (comp(k, f->first)){
					const_iterator fe = f++;
					return std::pair<const_iterator,const_iterator>(fe, f);
				}
			}
			return std::pair<const_iterator,const_iterator>(f, f);;
		}
	};

	template <class KEY, class T>
	void swap(map<KEY, T> &x, map<KEY, T> &y)
	{
		x.swap(y);
	}

	template <class KEY, class T>
	bool operator==(map<KEY, T> &x, map<KEY, T> &y){
		if (x.size() != y.size()){
			return false;
		}
		mapIterator<KEY, T> f1 = x.begin();
		mapIterator<KEY, T> l1 = x.end();
		mapIterator<KEY, T> f2 = y.begin();
		mapIterator<KEY, T> l2 = y.end();

		for (; f1 != l1; f1++, f2++)
			if (f1->first != f2->first || f1->second != f2->second)
				return false;
		return true;
	}

	template <class KEY, class T>
	bool operator!=(map<KEY, T> &x, map<KEY, T> &y){
		return !(x == y);
	}

	template <class KEY, class T, class Compare>
	bool operator<(map<KEY, T, Compare> &x, map<KEY, T, Compare> &y){

		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class KEY, class T, class Compare>
	bool operator>(map<KEY, T, Compare> &x, map<KEY, T, Compare> &y){

		return !(x < y) && !(x == y);
	}

	template <class KEY, class T, class Compare>
	bool operator>=(map<KEY, T, Compare> &x, map<KEY, T, Compare> &y){

		return !(x < y);
	}

	template <class KEY, class T, class Compare>
	bool operator<=(map<KEY, T, Compare> &x, map<KEY, T, Compare> &y){

		return !(x > y);
	}
}

#endif