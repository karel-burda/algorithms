cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(algorithms VERSION 0.3.0 LANGUAGES C)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
                   PUBLIC
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms/error_code.h

                       ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms/searching/binary_search.h
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms/number/swap.h
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms/string/reverse.h
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms/string/strlen.h
                       ${CMAKE_CURRENT_SOURCE_DIR}/include/algorithms/string/unique.h

                   PRIVATE
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/searching/binary_search.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/number/swap.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/reverse.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/strlen.c
                       ${CMAKE_CURRENT_SOURCE_DIR}/src/algorithms/string/unique.c)

target_include_directories(${PROJECT_NAME}
                                PUBLIC
                                    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(${PROJECT_NAME}
                            PUBLIC
                                c_std_11)

install(TARGETS ${PROJECT_NAME}
        DESTINATION lib
        EXPORT _targets)

export(EXPORT _targets
       NAMESPACE burda::
       FILE "${PROJECT_NAME}-config.cmake")

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
                                 COMPATIBILITY ExactVersion)
