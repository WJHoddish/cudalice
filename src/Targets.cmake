function(set_compile_options_to_cudalice_target target)
  set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                                             ${CMAKE_BINARY_DIR}/cudalice)

  target_link_libraries(
    ${target} PUBLIC ${CUDA_LIBRARIES} ${CUDA_cublas_LIBRARY}
                     ${OpenBLAS_LIBRARIES} glog::glog fmt::fmt)
endfunction()

function(cudalice_add_library)
  add_library(${ARGV})
  set_compile_options_to_cudalice_target(${ARGV0})
endfunction()

# ##############################################################################

file(
  GLOB
  cudalice_all_src
  "${CMAKE_CURRENT_SOURCE_DIR}/caffe/*.*"
  "${CMAKE_CURRENT_SOURCE_DIR}/tiny-cuda-nn/*.*"
  "${CMAKE_CURRENT_SOURCE_DIR}/cudalice/kernels/*.*"
  "${CMAKE_CURRENT_SOURCE_DIR}/cudalice/utils/*.*")

foreach(cudalice_single_file ${cudalice_all_src})
  if(${cudalice_single_file} MATCHES
     "^${CMAKE_CURRENT_SOURCE_DIR}/.*.(cpp|cu)$")
    if(${cudalice_single_file} MATCHES "_test.cpp$")
      # test file
      list(APPEND cudalice_all_test_cc ${cudalice_single_file})
    else()
      list(APPEND cudalice_all_obj_cc ${cudalice_single_file})
    endif()
  endif()

endforeach()

cudalice_add_library(cudalice SHARED ${cudalice_all_obj_cc})

# build test
if(CUDALICE_BUILD_TESTING)
  if(cudalice_all_test_cc)
    add_executable(cudalice_test ${cudalice_all_test_cc})
    target_link_libraries(cudalice_test cudalice ${GTEST_BOTH_LIBRARIES})
  endif()
endif()

if(CUDALICE_BUILD_SAMPLES)
  add_subdirectory(samples)
endif()
