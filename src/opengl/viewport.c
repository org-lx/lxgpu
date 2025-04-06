#include "opengl/opengl_renderer.h"

void gl_clear(int w, int h) {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glViewport(0,0,w,h);
}

void gl_set_clear_color(vec4 color) {
   glClearColor(color[0], color[1], color[2], color[3]);
}
