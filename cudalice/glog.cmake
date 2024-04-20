find_package(GTest REQUIRED)
find_package(gflags REQUIRED)
find_package(glog REQUIRED)

# ##############################################################################

find_package(OpenBLAS REQUIRED)
include_directories(${OpenBLAS_INCLUDE_DIRS})
