cmake_minimum_required(VERSION 3.21)
project(Lectures)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(echo echo/main.cpp)
add_executable(commandline commandline/main.cpp)
add_executable(best_practices
        best_practices/main.cpp
        best_practices/student_info.cpp)
add_executable(stringstream stringstream/main.cpp)
add_executable(vector vector/main.cpp)
add_executable(dynamic_array dynamic_array/main.cpp)
add_executable(linkedlist linkedlist/main.cpp)
add_executable(queues queues/main.cpp)
add_executable(stacks stacks/main.cpp stacks/stack.cpp stacks/grade.cpp)
add_executable(palindrome palindrome/main.cpp)
add_executable(recursion recursion/main.cpp)
add_executable(factorial factorial/main.cpp)
add_executable(binarysearchtree binarysearchtree/main.cpp)
add_executable(bubblesort bubblesort/main.cpp)
add_executable(selectionsort selectionsort/main.cpp)
add_executable(insertionsort insertionsort/main.cpp)
add_executable(shellsort shellsort/main.cpp)