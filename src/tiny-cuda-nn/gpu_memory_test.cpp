// Copyright (c) CNIC. 2024. All rights reserved.
// Author: Jiaheng Wang
// Date: 2024-04-21

#include "gpu_memory.h"

#include <gtest/gtest.h>

using namespace alice;

TEST(gpu_memory, gpu_memory) { auto a = GPUMemory<float>(32); }