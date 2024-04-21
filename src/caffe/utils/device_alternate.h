// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-21

#ifndef CUDALICE_DEVICE_ALTERNATE_H
#define CUDALICE_DEVICE_ALTERNATE_H

#include <cublas_v2.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <curand.h>

#include "cudalice/utils/utils.h"

#define CUBLAS_CHECK(condition)                        \
  do {                                                 \
    cublasStatus_t status = condition;                 \
    CHECK_EQ(status, CUBLAS_STATUS_SUCCESS)            \
        << " " << caffe::cublasGetErrorString(status); \
  } while (0)

namespace caffe {

// CUDA: library error reporting.
const char* cublasGetErrorString(cublasStatus_t error);

}  // namespace caffe

#endif  // CUDALICE_DEVICE_ALTERNATE_H
