// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-18

#include "math_functions.h"

#include <gtest/gtest.h>

#define M 2
#define N 3
#define K 4

using namespace alice;

TEST(math_functions, math_functions) {
  float* A = new float[M * K];
  float* X = new float[N * K];
  float* Y = new float[M * N];

  for (int i = 0; i < M * K; ++i) A[i] = i + 1;
  for (int i = 0; i < N * K; ++i) X[i] = i + 2;

  float *dA, *dX, *dY;

  cudaMalloc(&dA, M * K * sizeof(float));
  cudaMalloc(&dX, N * K * sizeof(float));
  cudaMalloc(&dY, M * N * sizeof(float));

  cudaMemcpy(dA, A, M * K * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(dX, X, N * K * sizeof(float), cudaMemcpyHostToDevice);

  {
    caffe_gpu_gemm(
        CblasNoTrans, CblasNoTrans, M, N, K, float(1), dA, dX, float(0), dY);
  }

  cudaMemcpy(Y, dY, M * N * sizeof(float), cudaMemcpyDeviceToHost);

  {
    for (int i = 0; i < M * N; ++i) std::cout << Y[i] << ", ";
    std::cout << "\n";
  }

  delete[] A;
  delete[] X;
  delete[] Y;

  cudaFree(dA);
  cudaFree(dX);
  cudaFree(dY);
}