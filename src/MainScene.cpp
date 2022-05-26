#include "MainScene.h"
#include "Physics.h"
#include "Event.h"

#include <cassert>
#include <cmath>
#include <cstdio>

// const uint32_t kFrameColor = 0x808080;
const uint32_t kFrameColor = 0xFFFFFF;

const Vec2f kSceneMinCoord{0.0f, 0.0f};
const Vec2f kSceneMaxCoord{1024.0f, 768.0f};

const float kDiskRadius = 120.0f;
const float kCirclesRadius = kDiskRadius / 6.0f;
const float kRectWidth = 1.7f * kCirclesRadius;
const float kRectSpeedY = -500.0f;
const float kRectRotationVelocity = 2.0f;

const float kDamageRectSpawnTime = 3.0f;
const float kScoreRectSpawnTime = 9.5f;
const float kRectSpawnTimeDelay = 0.5f;

MainScene::MainScene()
: central_disk_(Vec2f{512.0f, 250.0f}, kDiskRadius, kCirclesRadius, -3.5f, 0x5B9DED, 0x5B9DED, 0xFFFFFF, 0xFFFFFF),
  score_(0),
  rectangles_{},
  time_from_last_damage_rect_(0.0f),
  time_from_last_score_rect_(0.0f) {}

MainScene::Rectangle::Rectangle(Vec2f pos, float width, float height, float angle, uint32_t main_color, uint32_t frame_color, Vec2f velocity_, float rotation_velocity_, RectType rect_type_)
: ::Rectangle({pos, width, height, angle, main_color, frame_color}),
  velocity(velocity_),
  rotation_velocity(rotation_velocity_),
  rect_type(rect_type_) {}

float GetRandomFloatInRange(float a, float b) {
  assert(a <= b);
  return a + static_cast<float>(rand() % static_cast<size_t>((b - a)));
}

void MainScene::SpawnRectangles() {
  // kSceneMaxCoord.x / 2.0f, kSceneMaxCoord.y + 40.0f
  static Rectangle template_rect{Vec2f{kSceneMaxCoord.x / 2.0f, kSceneMaxCoord.y}, kRectWidth, kRectWidth, 0x13151A, 0, 0x13151A, Vec2f{0.0f, kRectSpeedY}, kRectRotationVelocity, RectType::kDamage};
  template_rect.pos.x = GetRandomFloatInRange(kSceneMaxCoord.x / 8.0f, kSceneMaxCoord.x - kSceneMaxCoord.x / 8.0f);
  float upper_x = GetRandomFloatInRange(central_disk_.disk.pos.x - central_disk_.disk.radius, central_disk_.disk.pos.x + central_disk_.disk.radius);
  template_rect.velocity.x = upper_x - template_rect.pos.x;
  if (rand() % 2 == 1) template_rect.rotation_velocity *= -1.0f;

  if (time_from_last_damage_rect_ >= kDamageRectSpawnTime && time_from_last_score_rect_ > kRectSpawnTimeDelay) {
    time_from_last_damage_rect_ = 0.0f;
    rectangles_.push_back(template_rect);
  }

  if (time_from_last_score_rect_ >= kScoreRectSpawnTime && time_from_last_damage_rect_ > kRectSpawnTimeDelay) {
    time_from_last_score_rect_ = 0.0f;
    rectangles_.push_back(template_rect);
    Rectangle& rect = rectangles_.back();
    rect.main_color = central_disk_.circles[0].main_color;
    rect.frame_color = central_disk_.circles[0].frame_color;
    rect.rect_type = RectType::kScore;
  }
}

void MainScene::EraseRectangle(size_t idx) {
  size_t sz = rectangles_.size();
  if (idx == sz - 1) {
    rectangles_.pop_back();
    return;
  }
  for (size_t i = idx + 1; i < sz - 1; ++i) {
    rectangles_[i - 1] = rectangles_[i];
  }
}

void MainScene::DeleteOutOfBoundRectangles() {
  size_t sz = rectangles_.size();
  size_t del_rects_num = 0;
  for (size_t i = 0; i < sz - del_rects_num;) {
    Rectangle rect = rectangles_[i];
    // we assume rect.pos.y >= kSceneMaxCoord.y means the rectangle was just spawned and not need to be deleted
    if (rect.pos.x <= kSceneMinCoord.x || rect.pos.x >= kSceneMaxCoord.x || rect.pos.y <= kSceneMinCoord.y)
    {
      EraseRectangle(i);
      ++del_rects_num;
      continue;
    }
    ++i;
  }
}

void MainScene::Update(float dt) {
  DeleteOutOfBoundRectangles();
  time_from_last_damage_rect_ += dt;
  time_from_last_score_rect_ += dt;
  SpawnRectangles();

  for (size_t crl_idx = 0; crl_idx < 2; ++crl_idx) {
    Circle crl = central_disk_.circles[crl_idx];
    size_t sz = rectangles_.size();
    size_t del_rects_num = 0;
    for (size_t rect_idx = 0; rect_idx < sz - del_rects_num;) {
      Rectangle rect = rectangles_[rect_idx];
      if (rect.rect_type == RectType::kDamage) {
        if (DoIntersect(crl, rect)) {
          event::PushEvent(event::kGameOver);
          return;
        }
      } else if (rect.rect_type == RectType::kScore) {
        if (DoIntersect(crl, rect)) {
          ++score_;
          printf("score %lu\n", score_);
          EraseRectangle(rect_idx);
          ++del_rects_num;
          continue;
        }
      }
      ++rect_idx;
    }
  }

  central_disk_.Update(dt);

  for (auto& rect : rectangles_) {
    rect.pos += dt * rect.velocity;
    rect.angle += dt * rect.rotation_velocity;
  }
}

void MainScene::Draw() {
  central_disk_.Draw();
  for (auto& rect : rectangles_) {
    rect.Draw();
  }
}

void MainScene::ProcessMouseClick() {
  central_disk_.SwitchDirection();
}

CentralDisk::Circle::Circle(Vec2f pos, float radius, uint32_t main_color,
                            uint32_t frame_color, float velocity_, float angle_)
: ::Circle({pos, radius, main_color, frame_color}),
  velocity(velocity_), angle(angle_) {}

CentralDisk::CentralDisk(Vec2f pos, float disk_radius,
                         float circle_radius, float velocity,
                         uint32_t disk_main_color, uint32_t disk_frame_color,
                         uint32_t circles_main_color, uint32_t circles_frame_color)
: disk({pos, disk_radius, disk_main_color, disk_frame_color})
{
  circles[0] = Circle{Vec2f{pos.x - disk_radius, pos.y}, circle_radius, circles_main_color, circles_frame_color, velocity, 0.0f};
  circles[1] = circles[0];
  circles[1].pos = Vec2f{pos.x + disk_radius, pos.y};
  circles[1].angle = M_PI;
}

void CentralDisk::Update(float dt) {
  for (size_t i = 0; i < 2; ++i) {
    CentralDisk::Circle& circle = circles[i];
    circle.angle += circle.velocity * dt;
    if (circle.angle > 2 * M_PI) {
      circle.angle -= 2 * M_PI;
    } else if (circle.angle < -2 * M_PI) {
      circle.angle += 2 * M_PI;
    }
    circle.pos.x = std::cos(circle.angle) * disk.radius + disk.pos.x;
    circle.pos.y = std::sin(circle.angle) * disk.radius + disk.pos.y;
  }
}

void CentralDisk::SwitchDirection() {
  for (size_t i = 0; i < 2; ++i) {
    circles[i].velocity *= -1.0f;
  }
}

void CentralDisk::Draw() {
  disk.Draw();
  for (size_t i = 0; i < 2; ++i) {
    circles[i].Draw();
  }
}