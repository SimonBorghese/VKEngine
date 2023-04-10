//
// Created by simon on 4/10/23.
//

#ifndef VKENGINE_VK_INITALIZERS_H
#define VKENGINE_VK_INITALIZERS_H

#include "vk_types.h"

namespace vkinit {
    VkCommandPoolCreateInfo command_pool_create_info(uint32_t queueFamilyIndex, VkCommandPoolCreateFlags flags = 0);

    VkCommandBufferAllocateInfo command_buffer_allocate_info(VkCommandPool pool, uint32_t count = 1, VkCommandBufferLevel level = VK_COMMAND_BUFFER_LEVEL_PRIMARY);
}


#endif //VKENGINE_VK_INITALIZERS_H
