#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main() {
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");

	setfillstyle(7, RED);
	ellipse(100, 100, 0, 360, 150, 75);
	floodfill(100, 100, WHITE);

	getch();
	closegraph();
}
