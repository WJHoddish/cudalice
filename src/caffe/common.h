// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-19

#ifndef CUDALICE_COMMON_H
#define CUDALICE_COMMON_H

#include <glog/logging.h>

#include <cmath>
#include <string>

#include "caffe/utils/device_alternate.h"

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

}  // namespace alice

#endif  // CUDALICE_COMMON_H
