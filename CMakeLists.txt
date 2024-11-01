cmake_minimum_required(VERSION 3.16)
project(twelvedata)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# enable ccache
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif ()

file(GLOB_RECURSE SOURCE_FILES "src/**/*.cpp" "src/**/*.h")

add_library(${PROJECT_NAME} STATIC
        include/twelvedata.hpp
        ${SOURCE_FILES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        POSITION_INDEPENDENT_CODE ON
)

include(cmake/CPM.cmake)

CPMAddPackage("gh:nlohmann/json@3.11.3")

target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

if(BUILD_TESTING)
    set(ENV_FILE_SOURCE ${CMAKE_SOURCE_DIR}/.env)
    set(ENV_FILE_DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/.env)
    configure_file(${ENV_FILE_SOURCE} ${ENV_FILE_DESTINATION} COPYONLY)

    CPMAddPackage("gh:mazylol/dotenvloader@1.0")
    CPMAddPackage("gh:libcpr/cpr#1.10.5") # subject to change

    add_executable(${PROJECT_NAME}_test test.cpp)
    target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME} dotenvloader cpr::cpr)

    set_target_properties(${PROJECT_NAME}_test PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
    )
endif()
