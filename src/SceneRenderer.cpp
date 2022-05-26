#include "SceneRenderer.h"
#include "Renderer.h"

// FIXME: float axis should be normalized
void DrawLine(float x1, float y1, float x2, float y2, uint32_t color) {
  DrawLine(static_cast<int32_t>(x1), static_cast<int32_t>(y1),
           static_cast<int32_t>(x2), static_cast<int32_t>(y2), color);
}

// FIXME: float axis should be normalized
void FillRectangle(float center_x, float center_y,
                   float width, float height,
                   float angle, uint32_t main_color,
                   uint32_t frame_color) {
  FillRectangle(static_cast<int32_t>(center_x), static_cast<int32_t>(center_y),
                static_cast<uint32_t>(width), static_cast<uint32_t>(height),
                angle, main_color, frame_color);
}

// FIXME: float axis should be normalized
void FillCircle(float center_x, float center_y,
                float radius, uint32_t main_color,
                uint32_t frame_color) {
  FillCircle(static_cast<int32_t>(center_x), static_cast<int32_t>(center_y),
             static_cast<uint32_t>(radius), main_color, frame_color);
}