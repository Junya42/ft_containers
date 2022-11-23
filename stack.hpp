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

				explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {
				};

				bool	empty(void) const {
					return _ctnr.empty();
				}

				size_type	size() const {
					return _ctnr.size();
				}

				value_type& top() {
					return _ctnr.back();
				}
				const value_type& top() const {
					return _ctnr.back();
				}

				void	push(const value_type& val) {
					_ctnr.push_back(val);
				}

				void	pop(void) {
					_ctnr.pop_back();
				}
				friend bool	operator==(stack<T, Container> const &lhs,
						stack<T, Container> const &rhs);

					friend bool	operator<(stack<T, Container> const &lhs,
							stack<T, Container> const &rhs);
				protected:

				container_type	_ctnr;
		};
	template <class T, class Container>
		bool	operator==(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return lhs._ctnr == rhs._ctnr;
		}
	template <class T, class Container>
		bool	operator!=(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return lhs._ctnr != rhs._ctnr;
		}
	template <class T, class Container>
		bool	operator<(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return lhs._ctnr < rhs._ctnr;
		}
	template <class T, class Container>
		bool	operator<=(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return lhs._ctnr <= rhs._ctnr;
		}
	template <class T, class Container>
		bool	operator>(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return lhs._ctnr > rhs._ctnr;
		}
	template <class T, class Container>
		bool	operator>=(const stack<T, Container>&lhs, const stack<T, Container>& rhs) {
			return lhs._ctnr >= rhs._ctnr;
		}
}

#endif
