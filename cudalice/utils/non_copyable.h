// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-19

#ifndef CUDALICE_NON_COPYABLE_H
#define CUDALICE_NON_COPYABLE_H

namespace alice {

/**
 * @brief https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-copyable_Mixin
 *
 * @tparam T
 */
template <class T>
class NonCopyable {
 public:
  NonCopyable(const NonCopyable&) = delete;
  T& operator=(const T&)          = delete;

 protected:
  NonCopyable()  = default;
  ~NonCopyable() = default;  /// Protected non-virtual destructor
};

}  // namespace alice

#endif  // CUDALICE_NON_COPYABLE_H
