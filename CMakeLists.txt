cmake_minimum_required(VERSION 3.16.3)
project(openMO VERSION 0.1.0)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

find_package(Eigen3 REQUIRED NO_MODULE)
if(Eigen3_FOUND)
    message("Eigen3 VERSION:${Eigen3_VERSION}")
else(Eigen3_FOUND)
    message(FATAL_ERROR "Cannot find Eigen3! Please set the Eigen3_DIR")
endif()

set(${PROJECT_NAME}_FILES 
    ${PROJECT_NAME}/common
    ${PROJECT_NAME}/bracket
    ${PROJECT_NAME}/openMO
)

add_library(${PROJECT_NAME} SHARED
    ${${PROJECT_NAME}_FILES}
    )

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(${PROJECT_NAME} Eigen3::Eigen)

if(NOT DEFINED BUILD_TESTING)
    option(BUILD_TESTING "Build with shared libraries" ON)
    message("BUILD_TESTING Defaulst Set To ON.")
endif()

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(${PROJECT_NAME}Test)
endif()
