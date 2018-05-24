#include "../Headers/tests.h"
#include "../Headers/Player.h"
#include "../Headers/Enemy.h"
#include <memory>
#include "../Headers/Map.h"
#include "../Headers/Level.h"
#include "../Headers/Bullet.h"

void demonstrate() {
  srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(800, 600), "Patterns_project");
  sf::RenderTexture visible;
  visible.create(800, 600);
  sf::Clock clock;
  std::map<sf::Keyboard::Key, bool> keys;
  //create test items
  std::string file_name = "Map/Jurec_map.tmx";
  Level lvl(file_name);

  std::string s1 = "Images/enemy.png";
  std::string s2 = "Animation/enemy.tmx";
  FighterEnemyFactory fuck(s1, s2);
  Enemy* fe = fuck.create_enemy(weak);

  std::string s3 = "Images/sonic.png";
  std::string s4 = "Animation/sonic.tmx";
  PlayerBuilder bld;
  Player pl = bld.build_player(s3, s4, 25, 25);

  std::string s5 = "Images/Bullet.png";
  std::string s6 = "Animation/Bullet.tmx";
  BulletFactory bfuck(s5, s6);
  Bullet* b = bfuck.create_bullet();


// MAIN WHILE //
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        window.close();
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      keys[sf::Keyboard::Right] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      keys[sf::Keyboard::Left] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      keys[sf::Keyboard::Up] = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      keys[sf::Keyboard::Down] = true;
    }

// UPDATE AND RENDER //

    visible.clear();
    lvl.draw(visible);
    fe->draw(visible, time);
    pl.key_check(keys);
    pl.draw(visible, time);
    pl.check_map_collision(lvl.get_solid());
    pl.update(time);

    b->draw(visible, time);
    visible.display();
    window.clear();

    sf::Sprite sprite(visible.getTexture());
    window.draw(sprite);
    window.display();
  }


  return;
}
