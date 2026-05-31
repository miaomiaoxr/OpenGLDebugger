# OpenGLDebugger

A lightweight OpenGL renderer/debugging playground built with modern C++ and CMake.

This project is being developed as a graphics engineering learning project with an emphasis on:

- Modern OpenGL rendering pipeline
- GPU programming concepts
- Rendering abstraction
- Shader system design
- Camera and transformation systems
- Graphics debugging workflow

The long-term goal is to evolve this from a simple demo into an engine-style rendering framework.

---

## Current Features

- GLFW window and OpenGL context creation
- GLAD OpenGL loader integration
- VBO / VAO pipeline setup
- Shader compilation and linking
- External GLSL shader files
- Shader abstraction class
- FPS-style camera with mouse/keyboard input
- MVP matrix pipeline (model / view / projection)
- Depth testing
- 3D cube rendering with per-face vertex colors

---

## Project Structure

```text
OpenGLDebugger/
├── external/
│   ├── glad/
│   ├── glfw/
│   └── glm/
│
├── shaders/
│   ├── triangle.vert
│   └── triangle.frag
│
├── src/
│   ├── main.cpp
│   ├── Shader.h
│   ├── Shader.cpp
│   ├── Camera.h
│   └── Camera.cpp
│
├── CMakeLists.txt
└── README.md
```

---

## Build

### Option 1: Command Line (CMake + Ninja)

Configure:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build
```

Run:

```bash
./build/OpenGLDebugger
```


---

### Option 2: Visual Studio

Open the project folder directly in Visual Studio.

Visual Studio will automatically detect:

- CMakeLists.txt
- Ninja toolchain
- MSVC compiler

Then:

```text
Build → Build All
```

or:

```text
Ctrl + Shift + B
```

Executable output is typically generated under:

```text
out/build/x64-Debug/
```

---

## Development Roadmap

Planned features:

### Rendering Core

- [x] MVP matrix pipeline
- [x] Uniform abstraction system
- [x] Camera system
- [x] FPS-style movement controls
- [ ] Mesh abstraction

### Rendering Features

- [x] Vertex color attributes
- [x] Depth testing
- [x] 3D cube rendering
- [ ] Texture loading
- [ ] Model loading
- [ ] Multiple shader support
- [ ] Lighting system

### Graphics Engineering Features

- [ ] OpenGL debug callback
- [ ] GPU error visualization
- [ ] Render state inspection
- [ ] Frame debugging utilities

### Architecture

- [ ] Renderer abstraction layer
- [ ] Material system
- [ ] Scene management
- [ ] Resource manager

---

## Dependencies

- GLFW
- GLAD
- GLM
- CMake
- Modern C++

---

## Notes

This project currently uses manually vendored dependencies under:

```text
external/
```

No package manager (vcpkg/conan) is required.

---
