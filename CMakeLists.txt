cmake_minimum_required(VERSION 3.14.2)
project(mathengine)

# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
# set(GCC_COMPILE_FLAGS "-Wall  -Werror -Wpedantic -Wno-variadic-macros -Wno-shadow -O3")
# set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

# enable_testing()
add_subdirectory(mathengine)
add_executable(math_engine math_engine.cpp)
# add_subdirectory(tests)


target_link_libraries(math_engine MathEngine)
install(TARGETS math_engine DESTINATION bin)