cmake_minimum_required(VERSION 3.13.4)

project(strukdat)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5
    COMPONENTS
        system window graphics network audio REQUIRED)

add_executable(${PROJECT_NAME} src/source/main.cpp)

add_subdirectory(src/include)

target_link_libraries(${PROJECT_NAME} myFunction nodeDraw sfml-graphics)
# install(TARGETS S)
