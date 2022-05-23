#include "MainScene.h"

MainScene::MainScene()
: central_disk_(Vec2f{512.0f, 250.0f}, 100.0f, 20.0f, -4.0f, 0x80FF, 0xE0E0E0) {}

void MainScene::Update(float dt) {
  central_disk_.Update(dt);
}

void MainScene::Draw() {
  central_disk_.Draw();
}

void MainScene::ProcessMouseClick() {
  central_disk_.SwitchDirection();
}