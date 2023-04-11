cmake_minimum_required(VERSION 3.26)
project(VKEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(VKEngine main.cpp vk_engine.cpp vk_engine.h vk_initalizers.cpp vk_initalizers.h vk_types.h thirdparty/vkbootstrap/VkBootstrap.cpp thirdparty/vkbootstrap/VkBootstrap.h thirdparty/vkbootstrap/VkBootstrapDispatch.h)

target_include_directories(VKEngine PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(VKEngine PUBLIC ${VULKAN_INCLUDE_DIRS})
target_include_directories(VKEngine PUBLIC ${CMAKE_SOURCE_DIR}/thirdparty/vkbootstrap)

target_link_libraries(VKEngine ${SDL2_LIBRARIES})
target_link_libraries(VKEngine ${Vulkan_LIBRARIES})
target_link_libraries(VKEngine ${CMAKE_DL_LIBS})

find_program(GLSL_VALIDATOR glslangValidator)


file(GLOB_RECURSE GLSL_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/shaders/*.frag"
        "${PROJECT_SOURCE_DIR}/shaders/*.vert"
        "${PROJECT_SOURCE_DIR}/shaders/*.comp")

foreach(GLSL ${GLSL_SOURCE_FILES})
    message(STATUS "BUILDING SHADER")
    get_filename_component(FILE_NAME ${GLSL} NAME)
    set(SPIRV "${PROJECT_SOURCE_DIR}/shaders/${FILE_NAME}.spv")
    message(STATUS ${GLSL})
    add_custom_command(
            OUTPUT ${SPIRV}
            COMMAND ${GLSL_VALIDATOR} -V ${GLSL} -o ${SPIRV}
            DEPENDS ${GLSL})
    list(APPEND SPIRV_BINARY_FILES ${SPIRV})
endforeach(GLSL)

add_custom_target(
        Shaders
        DEPENDS ${SPIRV_BINARY_FILES}
)
