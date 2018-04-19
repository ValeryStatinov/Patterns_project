#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"
#include "AnimationManager.h"
#include "AdditionalAlgebraicFunctions.h"
enum Direction {up, down, left, right};
class PlayingEnvironment;

class Entity {
 public:
  Entity();
  virtual ~Entity() {}
  virtual void update(PlayingEnvironment& play_env, float time) = 0;
  void draw_entity(sf::RenderTexture& render_texture, float time);
  void add_xml_animation(const std::string& file_name, sf::Texture& texture);
  sf::FloatRect get_rect();
  void set_position(float x, float y);

 protected:
  AnimationManager animation_manager_;
  sf::Vector2f position_;
  sf::Vector2f size_;
  sf::Vector2f velocity_vector_;
  float speed_;
  Direction dir_;
};

#endif // ENTITY_H
