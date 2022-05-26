#pragma once
#include <cstdint>

void SetupBuffer(uint32_t* buffer, uint32_t width, uint32_t height);

void DrawLine(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);

void FillRectangle(int32_t center_x, int32_t center_y,
                   uint32_t width, uint32_t height,
                   float angle, uint32_t main_color,
                   uint32_t frame_color);

void FillCircle(int32_t center_x, int32_t center_y,
                uint32_t radius, uint32_t main_color,
                uint32_t frame_color);