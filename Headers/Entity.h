#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include "AnimationManager.h"
#include "AdditionalAlgebraicFunctions.h"
#include "Level.h"
enum Direction {up, down, left, right};

// FLYWEIGHT
class StaticEntityParameters {
 public:
  sf::Texture texture_;
  sf::Vector2f size_;
  void set_texture(const std::string& file_name);
  void set_size(float x, float y);
  void set_size(sf::Vector2f size);
};


class Entity {
 public:
  Entity(StaticEntityParameters* static_params);
  virtual ~Entity() {}
  void draw(sf::RenderTexture& render_texture, float time);
  sf::FloatRect get_rect();
  void set_position(float x, float y);
  void add_xml_animation(const std::string& file_name);
  virtual void check_map_collision(const std::vector<Object>& solid) = 0;
 protected:
  AnimationManager animation_manager_;
  sf::Vector2f position_;
  sf::Vector2f velocity_vector_;
  float speed_;
  Direction dir_;
  StaticEntityParameters* static_params_;
};


#endif // ENTITY_H
