// generated file, all changes will be lost

#include "shaders.h"

struct shader_s glsl_shaders[3] = {
  {
    .body =
      "#version 110\n"
      "uniform sampler2D tex[2];\n"
      "void main()\n"
      "{\n"
      "    vec2 y_coord = gl_TexCoord[0].xy;\n"
      "    float y = texture2D(tex[0], y_coord).r;\n"
      "    float cb = texture2D(tex[1], y_coord).r - 0.5;\n"
      "    float cr = texture2D(tex[1], y_coord).g - 0.5;\n"
      "\n"
      "    gl_FragColor = vec4(\n"
      "        y + 1.4021 * cr,\n"
      "        y - 0.34482 * cb - 0.71405 * cr,\n"
      "        y + 1.7713 * cb,\n"
      "        1.0);\n"
      "}\n"
      "",
    .len = 370,
  },
  {
    .body =
      "#version 110\n"
      "uniform sampler2D tex[2];\n"
      "void main()\n"
      "{\n"
      "    vec2 y_coord = gl_TexCoord[0].xy;\n"
      "    vec2 cb_coord = vec2(y_coord.x, y_coord.y/2.0);\n"
      "    vec2 cr_coord = vec2(y_coord.x, y_coord.y/2.0 + 0.5);\n"
      "    float y = texture2D(tex[0], y_coord).r;\n"
      "    float cb = texture2D(tex[1], cb_coord).r - 0.5;\n"
      "    float cr = texture2D(tex[1], cr_coord).r - 0.5;\n"
      "\n"
      "    gl_FragColor = vec4(\n"
      "        y + 1.4021 * cr,\n"
      "        y - 0.34482 * cb - 0.71405 * cr,\n"
      "        y + 1.7713 * cb,\n"
      "        1.0);\n"
      "}\n"
      "",
    .len = 482,
  },
  {
    .body =
      "#version 110\n"
      "\n"
      "uniform sampler2D tex_0;\n"
      "\n"
      "void main()\n"
      "{\n"
      "    gl_FragColor = gl_Color * vec4(1.0, 1.0, 1.0, texture2D(tex_0, gl_TexCoord[0].xy).r);\n"
      "}\n"
      "",
    .len = 146,
  },
};
