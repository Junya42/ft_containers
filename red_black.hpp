#ifndef RED_BLACK_HPP
# define RED_BLACK_HPP

#include "node.hpp"
#include "pair.hpp"
#include "red_black_iterator.hpp"

#define RED		false
#define BLACK	true

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

				Tree(void) : _root(NULL), _cmp(key_compare()), _alloc_node(node_alloc()), _alloc(allocator_type()) {
				}

				Tree(const Tree& src) {
					*this = src;
				}

				Tree &operator=(const Tree& src) {
					_root = src._root;
					_alloc = src._alloc;
					_alloc_node = src._node;
					_cmp = src._cmp;
					return *this;
				}
				
				~Tree(void) {
				}

				ft::pair<iterator, bool>insert(const value_type& new_data) {
					if (!_root) {
						_root = _alloc_node.allocate(sizeof(Node_ptr));
						_alloc_node.construct(_root, Node(new_data));
						_root->color = BLACK;
						return ft::make_pair<iterator, bool>(iterator(_root, NULL), true);
					}
					Node_ptr	x, y;

					x = _root;
					while (x) {
						y = x;
						if (_cmp(x->data.first, new_data.first))
							x = x->right;
						else if (!(_cmp(x->data.first, new_data.first)))
							x = x->left;
						else
							return ft::make_pair<iterator, bool>(iterator(x, NULL), false);
					}
					x = _alloc_node.allocate(sizeof(Node_ptr));
					_alloc_node.construct(x, Node(new_data));
					x->parent = y;
					if (_cmp(x->data.first, y->data.first))
						y->left = x;
					else
						y->right = x;
					_insert_rebalance(x);
					return ft::make_pair<iterator, bool>(iterator(x, NULL), true);
				}

				void	delete_node(Node_ptr z) {
					Node_ptr y = z;
					Node_ptr x;
					bool y_orignal_color = y->color;
					if (!z->left) {
						x = z->right;
						_transplant(z, z->right);
					}
					else if (!z->right) {
						x = z->left;
						_transplant(z, z->left);
					}
					else {
						y = _minimum(z->right);
						y_orignal_color = y->color;
						x = y->right;
						if(y->parent == z) {
							x->parent = z;
						}
						else {
							_transplant(y, y->right);
							y->right = z->right;
							y->right->parent = y;
						}
						_transplant(z, y);
						y->left = z->left;
						y->left->parent = y;
						y->color = z->color;
					}
					if (y_orignal_color == BLACK)
						_delete_fix(x);
				}

			private:

				Node_ptr		_root;
				allocator_type	_alloc;
				node_alloc		_alloc_node;
				key_compare		_cmp;

				void	_left_rotate(Node_ptr &x) {
					Node_ptr	y;

					y = x->right;
					x->right = y->left;
					if (y->left)
						y->left->parent = x;
					y->parent = x->parent;
					if (!y->parent)
						_root = y;
					else if (x == x->parent->left)
						x->parent->left = y;
					else
						x->parent->right = y;
					y->left = x;
					x->parent = y;
				}

				void	_right_rotate(Node_ptr &x) {
					Node_ptr	y;

					y = x->left;
					x->left = y->right;
					if (y->right)
						y->right.parent = x;
					y->parent = x->parent;
					if (!y->parent)
						_root = y;
					else if (x == x->parent->left)
						x->parent->left = y;
					else
						x->parent->right = y;
					y->right = x;
					x->parent = y;
				}

				Node_ptr	_grandpa(Node_ptr &x) {
					return (x->parent->parent);
				}

				Node_ptr	_uncle(Node_ptr &x) {
					Node_ptr	tmp;

					tmp = _grandpa(x);
					if (x->parent == tmp->left)
						return (tmp->right);
					return (tmp->left);
				}

				void	_insert_rebalance(Node_ptr &x) {
					Node_ptr	y;

					while (x->parent && x->parent.color == RED) {
						y = _uncle(x);
						if (x->parent == _grandpa(x)->left) {
							if (y && y->color == RED) {
								x->parent->color = BLACK;
								y->color = BLACK;
								_grandpa(x)->color = RED;
								x = _grandpa(x);
							}
							else {
								if (x == x->parent->right) {
									x = x->parent;
									_left_rotate(x);
								}
								x->parent->color = BLACK;
								_grandpa(x)->color = RED;
								_right_rotate(_grandpa(x));
							}
						}
						else {
							if (y && y->color == RED) {
								x->parent->color = BLACK;
								y->color = BLACK;
								_grandpa(x)->color = RED;
								x = _grandpa(x);
							}
							else {
								if (x == x->parent->left) {
									x = x->parent;
									_right_rotate(x);
								}
								x->parent->color = BLACK;
								_grandpa(x)->color = RED;
								_left_rotate(_grandpa(x));
							}
						}
					}
					_root->color = BLACK;
				}

				void	_transplant(Node_ptr u, Node_ptr v) {
					if (!u->parent) {
						_root = v;
					}
					else if (u == u->parent->left) {
						u->parent->left = v;
					}
					else 
						u->parent->right = v;
					v->parent = u->parent;
				}

				Node_ptr	_minimum(Node_ptr x) {
					while (x->left) {
						x = x->left;
					}
					return x;
				}

				Node_ptr	_maximum(Node_ptr x) {
					while (x->right) {
						x = x->right;
					}
					return x;
				}

				void	_delete_fix(Node_ptr x) {
					while(x != _root && x->color == BLACK) {
						if(x == x->parent->left) {
							Node_ptr w = x->parent->right;
							if(w->color == RED) {
								w->color = BLACK;
								x->parent->color = RED;
								_left_rotate(x->parent);
								w = x->parent->right;
							}
							if(w->left->color == BLACK && w->right->color == BLACK) {
								w->color = RED;
								x = x->parent;
							}
							else {
								if(w->right->color == BLACK) {
									w->left->color = BLACK;
									w->color = RED;
									_right_rotate(w);
									w = x->parent->right;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->right->color = BLACK;
								_left_rotate(x->parent);
								x = _root;
							}
						}
						else {
							Node_ptr *w = x->parent->left;
							if(w->color == RED) {
								w->color = BLACK;
								x->parent->color = RED;
								_right_rotate(x->parent);
								w = x->parent->left;
							}
							if(w->right->color == BLACK && w->left->color == BLACK) {
								w->color = RED;
								x = x->parent;
							}
							else {
								if(w->left->color == BLACK) {
									w->right->color = BLACK;
									w->color = RED;
									_left_rotate(w);
									w = x->parent->left;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->left->color = BLACK;
								_right_rotate(x->parent);
								x = _root;
							}
						}
					}
					x->color = BLACK;
				}
		};
}

#endif
