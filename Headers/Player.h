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
enum PlayerClass {fighter, archer, mage};

class Player : public Entity {
 public:
  Player(PlayerClass player_class);
  Player() = delete;
  ~Player() {}
  void update(PlayingEnvironment& play_env, float time);
  void key_check(std::map<sf::Keyboard::Key, bool>& keys);
  void set_texture(std::string file_name);
  void set_attack(float attack);
  void set_defence(float defence);
  void set_health(float health);

 private:
  PlayerState state_;
  PlayerClass class_;
  float attack_;
  float defence_;
  float health_;
  sf::Texture texture_;

};


//------------------------BUILDERS--------------------------

class PlayerBuilder {
 public:
  PlayerBuilder();
  std::shared_ptr<Player> get_player();
  virtual void build_attack() = 0;
  virtual void build_defence() = 0;
  virtual void build_health() = 0;
 protected:
  std::shared_ptr<Player> player_;
};

class FighterPlayerBuilder : public PlayerBuilder {
 public:
  FighterPlayerBuilder(std::string file_name);
  void build_attack();
  void build_defence();
  void build_health();
};

class ArcherPlayerBuilder : public PlayerBuilder {
 public:
  ArcherPlayerBuilder(std::string file_name);
  void build_attack();
  void build_defence();
  void build_health();
};

class MagePlayerBuilder : public PlayerBuilder {
 public:
  MagePlayerBuilder(std::string file_name);
  void build_attack();
  void build_defence();
  void build_health();
};

#endif // PLAYER_H
