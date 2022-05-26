#include "Physics.h"

#include <cassert>
#include <cmath>
#include <utility>

struct Segment {
  Vec2f p1;
  Vec2f p2;
  // we assume neither of p1 or p2 is inside the circle
  bool DoIntersect(const Circle& crl) {
    Vec2f dir_vec = p2 - p1;
    assert(!(dir_vec.x == 0 && dir_vec.y == 0));
    dir_vec /= Length(dir_vec);
    Vec2f v = crl.pos - p1;
    float dist = std::abs(dir_vec.x * v.y - dir_vec.y * v.x);
    if (dist >= crl.radius) {
      return false;
    }
    Vec2f v_proj = DotProduct(dir_vec, v) * dir_vec;
    if (p1.x > p2.x) {
      if (p1.y > p2.y) {
        return p2.x <= v_proj.x && v_proj.x <= p1.x &&
               p2.y <= v_proj.y && v_proj.y <= p1.y;
      }
      return p2.x <= v_proj.x && v_proj.x <= p1.x &&
              p1.y <= v_proj.y && v_proj.y <= p2.y;
    }
    if (p1.y > p2.y) {
      return p1.x <= v_proj.x && v_proj.x <= p2.x &&
              p2.y <= v_proj.y && v_proj.y <= p1.y;
    }
    return p1.x <= v_proj.x && v_proj.x <= p2.x &&
            p1.y <= v_proj.y && v_proj.y <= p2.y;
  }
};

bool IsInside(Vec2f point, const Circle& crl) {
  Vec2f v = point - crl.pos;
  return Length(v) <= crl.radius;
}

bool DoIntersect(const Circle& crl, const Rectangle& rect) {
  float sin = std::sin(rect.angle);
  float cos = std::cos(rect.angle);
  Vec2f a = rect.width / 2.0f * Vec2f{cos, sin};
  Vec2f b = rect.height / 2.0f * Vec2f{-sin, cos};
  Vec2f A = a + b;
  Vec2f B = b - a;
  Vec2f D = -B;
  Vec2f C = -A;
  A += rect.pos;
  B += rect.pos;
  D += rect.pos;
  C += rect.pos;

  if (IsInside(A, crl) || IsInside(B, crl) || IsInside(D, crl) || IsInside(C, crl)) {
    return true;
  }
  
  Vec2f BA = B - A;
  Vec2f DA = D - A;
  float APAB = DotProduct(crl.pos - A, BA);
  float APAD = DotProduct(crl.pos - A, DA);
  if (APAB > 0 && APAB < DotProduct(BA, BA) &&
      APAD > 0 && APAD < DotProduct(DA, DA)) {
    return true;
  }

  return Segment{A, B}.DoIntersect(crl) ||
         Segment{A, D}.DoIntersect(crl) ||
         Segment{B, C}.DoIntersect(crl) ||
         Segment{D, C}.DoIntersect(crl);
}