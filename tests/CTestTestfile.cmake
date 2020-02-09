# CMake generated Testfile for 
# Source directory: /home/matt/Documents/MathEngine/tests
# Build directory: /home/matt/Documents/MathEngine/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Vector "/home/matt/Documents/MathEngine/tests/Vector")
set_tests_properties(Vector PROPERTIES  _BACKTRACE_TRIPLES "/home/matt/Documents/MathEngine/tests/CMakeLists.txt;34;add_test;/home/matt/Documents/MathEngine/tests/CMakeLists.txt;0;")
add_test(Matrix "/home/matt/Documents/MathEngine/tests/Matrix")
set_tests_properties(Matrix PROPERTIES  _BACKTRACE_TRIPLES "/home/matt/Documents/MathEngine/tests/CMakeLists.txt;35;add_test;/home/matt/Documents/MathEngine/tests/CMakeLists.txt;0;")
add_test(Quaternion "/home/matt/Documents/MathEngine/tests/Quaternion")
set_tests_properties(Quaternion PROPERTIES  _BACKTRACE_TRIPLES "/home/matt/Documents/MathEngine/tests/CMakeLists.txt;36;add_test;/home/matt/Documents/MathEngine/tests/CMakeLists.txt;0;")
subdirs("googletest-build")
