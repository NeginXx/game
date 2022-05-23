#include "SceneRenderer.h"
#include "Renderer.h"

// FIXME:
void DrawLine(float x1, float y1, float x2, float y2, uint32_t color) {
  DrawLine(static_cast<int32_t>(x1), static_cast<int32_t>(y1),
           static_cast<int32_t>(x2), static_cast<int32_t>(y2), color);
}

// FIXME:
void FillRect(float center_x, float center_y,
              float width, float height,
              float angle, uint32_t color) {
  FillRect(static_cast<int32_t>(center_x), static_cast<int32_t>(center_y),
           static_cast<uint32_t>(width), static_cast<uint32_t>(height),
           angle, color);
}

// FIXME:
void DrawCircle(float center_x, float center_y, float radius, uint32_t color) {
  DrawCircle(static_cast<int32_t>(center_x), static_cast<int32_t>(center_y),
             static_cast<uint32_t>(radius), color);
}