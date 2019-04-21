cmake_minimum_required(VERSION 3.14.2)

project(MathEngine)

# add_library(MathEngine STATIC mathengine/math_engine.cpp)
add_executable(math_engine mathengine/math_engine.cpp)

# install(TARGETS MathEngine DESTINATION lib)
# install(FILES math_engine.h DESTINATION include)
