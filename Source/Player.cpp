#include "../Headers/Player.h"

Player::Player(PlayerClass player_class) : Entity(), class_(player_class) {}

void Player::update(PlayingEnvironment &play_env, float time) {
  return;
}

void Player::key_check(std::map<sf::Keyboard::Key, bool> &keys) {
  if (keys[sf::Keyboard::Right]) {
    velocity_vector_.x += 1;
    state_ = run;
    dir_ = right;
  }
  if (keys[sf::Keyboard::Left]) {
    velocity_vector_.x -= 1;
    state_ = run;
    dir_ = left;
  }
  if (keys[sf::Keyboard::Up]) {
    velocity_vector_.y -= 1;
    state_ = run;
  }
  if (keys[sf::Keyboard::Down]) {
    velocity_vector_.y += 1;
    state_ = run;
  }
  velocity_vector_ = normalize(velocity_vector_);
  return;
}

void Player::set_texture(std::string file_name) {
  texture_.loadFromFile(file_name);
}

void Player::set_attack(float attack) {
  attack_ = attack;
}

void Player::set_defence(float defence) {
  defence_ = defence;
}

void Player::set_health(float health) {
  health_ = health;
}



///////-----------BUILDER------------

PlayerBuilder::PlayerBuilder() {}

std::shared_ptr<Player> PlayerBuilder::get_player() {
  return player_;
}

FighterPlayerBuilder::FighterPlayerBuilder(std::string file_name) {
  player_ = std::make_shared<Player>(Player(fighter));
  player_->set_texture(file_name);
  this->build_attack();
  this->build_defence();
  this->build_health();
}


void FighterPlayerBuilder::build_attack() {
  player_->set_attack(100);
}

void FighterPlayerBuilder::build_defence() {
  player_->set_defence(100);
}

void FighterPlayerBuilder::build_health() {
  player_->set_health(100);
}

ArcherPlayerBuilder::ArcherPlayerBuilder(std::string file_name) {
  player_ = std::make_shared<Player>(Player(archer));
  player_->set_texture(file_name);
  this->build_attack();
  this->build_defence();
  this->build_health();
}

void ArcherPlayerBuilder::build_attack() {
  player_->set_attack(150);
}

void ArcherPlayerBuilder::build_defence() {
  player_->set_defence(80);
}

void ArcherPlayerBuilder::build_health() {
  player_->set_health(70);
}

MagePlayerBuilder::MagePlayerBuilder(std::string file_name) {
  player_ = std::make_shared<Player>(Player(mage));
  player_->set_texture(file_name);
  this->build_attack();
  this->build_defence();
  this->build_health();
}

void MagePlayerBuilder::build_attack() {
  player_->set_attack(180);
}

void MagePlayerBuilder::build_defence() {
  player_->set_defence(60);
}

void MagePlayerBuilder::build_health() {
  player_->set_defence(60);
}























