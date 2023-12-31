/*sfml_input.h*/

/*this function is an SDL port of the keyboard function from the Raylib version of Chaste Tris*/
void keyboard()
{

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
 {
  move_id='A';
  tetris_move_left();
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
 {
  move_id='D';
  tetris_move_right();
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
 {
  move_id='W';
  tetris_move_up();
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
 {
  move_id='S';
  tetris_move_down();
 }

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
 {
  move_id='Z';
  block_rotate_left_basic();
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
 {
  move_id='X';
  block_rotate_right_basic();
 }
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
 {
  move_id='C';
  block_hold();
 }

}





/*
this function gets input from a previous log file and autoplays the moves from  it.
this is a highly experimental feature and probably won't be in the published game
*/
void next_file_input()
{
 int c;
 if(fp_input==NULL){return;}

 c=fgetc(fp_input);

 if(feof(fp_input))
 {
  printf("End of file reached.\n");
  printf("Now use keyboard input.\n");
  /*
   printf("Going back to beginning\n");
   fseek(fp_input,0,SEEK_SET);
  */

  fclose(fp_input); fp_input=NULL;  return;
 }

 else
 {
  /*printf("Character==%c\n",c);*/

  move_id=c;

  if(c=='W'){tetris_move_up();}
  if(c=='S'){tetris_move_down();}
  if(c=='A'){tetris_move_left();}
  if(c=='D'){tetris_move_right();}

  if(c=='Z'){block_rotate_left_basic();}
  if(c=='X'){block_rotate_right_basic();}
  if(c=='C'){block_hold();}
  
  if(c=='[')
  {
   move_log[moves]=c;
   moves++;
  }
  if(c==']')
  {
   move_log[moves]=c;
   moves++;
  }
  
 }


 /*the following code is meant to be used for longboi mode in combination with a special input file*/
 /*move backwards to the right spot for infinite loop of longbois*/
 
 /*
  c=ftell(fp_input);
  if(c==604){fseek(fp_input,512,SEEK_SET);}
 */

}

