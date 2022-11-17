#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <functional>
#if __x86_64__
#define ARCH 64
#else
#define ARCH 32
#endif 

#include <memory>
#include <cmath>
#include "reverse_iterator.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

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
               while (_end != _start)
                  _alloc.destroy(_end--);
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
                  _start = _alloc.allocate(n);
                  _end = _start;
                  _capacity = _start + n;
                  while (_end != _capacity)
                     _alloc.construct(_end++, val);
               }

            /* Range constructor */
            /* Construct a container with as many elements as the range [first, last],
             * with each element constructed from its corresponding element in that range, in the same order */
            template <class InputIterator>
               vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
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
               return _end + 1;
            }

            const_iterator end(void) const {
               return _end + 1;
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
               return ((size_type)(pow(2, ARCH)) / sizeof(T) - 1);
               //return _alloc.max_size();
            }

            size_type   capacity(void) const {
               return _capacity - _start;
            }

            bool        empty(void) const {
               return (_start == _end ? true : false);
            }

            void        reserve(size_type n) {
               if (!n)
                  reserve(1);
               if (n > capacity()) {
                  pointer  start;
                  size_type   cap;

                  start = _alloc.allocate(n);
                  for (pointer end = start; end != _end; end++)
                     _alloc.construct(end, *_end);
                  clear();
                  cap = capacity();
                  if (cap)
                     _alloc.deallocate(_start, cap);
                  _start = start;
                  _capacity = _start + n;
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
               return *(_end);
            }
            const_reference back(void) const {
               return *(_end);
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
                  for (pointer ptr = _start; ptr < _capacity; ptr++)
                     _alloc.destroy(ptr);
                  _alloc.deallocate(_start, capacity());
                  _start = _alloc.allocate(n);
                  for (_end = _start; _end < _start + n; _end++)
                     _alloc.construct(_end, val);
                  _capacity = _start + n;
               }
            }

            template <class InputIterator>
               void  assign(InputIterator first, InputIterator last) {
                  if (capacity()) {
                     clear();
                     _alloc.deallocate(_start, capacity());
                  }
                  size_type n;

                  n = last - first;
                  _start = _alloc.allocate(n);
                  for (_end = _start; _end < _start + n; _end++)
                     _alloc.construct(_end, *(first++));
                  _capacity = _end;
               }

            void     push_back(const value_type& val) {
               if (size() + 1 > capacity())
                  reserve(capacity() * 2);
               _alloc.construct(++_end, val);
            }

            void     pop_back(void) {
               _alloc.destroy(_end--);
            }

            iterator insert(iterator position, const value_type& val) {
               if (size() + 1 > capacity())
                  reserve(capacity() * 2);
               pointer  tmp;

               tmp = _end - 1;
               for (; tmp != position; tmp--) {
                  _alloc.construct(_end, *(tmp));
                  _alloc.destroy(tmp);
               }
               _alloc.construct(tmp, val);
               return position;
            }

            void     insert(iterator position, size_type n, const value_type &val) {
               while (size() + n > capacity())
                  reserve(capacity() * 2);
               pointer  tmp;
               pointer  save;
               pointer  ptr;

               tmp = _end - 1;
               save = tmp;
               _end += n;
               ptr = _end - 1;
               for (; tmp != position; tmp--) {
                  _alloc.construct(ptr--, *(tmp));
                  _alloc.destroy(tmp);
               }
               for (; tmp != save; tmp++) 
                  _alloc.construct(tmp, val);
            }

            template <class InputIterator>
               void  insert(iterator position, InputIterator first, InputIterator last) {
                  size_type   n;

                  n = last - first;
                  while (size() + n > capacity())
                     reserve(capacity() * 2);

                  pointer  tmp;
                  pointer  ptr;

                  tmp = _end - 1;
                  _end += n;
                  ptr = _end - 1;
                  for (; tmp != position; tmp--) {
                     _alloc.construct(ptr--, *(tmp));
                     _alloc.destroy(tmp);
                  }
                  while (first != last)
                     _alloc.construct(tmp, *(first)++);
               }

            iterator erase(iterator position) {
               iterator save;

               save = position;
               _alloc.destroy(save);
               while (save < _end) {
                  _alloc.construct(save, *(save + 1));
                  save++;
               }
               return position;
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
               while (_end != _start)
                  _alloc.destroy(_end--);
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
