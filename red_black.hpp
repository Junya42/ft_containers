#ifndef RED_BLACK_HPP
# define RED_BLACK_HPP

#include "node.hpp"
#include "red_black_iterator.hpp"

#define RED		true
#define BLACK	false

namespace ft {

	template <class T, class Compare, class Alloc, class Node = Node<T> >
		class Tree {

			public:

				typedef	T									value_type;
				typedef Compare								key_compare;
				typedef Alloc								allocator_type;

				typedef typename value_type::first_type							key_type;
				typedef typename value_type::second_type 						mapped_type;
				typedef typename allocator_type::size_type						size_type;
				typedef typename ft::Tree_iterator<Node>						iterator;
				typedef typename ft::const_Tree_iterator<Node>					const_iterator;
				typedef typename Node::Node_ptr									Node_ptr;
				typedef typename Node::const_Node_ptr							const_Node_ptr;
				typedef typename Node::Node_ref									Node_ref;
				typedef typename Node::const_Node_ref							const_Node_ref;
				typedef typename allocator_type::template rebind<Node>::other	node_alloc;

				Tree(void) : _root(NULL), _cmp(key_compare()), _node(node_alloc()), _alloc(allocator_type()) {
				}

				Tree(const Tree& src) {
					*this = src;
				}

				Tree &operator=(const Tree& src) {
					_root = src._root;
					_alloc = src._alloc;
					_node = src._node;
					_cmp = src._cmp;
					return *this;
				}
				
				~Tree(void) {
				}

			private:

				Node_ptr		_root;
				allocator_type	_alloc;
				node_alloc		_node;
				key_compare		_cmp;
		};
}

#endif
