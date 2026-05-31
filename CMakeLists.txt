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
    external/glm
)

# executable
add_executable(
    OpenGLDebugger
    src/main.cpp
    src/Shader.cpp
    src/Camera.cpp
)

target_include_directories(
    OpenGLDebugger
    PRIVATE
    src
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

# copy shaders to output directory after build
add_custom_command(TARGET OpenGLDebugger POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/shaders
    $<TARGET_FILE_DIR:OpenGLDebugger>/shaders
)
