#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <limits>
#include <utility>

#include "Renderer.h"
#include "Vec2.h"

struct Buffer {
  uint32_t* buffer;
  uint32_t width;
  uint32_t height;
} kBuffer{nullptr, 0, 0};

void SetupBuffer(uint32_t* buffer, uint32_t width, uint32_t height) {
  kBuffer.buffer = buffer;
  kBuffer.width = width;
  kBuffer.height = height;
}

// void DrawRectOutOfBound(int32_t x, int32_t y, uint32_t width,
//               uint32_t height, uint32_t color) {
//   int32_t x_start = Max(x, 0);
//   int32_t x_finish = Min(x + width, kBuffer.width);
//   int32_t y_start = Max(y, 0);
//   int32_t y_finish = Min(y + height, kBuffer.height);
//   for (uint32_t yy = y_start; yy < y_finish; ++yy) {
//     uint32_t* ptr = kBuffer.buffer + yy * kBuffer.width + x_start;
//     for (uint32_t xx = x_start; xx < x_finish; ++xx) {
//       *ptr++ = color;
//     }
//   }
// }

// void DrawRect(int32_t x, int32_t y, uint32_t width,
//               uint32_t height, uint32_t color) {
//   for (uint32_t yy = y; yy < y + height; ++yy) {
//     uint32_t* ptr = kBuffer.buffer + yy * kBuffer.width + x_start;
//     for (uint32_t xx = x; xx < x + width; ++xx) {
//       *ptr++ = color;
//     }
//   }
// }

void SetPixel(int32_t x, int32_t y, uint32_t color) {
  // that's a big flaw in performance, but for now it's easier to use
  if (x >= 0 && x < kBuffer.width && y >= 0 && y < kBuffer.height) {
    kBuffer.buffer[y * kBuffer.width + x] = color;
  }
}

void SetPixelInRow(int32_t y_row, int32_t x1, int32_t x2, uint32_t color) {
  assert(x2 >= x1);
  size_t range = x2 - x1;
  for (size_t i = 0; i < range; ++i) {
    SetPixel(x1 + i, y_row, color);
  }
}

void DrawCircle(int32_t center_x, int32_t center_y, uint32_t radius, uint32_t color) {
  int32_t x1 = center_x - radius;
  int32_t x2 = center_x + radius;
  int32_t y1 = center_y - radius;
  int32_t y2 = center_y + radius;

  uint32_t r2 = radius * radius;  

  for(int32_t y = y1; y < y2; ++y) {
    for(int32_t x = x1; x < x2; ++x) {
      if ((center_x - x) * (center_x - x) + (center_y - y) * (center_y - y) <= r2) {
        SetPixel(x, y, color);
      }
    }
  }
}

// void DrawCircle(int32_t center_x, int32_t center_y, uint32_t radius, uint32_t color) {
  
// }

void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color) {
  assert(x1 >= 0 && x1 < kBuffer.width);
  assert(x2 >= 0 && x2 < kBuffer.width);
  assert(y1 >= 0 && y1 < kBuffer.height);
  assert(y2 >= 0 && y2 < kBuffer.height);

  Vec2i diff{std::abs(x2 - x1), std::abs(y2 - y1)};
  Vec2i sign{x1 < x2 ? 1 : -1, y1 < y2 ? 1 : -1};

  Vec2i cur_coord = {x1, y1};
  Vec2i end_coord = {x2, y2};
  int32_t err = diff.x - diff.y;
  while (true) {
    SetPixel(cur_coord.x, cur_coord.y, color);
    if (cur_coord == end_coord) {
      break;
    }
    int32_t err2 = 2 * err;
    if (err2 > -diff.y) {
      err -= diff.y;
      cur_coord.x += sign.x;
    }
    if (err2 < diff.x) {
      err += diff.x;
      cur_coord.y += sign.y;
    }
  }
}

// this struct contains everything that's needed for Bresenham algorith (see function DrawLine)
struct RectSide {
  Vec2i cur_coord;
  Vec2i end_coord;
  Vec2i diff;
  Vec2i sign;
  int32_t cur_err;
  uint32_t color;

  RectSide() = delete;
  RectSide(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color_)
  : cur_coord({x1, y1}),
    end_coord({x2, y2}),
    diff({std::abs(x2 - x1), std::abs(y2 - y1)}),
    sign({x1 < x2 ? 1 : -1, y1 < y2 ? 1 : -1}),
    cur_err(diff.x - diff.y),
    color(color_) {}

  // draw while not proceed on the next row
  // returns is_drawing_finished
  bool DrawWhileNotProceed() {
    int32_t initial_y = cur_coord.y;
    while (initial_y == cur_coord.y) {
      SetPixel(cur_coord.x, cur_coord.y, color);
      if (cur_coord == end_coord) {
        return true;
      }
      int32_t err2 = cur_err * 2;
      if (err2 > -diff.y) {
        cur_err -= diff.y;
        cur_coord.x += sign.x;
      }
      if (err2 < diff.x) {
        cur_err += diff.x;
        cur_coord.y += sign.y;
      }
    }
    return false;
  }
};

enum SideName {
  kNW,
  kNE,
  kWS,
  kES
};

// Bresenham algorithm
void FillRect(int32_t center_x, int32_t center_y,
              uint32_t width, uint32_t height,
              float angle, uint32_t color) {
  float sin = std::sin(angle);
  float cos = std::cos(angle);
  Vec2f a = static_cast<float>(width) / 2.0f * Vec2f{cos, sin};
  Vec2f b = static_cast<float>(height) / 2.0f * Vec2f{-sin, cos};
  Vec2f np = a + b; // north point
  Vec2f wp = b - a; // west point
  Vec2f sp = -np;
  Vec2f ep = -wp;

  Vec2f rect_vertices[4] = {np, wp, ep, sp};

  std::sort(rect_vertices, rect_vertices + 4, [](const Vec2f& a, const Vec2f& b) {
    return a.y < b.y;
  });

  if (rect_vertices[1].x > rect_vertices[2].x) {
    std::swap(rect_vertices[1], rect_vertices[2]);
  }
  // now rect_vertices is np->wp->ep->sp

  np = rect_vertices[0];
  wp = rect_vertices[1];
  ep = rect_vertices[2];
  sp = rect_vertices[3];

  Vec2i n{static_cast<int32_t>(np.x), static_cast<int32_t>(np.y)};
  Vec2i w{static_cast<int32_t>(wp.x), static_cast<int32_t>(wp.y)};
  Vec2i e{static_cast<int32_t>(ep.x), static_cast<int32_t>(ep.y)};
  Vec2i s{static_cast<int32_t>(sp.x), static_cast<int32_t>(sp.y)};
  Vec2i center{center_x, center_y};
  n += center;
  w += center;
  e += center;
  s += center;

  RectSide side_nw{n.x, n.y, w.x, w.y, color};
  RectSide side_ne{n.x, n.y, e.x, e.y, color};
  RectSide side_ws{w.x, w.y, s.x, s.y, color};
  RectSide side_es{e.x, e.y, s.x, s.y, color};

  RectSide sides[4] = {side_nw, side_ne, side_ws, side_es};
  // FIXME: such a noodle code, but it works and i don't know how to fix this
  SideName name0 = kNW;
  SideName name1 = kNE;
  while (true) {
    SetPixelInRow(sides[name0].cur_coord.y, sides[name0].cur_coord.x, sides[name1].cur_coord.x, sides[name0].color);
    bool is_finished0 = sides[name0].DrawWhileNotProceed();
    bool is_finished1 = sides[name1].DrawWhileNotProceed();

    if (is_finished0 && is_finished1) {
      if (name0 == kNW && name1 == kNE) {
        name0 = kWS;
        name1 = kES;
        continue;
      }
      if (name0 == kWS && name1 == kES) {
        return;
      }
      assert(0);
    }

    if (is_finished0) {
      if (name0 == kNW) {
        name0 = kWS;
        continue;
      }
      if (name0 == kWS) {
        assert(name1 == kES && is_finished1);
        return;
      }
      assert(0);
    }

    if (is_finished1) {
      if (name1 == kNE) {
        name1 = kES;
        continue;
      }
      if (name1 == kES) {
        assert(name0 == kWS && is_finished0);
        return;
      }
      assert(0);
    }
  }
}