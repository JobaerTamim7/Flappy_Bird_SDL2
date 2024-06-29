cmake_minimum_required(VERSION 3.5)
project(FlappyBird LANGUAGES CXX)

set(SDL2_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL2/cmake)
set(SDL2_image_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL2_image/cmake)
set(SDL2_ttf_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL2_ttf/cmake)
set(SDL2_mixer_DIR ${CMAKE_CURRENT_LIST_DIR}/SDL2_mixer/cmake)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS} ${SDL2_ttf_INCLUDE_DIRS} ${SDL2_mixer_INCLUDE_DIRS})

file(GLOB SOURCES src/*.cpp)

add_executable(FlappyBird ${SOURCES})

target_link_libraries(FlappyBird SDL2::SDL2main SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer)


