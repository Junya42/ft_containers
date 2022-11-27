#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {
	
	template <class InputIteratorA, class InputIteratorB>
		bool	lexicographical_compare(InputIteratorA a_start, InputIteratorA a_end,
				InputIteratorB b_start, InputIteratorB b_end) {
			while (a_start != a_end) {
				if (b_start == b_end || *b_start < *a_start)
					return	false;
				else if (*a_start < *b_start)
					return	true;
				a_start++;
				b_start++;
			}
			return	(b_start != b_end);
		}
}

#endif
