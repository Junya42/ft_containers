#ifndef SET_RED_BLACK_ITERATOR_HPP
# define SET_RED_BLACK_ITERATOR_HPP

#include "bidirectional_iterator.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

namespace ft {

	template <class Iterator>
		class const_set_Tree_iterator;

	template <class Iterator>
		class set_Tree_iterator {
			
			public:

				typedef				Iterator*								iterator_type;
				typedef typename	Iterator::value_type					value_type;
				typedef const 		value_type *							pointer;
				typedef const 		value_type &							reference;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;

				set_Tree_iterator(void)
					: _node(NULL), _end(NULL) {
				}

				set_Tree_iterator(iterator_type node, iterator_type end)
					: _node(node), _end(end) {
				}

				set_Tree_iterator(const set_Tree_iterator& src) : _node(src._node), _end(src._end) {
				}

				set_Tree_iterator(const const_set_Tree_iterator<Iterator> &src)
					: _node(src.base()), _end(src.end()) {
				}
				set_Tree_iterator&	operator=(const set_Tree_iterator& src) {
					_node = src._node;
					_end = src._end;
					return *this;
				}

				~set_Tree_iterator(void) {
				}

				reference	operator*(void) const {
					return _node->data;
				}

				pointer	operator->(void) const {
					return &(_node->data);
				}
				
				iterator_type	base(void) const {
					return _node;
				}

				iterator_type	end(void) const {
					return _end;
				}


				set_Tree_iterator&	operator++(void) {
					_increment();
					return *this;
				}

				set_Tree_iterator	operator++(int) {
					set_Tree_iterator	tmp;

					tmp = *this;
					_increment();
					return	tmp;
				}

				set_Tree_iterator&	operator--(void) {
					_decrement();
					return *this;
				}

				set_Tree_iterator	operator--(int) {
					set_Tree_iterator	tmp;

					tmp = *this;
					_decrement();
					return tmp;
				}

				bool	operator==(const set_Tree_iterator& src) const {
					return _node == src._node;
				}

				bool	operator!=(const set_Tree_iterator& src) const {
					return _node != src._node;
				}

			private:

				iterator_type	_node;
				iterator_type	_end;

				void	_increment(void) {
					if (_node) {
						_end = _node;
						if (_node->right) {
							_node = _node->right;
							while (_node && _node->left) {
								_node = _node->left;
							}
						}
						else {
							while (_node->parent && _node->parent->right == _node) {
								_node = _node->parent;
							}
							_node = _node->parent;
						}
					}
				}

				void	_decrement(void) {
					if (_node) {
						if (_node->left) {
							_node = _node->left;
							while (_node && _node->right)
								_node = _node->right;
						}
						else {
							while (_node->parent && _node->parent->left == _node)
								_node = _node->parent;
							_node = _node->parent;
						}
					}
					else
						_node = _end;
				}
		};

	template <class Iterator>
		class const_set_Tree_iterator {

			public:

				typedef				Iterator*							iterator_type;
				typedef typename	Iterator::value_type					const value_type;
				typedef				const value_type *						pointer;
				typedef				const value_type &						reference;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;

				const_set_Tree_iterator(void)
					: _node(NULL), _end(NULL) {
					}

				const_set_Tree_iterator(iterator_type node, iterator_type end)
					: _node(node), _end(end) {
					}

				const_set_Tree_iterator(const const_set_Tree_iterator& src)
					: _node(src._node), _end(src._end) {
					} 
				
				const_set_Tree_iterator(const set_Tree_iterator<Iterator>& src)
					: _node(src.base()), _end(src.end()) {
					} 

				const_set_Tree_iterator&	operator=(const const_set_Tree_iterator& src) {
					_node = src._node;
					_end = src._end;
					return *this;
				}

				~const_set_Tree_iterator(void) {
				}

				reference	operator*(void) const {
					return _node->data;
				}

				pointer	operator->(void) const {
					return &(_node->data);
				}

				iterator_type	base(void) const {
					return _node;
				}

				iterator_type	end(void) const {
					return _end;
				}

				const_set_Tree_iterator&	operator++(void) {
					_increment();
					return *this;
				}

				const_set_Tree_iterator	operator++(int) {
					const_set_Tree_iterator	tmp;

					tmp = *this;
					_increment();
					return	tmp;
				}

				const_set_Tree_iterator&	operator--(void) {
					_decrement();
					return *this;
				}

				const_set_Tree_iterator	operator--(int) {
					const_set_Tree_iterator	tmp;

					tmp = *this;
					_decrement();
					return tmp;
				}

				bool	operator==(const const_set_Tree_iterator& src) const {
					return _node == src._node;
				}

				bool	operator!=(const const_set_Tree_iterator& src) const {
					return _node != src._node;
				}

			private:

				iterator_type	_node;
				iterator_type	_end;

				void	_increment(void) {
					if (_node) {
						_end = _node;
						if (_node->right) {
							_node = _node->right;
							while (_node && _node->left)
								_node = _node->left;
						}
						else {
							while (_node->parent && _node->parent->right == _node)
								_node = _node->parent;
							_node = _node->parent;
						}
					}
				}

				void	_decrement(void) {
					if (_node) {
						if (_node->left) {
							_node = _node->left;
							while (_node && _node->right)
								_node = _node->right;
						}
						else {
							while (_node->parent && _node->parent->left == _node)
								_node = _node->parent;
							_node = _node->parent;
						}
					}
					else
						_node = _end;
				}
		};
}

#endif
