#include <SFML/Graphics.hpp>

int width=1280,height=720;

int frame=0,lastframe=0,fps=60,delay,framelimit=1; /*only used for animation demos*/
time_t time0,time1;
int seconds,minutes,hours; /*to keep track of time*/
int sdl_time,sdl_time1;

char gamename[256];
int blocks_used=7;

char text[0x200];
char movetext[256],move_id;
int text_x; /*the x position of where text will go*/

FILE *fp; /*to save a file of moves played*/
char filename[256]; /*name of move log file*/
FILE *fp_input; /*file to get input from instead of the keyboard*/

#include "chastetris.h"
#include "sfml_input.h"


int main()
{
 sf::RenderWindow window(sf::VideoMode(width,height),"SFML Level 1");

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

