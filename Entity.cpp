#include "Entity.h"

Entity::Entity() {
  dir_ = right;
  position_.x = 0;
  position_.y = 0;
  size_.x = 0;
  size_.y = 0;
  velocity_vector_.x = 0;
  velocity_vector_.y = 0;
  speed_ = 0;
}

void Entity::draw_entity(sf::RenderTexture &render_texture, float time) {
  animation_manager_.draw_animation(render_texture, position_.x, position_.y);
  animation_manager_.tick(time);
  return;
}

void Entity::add_xml_animation(std::string file_name, sf::Texture& texture) {
  animation_manager_.load_from_xml(file_name, texture);
  return;
}

sf::FloatRect Entity::get_rect() {
  sf::FloatRect rect;
  rect.left = position_.x;
  rect.top = position_.y;
  rect.width = size_.x;
  rect.height = size_.y;
  return rect;
}

void Entity::set_position(float x, float y) {
  position_.x = x;
  position_.y = y;
  return;
}
