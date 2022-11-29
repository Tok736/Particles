cmake_minimum_required(VERSION 3.23)
set(PROJECT_NAME Particles)
project(${PROJECT_NAME})

# ==== Standard and flags ==== #
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS  "-lm -Wno-unknown-pragmas -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -lgcov")
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

# ==== Main directories ==== #
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

# ==== Running main.cpp ==== #
include_directories(${INCLUDE_DIR})
file(GLOB_RECURSE SOURCE_CPPS ${SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_CPPS})

# ==== Linking with cpp math library ==== #
target_link_libraries(${PROJECT_NAME} m)

# ==== Linking with SFML ==== #
set(SFML_DIR "C:\\SFML\\lib\\cmake\\SFML")
target_link_libraries(Particles sfml-graphics)
find_package(SFML 2.5 REQUIRED graphics network audio window system)
