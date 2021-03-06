/// @file utility.h
/// @data 01/03/2014 23:02:55
/// @author Ambroise Leclerc
/// @brief
//
// Embedded Template Library
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


#ifndef ETL_LIBSTD_UTILITY_H_
#define ETL_LIBSTD_UTILITY_H_

namespace std {

/// Returns an rvalue reference to arg and converts arg to an xvalue.
/// @param arg object to be moved
/// @return rvalue reference to arg
template<typename T>
typename remove_reference<T>::type&& move(T&& arg) noexcept {
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}  

/// Forwards arg to another function exactly as it was passed to the calling function
/// @param arg object to be forwarded
template<typename T>
constexpr T&& forward(typename std::remove_reference<T>::type& arg) noexcept {
  return static_cast<T&&>(arg);
}

/// Forwards arg to another function exactly as it was passed to the calling function
/// @param arg object to be forwarded
template<typename T>
constexpr T&& forward(typename std::remove_reference<T>::type&& arg) noexcept {
  static_assert(!std::is_lvalue_reference<T>::value, "not a rvalue reference");
  return static_cast<T&&>(arg);
}


} // namespace std
#endif /* ETL_LIBSTD_UTILITY_H_ */