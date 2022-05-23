#include <vector>
#include "Shape.h"
class MainScene {
 public:
  MainScene();
  void Update(float dt);
  void Draw();
  void ProcessMouseClick();
 private:
  CentralDisk central_disk_;
};