#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 2;
  c.green = MAX_COLOR;
  c.blue = 0;
  int m = XRES; int n = 0;
  clear_screen(s);
  /*
    while (m >= 0 && n <= YRES) {
    draw_line( 0, 0, XRES - m, YRES - n, s, c);
    c.blue+=13; c.green-=4; n++; m--;
    c.red += 3;
    if (c.green <= 0) {
    c.green = 255;
    }
    if (c.blue >= 255) {
    c.blue = 0;
    }
    if (c.red >= 255) {
    c.red = 2;
    }
    }
  */
  for (int i = 0; i <= XRES; i += 75){
    for (int j = YRES; j >= 0; j-= 50){
      draw_line(j, YRES + 3*i, XRES - j, YRES - i, s, c);
      c.blue += 2; c.green -= 4; n++; m--;
      c.red += 16;
      if (c.green <= 0) {
	c.green = 255;
      }
      if (c.blue >= 255) {
	c.blue = 0;
      }
      if (c.red >= 255) {
	c.red = 2;
      }
    }
  }

  /*
  //octant 1
  draw_line( 0, 0, XRES-1, YRES - 75, s, c);
  
  //octant 2
  draw_line( 0, 0, XRES - 75, YRES-1, s, c);
  
  //octant 8
  draw_line( 0, YRES-1, XRES-1, 75, s, c);  
  
  //octant 7
  draw_line( 0, YRES-1, XRES - 75, 0, s, c);
  
  c.green = 0;
  c.blue = MAX_COLOR;
  //octant 5
  draw_line( XRES - 1, YRES - 1, 0, 75, s, c);
  
  //octant 6
  draw_line( XRES - 1, YRES -1, 75, 0, s, c);

  //octant 4
  draw_line( XRES - 1, 0, 0, YRES - 75, s, c);

  //octant 3
  draw_line( XRES - 1, 0, 75, YRES - 1, s, c);
  
  c.blue = 0;
  c.red = MAX_COLOR;
  //y = x, y = -x
  draw_line( 0, 0, XRES - 1, YRES - 1, s, c);
  draw_line( 0, YRES - 1, XRES - 1, 0, s, c);

  //horizontal, vertical line
  draw_line( 0, YRES / 2, XRES - 1, YRES / 2, s, c);
  draw_line( XRES / 2, 0, XRES / 2, YRES - 1, s, c);
  */
  printf("displaying 0\n");
  display(s);
  printf("displaying\n");
  save_extension(s, "lines.png");
}  
