// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-20

#ifndef CUDALICE_TIMER_H
#define CUDALICE_TIMER_H

#include <chrono>

namespace alice {

struct Timer {
  Timer()
      : m_begin(std::chrono::high_resolution_clock::now()) {}

  int64_t elapsed() const {
    using namespace std::chrono;

    return duration_cast<milliseconds>(high_resolution_clock::now() - m_begin)
        .count();
  }

  void reset() { m_begin = std::chrono::high_resolution_clock::now(); }

  std::chrono::time_point<std::chrono::system_clock> m_begin;
};

}  // namespace alice

#endif  // CUDALICE_TIMER_H
