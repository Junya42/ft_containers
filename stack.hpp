#ifndef STACK_HPP
# define STACK_HPP

#include <deque>
#include <vector>
#include <list>
#include <cstddef>
#include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
		class	stack {

			public:

				typedef T			value_type;
				typedef Container	container_type;
				typedef size_t		size_type;

				explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {
				};

				bool	empty(void) const {
					return c.empty();
				}

				size_type	size() const {
					return c.size();
				}

				value_type& top() {
					return c.back();
				}
				const value_type& top() const {
					return c.back();
				}

				void	push(const value_type& val) {
					c.push_back(val);
				}

				void	pop(void) {
					c.pop_back();
				}
				friend bool	operator==(stack<T, Container> const &lhs,
						stack<T, Container> const &rhs) {
					return lhs.c == rhs.c;
				}

					friend bool	operator<(stack<T, Container> const &lhs,
							stack<T, Container> const &rhs) {
						return lhs.c < rhs.c;
					}
				protected:

				container_type	c;
		};
	template <class T, class Container>
		bool	operator!=(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return !(lhs == rhs);
		}
	template <class T, class Container>
		bool	operator<=(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return !(rhs < lhs);
		}
	template <class T, class Container>
		bool	operator>(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return rhs < lhs;
		}
	template <class T, class Container>
		bool	operator>=(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return !(lhs < rhs);
		}
}

#endif
