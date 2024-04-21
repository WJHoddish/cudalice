// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-18

#ifndef CUDALICE_MATH_FUNCTIONS_H
#define CUDALICE_MATH_FUNCTIONS_H

#include <cblas.h>

#include <cmath>

#include "caffe/common.h"

namespace alice {

template <typename Dtype>
void caffe_gpu_gemm(const CBLAS_TRANSPOSE TransA,
                    const CBLAS_TRANSPOSE TransB,
                    const int             M,
                    const int             N,
                    const int             K,
                    const Dtype           alpha,
                    const Dtype*          A,
                    const Dtype*          B,
                    const Dtype           beta,
                    Dtype*                C);

}  // namespace alice

#endif  // CUDALICE_MATH_FUNCTIONS_H
