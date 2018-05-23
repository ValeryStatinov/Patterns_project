#include "../Headers/tests.h"
#include "../Headers/Player.h"
#include "../Headers/Enemy.h"
#include <memory>
#include "../Headers/PlayingEnvironment.h"
void demonstrate() {
  srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(800, 600), "Patterns_project");
  sf::RenderTexture visable;
  visable.create(800, 600);
  FighterEnemy en(weak);
  sf::Clock clock;
  PlayingEnvironment plenv;
  ArcherPlayerBuilder bld("Images/sonic.png");
  std::shared_ptr<Player> player = bld.get_player();
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
    player->update(plenv, time);
    visable.display();
    window.clear();
    sf::Sprite sprite(visable.getTexture());
    window.draw(sprite);
    window.display();
  }


  return;
}
