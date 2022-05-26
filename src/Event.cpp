#include <queue>
#include <vector>
#include <unordered_map>
#include "Event.h"

namespace event {

std::queue<event::Type> kEvents;
std::unordered_map<event::Type, std::vector<std::function<void()>>> kRegistry;

void PushEvent(event::Type event) {
  kEvents.push(event);
}

void Subscribe(event::Type event, std::function<void()> callback) {
  kRegistry[event].push_back(callback);
}

void Dispatch() {
  while (!kEvents.empty()) {
    auto subscribers = kRegistry[kEvents.front()];
    for (auto callback : subscribers) {
      callback();
    }
    kEvents.pop();
  }
}

}