#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //printf("Checkpoint 1\n");
  double m = (y1 - y0) / (1.0 * (x1 - x0)); 
  if ( x1 < x0 ) { //if the user goofs and loads the coordinates incorrectly
    int temp = x1;
    x1 = x0;
    x0 = temp;
    temp = y1;
    y1 = y0;
    y0 = temp;

  }

  if ( m > 0 && m < 1 ) { //first octant
    //printf("Inside if!\n");
    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = x0 - x1;

    // d is delta
    int d = 2*A + B;  

    while (x <= x1) { 
      plot(s, c, x, y);
      if (d > 0) {
	y++;
	d += 2 * B;
      }
      x++;
      d += 2 * A;
    }
    //printf("I am relatively sure octants 1 & 5 are good to go. \n");
  }
  
  else if ( m >= 1 ) { //second octant (no infinity bound needed?)
    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = x0 - x1;
    int d = A + 2*B;
    while ( y <= y1) {
      plot(s, c, x, y);
      if (d < 0) { 
	x++;
	d += 2*A;
      }
      y++;
      d += 2*B;
    }
    //printf("I am relatively sure octants 2 & 6 are good to go. \n");
  }

  else if ( m < 0 && m >= -1) { //eighth octant
    //printf("Test octants 3 & 8. \n");
    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = x0 - x1; 

    // d is delta
    int d = 2 * A - B;  
   
    while (x <= x1) { 
      plot(s, c, x, y);
      if (d < 0) {
	y--;
	d -= 2 * B;
      }
      x++;
      d += 2 * A;
    }
    //printf("I am relatively sure octants 4 & 8 are good to go. \n");
  }

  else if ( m < -1 ) { //seventh octant
    //printf("Test octants 3 & 7. \n");
    int x = x0;
    int y = y0;
    int A = y1 - y0;
    int B = x0 - x1; 

    // d is delta
    int d = A - 2 * B;  
   
    while (y >= y1) { 
      plot(s, c, x, y);
      if (d > 0) {
	x++;
	d += 2 * A;
      }
      y--;
      d -= 2 * B;
    }
    //printf("I am relatively sure octants 3 & 7 are good to go. \n");
  }
  
  else if (y0 == y1) {//horizontal line
    int x = x0;
    int y = y0;
    while ( x < x1 ) {
      plot(s, c, x, y);
      x++; 
    }
  }
}


