cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(SecretSequence)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
SET(CMAKE_CXX_FLAGS "-O2 -std=c++11")

# OpenGL
find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )

# Freetype
find_package(Freetype REQUIRED)
include_directories( ${FREETYPE_INCLUDE_DIRS} )


set(LIBS glm glfw glad ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARIES}) # create LIBS var for all librairies

# add src files
file(GLOB_RECURSE SOURCE_FILES 
	${CMAKE_SOURCE_DIR}/src/*.c
	${CMAKE_SOURCE_DIR}/src/*.cpp)
	
# add header files
file(GLOB_RECURSE HEADER_FILES 
	${CMAKE_SOURCE_DIR}/src/*.h
	${CMAKE_SOURCE_DIR}/src/*.hpp)


include_directories(
	"${CMAKE_SOURCE_DIR}/src"
)

# disable GLFW demonstrations tools

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_SOURCE_DIR}/include/glfw/")
add_subdirectory("${CMAKE_SOURCE_DIR}/include/glad/")
add_subdirectory("${CMAKE_SOURCE_DIR}/include/glm/")


#add our executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${LIBS})

