#ifndef Node_HPP
# define Node_HPP

#include <iostream>

# define RED	false
# define BLACK	true

namespace ft {

	template<class T>
		struct Node {

			typedef T				value_type;
			typedef Node*			Node_ptr;
			typedef const Node*		const_Node_ptr;
			typedef Node&			Node_ref;
			typedef const Node& 	const_Node_ref;


			Node_ptr	parent;
			Node_ptr	left;
			Node_ptr	right;
			bool		color;
			value_type	data;

			Node(void) : parent(NULL), left(NULL), right(NULL), color(RED), data(value_type()) {
			}

			~Node(){
			};

			Node(value_type ndata, Node_ptr nparent = NULL, Node_ptr nleft = NULL, Node_ptr nright = NULL) : color(RED) {
				data = ndata;
				parent = nparent;
				left = nleft;
				right = nright;
			}

			Node(const Node& src) {
				*this = src;
			}

			Node& operator=(const Node& src) {
				data = src.data;
				parent = src.parent;
				left = src.left;
				right = src.right;
				color = src.color;
				return *this;
			}

		};
}

#endif
