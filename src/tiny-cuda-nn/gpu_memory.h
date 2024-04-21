// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-20

#ifndef CUDALICE_GPU_MEMORY_H
#define CUDALICE_GPU_MEMORY_H

#include <cuda.h>
#include <cuda_runtime_api.h>

#include <atomic>

#include "tiny-cuda-nn/common_host.h"

#define DEBUG_GUARD_SIZE 0

namespace alice {

inline std::atomic<size_t>& total_n_bytes_allocated() {
  static std::atomic<size_t> s_total_n_bytes_allocated{0};

  return s_total_n_bytes_allocated;
}

template <class T>
class GPUMemory {
  T*     m_data = nullptr;
  size_t m_size = 0;

 public:
  GPUMemory() {}

  GPUMemory(size_t size) { resize(size); }

  void allocate_memory(size_t n_bytes) {
    if (n_bytes == 0) {
      return;
    }

    uint8_t* rawptr = nullptr;

    CUDA_CHECK_THROW(
        cudaMalloc((void**)&rawptr, n_bytes + DEBUG_GUARD_SIZE * 2));

    if (rawptr) rawptr += DEBUG_GUARD_SIZE;
    m_data = (T*)(rawptr);
    total_n_bytes_allocated() += n_bytes;
  }

  void free_memory() {
    if (!m_data) {
      return;
    }

    uint8_t* rawptr = (uint8_t*)m_data;
    if (rawptr) rawptr -= DEBUG_GUARD_SIZE;
    CUDA_CHECK_THROW(cudaFree(rawptr));

    total_n_bytes_allocated() -= get_bytes();

    m_data = nullptr;
    m_size = 0;
  }

  void resize(const size_t size) {
    if (m_size != size) {
      if (m_size) {
        try {
          free_memory();
        } catch (const std::runtime_error& error) {
          throw std::runtime_error{
              fmt::format("Could not free memory: {}", error.what())};
        }
      }

      if (size > 0) {
        try {
          allocate_memory(size * sizeof(T));
        } catch (const std::runtime_error& error) {
          throw std::runtime_error{
              fmt::format("Could not allocate memory: {}", error.what())};
        }
      }

      m_size = size;
    }
  }

  size_t get_bytes() const { return m_size * sizeof(T); }
};

}  // namespace alice

#endif  // CUDALICE_GPU_MEMORY_H
