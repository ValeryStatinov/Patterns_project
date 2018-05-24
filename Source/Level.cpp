#include "../Headers/Level.h"

Level::Level(const std::string& file_name) {
  this->load_from_file(file_name);
  std::string solid = "solid";
  solid_ = this->get_objects(solid);
}

bool Level::load_from_file(const std::string &file_name) {
  return map_.LoadFromFile(file_name);
}

Object Level::get_object(const std::string &name) {
  return map_.GetObject(name);
}

std::vector<Object> Level::get_objects(const std::string &name) {
  return map_.GetObjects(name);
}

std::vector<Object> Level::get_all_objects() {
  return map_.GetAllObjects();
}

void Level::draw(sf::RenderTexture &render_texture) {
  map_.Draw(render_texture);
}

std::vector<Object> Level::get_solid() {
  return solid_;
}
