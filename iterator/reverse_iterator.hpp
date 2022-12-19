/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anremiki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:14:48 by anremiki          #+#    #+#             */
/*   Updated: 2022/11/16 19:30:05 by anremiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iterator>

namespace ft
{
   template<class Iterator>
      class reverse_iterator
      {
         public:

            typedef  Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;

            reverse_iterator(void) {
            };

            ~reverse_iterator(void) {
            };

            explicit reverse_iterator(reverse_iterator& src) {
               _it = src._it;
            }

            explicit reverse_iterator(iterator_type it) {
               _it = it;
            }

            template <class Iter>
               reverse_iterator(const reverse_iterator<Iter>& rev_it) {
                  _it = rev_it.base();
               }

            iterator_type  base(void) const {
               return _it;
            }

            reference  operator*(void) const {
               Iterator it;

               it = _it;
               return *(--it);
            }

            reverse_iterator  operator+(difference_type n) const{
               return reverse_iterator(_it - n);
            }

            reverse_iterator  &operator++(void) {
               --_it;
               return *this;
            }

            reverse_iterator  operator++(int) {
               reverse_iterator it;

               it = *this;
               --_it;
               return it;
            }

            reverse_iterator& operator +=(difference_type n) {
               _it -= n;
               return *this;
            }

            reverse_iterator  operator-(difference_type n) const{
               return reverse_iterator(_it + n);
            }

            reverse_iterator  &operator--(void) {
               ++_it;
               return *this;
            }

            reverse_iterator  operator--(int) {
               reverse_iterator  it;
               it = *this;
               ++_it;
               return it;
            }

            reverse_iterator& operator -=(difference_type n) {
               _it += n;
               return *this;
            }

            pointer  operator->(void) const {
               return &(operator*());
            }

            reference   operator[](difference_type n) const {
               return *(*this + n);
            }

         private:

            Iterator _it;
      };

   template <class Iterator, class Iterator2>
      bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) {
         return (lhs.base() == rhs.base() ? true : false);
      }

   template <class Iterator, class Iterator2>
      bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) {
         return (lhs.base() != rhs.base() ? true : false);
      }

   template <class Iterator, class Iterator2>
      bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) {
         return (lhs.base() > rhs.base());
      }

   template <class Iterator, class Iterator2>
      bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) {
         return (lhs.base() >= rhs.base());
      }

   template <class Iterator, class Iterator2>
      bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) {
         return (lhs.base() < rhs.base());
      }

   template <class Iterator, class Iterator2>
      bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator2>& rhs) {
         return (lhs.base() <= rhs.base());
      }

   template <class Iterator, class Iterator2>
      typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator2>& rhs) {
         return rhs.base() - lhs.base();
      }

   template <class Iterator>
      reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
         return reverse_iterator<Iterator>(rev_it.base() - n);
      }
}

#endif
