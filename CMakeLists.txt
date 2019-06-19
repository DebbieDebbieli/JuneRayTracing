#test cmake
#set(test_message "test vscode and cmake")
#message(STATUS "test_message: ${test_message}")

#project name
project(JuneRayTracing)

#compiler
set(CMAKE_CXX_COMPILER "g++")

set(JuneRayTracing_SRCS
    "rgb.cpp"
    "Image.cpp"
    "Vector3.cpp"
    "ONB.cpp"
    "JuneRayTracing.cpp")

add_executable(JuneRayTracing WIN32 ${JuneRayTracing_SRCS})