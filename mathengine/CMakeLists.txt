project(MathEngine)

add_library(MathEngine STATIC Vector.h Matrix.h MatrixColumn.h)
set_target_properties(MathEngine PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS MathEngine DESTINATION lib)
install(FILES Vector.h Matrix.h MatrixColumn.h DESTINATION include)
