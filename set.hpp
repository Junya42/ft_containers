#ifndef SET_HPP
# define SET_HPP

#include <alloca.h>
#include <iostream>
#include <memory>

#include "utils/pair.hpp"
#include "utils/node.hpp"
#include "utils/set_red_black.hpp"
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/equal.hpp"
#include "iterator/bidirectional_iterator.hpp"
#include "iterator/iterator_traits.hpp"
#include "iterator/reverse_iterator.hpp"

namespace ft {

		template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
		class set {
			
			public:

				typedef	T											key_type;
				typedef	T											value_type;
				typedef	Compare										key_compare;
				typedef	Compare										value_compare;
				typedef Alloc										allocator_type;

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

				explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _cmp(comp), _alloc(alloc), _size(0) {
				}

				template <class InputIterator>
					set(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _cmp(comp), _alloc(alloc), _size(0) {
						while (first != last) {
							insert(*first);
							first++;
						}
					}

				set(const set& x) : _size(0) {
					*this = x;
				}

				set& operator=(const set& x) {
					if (*this != x) {
						if (_size)
							clear();
						_cmp = x._cmp;
						_alloc = x._alloc;
						insert(x.begin(), x.end());
						_size = x._size;
					}
					return *this;
				}

				~set(void) {
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
					return _alloc.max_size();
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
						while (first != last) {
							insert(*first);
							first++;
						}
					}

				void	erase(iterator position) {
					erase(*position);
				}

				size_type	erase(const value_type& val) {
					ft::pair<iterator, bool>	tmp;

					tmp = _root.get_delete_node_ptr(val);
					if (tmp.second)
						_size--;
					return tmp.second;
				}

				void	erase(iterator first, iterator last) {
					iterator	tmp;
					while (first != last) {
						tmp = first;
						first++;
						erase(*tmp);
					}
				}

				void	swap(set& x) {
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

				iterator	find(const value_type &val) {
					return	_root.find(val);
				}

				const_iterator	find(const value_type& val) const {
					return	_root.find(val);
				}

				size_type	count(const value_type& val) const {
					return	_root.count(val);
				}

				iterator	lower_bound(const value_type& val) {
					return	_root.lower_bound(val);
				}

				const_iterator	lower_bound(const value_type& val) const {
					return	_root.lower_bound(val);
				}

				iterator	upper_bound(const value_type& val) {
					return	_root.upper_bound(val);
				}

				const_iterator	upper_bound(const value_type& val) const {
					return	_root.upper_bound(val);
				}

				ft::pair<iterator, iterator>	equal_range(const value_type& val) {
					return	ft::make_pair<iterator, iterator>(lower_bound(val), upper_bound(val));
				}

				ft::pair<const_iterator, const_iterator>	equal_range(const value_type& val) const {
					return	ft::make_pair<const_iterator, const_iterator>(lower_bound(val), upper_bound(val));
				}

				/***** ALLOCATOR *****/

				allocator_type	get_allocator(void) const {
					return _alloc;
				}

			private:

				Tree<value_type, key_compare, allocator_type> _root;
				key_compare	_cmp;
				allocator_type	_alloc;
				size_type		_size;
		};

	template <class T, class Compare, class Alloc>
		void	swap(ft::set<T, Compare, Alloc>&lhs, ft::set<T, Compare, Alloc>& rhs) {
			if (lhs == rhs)
				return ;
			lhs.swap(rhs);
		}

	template <class T, class Compare, class Alloc>
		bool	operator==(const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
			if ( lhs.size() != rhs.size() )
				return false;
			typename set<T, Compare, Alloc>::const_iterator it = lhs.begin();
			typename set<T, Compare, Alloc>::const_iterator ite = lhs.end();
			typename set<T, Compare, Alloc>::const_iterator rit = rhs.begin();

			while (it != ite && rit != rhs.end()) {
				if (*it != *rit)
					return false;
				it++;
				rit++;
			}
			if (it != ite || rit != rhs.end())
				return false;
			return true;
		}

	template <class T, class Compare, class Alloc>
		bool	operator!=(const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
			return	!(lhs == rhs);
		}
	template <class T, class Compare, class Alloc>
		bool	operator<(const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class T, class Compare, class Alloc>
		bool	operator<=(const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
			return !(rhs < lhs);
		}
	template <class T, class Compare, class Alloc>
		bool	operator>(const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
			return rhs < lhs;
		}
	template <class T, class Compare, class Alloc>
		bool	operator>=(const ft::set<T, Compare, Alloc>& lhs, const ft::set<T, Compare, Alloc>& rhs) {
			return	!(lhs < rhs);
		}
}

#endif
