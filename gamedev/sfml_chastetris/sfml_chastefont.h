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
 sf::Sprite sprite; /*sprite which will use texture for actual drawing*/
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

 /*now that the font is loaded and we know the dimensions, create a texture from it*/
 new_font.texture.loadFromImage(new_font.image);

 /*then load the texture into a sprite(this is drawable)*/
 new_font.sprite.setTexture(new_font.texture);

 return new_font;
}



