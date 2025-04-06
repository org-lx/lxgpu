#pragma once

#include "shader.h"

typedef struct {
  string name;

  enum lxg_shader_value_type {
    lxg_shader_value_type_int,
    lxg_shader_value_type_bool,
    lxg_shader_value_type_float,
    lxg_shader_value_type_double,
    lxg_shader_value_type_vec2,
    lxg_shader_value_type_vec3,
    lxg_shader_value_type_vec4,
    lxg_shader_value_type_mat2,
    lxg_shader_value_type_mat3,
    lxg_shader_value_type_mat4
  } type;

  union {
    int v_int;
    _Bool v_bool;
    float v_float;
    double v_double;
    vec2 v_vec2;
    vec3 v_vec3;
    vec4 v_vec4;
    mat2 v_mat2;
    mat3 v_mat3;
    mat4 v_mat4;
  } value;
} lxg_shader_value;
MAKE_LIST(lxg_shader_value);

typedef struct {
  lxg_shader_value_list values;
  string shader;

  string name;
  string path;
  string real_path;
} lxg_material;
MAKE_LIST(lxg_material);

extern lxg_material_list loaded_material_list;

lxg_material *get_material(string);
void add_material(lxg_material*);

shader_value get_shader_value(material *, string);
void set_shader_value(material *, shader_value);

void compile_default_materials();
