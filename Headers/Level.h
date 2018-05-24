#ifndef LEVEL_H
#define LEVEL_H

#include "Map.h"

class Level {
 public:
  Level(const std::string& file_name);
  bool load_from_file(const std::string& file_name);
  Object get_object(const std::string& name);
  std::vector<Object> get_objects(const std::string& name);
  std::vector<Object> get_all_objects();
  std::vector<Object> get_solid();
  void draw(sf::RenderTexture& render_texture);

 private:
  Map map_;
  std::vector<Object> solid_;
};

#endif // LEVEL_H
