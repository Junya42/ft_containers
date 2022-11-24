#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <memory>

#include "pair.hpp"
#include "node.hpp"
#include "red_black.hpp"
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicographical_compare.hpp"
#include "equal.hpp"
#include "bidirectional_iterator.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft {

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map {
			
			public:

				typedef ft::pair<const Key, T>		value_type;
				typedef	Key							key_type;
				typedef	T							mapped_type;
				typedef	Compare						key_compare;
				typedef Alloc																		allocator_type;
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

				explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
					_cmp = comp;
					_alloc = alloc;
				}

				template <class InputIterator>
					map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type()) {
					}

				map(const map& x){
					*this = x;
				}
				map& operator=(const map& x) {
					return *this;
				}

				/***** ITERATOR *****/

				iterator	begin(void) {
				}

				const_iterator	begin(void) const {
				}

				iterator	end(void) {
				}

				const_iterator	end(void) const {
				}

				reverse_iterator	rbegin(void) {
				}

				const_reverse_iterator	rbegin(void) const {
				}

				reverse_iterator	rend(void) {
				}

				const_reverse_iterator	rend(void) const {
				}

				/***** CAPACITY *****/

				bool	empty(void) const {
					if (_size)
						return true;
					return false;
				}

				size_type	size(void) const {
					return _size;
				}

				size_type	max_size(void) const {
					return _alloc.max_size();
				}

				/***** ELEMENT ACCESS *****/

				mapped_type&	operator[](const key_type& k) {
				}

				/***** MODIFIERS *****/

				pair<iterator, bool>	insert(const value_type& val) {
				}

				iterator	insert(iterator position, const value_type& val) {
				}

				template <class InputIterator>
					void	insert(InputIterator first, InputIterator last) {
					}

				void	erase(iterator position) {
				}

				size_type	erase(const key_type& k) {
				}

				void	erase(iterator first, iterator last) {
				}

				void	swap(map& x) {
				}

				void	clear(void) {
				}

				/***** OBSERVERS *****/

				key_compare	key_comp(void) const {
				}

				value_compare	value_comp(void) const {
				}

				/***** OPERATIONS *****/

				iterator	find(const key_type& k) {
				}

				const_iterator	find(const key_type& k) const {
				}

				size_type	count(const key_type& k) const {
				}

				iterator	lower_bound(const key_type& k) {
				}

				const_iterator	lower_bound(const key_type& k) const {
				}

				iterator	upper_bound(const key_type& k) {
				}

				const_iterator	upper_bound(const key_type& k) const {
				}

				pair<iterator, iterator>	equal_range(const key_type& k) {
				}

				pair<const_iterator, const_iterator>	equal_range(const key_type& k) const {
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
}

#endif
