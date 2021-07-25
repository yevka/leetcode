cmake_minimum_required(VERSION 3.19)
project(cpp_skeleton VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(NOT EXISTS ${CMAKE_BUILD_TYPE})
    set(CMAKE_BUILD_TYPE "Debug")
endif()

#######################################################################################################
# Conan
#######################################################################################################
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.16.1/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake"
                  EXPECTED_HASH SHA256=396e16d0f5eabdc6a14afddbcfff62a54a7ee75c6da23f32f7a31bc85db23484
                  TLS_VERIFY ON)
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_configure(REQUIRES gtest/1.11.0 GENERATORS cmake_find_package)
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conan-center
                    SETTINGS ${settings})
#######################################################################################################

find_package(GTest REQUIRED)

enable_testing()
file(GLOB_RECURSE SRCS *.cc)
add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    GTest::gtest
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
