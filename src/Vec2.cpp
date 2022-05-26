#include "Vec2.h"

float Length(const Vec2<float>& v) {
  return sqrtf(v.x * v.x + v.y * v.y);
}