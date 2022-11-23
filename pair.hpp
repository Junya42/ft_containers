#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template <class T1, class T2>
		struct	pair {

				typedef T1		first_type;
				typedef	T2		second_type;

				pair();

				template<class U, class V>
					pair (const pair<U,V>& pr) {
						*this = pr;
					}

				pair&	operator=(const pair& pr) {
					_first = pr._first;
					_second = pr._second;
					return *this;
				}

				pair (const first_type& a, const second_type& b) : _first(a), _second(b) {
				}

				first_type	_first;
				second_type	_second;
		};

	template <class T1, class T2>
		pair<T1, T2>	make_pair(T1 x, T2 y) {
			return pair<T1, T2>(x, y);
		}
	
	template <class T1, class T2>
		bool	operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}

	template <class T1, class T2>
		bool	operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
			return !(lhs == rhs);
		}

	template <class T1, class T2>
		bool	operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
			return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
		}

	template <class T1, class T2>
		bool	operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
			return !(rhs < lhs);
		}

	template <class T1, class T2>
		bool	operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
			return rhs < lhs;
		}

	template <class T1, class T2>
		bool	operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
			return !(lhs < rhs);
		}
}

#endif
