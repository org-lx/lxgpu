#pragma once

#include "utils/types.h"

#include "buffer.h"
#include "shader.h"
#include "vertex.h"
#include "render_mesh.h"
#include "material.h"

typedef struct {
   render_mesh* render_mesh;
   material* material;

   mat4 model;
   mat4 view;
   mat4 perspective;
} draw_call_params;

typedef struct {
   void (*initilize)(void);
   void (*shutdown)(void);

   void (*set_clear_color)(vec4);
   void (*clear)(int w, int h);

   void (*draw)(draw_call_params* draw_data);

   gpu_buffer (*create_buffer)(size_t size, const void* data, int usage);
   void (*bind_buffer)(gpu_buffer*);
   void (*update_buffer)(gpu_buffer* buffer, size_t size, const void* data);
   void (*destroy_buffer)(gpu_buffer* buffer);

   shader (*create_shader)(string vert, string frag);
   void (*destroy_shader)(shader*);

   render_mesh (*create_render_mesh)(mesh*);
   void (*destroy_render_mesh)(render_mesh*);
} renderer;

extern renderer main_renderer;
void set_renderer(string);


