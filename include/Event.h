#pragma once

#include <functional>

namespace event {

enum Type {
  kGameOver
};

void PushEvent(event::Type event);

void Subscribe(event::Type event, std::function<void()> callback);

void Dispatch();

}