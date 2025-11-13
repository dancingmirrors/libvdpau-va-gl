// generated file, all changes will be lost

#ifndef VA_GL_GLSL_SHADERS_H
#define VA_GL_GLSL_SHADERS_H

#include <GL/gl.h>

struct shader_s {
    const char *body;
    int         len;
};

extern struct shader_s glsl_shaders[3];

#define SHADER_COUNT     3

enum {
    glsl_NV12_RGBA = 0,
    glsl_YV12_RGBA = 1,
    glsl_red_to_alpha_swizzle = 2,
};

#endif /* VA_GL_GLSL_SHADERS_H */
