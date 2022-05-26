#pragma once
#include "Vec2.h"

struct Circle {
  Vec2f pos;
  float radius;
  uint32_t main_color;
  uint32_t frame_color;
  void Draw();
};

struct Rectangle {
  Vec2f pos;
  float width;
  float height;
  float angle;
  uint32_t main_color;
  uint32_t frame_color;
  void Draw();
};