cmake_minimum_required(VERSION 3.23)
project(Boids)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/CPP_Libs/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

# Define directories and the contained folder and files inside.
if(WIN32)
    source_group("include" REGULAR_EXPRESSION "include/*")
    source_group("src" REGULAR_EXPRESSION "src/*")
endif(WIN32)

# Gather list of header and source files for compilation
file(GLOB_RECURSE CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(Boids ${CPP_FILES} ${HPP_FILES})

include_directories(C:/CPP_Libs/SFML/include)
target_link_libraries(Boids sfml-system sfml-window sfml-graphics sfml-audio)
