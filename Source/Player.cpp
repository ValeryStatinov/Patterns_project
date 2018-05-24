#include "../Headers/Player.h"

Player::Player(StaticEntityParameters* static_params)
  : Entity(static_params) {
  state_ = stay;
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

void Player::check_map_collision(const std::vector<Object> &solid) {
  //check x
  sf::FloatRect r = solid[0].rect;
  for (auto it = solid.begin(); it != solid.end(); ++it) {
    if ((this->get_rect()).intersects((it->rect))) {
      if (velocity_vector_.x > 0) {
        position_.x = it->rect.left - static_params_->size_.x;
      }
      if (velocity_vector_.x < 0) {
        position_.x = it->rect.left + it->rect.width;
      }
    }
  }
}

void Player::key_check(std::map<sf::Keyboard::Key, bool> &keys) {
  if (keys[sf::Keyboard::Right]) {
    velocity_vector_.x = 1;
  }
  if (keys[sf::Keyboard::Left]) {
    velocity_vector_.x = -1;
  }
  if (keys[sf::Keyboard::Up]) {
    velocity_vector_.y = -1;
  }
  if (keys[sf::Keyboard::Down]) {
    velocity_vector_.y = 1;
  }
  velocity_vector_ = normalize(velocity_vector_);
  for (auto it = keys.begin(); it != keys.end(); ++it) {
    it->second = false;
  }
  return;
}

void Player::update(float time) {
  position_ += velocity_vector_ * speed_ * time;
  velocity_vector_.x = 0;
  velocity_vector_.y = 0;
}




///////-----------BUILDER------------
PlayerBuilder::PlayerBuilder() {}

Player PlayerBuilder::build_player(const std::string& image_name, const std::string& animation_name,
                                   float x, float y) {
  StaticEntityParameters* static_params = new StaticEntityParameters;
  static_params->set_texture(image_name);
  static_params->set_size(x, y);
  Player p(static_params);
  p.add_xml_animation(animation_name);
  p.set_attack(100);
  p.set_defence(100);
  p.set_health(100);
  return p;
}

Player PlayerBuilder::build_player(const std::string &image_name, const std::string &animation_name,
                                   sf::Vector2f size) {
  StaticEntityParameters* static_params = new StaticEntityParameters;
  static_params->set_texture(image_name);
  static_params->set_size(size);
  Player p(static_params);
  p.add_xml_animation(animation_name);
  p.set_attack(100);
  p.set_defence(100);
  p.set_health(100);
  return p;
}
