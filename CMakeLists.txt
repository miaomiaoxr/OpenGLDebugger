cmake_minimum_required(VERSION 3.16)

project(OpenGLDebugger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# GLFW
add_subdirectory(external/glfw)

# GLAD
add_library(glad
    external/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

# executable
add_executable(
    OpenGLDebugger
    src/main.cpp
)

target_include_directories(
    OpenGLDebugger
    PRIVATE
    external/glad/include
)

target_link_libraries(
    OpenGLDebugger
    glfw
    glad
)

# Windows OpenGL
if(WIN32)
    target_link_libraries(
        OpenGLDebugger
        opengl32
    )
endif()

# Linux OpenGL
if(UNIX AND NOT APPLE)

    find_package(OpenGL REQUIRED)

    target_link_libraries(
        OpenGLDebugger
        OpenGL::GL
        dl
        pthread
    )

endif()