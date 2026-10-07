cmake_minimum_required(VERSION 3.16)
project(DigitalImageProcessingWeb LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_library(dip_core STATIC
    core/basic.cpp
    core/spatial.cpp
    core/frequency.cpp
    core/color.cpp
    core/geometry.cpp
)
target_include_directories(dip_core PUBLIC core)
if(NOT MSVC)
    target_compile_options(dip_core PRIVATE -Wall -Wextra)
endif()

if(EMSCRIPTEN)
    # WebAssembly module consumed by site/app.js (ES module factory).
    add_executable(dip bindings/bindings.cpp)
    target_link_libraries(dip PRIVATE dip_core)
    target_link_options(dip PRIVATE
        -lembind
        -sMODULARIZE=1
        -sEXPORT_ES6=1
        -sEXPORT_NAME=createDipModule
        -sENVIRONMENT=web
        -sALLOW_MEMORY_GROWTH=1
        -sMAXIMUM_MEMORY=2GB
    )
    set_target_properties(dip PROPERTIES
        SUFFIX ".js"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/site"
    )
else()
    enable_testing()
    add_executable(core_test tests/core_test.cpp)
    target_link_libraries(core_test PRIVATE dip_core)
    add_test(NAME core_test COMMAND core_test)
endif()
