#include "Shape.h"
#include "SceneRenderer.h"

void Circle::Draw() {
  FillCircle(pos.x, pos.y, radius, main_color, frame_color);
}

void Rectangle::Draw() {
  FillRectangle(pos.x, pos.y, width, height, angle, main_color, frame_color);
}