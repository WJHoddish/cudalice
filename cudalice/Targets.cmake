file(GLOB cudalice_all_src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(cudalice_single_file ${cudalice_all_src})
  if(${cudalice_single_file} MATCHES "_test.cpp$")
    # test file
    list(APPEND cudalice_all_test_cc ${cudalice_single_file})
  endif()
endforeach()

list(REMOVE_ITEM cudalice_all_src ${cudalice_all_test_cc})

cudalice_add_library(cudalice SHARED ${cudalice_all_src})

# build test
if(cudalice_all_test_cc)
  add_executable(test ${cudalice_all_test_cc})
  target_link_libraries(test cudalice ${GTEST_BOTH_LIBRARIES})
endif()
