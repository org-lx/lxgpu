#include "GL/glew.h"

#include "opengl/opengl_renderer.h"

void gl_initilize(void) {
   glewInit();
   glEnable(GL_DEPTH_TEST);
}
