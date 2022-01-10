#minimum cmake version number
cmake_minimum_required(VERSION 3.0)

# define project parameters
project(
    media
    VERSION 1.0
    DESCRIPTION "a simple media player"
    LANGUAGES CXX
)

# add main executable
add_executable(
    media
    src/main.cpp
)
target_link_libraries(
    media
    sfml-audio
    sfml-graphics
    sfml-window
    sfml-system
)

# create main target
target_compile_features(
    media
    PRIVATE
    cxx_std_11
)

# set conpiler warning level
# Crossplatform
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(
        media
        PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(media PRIVATE /W4)
endif()