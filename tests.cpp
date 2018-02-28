#include "tests.h"

void demonstrate() {
  srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(800, 600), "Patterns_project");
  sf::RenderTexture visable;
  visable.create(800, 600);
  EnemyFactory factory;
  std::vector<Enemy*> enemies;
  enemies.push_back(factory.create_fighter_enemy(weak));
  enemies.push_back(factory.create_archer_enemy(weak));
  enemies.push_back(factory.create_mage_enemy(weak));
  for (auto it = enemies.begin(); it != enemies.end(); ++it) {
    //(*it)->set_position(rand() % 600 + 400, rand() % 400 + 200);
    (*it)->set_position(400, 300);

  }
  sf::Clock clock;
  while(window.isOpen()) {
    sf::Event event;
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time /= 800;


    while(window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
// UPDATE AND RENDER //
    visable.clear();

    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
      (*it)->draw_entity(visable, time);
      (*it)->update(time);
    }

    visable.display();

    window.clear();
    sf::Sprite sprite(visable.getTexture());
    window.draw(sprite);
    window.display();
  }

  for (auto it = enemies.begin(); it != enemies.end(); ++it) {
    delete(*(it));
  }
  return;
}
