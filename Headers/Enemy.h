#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <vector>
enum EnemyState {wander, enemy_stay};
enum EnemyStrength {weak, medium, strong};
//-------------------class Enemy------------------------
class Enemy : public Entity {
 public:
  Enemy();
  virtual ~Enemy() {}
  virtual void update(float time) = 0;

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
};

//------------------class FighterEnemy-------------------
class FighterEnemy : public Enemy {
 public:
  FighterEnemy() = delete;
  ~FighterEnemy() {}
  FighterEnemy(EnemyStrength strength);
  friend class EnemyFactory;
  void update(float time);

 private:
  static sf::Texture load_texture();
  static sf::Texture texture_;
};

//------------------class ArcherEnemy---------------------
class ArcherEnemy : public Enemy {
 public:
  ArcherEnemy() = delete;
  ~ArcherEnemy() {}
  ArcherEnemy(EnemyStrength strength);
  friend class EnemyFactory;
  void update(float time);

 private:
  static sf::Texture load_texture();
  static sf::Texture texture_;
};

//------------------class MageEnemy------------------------
class MageEnemy : public Enemy {
 public:
  MageEnemy() = delete;
  ~MageEnemy() {}
  MageEnemy(EnemyStrength strength);
  friend class EnemyFactory;
  void update(float time);

 private:
  static sf::Texture load_texture();
  static sf::Texture texture_;
};

/////////////////// FACTORY ///////////////////////////

class EnemyFactory {
 public:
  static Enemy* create_fighter_enemy(EnemyStrength strength);
  static Enemy* create_archer_enemy(EnemyStrength strength);
  static Enemy* create_mage_enemy(EnemyStrength strength);
  static std::vector<Enemy*> create_n_fighter_enemies(EnemyStrength strength, std::size_t n);
  static std::vector<Enemy*> create_n_archer_enemies(EnemyStrength strength, std::size_t n);
  static std::vector<Enemy*> create_n_mage_enemies(EnemyStrength strength, std::size_t n);
};

#endif // ENEMY_H
