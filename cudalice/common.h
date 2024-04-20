// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-19

#ifndef CUDALICE_COMMON_H
#define CUDALICE_COMMON_H

#include <cublas_v2.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <curand.h>
#include <glog/logging.h>

#include "cudalice/utils/non_copyable.h"

#define CUBLAS_CHECK(condition)                        \
  do {                                                 \
    cublasStatus_t status = condition;                 \
    CHECK_EQ(status, CUBLAS_STATUS_SUCCESS)            \
        << " " << alice::cublasGetErrorString(status); \
  } while (0)

namespace alice {

class Caffe : private NonCopyable<Caffe> {
 public:
  ~Caffe();

  static Caffe& Get();

  static const cublasHandle_t& cublas_handle() { return Get().cublas_handle_; }

 protected:
  cublasHandle_t cublas_handle_;

 private:
  Caffe();
};

// CUDA: library error reporting.
const char* cublasGetErrorString(cublasStatus_t);

}  // namespace alice

#endif  // CUDALICE_COMMON_H
