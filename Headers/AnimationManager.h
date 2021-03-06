#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H
#include "../TinyXML/tinystr.h"
#include "../TinyXML/tinyxml.h"
#include <vector>
#include <string>
#include <map>
#include "../SFML-2.4.2/include/SFML/Graphics.hpp"

class AnimationManager;

class Animation {
 public:
  friend class AnimationManager;
  Animation();
  void tick(float time);

 private:
  std::vector<sf::IntRect> frames_, frames_flip_;
  sf::Sprite sprite_;
  float current_frame_;
  float speed_;
  bool flip_;
};

//------------------------------

class AnimationManager {
 public:
  AnimationManager() {}
  void draw_animation(sf::RenderTexture& texture, float x, float y);
  void tick(float time);
  void flip();
  void load_from_xml(const std::string& file_name, sf::Texture& texture);
  void color(const sf::Color& color);
  void set_animation(const std::string& anim_name);
 private:
  std::string current_animation_;
  std::map<std::string, Animation> animation_list_;
};
#endif // ANIMATIONMANAGER_H
