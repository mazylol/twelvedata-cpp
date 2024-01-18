cmake_minimum_required(VERSION 3.16)
project(twelvedata)

set(CMAKE_CXX_STANDARD 20)

add_library(${PROJECT_NAME}
        include/twelvedata.h
        src/twelvedata.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(${PROJECT_NAME}_test test.cpp)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME})