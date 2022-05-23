#include "Vec2.h"

struct Circle {
  Vec2f pos;
  float radius;
  uint32_t color;
  void Draw();
};

class CentralDisk {
 public:
  CentralDisk(Vec2f pos, float disk_radius,
              float circle_radius, float velocity,
              uint32_t disk_color, uint32_t circles_color);
  void Update(float dt);
  void SwitchDirection();
  void Draw();
 private:
  struct Circle : ::Circle {
    float velocity;
    float angle;
  };
  Vec2f pos_;
  float radius_;
  Circle circles_[2];
  uint32_t color_;
};