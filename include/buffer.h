#pragma once

#include "utils/types.h"

typedef enum {
   lxg_buffer_usage_data = 0,
   lxg_buffer_usage_elements = 1,
} lxg_buffer_usage;

/// vram location descriptor
typedef struct {
   /// per api value, eg with vulkan it is a VkBuffer
   /// with opengl it is two lxuint's for the location and type
   void* buffer_descriptor;

   /// size of buffer
   lxuint size;
   lxg_buffer_usage usage;
} lxg_gpu_buffer;
