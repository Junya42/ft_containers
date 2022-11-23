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

		};
}

#endif
