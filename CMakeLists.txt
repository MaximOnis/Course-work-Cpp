cmake_minimum_required(VERSION 3.24)
project(Course_work1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Course_work1 main.cpp Subject/Subject.cpp Subject/Subject.h Student/Student.h Student/Student.cpp Group/Group.h Group/Group.cpp Unik/Unik.h Unik/Unik.cpp)
