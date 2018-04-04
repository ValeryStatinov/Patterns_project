#include "../Headers/Player.h"

Player::Player() : Entity() {
  animation_manager_.set_animation("stay");
}

void Player::update(float time) {
  if (state_ == stay) {
    animation_manager_.set_animation("stay");
    if (dir_ == left) {
      animation_manager_.flip();
    }
  }

  if (state_ == run) {
    position_ += velocity_vector_ * speed_ * time;
    animation_manager_.set_animation("run");
    if (dir_ == left) {
      animation_manager_.flip();
    }
  }

  velocity_vector_.x = 0;
  velocity_vector_.y = 0;
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
