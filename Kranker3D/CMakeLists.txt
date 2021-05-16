cmake_minimum_required(VERSION 3.19)

project(Kranker3D)


file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad")



set(DEPENDENCIES_HEADERS
			"${CMAKE_CURRENT_SOURCE_DIR}/glm/glm/*.hpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include"
			"${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.h"
			"${CMAKE_CURRENT_SOURCE_DIR}/GLAD/include"
			"${CMAKE_CURRENT_SOURCE_DIR}/glfw/include"
			"${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/"
)

set(DEPENDENCIES_SOURCES
			"${CMAKE_CURRENT_SOURCE_DIR}/glm/glm/*.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/spdlog/src"
			"${CMAKE_CURRENT_SOURCE_DIR}/imgui/*.cpp"
			"${CMAKE_CURRENT_SOURCE_DIR}/glfw/src"
)

set(STB_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/stb.h" "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/stb_image.h"  "${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/stb_image_write.h")



target_include_directories(Kranker3D PRIVATE ${DEPENDENCIES_HEADERS} ${STB_INCLUDE_DIRS})

target_link_libraries(Kranker3D PRIVATE
		glfw
		glm::glm
		spdlog 
		glad
		
)