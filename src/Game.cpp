#include "Renderer.h"
#include "Engine.h"
#include "MainScene.h"
#include <stdlib.h>
#include <memory.h>
#include <cstdio>
#include <cmath>

//  is_key_pressed(int button_vk_code) (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//  is_mouse_button_pressed(int button) (0 - left button, 1 - right button)

MainScene* kMainScene = nullptr;

void initialize() {
  SetupBuffer(reinterpret_cast<uint32_t*>(buffer), SCREEN_WIDTH, SCREEN_HEIGHT);
  kMainScene = new MainScene;
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  kMainScene->Update(dt);
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();
  static bool is_mouse_processed = false;
  if (is_mouse_button_pressed(0)) {
    if (!is_mouse_processed) {
      kMainScene->ProcessMouseClick();
    }
    is_mouse_processed = true;
  } else {
    is_mouse_processed = false;
  }
}

void draw()
{
  // memset(buffer, 0xFF, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
  for (size_t y = 0; y < SCREEN_HEIGHT; ++y) {
    for (size_t x = 0; x < SCREEN_WIDTH; ++x) {
      buffer[y][x] = 0xCC;
    }
  }
  // DrawLine(0, 0, 600, 600, 0xFF0000);
  // FillRect(200, 200, 50, 50, M_PI / 4.0f, 0xFF0000);
  // FillRect(300, 300, 100, 100, M_PI / 4.0f, 0xFF);

  kMainScene->Draw();
  // DrawCircle(300, 300, 200, 0xFF);
  
  // static float angle = M_PI/3.0f;
  // angle += 0.01f;
  // FillRect(400, 400, 150, 150, angle, 0xF00FF0);
  // FillRect(0, 0, 50, 150, angle, 0xF00FF0);
}

// free game data in this function
void finalize()
{
}