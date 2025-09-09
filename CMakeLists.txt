cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

# Create library from shared code
add_library(rpn_lib STATIC src/rpn.cpp)

# Create main executable
add_executable(rpn_calculator src/main.cpp)
target_link_libraries(rpn_calculator PRIVATE rpn_lib)

enable_testing()
add_subdirectory(tests)
