cmake_minimum_required(VERSION 3.14)
project(Math VERSION 1.0 DESCRIPTION "")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_sources(${PROJECT_NAME}
		PUBLIC
		include/Math/mat2.h
		include/Math/mat3.h
		include/Math/mat3x4.h
		include/Math/mat4.h
		include/Math/quat.h
		include/Math/vec2.h
		include/Math/vec3.h
		include/Math/vec4.h
		PRIVATE
		src/mat2.cpp
		src/mat3.cpp
		src/mat3x4.cpp
		src/mat4.cpp
		src/quat.cpp
		src/vec2.cpp
		src/vec3.cpp
		src/vec4.cpp)
