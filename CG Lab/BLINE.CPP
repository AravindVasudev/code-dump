#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>

void main() {
	int gdriver = DETECT, gmode;
	int x, y, x1, x2, y1, y2;
	int dx, dy;
	int p;
	int xend;

	clrscr();

	initgraph(&gdriver, &gmode, "C:\\");

	printf("\n\n\t\t\tBresenham\'s Line Drawing Algorithm");
	printf("\n\t\t\t===================================");

	printf("\n\n\t\tEnter the Coordinates:\t");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	dx = abs(x1 - x2);
	dy = abs(y1 - y2);
	p  = 2 * (dy - dx);

	if(x1 > x2) {
		x    = x2;
		y    = y2;
		xend = x1;
	}
	else {
		x    = x1;
		y    = y1;
		xend = x2;
	}

	putpixel(x, y, 255);
	while(x < xend) {
		x++;
		if(p < 0) {
			p += (2 * dy);
			putpixel(x, y, 255);
		}
		else {
			y++;
			p += (2 * (dy - dx));
			putpixel(x, y, 255);
		}
	}

	getch();
	closegraph();
}