#include "../Headers/AnimationManager.h"

Animation::Animation() {
  current_frame_ = 0;
  flip_ = false;
}

void Animation::tick(float time) {
  current_frame_ += speed_ * time;
  if (current_frame_ > frames_.size()) {
    current_frame_ = 0;
  }

  int int_current_frame = (int)current_frame_;

  if (flip_) {
    sprite_.setTextureRect(frames_flip_[int_current_frame]);
  }
  else {
    sprite_.setTextureRect(frames_[int_current_frame]);

  }
  return;
}

void AnimationManager::draw_animation(sf::RenderTexture &texture, float x, float y) {
  animation_list_[current_animation_].sprite_.setPosition(x, y);
  texture.draw(animation_list_[current_animation_].sprite_);
  return;
}

void AnimationManager::tick(float time) {
  animation_list_[current_animation_].tick(time);
  animation_list_[current_animation_].flip_ = false;
  return;
}

void AnimationManager::flip() {
  animation_list_[current_animation_].flip_ = true;
  return;
}

void AnimationManager::load_from_xml(std::string& file_name, sf::Texture& texture) {
  TiXmlDocument animFile(file_name.c_str());

  animFile.LoadFile();

  TiXmlElement* head;
  head = animFile.FirstChildElement("sprites");
  TiXmlElement* animElement;
  animElement = head->FirstChildElement("animation");
  while (animElement) {
    Animation anim;
    current_animation_ = animElement->Attribute("title");
    int delay = atoi(animElement->Attribute("delay"));
    anim.speed_ = 1.0 / delay;
    anim.sprite_.setTexture(texture);

    TiXmlElement* cut;

    cut = animElement->FirstChildElement("cut");
    while (cut) {
      int x = atoi(cut->Attribute("x"));
      int y = atoi(cut->Attribute("y"));
      int w = atoi(cut->Attribute("w"));
      int h = atoi(cut->Attribute("h"));

      anim.frames_.push_back(sf::IntRect(x, y, w, h));
      anim.frames_flip_.push_back(sf::IntRect(x + w, y, -w, h));
      cut = cut->NextSiblingElement("cut");
    }

    anim.sprite_.setTextureRect(sf::IntRect(anim.frames_[0]));

    animation_list_[current_animation_] = anim;
    animElement = animElement->NextSiblingElement("animation");
  }
  return;
}

void AnimationManager::color(const sf::Color& color) {
  animation_list_[current_animation_].sprite_.setColor(color);
  return;
}

void AnimationManager::set_animation(std::string anim_name) {
  current_animation_ = anim_name;
  return;
}

