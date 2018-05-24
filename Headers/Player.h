#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <map>
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include "AnimationManager.h"
#include "AdditionalAlgebraicFunctions.h"
#include "Entity.h"
#include <memory>
enum PlayerState {stay, run, attack, attacked};

class Player : public Entity {
 public:
  Player(StaticEntityParameters* static_params);
  Player() = delete;
  ~Player() {}
  void set_attack(float attack);
  void set_defence(float defence);
  void set_health(float health);
  void check_map_collision(const std::vector<Object>& solid);
  void key_check(std::map<sf::Keyboard::Key, bool> &keys);
  void update(float time);
 private:
  PlayerState state_;
  float attack_;
  float defence_;
  float health_;
};


//------------------------BUILDERS--------------------------
class PlayerBuilder {
 public:
  PlayerBuilder();
  Player build_player(const std::string& image_name, const std::string& animation_name,
                             float x, float y);
  Player build_player(const std::string& image_name, const std::string& animation_name,
                             sf::Vector2f size);
 private:
};


#endif // PLAYER_H
