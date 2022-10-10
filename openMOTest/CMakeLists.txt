cmake_minimum_required(VERSION 3.16)

include_directories(${CMAKE_SOURCE_DIR})
add_executable(testBracket ${CMAKE_CURRENT_SOURCE_DIR}/testBracket.cxx)
target_link_libraries(testBracket
    Eigen3::Eigen
)