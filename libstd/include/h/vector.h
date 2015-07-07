/// @file vector
/// @data 17/04/2014 16:34:53
/// @author Ambroise Leclerc
/// @brief Vector container.
//
// Copyright (c) 2014, Ambroise Leclerc
//   All rights reserved.
//
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in
//     the documentation and/or other materials provided with the
//     distribution.
//   * Neither the name of the copyright holders nor the names of
//     contributors may be used to endorse or promote products derived
//     from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 'AS IS'
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.

#ifndef ETL_LIBSTD_VECTOR_H_
#define ETL_LIBSTD_VECTOR_H_

namespace std {

template<typename T, typename Allocator = std::allocator<T>>
class vector {
 public:
  using value_type              = T;
  using allocator_type          = Allocator;
  using size_type               = std::size_t;
  using difference_type	        = std::ptrdiff_t;
  using reference               = value_type&;
  using const_reference	        = const value_type&;
  using pointer	                = std::allocator_traits<Allocator>::pointer;
  using const_pointer           = std::allocator_traits<Allocator>::const_pointer;
  using iterator                = T*;
  using const_iterator          = const T*;
  using reverse_iterator        = std::reverse_iterator<iterator>;
  using const_reverse_iterator  = std::reverse_iterator<const_iterator>;
  
  // Constructors
  vector() : vector(Allocator()) {}
  explicit vector(const Allocator& alloc) : vector(etl::architecture::kDefaultBufferSize, alloc) {}
  vector(size_type count, const T& value, const Allocator& alloc = Allocator())
   : size_(ETL_DEFAULT_BUFFER_SIZE + count), buffer_(alloc.allocate(size_), nb_elements_(0), allocator_(alloc) {
     assign(begin(), end());
  }
  explicit vector(size_type count, const Allocator& alloc = Allocator())
   : size_(count), buffer_(alloc.allocate(size_), nb_elements_(0), allocator_(alloc) {}
  vector(const vector& other);
  vector(const vector& other, const Allocator& alloc);
  vector(vector&& other)
  vector(vector&& other, const Allocator& alloc);
  vector(std::initializer_list<T> init, const Allocator& alloc = Allocator());
  
  template<typename InputIt>
  vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
  
  
  
 protected:
  T* buffer_;
  Allocator allocator_;
  std::size_t nb_elements_;
  std::size_t size_;
  
};  

} // namespace std

#endif // ETL_LIBSTD_VECTOR_H_