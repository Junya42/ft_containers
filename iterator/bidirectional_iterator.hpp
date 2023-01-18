#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "iterator.hpp"
# include "iterator_traits.hpp"

namespace ft {

    template <class Iterator>
       class bidirectional_iterator : ft::bidirectional_iterator_tag {

          public:

             typedef Iterator iterator_type;
             typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::iterator_category iterator_category;
             typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::value_type value_type;
             typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::difference_type difference_type;
             typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::pointer pointer;
             typedef typename ft::iterator< bidirectional_iterator_tag, Iterator>::reference reference;

             bidirectional_iterator(void) {
             }

             explicit bidirectional_iterator(iterator_type& it) {
                _it = it;
             }

             ~bidirectional_iterator( void ) {
             }

             iterator_type base( void ) const {
                return _it;   
             }

             bidirectional_iterator & operator=( bidirectional_iterator & src ) {
                _it = src._it;
                return *this;
             }

             reference operator*(void) const {
                Iterator tmp;

                tmp = _it;
                return *tmp;
             }

             reference operator->(void) const {
                return &(operator*());
             }

             bidirectional_iterator& operator++(void) {
                ++_it;
                return *this;
             }

             bidirectional_iterator operator++(int) {
                bidirectional_iterator tmp;

                tmp = *this;
                ++_it;
                return tmp;
             }

             bidirectional_iterator& operator--(void) {
                --_it;
                return *this;
             }

             bidirectional_iterator  operator--(int) {
                bidirectional_iterator tmp;

                tmp = *this;
                --_it;
                return tmp;
             }

          private:
             Iterator _it;
       };

    template <class Iterator, class Iterator2>
       bool operator==( const bidirectional_iterator<Iterator>& lhs, const bidirectional_iterator<Iterator2>& rhs ) {
          return lhs.base() == rhs.base();
       }

    template <class Iterator, class Iterator2>
       bool operator!=( const bidirectional_iterator<Iterator>& lhs, const bidirectional_iterator<Iterator2>& rhs ) {
          return lhs.base() != rhs.base();
       }

}

#endif
