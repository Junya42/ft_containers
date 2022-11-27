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

			Node(value_type ndata, Node_ptr nparent = NULL, Node_ptr nleft = NULL, Node_ptr nright = NULL)
				: parent(nparent), left(nleft), right(nright), color(RED), data(ndata) {
			}

			Node(const Node& src) 
				: parent(src.parent), left(src.left), right(src.right), color(src.color), data(src.data) {
			}

			Node& operator=(const Node& src) {
				parent = src.parent;
				left = src.left;
				right = src.right;
				data = src.data;
				color = src.color;
				return *this;
			}
		};
}

#endif
