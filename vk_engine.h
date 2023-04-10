//
// Created by simon on 4/10/23.
//

#ifndef VKENGINE_VK_ENGINE_H
#define VKENGINE_VK_ENGINE_H

#include "vk_types.h"
#include <vector>

class VulkanEngine {
public:

    bool _isInitalized{false};
    int _frameNumber {0};

    VkExtent2D _windowExtent {1700,900};

    struct SDL_Window* _window {nullptr };

    void init();

    void cleanup();

    void draw();

    void run();

    VkInstance _instance;
    VkDebugUtilsMessengerEXT _debug_messenger;
    VkPhysicalDevice _chosenGPU;
    VkDevice _device;
    VkSurfaceKHR _surface;

    VkSwapchainKHR _swapchain;
    VkFormat _swapchainImageFormat;
    std::vector<VkImage> _swapchainImages;
    std::vector<VkImageView> _swapchainImageViews;

    VkQueue _graphicsQueue;
    uint32_t _graphicsQueueFamily;
    VkCommandPool _commandPool;
    VkCommandBuffer _mainCommandBuffer;

    VkRenderPass _renderPass;

    std::vector<VkFramebuffer> _framebuffers;

    VkSemaphore _presentSemaphore, _renderSemaphore;
    VkFence _renderFence;

protected:
    void init_vulkan();

    void init_swapchain();

    void init_commands();

    void init_default_renderpass();

    void init_framebuffer();

    void init_sync_structures();

private:


};


#endif //VKENGINE_VK_ENGINE_H
