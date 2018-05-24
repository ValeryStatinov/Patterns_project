#include "../Headers/Enemy.h"
#include <ctime>

Enemy::Enemy(StaticEntityParameters* static_params)
  : Entity(static_params) {
  srand(time(NULL));
  stay_time_ = rand() % 5000 + 2500;
  stay_timer_ = 0;
  state_ = wander;
}

void Enemy::go_to_target(float time, float speed_factor) {
  velocity_vector_ = target_ - position_;
  if (velocity_vector_ * velocity_vector_ < 10E-3) {
    state_ = enemy_stay;
    return;
  }
  velocity_vector_ = normalize(velocity_vector_);
  position_ += velocity_vector_ * speed_ * time * speed_factor;
  velocity_vector_.x = 0;
  velocity_vector_.y = 0;
  return;
}

/////////////// FIGHTER ENEMY ////////////////////////////
FighterEnemy::FighterEnemy(StaticEntityParameters* static_params,
                           EnemyStrength strength)
  : Enemy(static_params) {//TODO adjust parameters
  switch(strength) {
    case weak:
      strength_ = weak;
      attack_ = 10;
      defence_ = 10;
      health_ = 100;
      speed_ = 0.02;
      break;
    case medium:
      strength_ = medium;
      attack_ = 20;
      defence_ = 20;
      health_ = 200;
      speed_ = 0.02;
      break;
    case strong:
      strength_ = strong;
      attack_ = 30;
      defence_ = 30;
      health_ = 300;
      speed_ = 0.02;
      break;
  }
  state_ = enemy_stay;
  target_.x = 0;
  target_.y = 0;
}



/*void FighterEnemy::update(PlayingEnvironment& play_env, float time) { // TODO enemy logic ai
  if (state_ == enemy_stay) {
    stay_timer_ += time;
    animation_manager_.set_animation("stay");
    if (stay_timer_ > stay_time_) {
      stay_timer_ = 0;
      animation_manager_.set_animation("run");
      target_.x = position_.x + size_.x / 2 + (rand() % 120) - 60;
      target_.y = position_.y + size_.y / 2 + (rand() % 150) - 75;
      state_ = wander;
    }
  }
  if (state_ == wander) {
    go_to_target(time, 1);
  }
  return;
}*/

////////////////// ARCHER ENEMY //////////////////////////////

ArcherEnemy::ArcherEnemy(StaticEntityParameters* static_params,
                         EnemyStrength strength)
  : Enemy(static_params) { //TODO adjust parameters
  switch(strength) {
    case weak:
      strength_ = weak;
      attack_ = 10;
      defence_ = 10;
      health_ = 100;
      speed_ = 0.03;
      break;
    case medium:
      strength_ = medium;
      attack_ = 20;
      defence_ = 20;
      health_ = 200;
      speed_ = 0.03;
      break;
    case strong:
      strength_ = strong;
      attack_ = 30;
      defence_ = 30;
      health_ = 300;
      speed_ = 0.03;
      break;
  }
  state_ = enemy_stay;
  target_.x = 0;
  target_.y = 0;
}



/*void ArcherEnemy::update(PlayingEnvironment& play_env, float time) { // TODO enemy logic ai
  if (state_ == enemy_stay) {
    animation_manager_.set_animation("stay");
    stay_timer_ += time;
    if (stay_timer_ > stay_time_) {
      stay_timer_ = 0;
      animation_manager_.set_animation("run");
      target_.x = position_.x + size_.x / 2 + (rand() % 120) - 60;
      target_.y = position_.y + size_.y / 2 + (rand() % 150) - 75;
      state_ = wander;
    }
  }
  if (state_ == wander) {
    go_to_target(time, 1);
  }
  return;
}*/

/////////////////////// MAGE ENEMY ////////////////////////////////
MageEnemy::MageEnemy(StaticEntityParameters* static_params,
                     EnemyStrength strength)
  : Enemy(static_params) { //TODO adjust parameters
  switch(strength) {
    case weak:
      strength_ = weak;
      attack_ = 10;
      defence_ = 10;
      health_ = 100;
      speed_ = 0.01;
      break;
    case medium:
      strength_ = medium;
      attack_ = 20;
      defence_ = 20;
      health_ = 200;
      speed_ = 0.01;
      break;
    case strong:
      strength_ = strong;
      attack_ = 30;
      defence_ = 30;
      health_ = 300;
      speed_ = 0.01;
      break;
  }
  state_ = enemy_stay;
  target_.x = 0;
  target_.y = 0;
}



/*void MageEnemy::update(PlayingEnvironment& play_env, float time) { // TODO enemy logic ai
  if (state_ == enemy_stay) {
    stay_timer_ += time;
    animation_manager_.set_animation("stay");
    if (stay_timer_ > stay_time_) {
      stay_timer_ = 0;
      animation_manager_.set_animation("run");
      target_.x = position_.x + size_.x / 2 + (rand() % 120) - 60;
      target_.y = position_.y + size_.y / 2 + (rand() % 150) - 75;
      state_ = wander;
    }
  }
  if (state_ == wander) {
    go_to_target(time, 1);
  }
  return;
}*/

//////////////////////// FACTORY ////////////////////////////
EnemyFactory::EnemyFactory() {
  static_params_ = new StaticEntityParameters;
}

EnemyFactory::~EnemyFactory() {
  delete static_params_;
}

void EnemyFactory::set_enemy_size(float x, float y) {
  static_params_->set_size(x, y);
  return;
}

void EnemyFactory::set_enemy_size(sf::Vector2f size) {
  static_params_->set_size(size);
}

//fighter factory
FighterEnemyFactory::FighterEnemyFactory(const std::string& image_name, const std::string& animation_name)
  : EnemyFactory(){
  static_params_->set_texture(image_name);
  static_params_->set_size(0, 0);
  animation_name_ = animation_name;
}

Enemy* FighterEnemyFactory::create_enemy(EnemyStrength strength) {
  Enemy* enemy = new FighterEnemy(static_params_, strength);
  enemy->add_xml_animation(animation_name_);
  return enemy;
}

std::list<Enemy*> FighterEnemyFactory::create_enemies(EnemyStrength strength, std::size_t n) {
  std::list<Enemy*> enemies;
  for (std::size_t i = 0; i < n; ++i) {
    Enemy* enemy = new FighterEnemy(static_params_, strength);
    enemy->add_xml_animation(animation_name_);
    enemies.push_back(enemy);
  }
  return enemies;
}

//archer factory
ArcherEnemyFactory::ArcherEnemyFactory(const std::string& image_name, const std::string& animation_name)
  : EnemyFactory() {
  static_params_->set_texture(image_name);
  static_params_->set_size(0, 0);
  animation_name_ = animation_name;
}

Enemy* ArcherEnemyFactory::create_enemy(EnemyStrength strength) {
  Enemy* enemy = new ArcherEnemy(static_params_, strength);
  enemy->add_xml_animation(animation_name_);
  return enemy;
}

std::list<Enemy*> ArcherEnemyFactory::create_enemies(EnemyStrength strength, std::size_t n) {
  std::list<Enemy*> enemies;
  for (std::size_t i = 0; i < n; ++i) {
    Enemy* enemy = new ArcherEnemy(static_params_, strength);
    enemy->add_xml_animation(animation_name_);
    enemies.push_back(enemy);
  }
  return enemies;
}

//mage factory
MageEnemyFactory::MageEnemyFactory(const std::string& image_name, const std::string& animation_name)
  : EnemyFactory() {
  static_params_->set_texture(image_name);
  static_params_->set_size(0, 0);
  animation_name_ = animation_name;
}

Enemy* MageEnemyFactory::create_enemy(EnemyStrength strength) {
  Enemy* enemy = new MageEnemy(static_params_, strength);
  enemy->add_xml_animation(animation_name_);
  return enemy;
}

std::list<Enemy*> MageEnemyFactory::create_enemies(EnemyStrength strength, std::size_t n) {
  std::list<Enemy*> enemies;
  for (std::size_t i = 0; i < n; ++i) {
    Enemy* enemy = new MageEnemy(static_params_, strength);
    enemy->add_xml_animation(animation_name_);
    enemies.push_back(enemy);
  }
  return enemies;
}
