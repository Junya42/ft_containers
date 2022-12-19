#ifndef MAP_HPP
#define MAP_HPP

#include <alloca.h>
#include <iostream>
#include <memory>

#include "utils/pair.hpp"
#include "utils/node.hpp"
#include "utils/red_black.hpp"
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/equal.hpp"
#include "iterator/bidirectional_iterator.hpp"
#include "iterator/iterator_traits.hpp"
#include "iterator/reverse_iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map {
			
			public:

				typedef	Key											key_type;
				typedef	T											mapped_type;
				typedef	Compare										key_compare;
				typedef Alloc										allocator_type;
				typedef ft::pair<const key_type, mapped_type>		value_type;

				typedef typename    allocator_type::difference_type 								difference_type;
				typedef typename    allocator_type::size_type 										size_type;
				typedef typename    allocator_type::reference 										reference;
				typedef typename    allocator_type::const_reference 								const_reference;
				typedef typename    allocator_type::pointer 										pointer;
				typedef typename    allocator_type::const_pointer 									const_pointer;
				typedef typename	ft::Tree<value_type, key_compare, allocator_type>::iterator		iterator;
				typedef typename 	ft::Tree<value_type, key_compare, allocator_type>::const_iterator	const_iterator;
				typedef typename    ft::reverse_iterator<iterator> 									reverse_iterator;
				typedef typename    ft::reverse_iterator<const_iterator> 							const_reverse_iterator;

				class value_compare
				{
					friend class ft::map< Key, T, Compare, Alloc>;

					protected:

						key_compare comp;
						value_compare (key_compare c) : comp(c) {}

					public:

						typedef bool result_type;
						typedef value_type first_argument_type;
						typedef value_type second_argument_type;

						bool operator()(const value_type& x, const value_type& y) const {
							return comp(x.first, y.first);
						}
				};

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _cmp(comp), _alloc(alloc), _size(0) {
				}

				template <class InputIterator>
					map(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _cmp(comp), _alloc(alloc), _size(0) {
						while (first != last) {
							insert(*first);
							first++;
						}
					}

				map(const map& x) : _size(0) {
					*this = x;
				}

				map& operator=(const map& x) {
					if (*this != x) {
						//if (_size)
						//	clear();
						_cmp = x._cmp;
						_alloc = x._alloc;
						_root.clear();
						insert(x.begin(), x.end());
						_size = x._size;
					}
					return *this;
				}

				~map(void) {
					//clear();
				}

				/***** ITERATOR *****/

				iterator	begin(void) {
					return _root.begin();
				}

				const_iterator	begin(void) const {
					return _root.const_begin();
				}

				iterator	end(void) {
					return	_root.end();
				}

				const_iterator	end(void) const {
					return _root.const_end();
				}

				reverse_iterator	rbegin(void) {
					return reverse_iterator(_root.end());
				}

				const_reverse_iterator	rbegin(void) const {
					return const_reverse_iterator(_root.const_end());
				}

				reverse_iterator	rend(void) {
					return reverse_iterator(_root.begin());
				}

				const_reverse_iterator	rend(void) const {
					return const_reverse_iterator(_root.const_begin());
				}

				/***** CAPACITY *****/

				bool	empty(void) const {
					if (_size)
						return false;
					return true;
				}

				size_type	size(void) const {
					return _size;
				}

				size_type	max_size(void) const {
					return _root.max_size();
				}

				/***** ELEMENT ACCESS *****/

				mapped_type&	operator[](const key_type& k) {
					return	(*((insert(ft::make_pair(k, mapped_type()))).first)).second;
				}

				/***** MODIFIERS *****/

				pair<iterator, bool>	insert(const value_type& val) {
					ft::pair<iterator, bool>	tmp;

					tmp = _root.insert(val);
					if (tmp.second)
						_size++;
					return tmp;
				}

				iterator	insert(iterator position, const value_type& val) {
					ft::pair<iterator, bool>	tmp;

					tmp = _root.insert(position, val);
					if (!tmp.second)
						return insert(val).first;
					if (tmp.second)
						_size++;
					return tmp.first;
				}

				template <class InputIterator>
					void	insert(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
						//ft::pair<iterator, bool>	tmp;
						while (first != last) {
							//tmp = insert(*first);
							insert(*first);
							first++;
							//if (tmp.second)
							//	_size++;
						}
					}

				void	erase(iterator position) {
					erase(position->first);
				}

				size_type	erase(const key_type& k) {
					ft::pair<iterator, bool>	tmp;

					tmp = _root.get_delete_node_ptr(k);
					if (tmp.second) {
						_size--;
					}
					return tmp.second;
				}

				void	erase(iterator first, iterator last) {
					//if (first == _root.begin() && last == _root.end()) {
				//		clear();
				//		return ;
				//	}
					iterator	tmp;
					
					while (first != last) {
						tmp = first;
						first++;
						erase(tmp->first);
					}
				}

				void	swap(map& x) {
					key_compare		key;
					size_type		size;
					allocator_type	alloc;

					key = _cmp;
					size = _size;
					alloc = _alloc;

					_cmp = x._cmp;
					_size = x._size;
					_alloc = x._alloc;

					x._cmp = key;
					x._size = size;
					x._alloc = alloc;

					_root.swap(x._root);
				}

				void	clear(void) {
					_root.clear();
					_size = 0;
				}

				/***** OBSERVERS *****/

				key_compare	key_comp(void) const {
					return	_cmp;
				}

				value_compare	value_comp(void) const {
					return	value_compare(_cmp);
				}

				/***** OPERATIONS *****/

				iterator	find(const key_type& k) {
					return	_root.find(k);
				}

				const_iterator	find(const key_type& k) const {
					return	_root.find(k);
				}

				size_type	count(const key_type& k) const {
					return	_root.count(k);
				}

				iterator	lower_bound(const key_type& k) {
					return	_root.lower_bound(k);
				}

				const_iterator	lower_bound(const key_type& k) const {
					return	_root.lower_bound(k);
				}

				iterator	upper_bound(const key_type& k) {
					return	_root.upper_bound(k);
				}

				const_iterator	upper_bound(const key_type& k) const {
					return	_root.upper_bound(k);
				}

				ft::pair<iterator, iterator>	equal_range(const key_type& k) {
					return	ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k));
				}

				ft::pair<const_iterator, const_iterator>	equal_range(const key_type& k) const {
					return	ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
				}

				/***** ALLOCATOR *****/

				allocator_type	get_allocator(void) const {
					return _alloc;
				}

				Tree<value_type, key_compare, allocator_type>	get_root(void) const {
					return _root;
				}

			private:

				Tree<value_type, key_compare, allocator_type> _root;
				key_compare	_cmp;
				allocator_type	_alloc;
				size_type		_size;
		};

	template <class Key, class T, class Compare, class Alloc>
		void	swap(ft::map<Key, T, Compare, Alloc>&lhs, ft::map<Key, T, Compare, Alloc>& rhs) {
			if (lhs == rhs)
				return ;
			lhs.swap(rhs);
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			if ( lhs.size() != rhs.size() )
				return false;
			typename map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
			typename map<Key, T, Compare, Alloc>::const_iterator ite = lhs.end();
			typename map<Key, T, Compare, Alloc>::const_iterator rit = rhs.begin();

			while (it != ite && rit != rhs.end()) {
				if ( it->first != rit->first || it->second != rit->second )
					return false;
				it++;
				rit++;
			}
			if (it != ite || rit != rhs.end())
				return false;
			return true;
		}

	template <class Key, class T, class Compare, class Alloc>
		bool	operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			return	!(lhs == rhs);
		}
	template <class Key, class T, class Compare, class Alloc>
		bool	operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class Key, class T, class Compare, class Alloc>
		bool	operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			return !(rhs < lhs);
		}
	template <class Key, class T, class Compare, class Alloc>
		bool	operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			return rhs < lhs;
		}
	template <class Key, class T, class Compare, class Alloc>
		bool	operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
			return	!(lhs < rhs);
		}
}

#endif
