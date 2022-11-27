/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_iterator.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:45:32 by anremiki          #+#    #+#             */
/*   Updated: 2022/11/24 18:07:25 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_ITERATOR_HPP
# define RED_BLACK_ITERATOR_HPP

#include "bidirectional_iterator.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <iostream>

namespace ft {

	template <class Iterator>
		class const_Tree_iterator;

	template <class Iterator>
		class Tree_iterator {
			
			public:

				typedef				Iterator*								iterator_type;
				typedef typename	Iterator::value_type					value_type;

				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer			pointer;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

				Tree_iterator(void)
					: _node(NULL), _end(NULL) {
				}

				Tree_iterator(iterator_type node, iterator_type end)
					: _node(node), _end(end) {
					}

				Tree_iterator(const Tree_iterator& src) : _node(src._node), _end(src._end) {
				}

				Tree_iterator&	operator=(const Tree_iterator& src) {
					_node = src._node;
					_end = src._end;
					return *this;
				}

				~Tree_iterator(void) {
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


				Tree_iterator&	operator++(void) {
					_increment();
					return *this;
				}

				Tree_iterator	operator++(int) {
					Tree_iterator	tmp;

					tmp = *this;
					_increment();
					return	tmp;
				}

				Tree_iterator&	operator--(void) {
					_decrement();
					return *this;
				}

				Tree_iterator	operator--(int) {
					Tree_iterator	tmp;

					tmp = *this;
					_decrement();
					return tmp;
				}

				bool	operator==(const Tree_iterator& src) const {
					return _node == src._node;
				}

				bool	operator!=(const Tree_iterator& src) const {
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

	template <class Iterator>
		class const_Tree_iterator {

			public:

				typedef				const Iterator*							iterator_type;
				typedef typename	Iterator::value_type					const value_type;

				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type	difference_type;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer			pointer;
				typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

				const_Tree_iterator(void)
					: _node(NULL), _end(NULL) {
					}

				const_Tree_iterator(iterator_type node, iterator_type end)
					: _node(node), _end(end) {
					}

				const_Tree_iterator(const const_Tree_iterator& src)
					: _node(src._node), _end(src._end) {
					} 

				const_Tree_iterator(const Tree_iterator<Iterator>& src)
					: _node(src.base()), _end(src.end()) {
					} 

				const_Tree_iterator&	operator=(const const_Tree_iterator& src) {
					_node = src._node;
					_end = src._end;
					return *this;
				}

				~const_Tree_iterator(void) {
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

				const_Tree_iterator&	operator++(void) {
					_increment();
					return *this;
				}

				const_Tree_iterator	operator++(int) {
					const_Tree_iterator	tmp;

					tmp = *this;
					_increment();
					return	tmp;
				}

				const_Tree_iterator&	operator--(void) {
					_decrement();
					return *this;
				}

				const_Tree_iterator	operator--(int) {
					const_Tree_iterator	tmp;

					tmp = *this;
					_decrement();
					return tmp;
				}

				bool	operator==(const const_Tree_iterator& src) const {
					return _node == src._node;
				}

				bool	operator!=(const const_Tree_iterator& src) const {
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
