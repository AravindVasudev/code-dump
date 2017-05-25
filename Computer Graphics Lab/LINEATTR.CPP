#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main() {
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");

	setlinestyle(DASHED_LINE, 1, 1);
	setcolor(9);
	line(100, 100, 200, 200);

	getch();
	closegraph();
}