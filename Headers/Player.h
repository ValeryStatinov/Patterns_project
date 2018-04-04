#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <map>
#include "../Headers/Entity.h"
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include "AnimationManager.h"
#include "AdditionalAlgebraicFunctions.h"

enum State {stay, run, attack, attacked};

class Player : public Entity {
 public:
  Player();
  void update(float time);
  void key_check(std::map<sf::Keyboard::Key, bool>& keys);

 private:
  State state_;

};

#endif // PLAYER_H
