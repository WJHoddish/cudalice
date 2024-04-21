option(CUDALICE_BUILD_TESTING "You need" ON)
option(CUDALICE_BUILD_SAMPLES "" ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ##############################################################################
# CUDA compiler setup
# ##############################################################################

if(POLICY CMP0146)
  cmake_policy(SET CMP0146 OLD)
endif()

find_package(CUDA REQUIRED)

if(CUDA_FOUND)
  enable_language(CUDA)
  add_definitions(-DBUILD_CUDA)

  include_directories(${CUDA_INCLUDE_DIRS})
endif()

# ##############################################################################
# Dependencies
# ##############################################################################

find_package(GTest REQUIRED)
find_package(gflags REQUIRED)
find_package(glog REQUIRED)

find_package(fmt REQUIRED)

find_package(OpenBLAS REQUIRED)
include_directories(${OpenBLAS_INCLUDE_DIRS})

# ##############################################################################
# Retrieve sources and build library
# ##############################################################################

include(Targets.cmake)
