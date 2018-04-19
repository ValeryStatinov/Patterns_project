#ifndef PLAYINGENVIRONMENT_H
#define PLAYINGENVIRONMENT_H

#include "AdditionalAlgebraicFunctions.h"
#include "AnimationManager.h"
#include "Enemy.h"
#include "Player.h"
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include <vector>
#include <string>


class PlayingEnvironment {
 public:
  //Player& get_player();
  std::vector<Enemy*>& get_enemies();
 private:
  //Player player_;
  std::vector<Enemy*> enemies_;
};

#endif // PLAYINGENVIRONMENT_H
