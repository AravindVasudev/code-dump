#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main() {
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");

	setfillstyle(7, RED);
	circle(100, 100, 150);
	floodfill(100, 100, WHITE);

	getch();
	closegraph();
}