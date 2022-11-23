#ifndef RED_BLACK_ITERATOR_HPP
# define RED_BLACK_ITERATOR_HPP

#include "bidirectional_iterator.hpp"
#include "iterator_traits.hpp"

namespace ft {

	template <class Iterator>
		class Tree_iterator {
			
			public:

				typedef				Iterator*								iterator_type;
				typedef typename	Iterator::value_type					value_type;

				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer			pointer;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
		};

	template <class Iterator>
		class const_Tree_iterator {
			
			public:

				typedef				const Iterator*							const iterator_type;
				typedef typename	Iterator::value_type					const value_type;

				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer			pointer;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;
		};
}

#endif
