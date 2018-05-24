#ifndef BULLET_H
#define BULLET_H
#include <iostream>
#include <string>
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include "AnimationManager.h"
#include "AdditionalAlgebraicFunctions.h"
#include "Entity.h"
#include <list>

class Bullet : public Entity {
 public:
  Bullet(StaticEntityParameters* static_params);
  ~Bullet() {}
  void check_map_collision(const std::vector<Object>& solid) {}
 private:
};

class BulletFactory {
 public:
  BulletFactory(const std::string& image_name, const std::string& animation_name);
  ~BulletFactory();
  Bullet* create_bullet();
  std::list<Bullet*> create_bullets(std::size_t n);

 private:
  StaticEntityParameters* static_params_;
  std::string animation_name_;
};

#endif // BULLET_H
