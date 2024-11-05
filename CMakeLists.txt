cmake_minimum_required(VERSION 3.16)
project(twelvedata)

# Enable compile commands export for easier debugging
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Option to use ccache for faster builds
option(USE_CCACHE "Use ccache for compilation" ON)
if (USE_CCACHE)
    find_program(CCACHE_PROGRAM ccache)
    if (CCACHE_PROGRAM)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    endif ()
endif ()

# Create a static library
add_library(${PROJECT_NAME} STATIC)

# Define source files for the library
target_sources(${PROJECT_NAME} PRIVATE
        # Core components
        src/core/CurrencyConversion.cpp
        src/core/EndOfDayPrice.cpp
        src/core/ExchangeRate.cpp
        src/core/Quote.cpp
        src/core/RealTimePrice.cpp
        src/core/TimeSeries.cpp

        # Reference data components
        src/reference/Bondlist.cpp
        src/reference/Commoditieslist.cpp
        src/reference/Countries.cpp
        src/reference/Cryptocurrencyexchanges.cpp
        src/reference/Cryptolist.cpp
        src/reference/EarliestTimestamp.cpp
        src/reference/Etflist.cpp
        src/reference/Exchanges.cpp
        src/reference/Forexlist.cpp
        src/reference/Fundlist.cpp
        src/reference/Indiceslist.cpp
        src/reference/InstrumentType.cpp
        src/reference/MarketState.cpp
        src/reference/Stocklist.cpp
        src/reference/SymbolSearch.cpp
)

# Macro to set common target properties
macro(set_common_properties target)
    set_target_properties(${target} PROPERTIES
            CXX_STANDARD 20
            CXX_STANDARD_REQUIRED ON
            POSITION_INDEPENDENT_CODE ON
    )
endmacro()

# Set properties for the main library
set_common_properties(${PROJECT_NAME})

# Include CPM.cmake for package management
include(cmake/CPM.cmake)

# Add external dependencies using CPM
CPMAddPackage("gh:nlohmann/json@3.11.3")

# Link external libraries to the project
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

# Include directories for the library
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Configuration for testing
if (BUILD_TESTING)
    # Configure environment file for testing
    set(ENV_FILE_SOURCE ${CMAKE_SOURCE_DIR}/.env)
    set(ENV_FILE_DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/.env)
    configure_file(${ENV_FILE_SOURCE} ${ENV_FILE_DESTINATION} COPYONLY)

    # Add testing dependencies
    CPMAddPackage("gh:mazylol/dotenvloader@1.0")
    CPMAddPackage("gh:libcpr/cpr#1.10.5") # subject to change

    # Create test executable
    add_executable(${PROJECT_NAME}_test test.cpp)
    target_link_libraries(${PROJECT_NAME}_test PRIVATE ${PROJECT_NAME} dotenvloader cpr::cpr)

    # Set properties for the test executable
    set_common_properties(${PROJECT_NAME}_test)
endif ()

# Installation configuration
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

# Install header files under /usr/local/include/twelvedata
install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.hpp"
)