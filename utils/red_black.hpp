#ifndef RED_BLACK_HPP
# define RED_BLACK_HPP

#include "node.hpp"
#include "pair.hpp"
#include "../iterator/red_black_iterator.hpp"

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

				Tree(void)
					: _root(NULL), _alloc(allocator_type()), _alloc_node(node_alloc()), _cmp(key_compare()) {
				}

				explicit Tree(const key_compare& key)
					: _root(NULL), _alloc(allocator_type()), _alloc_node(node_alloc()), _cmp(key) {
				}

				Tree(const Tree& src) {
					*this = src;
				}

				Tree &operator=(const Tree& src) {
					_root = src._root;
					_alloc = src._alloc;
					_alloc_node = src._alloc_node;
					_cmp = src._cmp;
					return *this;
				}
				
				~Tree(void) {
					clear();
				}


				size_type	max_size(void) const {
					return _alloc_node.max_size();
				}

				void	clear(void) {
					_root = _clear_nodes(_root);
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
						if (_cmp(x->data.first, new_data.first)) {
							x = x->right;
						}
						else if (_cmp(new_data.first, x->data.first)) {
							x = x->left;
						}
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

				ft::pair<iterator, bool>insert(iterator	position, const value_type& new_data) {
					if (!position.base())
						return ft::make_pair<iterator, bool>(iterator(_root, NULL), false);
					if (!_root) {
						_root = _alloc_node.allocate(sizeof(Node_ptr));
						_alloc_node.construct(_root, Node(new_data));
						_root->color = BLACK;
						return ft::make_pair<iterator, bool>(iterator(_root, NULL), true);
					}
					Node_ptr	x, y;

					x = position.base();
					while (x) {
						y = x;
						if (_cmp(x->data.first, new_data.first)) {
<<<<<<< HEAD
							if (x->parent && x == x->parent->left &&(_cmp(x->parent->data.first, new_data.first)))
=======
							if (x->parent && x == x->parent->left && (!_cmp(new_data.first, x->parent->data.first)))
>>>>>>> 1a2bb6206fea81b9ccedd624c1df881597cf2b20
								x = x->parent;
							else
								x = x->right;
						}
						else if (_cmp(new_data.first, x->data.first)) {
<<<<<<< HEAD
							if (x->parent && x == x->parent->right && (_cmp(new_data.first, x->parent->data.first)))
=======
							if (x->parent && x == x->parent->right && (!_cmp(x->parent->data.first, new_data.first)))
>>>>>>> 1a2bb6206fea81b9ccedd624c1df881597cf2b20
								x = x->parent;
							else
								x = x->left;
						}
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

				ft::pair<iterator, bool>	get_delete_node_ptr(const key_type &key) {
					Node_ptr	ptr = _root;

					while (ptr && ptr->data.first != key) {
						if (_cmp(ptr->data.first, key))
							ptr = ptr->right;
						else if (_cmp(key, ptr->data.first))
							ptr = ptr->left;
						else
							break ;
					}
					if (!ptr)
						return ft::make_pair<iterator, bool>(iterator(NULL, NULL), false);
					return delete_node(ptr);
				}

				ft::pair<iterator, bool>	delete_node(Node_ptr &z) {
					Node_ptr x, y;
					bool orignal_color;

					y = z;
					orignal_color = y->color;
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
						orignal_color = y->color;
						x = y->right;
						if(x && y->parent == z) {
							x->parent = y;
						}
						else {
							_transplant(y, y->right);
							y->right = z->right;
							if (y->right) {
								y->right->parent = y;
							}
						}
						_transplant(z, y);
						y->left = z->left;
						if (y->left) {
							y->left->parent = y;
						}
						y->color = z->color;
					}
					_alloc_node.destroy(z);
					_alloc_node.deallocate(z, sizeof(Node_ptr));
					if (orignal_color == BLACK)
						_delete_fix(x);
					return ft::make_pair<iterator, bool>(iterator(x, NULL), true);
				}

				void	erase_all(Node_ptr x, Node_ptr limit) {
					if (!x)
						return ;
					(void)limit;
					_alloc_node.destroy(x);
					_alloc_node.deallocate(x, sizeof(Node_ptr));
				}

				iterator	find(const key_type& k) {
					Node_ptr ptr;

					ptr = _root;
					while (ptr) {
						if (_cmp(ptr->data.first, k))
							ptr = ptr->right;
						else if (_cmp(k, ptr->data.first))
							ptr = ptr->left;
						else
							return iterator(ptr, NULL);
					}
					return iterator(ptr, NULL);
				}

				const_iterator	find(const key_type& k) const {
					Node_ptr ptr;

					ptr = _root;
					while (ptr) {
						if (_cmp(ptr->data.first, k))
							ptr = ptr->right;
						else if (_cmp(k, ptr->data.first))
							ptr = ptr->left;
						else
							return const_iterator(ptr, NULL);
					}
					return const_iterator(ptr, NULL);
				}

				size_type	count(const key_type& k) const {
					Node_ptr ptr;

					ptr = _root;
					while (ptr) {
						if (_cmp(ptr->data.first, k))
							ptr = ptr->right;
						else if (_cmp(k, ptr->data.first))
							ptr = ptr->left;
						else
							return 1;
					}
					return 0;
				}

				iterator	begin(void) {
					return iterator(_minimum(_root), NULL);
				}

				const_iterator	const_begin(void) const {
					return const_iterator(_minimum(_root), NULL);
				}

				iterator	end(void) {
					return iterator(NULL, _maximum(_root));
				}

				const_iterator	const_end(void) const {
					return const_iterator(NULL, _maximum(_root));
				}

				iterator	lower_bound(const key_type& k) {
					iterator	it, ite;

					it = begin();
					ite = end();
					while (it != ite) {
						if (!(_cmp(it->first, k)))
							return it;
						it++;
					}
					return	it;
				}

				const_iterator	lower_bound(const key_type& k) const {
					const_iterator	it, ite;

					it = const_begin();
					ite = const_end();
					while (it != ite) {
						if (!(_cmp(it->first, k)))
							return it;
						it++;
					}
					return it;
				}

				iterator	upper_bound(const key_type& k) {
					iterator	it, ite;

					it = begin();
					ite = end();
					while (it != ite) {
						if (_cmp(k, it->first))
							return it;
						it++;
					}
					return	it;
				}

				const_iterator	upper_bound(const key_type& k) const {
					const_iterator	it, ite;

					it = const_begin();
					ite = const_end();
					while (it != ite) {
						if (_cmp(k, it->first))
							return it;
						it++;
					}
					return	it;
				}

				void	swap(Tree& src) {
					Node_ptr	tmp_node;
					key_compare	tmp_key;
					node_alloc	tmp_node_alloc;

					tmp_node = _root;
					_root = src._root;
					src._root = tmp_node;

					tmp_key = _cmp;
					_cmp = src._cmp;
					src._cmp = tmp_key;

					tmp_node_alloc = _alloc_node;
					_alloc_node = src._alloc_node;
					src._alloc_node = tmp_node_alloc;
				}

			private:

				Node_ptr		_root;
				allocator_type	_alloc;
				node_alloc		_alloc_node;
				key_compare		_cmp;

				void	_left_rotate(Node_ptr x) {
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

				void	_right_rotate(Node_ptr x) {
					Node_ptr	y;

					y = x->left;
					x->left = y->right;
					if (y->right)
						y->right->parent = x;
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

				void	_insert_rebalance(Node_ptr x) {
					Node_ptr	y;

					while (x->parent && x->parent->color == RED) {
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
								y = _grandpa(x);
								y->color = RED;
								_right_rotate(y);
								//_grandpa(x)->color = RED;
								//_right_rotate(_grandpa(x));
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
								y = _grandpa(x);
								y->color = RED;
								_left_rotate(y);
								//_grandpa(x)->color = RED;
								//_left_rotate(_grandpa(x));
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
					if (v)
						v->parent = u->parent;
				}

				Node_ptr	_minimum(Node_ptr x) const {
					if (!x)
						return NULL;
					if (x->left)
						return	_minimum(x->left);
					return x;
				}

				Node_ptr	_maximum(Node_ptr x) const {
					if (!x)
						return NULL;
					if (x->right)
						return _maximum(x->right);
					return x;
				}

				void	_delete_fix(Node_ptr x) {
					while (x && x != _root && x->color == BLACK) {
						if (x == x->parent->left) {
							Node_ptr w = x->parent->right;
							if (w->color == RED) {
								w->color = BLACK;
								x->parent->color = RED;
								_left_rotate(x->parent);
								w = x->parent->right;
							}
							if ((!w->right || w->right->color == BLACK) && (!w->left || w->left->color == BLACK)) {
								w->color = RED;
								x = x->parent;
							}
							else {
								if (!w->right || w->right->color == BLACK) {
									w->left->color = BLACK;
									w->color = RED;
									_right_rotate(w);
									w = x->parent->right;
								}
								w->color = x->parent->color;
								if (x->parent->parent)
									x->parent->parent->color = BLACK;
								if (w->right)
									w->right->color = BLACK;
								_left_rotate(x->parent);
								x = _root;
							}
						}
						else {
							Node_ptr w = x->parent->left;
							if (w->color == RED) {
								w->color = BLACK;
								x->parent->color = RED;
								_right_rotate(x->parent);
								w = x->parent->left;
							}
							if ((!w->right || w->right->color == BLACK) && (!w->left || w->left->color == BLACK)) {
								w->color = RED;
								x = x->parent;
							}
							else {
								if (!w->left || w->left->color == BLACK) {
									w->right->color = BLACK;
									w->color = RED;
									_left_rotate(w);
									w = x->parent->left;
								}
								w->color = x->parent->color;
								if (x->parent->parent)
									x->parent->parent->color = BLACK;
								if (w->left)
									w->left->color = BLACK;
								_right_rotate(x->parent);
								x = _root;
							}
						}
					}
					if (x)
						x->color = BLACK;
				}

				Node_ptr	_clear_nodes(Node_ptr ptr) {
					if (!ptr)
						return NULL;	
					if (ptr->right)
						_clear_nodes(ptr->right);
					if (ptr->left)
						_clear_nodes(ptr->left);
					_alloc_node.destroy(ptr);
					_alloc_node.deallocate(ptr, 1);
					ptr = NULL;
					return NULL;
				}
		};
}

#endif
