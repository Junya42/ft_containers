#ifndef	EQUAL_HPP
# define EQUAL_HPP

namespace ft {
	
	template<class InputIteratorA, class InputIteratorB>
		bool	equal(InputIteratorA a, InputIteratorA end, InputIteratorB b) {
			while (a != end) 
				if (!(*(a++) == *(b++)))
					return	false;
			return	true;
		}
}

#endif
