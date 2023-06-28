cmake_minimum_required(VERSION 3.16)
include_directories(${CMAKE_SOURCE_DIR}/openMO)

add_executable(testBounded
    testBounded.cxx
)

add_executable(testBracket
    testBracket.cxx
)

add_executable(testBrent
    testBrent.cxx
)

add_executable(testPowell
    testPowell.cxx
)
