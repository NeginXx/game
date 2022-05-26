#include "Renderer.h"
#include "Event.h"
#include "Engine.h"
#include "MainScene.h"
#include <stdlib.h>
#include <memory.h>
#include <cstdio>
#include <cmath>
#include <ctime>

//  is_key_pressed(int button_vk_code) (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, VK_RETURN)
//  is_mouse_button_pressed(int button) (0 - left button, 1 - right button)

MainScene* kMainScene = nullptr;
bool kIsGameOver = false;

void initialize() {
  srand(time(NULL));
  SetupBuffer(reinterpret_cast<uint32_t*>(buffer), SCREEN_WIDTH, SCREEN_HEIGHT);
  kMainScene = new MainScene;
  event::Subscribe(event::kGameOver, []() {
    kIsGameOver = true;
  });
}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE)) {
    schedule_quit_game();
  }

  if (kIsGameOver) { // restart the game
    kIsGameOver = false;
    delete kMainScene;
    kMainScene = new MainScene;
    return;
  }

  kMainScene->Update(dt);
  static bool is_mouse_processed = false;
  if (is_mouse_button_pressed(0)) {
    if (!is_mouse_processed) {
      kMainScene->ProcessMouseClick();
    }
    is_mouse_processed = true;
  } else {
    is_mouse_processed = false;
  }

  event::Dispatch();
}

void draw()
{
  // memset(buffer, 0xFF, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
  for (size_t y = 0; y < SCREEN_HEIGHT; ++y) {
    for (size_t x = 0; x < SCREEN_WIDTH; ++x) {
      buffer[y][x] = 0x61A7FB;
    }
  }
  kMainScene->Draw();
}

// free game data in this function
void finalize()
{
  delete kMainScene;
}