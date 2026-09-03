cmake_minimum_required(VERSION 3.16)
project(EdgeScoreX4 LANGUAGES C CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(edgescore_model STATIC model/src/edgescore_model.cpp)
target_include_directories(edgescore_model PUBLIC model/include)
target_compile_options(edgescore_model PRIVATE -Wall -Wextra -Wpedantic)

if(BUILD_TESTING)
  add_subdirectory(third_party/googletest EXCLUDE_FROM_ALL)
  add_executable(edgescore_model_tests tests/cpp/edgescore_model_test.cpp)
  target_link_libraries(edgescore_model_tests PRIVATE edgescore_model GTest::gtest_main)
  target_compile_options(edgescore_model_tests PRIVATE -Wall -Wextra -Wpedantic)
  include(GoogleTest)
  gtest_discover_tests(edgescore_model_tests)
endif()