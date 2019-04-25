add_library(MathEngine STATIC Vector.h Vector.cpp Matrix.h Matrix.cpp Quaternion.h Quaternion.cpp)
add_executable(math_engine math_engine.cpp)
target_link_libraries(math_engine MathEngine)
