cmake_minimum_required(VERSION 3.16)

include_directories(${CMAKE_SOURCE_DIR})
add_executable(testBracket ${CMAKE_CURRENT_SOURCE_DIR}/testBracket.cxx)
target_link_libraries(testBracket
    Eigen3::Eigen
)

add_executable(testBrent ${CMAKE_CURRENT_SOURCE_DIR}/testBrent.cxx)
target_link_libraries(testBrent
    Eigen3::Eigen
)

add_executable(testPowell ${CMAKE_CURRENT_SOURCE_DIR}/testPowell.cxx)
target_link_libraries(testPowell
    Eigen3::Eigen
)