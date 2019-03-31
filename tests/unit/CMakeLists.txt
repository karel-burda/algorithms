cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(tests LANGUAGES C CXX)

message(STATUS "Building unit tests")

include(${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/cmake-helpers/cmake-helpers/cpp_gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../submodules/cmake-helpers/cmake-helpers/cpp_warnings.cmake)

add_executable(${PROJECT_NAME} "")

target_sources(${PROJECT_NAME}
                   PRIVATE
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/bits/bits.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/bytes/endianness.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/number/prime.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/number/swap.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/searching/binary_search.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/sorting/mergesort.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/sorting/quicksort.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/sorting/radix.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/permutation.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/reverse.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/strlen.cpp
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/unique.cpp

                       ${CMAKE_CURRENT_SOURCE_DIR}/src/structures/bit_array.cpp)


find_package(test-utils CONFIG REQUIRED)
message(STATUS "Found version of test-utils is: ${test-utils_VERSION}")
target_link_libraries(${PROJECT_NAME} PRIVATE burda::test-utils)

find_package(algorithms CONFIG REQUIRED)
message(STATUS "Found version of algorithms is: ${algorithms_VERSION}")
target_link_libraries(${PROJECT_NAME} PRIVATE burda::algorithms)

target_compile_options(${PROJECT_NAME}
                           PRIVATE
                               $<$<CXX_COMPILER_ID:MSVC>:/MP>)

burda_cmake_helpers_cpp_gtest_bootstrap_and_link(${PROJECT_NAME} "release-1.8.1" "Release" PRIVATE)

enable_testing()

add_test(NAME all-unit-tests
         COMMAND $<TARGET_FILE:${PROJECT_NAME}> --gtest_color=yes --gtest_shuffle)

add_custom_target(run-all-tests-verbose
                  COMMAND ${CMAKE_CTEST_COMMAND} -V -C ${CMAKE_BUILD_TYPE} --build-run-dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} --timeout 300
                  DEPENDS ${PROJECT_NAME})
