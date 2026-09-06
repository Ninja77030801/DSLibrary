cmake_minimum_required(VERSION 3.15)
project(DSLibrary VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DSLibrary INTERFACE)

target_include_directories(DSLibrary
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(DSLibrary INTERFACE cxx_std_20)