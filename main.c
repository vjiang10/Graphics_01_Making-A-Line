#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = 255;
  c.blue = 0;

  clear_screen(s);
  //octants 1 and 5
  draw_line(0, 0, XRES-1, YRES-1, s, c); // check
  draw_line(0, 0, XRES-1, YRES / 2, s, c); // check 
  draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c); // check

  //octants 8 and 4
  c.blue = 255;
  draw_line(0, YRES-1, XRES-1, 0, s, c);
  draw_line(0, YRES-1, XRES-1, YRES/2, s, c);
  draw_line(XRES-1, 0, 0, YRES/2, s, c);

  //octants 2 and 6
  c.red = 255;
  c.green = 0;
  c.blue = 0;
  draw_line(0, 0, XRES/2, YRES-1, s, c);
  draw_line(XRES-1, YRES-1, XRES/2, 0, s, c);

  //octants 7 and 3
  c.blue = 255;
  draw_line(0, YRES-1, XRES/2, 0, s, c);
  draw_line(XRES-1, 0, XRES/2, YRES-1, s, c);

  //horizontal and vertical
  c.blue = 0;
  c.green = 255;
  draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
  draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);

  display(s);
  save_extension(s, "lines.png");

  // line curve 1
  screen s1;
  clear_screen(s1);
  color c1;
  c1.blue = 250;
  c1.red = 0;
  c1.green = 0;
  // curve part 1
  line_curve_1(0,0,500,500,s1,c1);
  // curve part 2
  line_curve_1(0,500,500,-500,s1,c1);
  // curve part 3
  line_curve_1(500,500,-500,-500,s1,c1);
  // curve part 4
  line_curve_1(500,0,-500,500,s1,c1);
  // inner curves
  // change color a bit (orange, purple, or red)
  line_curve_1(250,250,-220,-220,s1,c1);
  line_curve_1(250,250,220,-220,s1,c1);
  line_curve_1(250,250,-220,220,s1,c1);
  line_curve_1(250,250,220,220,s1,c1);

  save_extension(s1, "line_curve_1.png");

  // line curve 2
  screen s2;
  clear_screen(s2);
  color c2;
  c2.blue = 255;
  c2.red = 100;
  c2.green = 0;
  // corner 1 (upper-left)
  line_curve_2(0,500,s2,c2);
  // corner 2 (upper-right)
  line_curve_2(500,500,s2,c2);
  // corner 3 (lower-right)
  line_curve_2(500,0,s2,c2);
  // corner 4 (lower-left)
  line_curve_2(0,0,s2,c2);

  save_extension(s2, "line_curve_2.png");
}
