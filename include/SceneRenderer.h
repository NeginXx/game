#pragma once
#include <cstdint>

void DrawLine(float x1, float y1, float x2, float y2, uint32_t color);

void FillRectangle(float center_x, float center_y,
                   float width, float height,
                   float angle, uint32_t main_color,
                   uint32_t frame_color);

void FillCircle(float center_x, float center_y,
                float radius, uint32_t main_color,
                uint32_t frame_color);