#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>

int main(){

  sf::RenderWindow window(sf::VideoMode(500,700), "Snake by Pikmin");
  window.setFramerateLimit(60);

  sf::RectangleShape cubo(sf::Vector2f(100,100));
  
  sf::RectangleShape piso(sf::Vector2f(500,100));
  piso.setPosition(0,400);
  piso.setFillColor(sf::Color::Green);

  const float gravedad = 9.8f;
  int time = 0;

  while(window.isOpen()){
    sf::Event evento;

    if(window.pollEvent(evento)){
      if(evento.type == sf::Event::Closed){
        window.close();
      }

    }

    cubo.move(0,gravedad);

    if(cubo.getPosition().y > (piso.getPosition().y - 100)){
      cubo.move(0,-gravedad);
      time = 0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
      cubo.move(3,0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      cubo.move(-3,0);
    }

    if(time < 14){
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        cubo.move(0,-(gravedad+20));
        time++;
        std::system("clear");
        std::cout << time << std::endl; 
      }
    }

    window.clear();
    window.draw(cubo);
    window.draw(piso);
    window.display();

  }

  return EXIT_SUCCESS;
}
