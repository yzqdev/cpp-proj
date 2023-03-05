cmake_minimum_required(VERSION 3.13)
project(ctutor)

set(CMAKE_CXX_STANDARD 14)

#set(INC_DIR ~\\ClionProjects\\cpp1\\include)
#set(LINK_DIR ~\\Codes\\ClionProjects\\cpp1\\lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
#link_libraries(wfdb)
add_executable(cpptutor Main.cpp NumOperate.cpp NumOperate.h FileOperate.cpp FileOperate.h DynamicMemory.cpp DynamicMemory.h Arraytest.cpp Arraytest.h func/Pointers.cpp func/Pointers.h polymorphism/Rectangle.cpp polymorphism/Rectangle.h MultiThread.cpp MultiThread.h MyExcetion.cpp MyExcetion.h Peektest.cpp Peektest.h langpack/Clang.cpp langpack/Clang.h langpack/Cpplang.cpp langpack/Cpplang.h Student.cpp Student.h AddScore.cpp AddScore.h Temp.cpp Temp.h Datatype.cpp Datatype.h Pointers/Dogspointer.cpp Pointers/Dogspointer.h Pointers/String.cpp Pointers/String.h leetcode/Leet1.cpp leetcode/Leet1.h)
