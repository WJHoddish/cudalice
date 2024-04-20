// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-18

#include "math_functions.h"

namespace alice {

template <>
void caffe_gpu_gemm<float>(const CBLAS_TRANSPOSE TransA,
                           const CBLAS_TRANSPOSE TransB,
                           const int             M,
                           const int             N,
                           const int             K,
                           const float           alpha,
                           const float*          A,
                           const float*          B,
                           const float           beta,
                           float*                C) {
  int lda = (TransA == CblasNoTrans) ? K : M;
  int ldb = (TransB == CblasNoTrans) ? N : K;

  cublasOperation_t cuTransA =
      (TransA == CblasNoTrans) ? CUBLAS_OP_N : CUBLAS_OP_T;
  cublasOperation_t cuTransB =
      (TransB == CblasNoTrans) ? CUBLAS_OP_N : CUBLAS_OP_T;

  CUBLAS_CHECK(cublasSgemm(Caffe::cublas_handle(),
                           cuTransB,
                           cuTransA,
                           N,
                           M,
                           K,
                           &alpha,
                           B,
                           ldb,
                           A,
                           lda,
                           &beta,
                           C,
                           N));
}

}  // namespace alice