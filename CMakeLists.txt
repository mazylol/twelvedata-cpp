cmake_minimum_required(VERSION 3.16)
project(twelvedata)

# enable ccache
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

set(CMAKE_CXX_STANDARD 20)

set(ENV_FILE_SOURCE ${CMAKE_SOURCE_DIR}/.env)
set(ENV_FILE_DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/.env)
configure_file(${ENV_FILE_SOURCE} ${ENV_FILE_DESTINATION} COPYONLY)

add_library(${PROJECT_NAME} STATIC
        include/twelvedata.h
        src/twelvedata.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE ON
)

include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#7.1.3")
CPMAddPackage("gh:nlohmann/json@3.10.5")
CPMAddPackage("gh:libcpr/cpr#1.10.5") # subject to change

target_link_libraries(${PROJECT_NAME} fmt::fmt nlohmann_json::nlohmann_json cpr::cpr)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

CPMAddPackage("gh:laserpants/dotenv-cpp#432def2fb9c2a5e51e6d491f35f2e8f35fa900b0")

add_executable(${PROJECT_NAME}_test test.cpp)
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} dotenv)

set_target_properties(${PROJECT_NAME}_test PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)