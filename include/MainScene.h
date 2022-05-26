#pragma once
#include <vector>
#include "Shape.h"
struct CentralDisk {
  CentralDisk(Vec2f pos, float disk_radius,
              float circle_radius, float velocity,
              uint32_t disk_main_color, uint32_t disk_frame_color,
              uint32_t circles_main_color, uint32_t circles_frame_color);
  void Update(float dt);
  void SwitchDirection();
  void Draw();

  struct Circle : ::Circle {
    Circle() = default;
    Circle(Vec2f pos, float radius, uint32_t main_color,
           uint32_t frame_color, float velocity, float angle);
    float velocity;
    float angle;
  };
  ::Circle disk;
  Circle circles[2];
};

class MainScene {
 public:
  MainScene();
  void Update(float dt);
  void Draw();
  void ProcessMouseClick();
 private:
  enum RectType {
    kDamage,
    kScore
  };
  struct Rectangle : ::Rectangle {
    Rectangle(Vec2f pos, float width, float height, float angle, uint32_t main_color, uint32_t frame_color, Vec2f velocity, float rotation_velocity, RectType rect_type);
    Vec2f velocity;
    float rotation_velocity;
    RectType rect_type;
  };
  void EraseRectangle(size_t idx);
  void DeleteOutOfBoundRectangles();
  void SpawnRectangles();
  CentralDisk central_disk_;
  uint64_t score_;
  std::vector<Rectangle> rectangles_;
  float time_from_last_damage_rect_;
  float time_from_last_score_rect_;
};