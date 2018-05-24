#include "../Headers/Entity.h"

Entity::Entity(StaticEntityParameters* static_params)
  : static_params_(static_params) {
  dir_ = right;
  position_.x = 0;
  position_.y = 0;
  velocity_vector_.x = 0;
  velocity_vector_.y = 0;
  speed_ = 0.1;
  animation_manager_.set_animation("stay");
}

void Entity::draw(sf::RenderTexture &render_texture, float time) {
  animation_manager_.draw_animation(render_texture, position_.x, position_.y);
  animation_manager_.tick(time);
  return;
}


void Entity::add_xml_animation(const std::string& file_name) {
  animation_manager_.load_from_xml(file_name, static_params_->texture_);
  return;
}

void Entity::set_position(float x, float y) {
  position_.x = x;
  position_.y = y;
  return;
}

sf::FloatRect Entity::get_rect() {
  sf::FloatRect rect;
  rect.left = position_.x;
  rect.top = position_.y;
  rect.width = static_params_->size_.x;
  rect.height = static_params_->size_.y;
  return rect;
}

void StaticEntityParameters::set_texture(const std::string& file_name) {
  texture_.loadFromFile(file_name);
  return;
}

void StaticEntityParameters::set_size(float x, float y) {
  size_.x = x;
  size_.y = y;
  return;
}

void StaticEntityParameters::set_size(sf::Vector2f size) {
  size_ = size;
  return;
}


