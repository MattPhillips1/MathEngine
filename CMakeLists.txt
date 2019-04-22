cmake_minimum_required(VERSION 3.14.2)
project(MathEngine)

enable_testing()
# add_library(MathEngine STATIC mathengine/math_engine.cpp)
add_subdirectory(mathengine)
add_subdirectory(tests)

# install(TARGETS MathEngine DESTINATION lib)
# install(FILES math_engine.h DESTINATION include)
