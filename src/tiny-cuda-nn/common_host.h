// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-20

#ifndef CUDALICE_COMMON_HOST_H
#define CUDALICE_COMMON_HOST_H

#include <fmt/format.h>

#define STRINGIFY(x) #x
#define STR(x) STRINGIFY(x)
#define FILE_LINE __FILE__ ":" STR(__LINE__)

#define CUDA_CHECK_THROW(x)                                                \
  do {                                                                     \
    cudaError_t _result = x;                                               \
    if (_result != cudaSuccess) {                                          \
      throw std::runtime_error{fmt::format(FILE_LINE " " #x " failed: {}", \
                                           cudaGetErrorString(_result))};  \
    }                                                                      \
  } while (0)

#endif  // CUDALICE_COMMON_HOST_H
