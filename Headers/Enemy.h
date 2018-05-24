#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

#include <vector>
#include <list>

enum EnemyState {wander, enemy_stay};
enum EnemyStrength {weak, medium, strong};

//-------------------class Enemy------------------------
class Enemy : public Entity {
 public:
  Enemy(StaticEntityParameters* static_params);
  virtual ~Enemy() {}

 protected:
  EnemyState state_;
  sf::Vector2f target_;
  EnemyStrength strength_;
  float stay_timer_;
  float stay_time_;
  float attack_;
  float defence_;
  float health_;
  void go_to_target(float time, float speed_factor);
  void check_map_collision(const std::vector<Object>& solid) {}
};

//------------------class FighterEnemy-------------------
class FighterEnemy : public Enemy {
 public:
  FighterEnemy() = delete;
  ~FighterEnemy() {}
  FighterEnemy(StaticEntityParameters* static_params, EnemyStrength strength);
};

//------------------class ArcherEnemy---------------------
class ArcherEnemy : public Enemy {
 public:
  ArcherEnemy() = delete;
  ~ArcherEnemy() {}
  ArcherEnemy(StaticEntityParameters* static_params, EnemyStrength strength);
};

//------------------class MageEnemy------------------------
class MageEnemy : public Enemy {
 public:
  MageEnemy() = delete;
  ~MageEnemy() {}
  MageEnemy(StaticEntityParameters* static_params, EnemyStrength strength);
};

/////////////////// FACTORY ///////////////////////////

class EnemyFactory {
 protected:
  EnemyFactory();
  virtual Enemy* create_enemy(EnemyStrength strength) = 0;
  virtual std::list<Enemy*> create_enemies(EnemyStrength strength, std::size_t n) = 0;
  virtual ~EnemyFactory();
  void set_enemy_size(float x, float y);
  void set_enemy_size(sf::Vector2f size);
  StaticEntityParameters* static_params_;
};

class FighterEnemyFactory : public EnemyFactory {
 public:
  FighterEnemyFactory(const std::string& image_name, const std::string& animation_name);
  Enemy* create_enemy(EnemyStrength strength);
  std::list<Enemy*> create_enemies(EnemyStrength strength, std::size_t n);
  ~FighterEnemyFactory() {}
 private:
  std::string animation_name_;
};

class ArcherEnemyFactory : public EnemyFactory {
 public:
  ArcherEnemyFactory(const std::string& image_name, const std::string& animation_name);
  Enemy* create_enemy(EnemyStrength strength);
  std::list<Enemy*> create_enemies(EnemyStrength strength, std::size_t n);
  ~ArcherEnemyFactory() {}
 private:
  std::string animation_name_;
};

class MageEnemyFactory : public EnemyFactory {
 public:
  MageEnemyFactory(const std::string& image_name, const std::string& animation_name);
  Enemy* create_enemy(EnemyStrength strength);
  std::list<Enemy*> create_enemies(EnemyStrength strength, std::size_t n);
  ~MageEnemyFactory() {}
 private:
  std::string animation_name_;
};

#endif // ENEMY_H
