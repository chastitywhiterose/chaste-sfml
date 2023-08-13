#include <SFML/Graphics.hpp>

int width=1280,height=720;
int loop=1;
int frame=0,lastframe=0,fps=60,delay,framelimit=1; /*only used for animation demos*/
time_t time0,time1;
int seconds,minutes,hours; /*to keep track of time*/
int mill,mill1; /*milliseconds*/

char gamename[256];
int blocks_used=7;

char text[0x200];
char movetext[256],move_id;
int text_x; /*the x position of where text will go*/

FILE *fp; /*to save a file of moves played*/
char filename[256]; /*name of move log file*/
FILE *fp_input; /*file to get input from instead of the keyboard*/

sf::RenderWindow window;
sf::Event event;
sf::Clock sfclock;
sf::Time sftime;
sf::RectangleShape rectangle;
sf::IntRect rect;

#include "chastetris.h"
#include "chastetris_gamesave.h"
#include "chaste_the_rainbow.h"
#include "sfml_chastefont.h"
#include "sfml_input.h"
#include "sfml_graphics.h"


int main()
{
 window.create(sf::VideoMode(width,height),"SFML Level 2");
 window.setKeyRepeatEnabled(false);

 main_font=chaste_font_load("./font/FreeBASIC Font 8.png");

test_font_image();

 title_screen();

 //sfml_chastetris();

 window.close();

return 0;
}

