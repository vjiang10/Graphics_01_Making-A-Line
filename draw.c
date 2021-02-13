#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    int x = x0; int y = y0;
    int dX = x1-x0; int dY = y1-y0; 
    if (x1 < x0) {x = x1; y = y1; dX*=-1; dY*=-1;}
    int x_res = x+dX; int y_res = y+dY;
    int d, A, B;
    
    // slope = 0 (dY = 0)
    if (dY == 0) for (x=x0;x<x1;x++) plot(s,c,x,y);

    // undefined slope (dX = 0)
    else if (dX == 0) for (y=y0;y<y1;y++) plot(s,c,x,y);
    
    // separate cases
    // octant 1 & 5 (0<m<1)
    else if (dY <= dX && dY > 0) {
        A = dY; B = -1*dX; 
        d = 2*A + B;
        int x_res = x+dX;
        while (x<=x_res) {
            plot(s,c,x,y);
            if (d > 0) {y++; d+=2*B;}
            x++;
            d+=2*A;
        }
    }

    // octant 2 & 6 (1<m<{1/0})
    else if (dY > dX) {
        A = dX; B = -1*dY;
        d = 2*A + B;
        int y_res = y+dY;
        while (y<=y_res) {   
            plot(s,c,x,y);
            if (d > 0) {x++; d+=2*B;}
            y++; 
            d+=2*A;
        }
    }
    
    // octant 3 & 7 ({-1/0}<m<-1)
    else if (-1*dY > dX) {
        A = dX; B = -1*dY;
        d = 2*A - B;
        while (y>=y_res) {   
            plot(s,c,x,y);
            if (d > 0) {x++; d-=2*B;}
            y--; 
            d+=2*A;
        }
    }

    // octant 4 & 8 (-1<m<0) 
    else {
        A = dY; B = -1*dX; 
        d = 2*A - B;
        while (x<=x_res) {
            plot(s,c,x,y);
            if (d < 0) {y--; d-=2*B;}
            x++;
            d+=2*A;
        }
    }
}

// line_curve_1
void line_curve_1(int x0, int y0, int dX, int dY, screen s, color c) {
    int x;
    for (x = 1; x < 20; x++) {
        c.green -= x;
        draw_line(x0+x*(dX/20),y0,x0,y0+dY-x*(dY/20), s, c); 
    }
}


