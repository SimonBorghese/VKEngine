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
