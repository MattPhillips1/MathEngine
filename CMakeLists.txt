cmake_minimum_required(VERSION 3.14.2)
project(MathEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set(GCC_COMPILE_FLAGS "-Wall  -Werror -Wpedantic -Wno-variadic-macros -Wno-long-long -Wno-shadow -O2")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

enable_testing()
add_subdirectory(mathengine)
add_subdirectory(tests)

# install(TARGETS MathEngine DESTINATION lib)
# install(FILES math_engine.h DESTINATION include)
