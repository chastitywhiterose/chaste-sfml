/*sfml_graphics.h*/

void title_screen()
{
 sf::RectangleShape rectangle(sf::Vector2f(10,10));
 sf::CircleShape circle(10.f);

 while(loop)
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

  main_font.sprite.setColor(sf::Color(0,255,0)); // green
  window.draw(main_font.sprite);

  window.display();

  //polling section
  
  while (window.pollEvent(event))
  {
   if(event.type == sf::Event::Closed) {loop=0;}
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){loop=0;}
  }

 }

}










/*more global variables to be defined before game loop function*/
int block_size;
int border_size;
int grid_offset_x;

/*
sets up the variables before the game loop so that the Tetris field is in the center.
This is done because I updated the game later on. This corrects everything before the game loop starts.
*/
void screen_setup_centered()
{
 grid_offset_x=(width-(20/2*block_size))/2; /*to center of screen*/
 border_size=12;
}

/*
this is a function which is called by main after window is created. It contains the game loop.
*/
void sfml_chastetris()
{
 int pixel,r,g,b;
 int x=0,y=0;


 block_size=height/grid_height;
 grid_offset_x=block_size*1; /*how far from the left size of the window the grid display is*/
 border_size=block_size;

 printf("block_size==%d\n",block_size);
  
 /*if the following function is called, screen is centered. Otherwise use old left side style.*/
 screen_setup_centered();

 chastetris_info();

 spawn_block();


 /*first empty the grid*/
 y=0;
 while(y<grid_height)
 {
  x=0;
  while(x<grid_width)
  {
   main_grid.array[x+y*grid_width]=empty_color;
   x+=1;
  }
  y+=1;
 }


 delay=1000/fps;
 
 /*get time before the game starts using standard library time function*/
 time(&time0);
 
 loop=1;
  /* Loop until the user closes the window */
 while(loop)
 {
  sftime=sfclock.getElapsedTime();
  mill=sftime.asMilliseconds();
  mill1=mill+delay;

  window.clear();

 /*make backup of entire grid*/
  temp_grid=main_grid;

  /*draw block onto temp grid at it's current location*/
  y=0;
  while(y<max_block_width)
  {
   x=0;
   while(x<max_block_width)
   {
    if(main_block.array[x+y*max_block_width]!=0)
    {
     if(temp_grid.array[main_block.x+x+(main_block.y+y)*grid_width]!=0)
     {
      printf("Error: Block in Way\n");

      /*because a collision has occurred. We will restore everything back to the way it was before block was moved.*/

      break;
     }
     else
     {
      temp_grid.array[main_block.x+x+(main_block.y+y)*grid_width]=main_block.color;
     }
    }
    x+=1;
   }
   y+=1;
  }



/*display the tetris grid*/

 y=0;
 while(y<grid_height)
 {
  x=0;
  while(x<grid_width)
  {
   pixel=temp_grid.array[x+y*grid_width];
   r=(pixel&0xFF0000)>>16;
   g=(pixel&0x00FF00)>>8;
   b=(pixel&0x0000FF);


/* printf("x=%d y=%d ",x,y);
 printf("red=%d green=%d blue=%d\n",r,g,b);*/


/*rect_color=SDL_MapRGB(surface->format,r,g,b);*/

rectangle.setFillColor(sf::Color(r,g,b));

/*set up the rectangle structure with the needed data to square the squares*/
rect.left=grid_offset_x+x*block_size;
rect.top=y*block_size;
rect.width=block_size;
rect.height=block_size;

rectangle.setPosition(sf::Vector2f(rect.left,rect.top));
rectangle.setSize(sf::Vector2f(rect.width,rect.height));
window.draw(rectangle);


   x+=1;
  }
  y+=1;
 }




 /*draw the boundary walls*/

/*
 set up the rectangle structure with the needed data to square the walls
*/

 rectangle.setFillColor(sf::Color(128,128,128));

 rect.left=grid_offset_x-border_size;
 rect.top=0*block_size;
 rect.width=border_size;
 rect.height=height;

 rectangle.setPosition(sf::Vector2f(rect.left,rect.top));
 rectangle.setSize(sf::Vector2f(rect.width,rect.height));
 window.draw(rectangle);

 rect.left=grid_offset_x+grid_width*block_size;

 rectangle.setPosition(sf::Vector2f(rect.left,rect.top));
 window.draw(rectangle);


 /*end of drawing code for grid*/

 //stats_func();
 //draw_input();


 /*optionally, get input from another file instead of keyboard if I have this enabled.*/
  next_file_input();

 /*test for events and only process if they exist*/
  while (window.pollEvent(event))
  {
   if(event.type == sf::Event::Closed) {loop=0;}
   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){loop=0;}
   keyboard();
  }

 window.display();

 /*time loop used to slow the game down so users can see it*/

 while(mill<mill1)
 {
  sftime=sfclock.getElapsedTime();
  mill=sftime.asMilliseconds();
 }


 frame++;

 }

}
