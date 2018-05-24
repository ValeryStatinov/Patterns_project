#include "../Headers/Bullet.h"

Bullet::Bullet(StaticEntityParameters *static_params)
  : Entity(static_params) {}

BulletFactory::BulletFactory(const std::string& image_name, const std::string& animation_name) {
  static_params_ = new StaticEntityParameters;
  static_params_->set_texture(image_name);
  animation_name_ = animation_name;
}

BulletFactory::~BulletFactory() {
  delete static_params_;
}

Bullet* BulletFactory::create_bullet() {
  Bullet* bullet = new Bullet(static_params_);
  bullet->add_xml_animation(animation_name_);
  return bullet;
}

std::list<Bullet*> BulletFactory::create_bullets(std::size_t n) {
  std::list<Bullet*> bullets;
  for (std::size_t i = 0; i < n; ++i) {
    Bullet* bullet = new Bullet(static_params_);
    bullet->add_xml_animation(animation_name_);
    bullets.push_back(bullet);
  }
  return bullets;
}
