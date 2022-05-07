#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
 
    circle(50, 50, 30);
 
    delay(500000);
    closegraph();
    return 0;
}