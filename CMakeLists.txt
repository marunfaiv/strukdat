cmake_minimum_required(VERSION 3.13.4)

project(strukdat)

add_executable(${PROJECT_NAME} src/source/main.cpp)

add_subdirectory(src/include)

target_link_libraries(${PROJECT_NAME} myFunction)
