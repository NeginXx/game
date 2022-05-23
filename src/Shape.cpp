#include "Shape.h"
#include "SceneRenderer.h"

#include <cmath>
#include <cstdio>

void Circle::Draw() {
  DrawCircle(pos.x, pos.y, radius, color);
}

CentralDisk::CentralDisk(Vec2f pos, float disk_radius,
              float circle_radius, float velocity,
              uint32_t disk_color, uint32_t circles_color)
: pos_(pos),
  radius_(disk_radius),
  circles_{},
  color_(disk_color)
{
  circles_[0].pos = Vec2f{pos.x - disk_radius, pos.y};
  circles_[1].pos = Vec2f{pos.x + disk_radius, pos.y};

  circles_[0].radius = circle_radius;
  circles_[1].radius = circle_radius;

  circles_[0].velocity = velocity;
  circles_[1].velocity = velocity;

  circles_[0].angle = 0;
  circles_[1].angle = M_PI;

  circles_[0].color = circles_color;
  circles_[1].color = circles_color;
}

void CentralDisk::Update(float dt) {
  for (size_t i = 0; i < 2; ++i) {
    CentralDisk::Circle& circle = circles_[i];
    circle.angle += circle.velocity * dt;
    if (circle.angle > 2 * M_PI) {
      circle.angle -= 2 * M_PI;
    } else if (circle.angle < -2 * M_PI) {
      circle.angle += 2 * M_PI;
    }
    circle.pos.x = std::cos(circle.angle) * radius_ + pos_.x;
    circle.pos.y = std::sin(circle.angle) * radius_ + pos_.y;
  }
}

void CentralDisk::SwitchDirection() {
  for (size_t i = 0; i < 2; ++i) {
    circles_[i].velocity *= -1.0f;
  }
}

void CentralDisk::Draw() {
  DrawCircle(pos_.x, pos_.y, radius_, color_);
  for (size_t i = 0; i < 2; ++i) {
    circles_[i].Draw();
  }
}