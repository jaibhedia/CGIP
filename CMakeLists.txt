cmake_minimum_required(VERSION 3.10)
project(FreeGLUTDemo)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(FreeGLUTDemo main.cpp)

# Specify the paths to FreeGLUT
set(GLUT_INCLUDE_DIR "C:/Users/shann/Downloads/freeglut/include")
set(GLUT_LIBRARY "C:/Users/shann/Downloads/freeglut/freeglut/lib/x64/freeglut.lib")

# Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# Manually specify FreeGLUT include and library directories
include_directories(${GLUT_INCLUDE_DIR})
link_directories("C:/Users/shann/Downloads/freeglut/freeglut/lib/x64")

# Link the libraries
target_link_libraries(FreeGLUTDemo ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} opengl32 glu32)
