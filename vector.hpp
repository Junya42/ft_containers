#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <functional>
#if __x86_64__
#define ARCH 64
#else
#define ARCH 32
#endif 

#include <iostream>
#include <memory>
#include <cmath>
#include "utils/is_integral.hpp"
#include "utils/enable_if.hpp"
#include "utils/equal.hpp"
#include "utils/lexicographical_compare.hpp"
#include "iterator/reverse_iterator.hpp"

namespace ft
{
   template< class T, class Alloc = std::allocator<T> >
      class vector
      {
         public:

            typedef T         value_type;
            typedef Alloc     allocator_type;
            typedef T*        iterator;
            typedef const T*  const_iterator;
            typedef typename  allocator_type::reference reference;
            typedef typename  allocator_type::const_reference const_reference;
            typedef typename  allocator_type::pointer pointer;
            typedef typename  allocator_type::const_pointer const_pointer;
            typedef typename  allocator_type::difference_type difference_type;
            typedef typename  allocator_type::size_type size_type;
            typedef typename  ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename  ft::reverse_iterator<const_iterator> const_reverse_iterator;


            /***** Destructor *****/
            /**********************/

            ~vector() {
               clear();
               _alloc.deallocate(_start, capacity());
            }

            /***** Constructor *****/
            /***********************/

            /* Empty container constructor (Default constructor) */
            /* Constructs an empty container, with no elements */
            explicit vector (const allocator_type& alloc = allocator_type())
               :  _start(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {
               }

            /* Fill constructor */
            /* Constructs a container with n elements. Each element is a copy of val */
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
               : _start(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {
                  assign(n, val);
               }

            /* Range constructor */
            /* Construct a container with as many elements as the range [first, last],
             * with each element constructed from its corresponding element in that range, in the same order */
            template <class InputIterator>
               vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type())
               : _start(NULL), _end(NULL), _capacity(NULL), _alloc(alloc) {
                  assign(first, last);
               }

            /* Copy constructor */
            /* Constructs a container with a copy of each of the elements in x, in the same order */
            vector( vector const & src )
               : _start(NULL), _end(NULL), _capacity(src._capacity), _alloc(src._alloc) {
                  *this = src;
               }

            vector & operator=( vector const & src ) {
               assign(src.begin(), src.end());
               return *this;
            }

            /***** Iterator *****/
            /********************/

            iterator begin(void) {
               return (_start);
            }

            const_iterator begin(void) const {
               return (_start);
            }

            iterator end(void) {
               return _end;
            }

            const_iterator end(void) const {
               return _end;
            }

            reverse_iterator rbegin(void) {
               return reverse_iterator(_end);
            }

            const_reverse_iterator rbegin(void) const {
               return reverse_iterator(_end);
            }

            reverse_iterator rend(void) {
               return reverse_iterator(_start);
            }

            const_reverse_iterator rend(void) const {
               return reverse_iterator(_start);
            }
            /***** Capacity *****/
            /********************/

            size_type   size(void) const {
               return _end - _start;
            }

            size_type   max_size(void) const {
               return _alloc.max_size();
            }

            size_type   capacity(void) const {
               return _capacity - _start;
            }

            bool        empty(void) const {
               return (_start == _end ? true : false);
            }

            void        reserve(size_type n) {
               if (!n) {
                  reserve(1);
                  return ;
               }
               if (n > capacity()) {
                  pointer  start;
                  pointer  end;
                  pointer  ptr;

                  start = _alloc.allocate(sizeof(value_type) * n);
                  end = start;
                  ptr = _start;
                  if (size()) {
                     while (ptr < _end) {
                        _alloc.construct(end, *ptr);
                        ptr++;
                        end++;
                     }
                     clear();
                     if (capacity())
                        _alloc.deallocate(_start, capacity());
                     _start = start;
                     _capacity = start + n;
                     _end = end;
                  }
                  else {
                     if (capacity())
                        _alloc.deallocate(_start, capacity());
                     _start = start;
                     _capacity = start + n;
                     _end = start;
                  }
               }
            }

            void        resize(size_type n, value_type val = value_type()) {
               pointer  ptr = _start + n;
               if (n < size())
               {
                  while (ptr < _end)
                     _alloc.destroy(ptr++);
               }
               else if (n > size())
               {
                  if (n > capacity())
                     reserve(n);
                  while (n != size())
                     push_back(val);
               }
            }

            /***** Element access *****/
            /**************************/

            reference operator[](size_type n) {
               return *(_start + n);
            }

            const_reference operator[](size_type n) const {
               return *(_start + n);
            }

            reference at(size_type n) {
               return _start[n];
            }

            const_reference at(size_type n) const {
               return _start[n];
            }

            reference front(void) {
               return *(_start);
            }

            const_reference front(void) const {
               return *(_start);
            }

            reference back(void) {
               return *(_end - 1);
            }
            const_reference back(void) const {
               return *(_end - 1);
            }

            /***** Modifiers *****/
            /*********************/

            void     assign(size_type n, const value_type &val) {
               if (n <= capacity()) {
                  for (pointer ptr = _start; ptr < _end; ptr++) {
                     _alloc.destroy(ptr);
                     _alloc.construct(ptr, val);
                  }
               }
               else {
                  for (pointer ptr = _start; ptr < _end; ptr++)
                     _alloc.destroy(ptr);
                  _alloc.deallocate(_start, capacity());
                  _start = _alloc.allocate(sizeof(value_type) * n);

                  for (_end = _start; _end < _start + n; _end++)
                     _alloc.construct(_end, val);
                  _capacity = _start + n;
               }
            }

            template <class InputIterator>
               void  assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
                  if (capacity()) {
                     clear();
                     _alloc.deallocate(_start, capacity());
                  }
                  difference_type n;

                  n = last - first;
                  if (n > 0) {
                     _start = _alloc.allocate(sizeof(value_type) * n);
                     for (_end = _start; _end < _start + n; _end++) {
                        _alloc.construct(_end, *first);
                        first++;
                     }
                     _capacity = _end;
                  }
                  else {
                     _start = NULL;
                     _end = NULL;
                     _capacity = NULL;
                  }
               }

            void     push_back(const value_type& val) {
               if (size() + 1 > capacity())
                  reserve(size() * 2);
               _alloc.construct(_end, val);
               _end++;
            }

            void     pop_back(void) {
               _alloc.destroy(--_end);
            }

            iterator insert(iterator position, const value_type& val) {
               difference_type   pos = position - _start;

               if (size() + 1 > capacity())
                  reserve(size() * 2);
               pointer  tmp;
               pointer  new_end;
               pointer  new_pos;

               new_pos = _start + pos;
               tmp = _end - 1;
               new_end = _end;
               while (tmp >= new_pos) {
                  _alloc.construct(new_end, *(tmp));
                  _alloc.destroy(tmp);
                  tmp--;
                  new_end--;
               }
               if (tmp < _start)
                  tmp++;
               _alloc.construct(tmp, val);
               _end++;
               return new_pos;
            }

            void     insert(iterator position, size_type n, const value_type &val) {
               if (!n)
                  return ;
               difference_type   pos = position - _start;

               if (!capacity())
                  reserve(n);
               else if (size() + n > capacity() * 2) 
                  reserve(capacity() + n);
               else if (size() + n > capacity())
                  reserve(size() * 2);

               pointer  ptr;
               pointer  new_end;
               pointer  test;

               test = _start + pos;
               ptr = _end - 1;
               new_end = ptr + n;
               size_type   removed = 0;
               while (ptr >= test)
               {
                  removed++;
                  if (new_end < _end) {
                     _alloc.destroy(new_end);
                  }
                  _alloc.construct(new_end, *ptr);
                  ptr--;
                  new_end--;
               }
               ptr++;
               new_end++;
               while (ptr < new_end)
               {
                  if (ptr < test + removed)
                     _alloc.destroy(ptr);
                  _alloc.construct(ptr, val);
                  ptr++;
               }
               _end = _end + n;
            }

            template <class InputIterator>
               void  insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last) {
                  difference_type   pos = position - _start;
                  difference_type   itrange = last - first;

                  if (!itrange)
                     return ;
                  if (!capacity())
                     reserve(itrange);
                  else if (size() + itrange > capacity() * 2) 
                     reserve(capacity() + itrange);
                  else if (size() + itrange > capacity())
                     reserve(size() * 2);
                  pointer  test;
                  pointer  ptr;
                  pointer  new_end;

                  test = _start + pos;
                  ptr = _end - 1;
                  new_end = ptr + itrange;
                  while (ptr >= test)
                  {
                     if (new_end < _end)
                        _alloc.destroy(new_end);
                     _alloc.construct(new_end, *ptr);
                     ptr--;
                     new_end--;
                  }
                  ptr++;
                  new_end++;
                  while (ptr < new_end) {
                     if (ptr < test)
                        _alloc.destroy(ptr);
                     _alloc.construct(ptr, *first);
                     first++;
                     ptr++;
                  }
                  _end = _end + itrange;
               }

            iterator erase(iterator position) {
               iterator save;

               save = position;
               _alloc.destroy(save);
               while (save + 1 < _end) {
                  _alloc.construct(save, *(save + 1));
                  _alloc.destroy(save + 1);
                  save++;
               }
               _end--;
               return position;
            }

            iterator erase(iterator first, iterator last) {
               iterator save;
               iterator ptr;

               save = first;
               while (save < _end && save < last) {
                  _alloc.destroy(save);
                  save++;
               }
               ptr = first;
               while (save < _end) {
                  _alloc.construct(ptr, *save);
                  _alloc.destroy(save);
                  save++;
                  ptr++;
               }
               _end = _end - (last - first);
               return first;
            }

            void     swap(vector& x) {
               pointer startcpy;
               pointer endcpy;
               pointer capacitycpy;

               startcpy = _start;
               endcpy = _end;
               capacitycpy = _capacity;

               _start = x._start;
               _end = x._end;
               _capacity = x._capacity;

               x._start = startcpy;
               x._end = endcpy;
               x._capacity = capacitycpy;
            }

            void     clear(void) {
               if (_start != NULL)
               {
                  --_end;
                  while (_end >= _start) {
                     _alloc.destroy(_end);
                     _end--;
                  }
                  _end = _start;
               }
            }

            /***** Allocator *****/
            /*********************/

            allocator_type get_allocator() const {
               return _alloc;
            }

         private:

            pointer        _start;
            pointer        _end;
            pointer        _capacity;
            allocator_type _alloc;
      };

   template <class T, class Alloc>
      void  swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
         if (x == y)
            return ;
         x.swap(y);
      }

   /***** Relational operators *****/
   /********************************/

   template <class T, class Alloc>
      bool  operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
         return   (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
      }

   template <class T, class Alloc>
      bool  operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
         return   !(lhs == rhs);
      }
   template <class T, class Alloc>
      bool  operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
         return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
      }
   template <class T, class Alloc>
      bool  operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
         return   !(rhs < lhs);
      }
   template <class T, class Alloc>
      bool  operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
         return rhs < lhs;
      }
   template <class T, class Alloc>
      bool  operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs){
         return !(lhs < rhs);
      }
}

#endif
