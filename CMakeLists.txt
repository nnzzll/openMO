cmake_minimum_required(VERSION 3.0.0)
project(openMO VERSION 0.1.0 LANGUAGES C CXX)

include_directories(
    "Include"
    "${CMAKE_SOURCE_DIR}"
)

add_subdirectory(openMOTest)