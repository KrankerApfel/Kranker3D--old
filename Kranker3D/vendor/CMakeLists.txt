#./libs/CMakeLists.txt

set(BUILD_SHARED_LIBS OFF)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glm")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/spdlog")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glfw")




set(DEPENDENCIES_HEADERS
			"${CMAKE_CURRENT_SOURCE_DIR}/glm/glm"
			"${CMAKE_CURRENT_SOURCE_DIR}/spdlog/include"
			"${CMAKE_CURRENT_SOURCE_DIR}/imgui"
			"${CMAKE_CURRENT_SOURCE_DIR}/GLAD/include"
			"${CMAKE_CURRENT_SOURCE_DIR}/glfw/include"
			"${CMAKE_CURRENT_SOURCE_DIR}/stb"
			 PARENT_SCOPE
)