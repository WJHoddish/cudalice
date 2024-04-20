if(POLICY CMP0146)
  cmake_policy(SET CMP0146 OLD)
endif()

# ##############################################################################

find_package(CUDA REQUIRED)

if(CUDA_FOUND)
  enable_language(CUDA)
  add_definitions(-DBUILD_CUDA)

  include_directories(${CUDA_INCLUDE_DIRS})
endif()
