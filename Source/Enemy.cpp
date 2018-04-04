#include "../Headers/Enemy.h"
#include <ctime>

Enemy::Enemy() {
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

sf::Texture FighterEnemy::texture_ = FighterEnemy::load_texture();
sf::Texture ArcherEnemy::texture_ = ArcherEnemy::load_texture();
sf::Texture MageEnemy::texture_ = MageEnemy::load_texture();
/////////////// FIGHTER ENEMY ////////////////////////////
FighterEnemy::FighterEnemy(EnemyStrength strength) : Enemy() {//TODO adjust parameters
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
  this->add_xml_animation("Animation/FighterEnemy.tmx", texture_);
  animation_manager_.set_animation("stay");
}

sf::Texture FighterEnemy::load_texture() {
  sf::Texture temp_texture;
  temp_texture.loadFromFile("Images/FighterEnemy.png");
  return temp_texture;
}

void FighterEnemy::update(float time) { // TODO enemy logic ai
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
}

////////////////// ARCHER ENEMY //////////////////////////////

ArcherEnemy::ArcherEnemy(EnemyStrength strength) : Enemy() { //TODO adjust parameters
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
  this->add_xml_animation("Animation/ArcherEnemy.tmx", texture_);
  animation_manager_.set_animation("stay");
}

sf::Texture ArcherEnemy::load_texture() {
  sf::Texture temp_texture;
  temp_texture.loadFromFile("Images/ArcherEnemy.png");
  return temp_texture;
}

void ArcherEnemy::update(float time) { // TODO enemy logic ai
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
}

/////////////////////// MAGE ENEMY ////////////////////////////////
MageEnemy::MageEnemy(EnemyStrength strength) : Enemy() { //TODO adjust parameters
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
  this->add_xml_animation("Animation/MageEnemy.tmx", texture_);
  animation_manager_.set_animation("stay");
}

sf::Texture MageEnemy::load_texture() {
  sf::Texture temp_texture;
  temp_texture.loadFromFile("Images/MageEnemy.png");
  return temp_texture;
}

void MageEnemy::update(float time) { // TODO enemy logic ai
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
}

//////////////////////// FACTORY ////////////////////////////
Enemy* EnemyFactory::create_fighter_enemy(EnemyStrength strength) {
  Enemy* enemy = new FighterEnemy(strength);
  return enemy;
}

Enemy* EnemyFactory::create_archer_enemy(EnemyStrength strength) {
  Enemy* enemy = new ArcherEnemy(strength);
  return enemy;
}

Enemy* EnemyFactory::create_mage_enemy(EnemyStrength strength) {
  Enemy* enemy = new MageEnemy(strength);
  return enemy;
}

std::vector<Enemy*> EnemyFactory::create_n_fighter_enemies(EnemyStrength strength, std::size_t n) {
  std::vector<Enemy*> vect;
  for (std::size_t i = 0; i < n; ++i) {
    vect.push_back(create_fighter_enemy(strength));
  }
  return vect;
}

std::vector<Enemy*> EnemyFactory::create_n_archer_enemies(EnemyStrength strength, std::size_t n) {
  std::vector<Enemy*> vect;
  for (std::size_t i = 0; i < n; ++i) {
    vect.push_back(create_archer_enemy(strength));
  }
  return vect;
}

std::vector<Enemy*> EnemyFactory::create_n_mage_enemies(EnemyStrength strength, std::size_t n) {
  std::vector<Enemy*> vect;
  for (std::size_t i = 0; i < n; ++i) {
    vect.push_back(create_mage_enemy(strength));
  }
  return vect;
}







