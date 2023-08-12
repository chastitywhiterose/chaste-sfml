#include <SFML/Graphics.hpp>
int main()
{
 sf::RenderWindow window(sf::VideoMode(1280,720),"SFML Level 0");

 sf::RectangleShape rectangle(sf::Vector2f(10,10));
 sf::CircleShape circle(10.f);



 while(window.isOpen())
 {
  //drawing section
   window.clear();

  rectangle.setSize(sf::Vector2f(100,100));
  rectangle.setFillColor(sf::Color(0,0,255));   
  rectangle.setPosition(sf::Vector2f(100.f, 100.f));
  window.draw(rectangle);

  rectangle.setFillColor(sf::Color(0,255,0));   
  rectangle.setPosition(sf::Vector2f(300.f, 100.f));
  window.draw(rectangle);

  rectangle.setFillColor(sf::Color(255,0,0));   
  rectangle.setPosition(sf::Vector2f(500.f, 100.f));
  window.draw(rectangle);

  circle.setRadius(50);
  circle.setFillColor(sf::Color(255,255,0) );
  circle.setPosition(sf::Vector2f(100.f, 300.f));
  window.draw(circle);

  circle.setFillColor(sf::Color(0,255,255) );
  circle.setPosition(sf::Vector2f(300.f, 300.f));
  window.draw(circle);

  circle.setFillColor(sf::Color(255,0,255) );
  circle.setPosition(sf::Vector2f(500.f, 300.f));
  window.draw(circle);


  window.display();

  //polling section
  sf::Event event;
  while (window.pollEvent(event))
  {
   if (event.type == sf::Event::Closed) {window.close();}
   if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {window.close();}
  }


 }

return 0;
}

