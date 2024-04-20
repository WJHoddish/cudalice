function(set_compile_options_to_cudalice_target target)
  set_target_properties(${target} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
                                             ${CMAKE_BINARY_DIR}/cudalice)

  # FIXME:
  target_link_libraries(${target} ${CUDA_LIBRARIES} ${CUDA_cublas_LIBRARY}
                        ${OpenBLAS_LIBRARIES} glog::glog)
endfunction()

function(cudalice_add_library)
  add_library(${ARGV})
  set_compile_options_to_cudalice_target(${ARGV0})
endfunction()

# ##############################################################################

include(cuda.cmake)
include(glog.cmake)

include(Targets.cmake)
