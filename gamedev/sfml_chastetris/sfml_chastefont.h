/*
 Chastity font SDL texture version
 
 This file is a clone of my font library that uses textures instead of surfaces.
 The functions and struct have the same names as the surface version so that it can be used as a drop in replacement depending on whether I am using a renderer or not.
*/


/*
texture font structure
*/
struct chaste_font
{
 int char_width; /*width of a char*/
 int char_height; /*height of a char*/
 sf::Image image; /*the image of loaded font*/
 sf::Texture texture; /*the texture of this font which will be loaded from surface*/
};



/*global fonts that will be reused many times*/
struct chaste_font main_font,font_8,font_16,font_32,font_64,font_128,font_pico8;

/*function to load a font and return a structure with the needed data to draw later*/
struct chaste_font chaste_font_load(const char *s)
{
 int w,h;
 struct chaste_font new_font;
 
 printf("Loading font: %s\n",s);

 if(new_font.image.loadFromFile(s))
 {
  printf("Image: %s is loaded\n",s);
 }
 else
 {
  printf("Error loading image: %s\n",s);
 }

 sf::Vector2u v=new_font.image.getSize();
 w=v.x;
 h=v.y;

 /*
  by default,font height is detected by original image height
  but the font width is the width of the image divided by 95
  because there are exactly 95 characters in the font format that I created.
 */
 new_font.char_width=w/95; /*there are 95 characters in my font files*/
 new_font.char_height=h;

printf("Size of loaded font is %d,%d\n",new_font.char_width,new_font.char_height);

 new_font.image.createMaskFromColor(sf::Color(0,0,0));

 /*now that the font is loaded and we know the dimensions, create a texture from it*/
 if(!new_font.texture.loadFromImage(new_font.image))
 {
  printf("Error loading texture: %s\n",s);
 }

 return new_font;
}




void test_font_image()
{
 int x,y,w,h;
 sf::Uint32 intcolor;
 sf::Color color;
 sf::Vector2u v=main_font.image.getSize();
 w=v.x;
 h=v.y;

 printf("Size of font image is %d,%d\n",w,h);

 printf("Testing pixels next\n");

 y=0;
 while(y<h)
 {
  x=0;
  while(x<w)
  {
   color=main_font.image.getPixel(x,y);
   //printf("%d,%d = R%d,G%d,B%d A%d\n",x,y,color.r,color.g,color.b,color.a);
   intcolor=color.toInteger()>>8;
   printf("intcolor=%X\n",intcolor);
   x++;
  }
  y++;
 }
}




/*
 this function successfully draws a string of characters from the loaded font
 arguments are: character pointer, character x pos, character y pos
*/
void chaste_font_draw_string(const char *s,int cx,int cy)
{
 int x,y,i,c,cx_start=cx;
 sf::IntRect rect_source,rect_dest;
 i=0;
 while(s[i]!=0)
 {
  c=s[i];
  if(c=='\n'){ cx=cx_start; cy+=main_font.char_height;}
  else
  {
   x=(c-' ')*main_font.char_width;
   y=0*main_font.char_height;

   rect_source.left=x;
   rect_source.top=y;
   rect_source.width=main_font.char_width;
   rect_source.height=main_font.char_height;

   rect_dest=rect_source;
   rect_dest.left=cx;
   rect_dest.top=cy;

   //draw sprite from this section of the texture 
   sf::Sprite sprite(main_font.texture,rect_source);
   sprite.setPosition(cx,cy);
   window.draw(sprite);

   cx+=main_font.char_width;
  }
  i++;
 }
}



void chaste_font_draw_string_scaled(const char *s,int cx,int cy,int scale)
{
 int x,y,i,c,cx_start=cx;
 sf::IntRect rect_source,rect_dest;
 i=0;
 while(s[i]!=0)
 {
  c=s[i];
  if(c=='\n'){ cx=cx_start; cy+=main_font.char_height*scale;}
  else
  {
   x=(c-' ')*main_font.char_width;
   y=0*main_font.char_height;


  rect_source.left=x;
   rect_source.top=y;
   rect_source.width=main_font.char_width;
   rect_source.height=main_font.char_height;

   //draw sprite from this section of the texture 
   sf::Sprite sprite(main_font.texture,rect_source);
   sprite.setPosition(cx,cy);
   sprite.setScale(scale,scale);
   window.draw(sprite);

   cx+=main_font.char_width*scale;
  }
  i++;
 }
}



