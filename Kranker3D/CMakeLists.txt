cmake_minimum_required(VERSION 3.19)

project(Kranker3D)
#find_package(imgui CONFIG)



file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} 

)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/spdlog")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui")


set(DEPENDENCIES_HEADERS
			"${CMAKE_CURRENT_SOURCE_DIR}/vendor/stb/"
       
)

target_include_directories(Kranker3D PUBLIC  ${DEPENDENCIES_HEADERS} )


target_link_libraries(Kranker3D PUBLIC
		glfw
		glm::glm
		spdlog 
		glad
        imgui
 )