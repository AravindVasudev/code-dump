#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>

void main() {
	int gdriver = DETECT;
	int gmode;
	int xa, xb, ya, yb;
	int xinc, yinc;
	int dx, dy;
	int slope;
	int i;
	int steps;

	clrscr();

	initgraph(&gdriver, &gmode, "C:\\");

	printf("\n\n\t\t\tDDA Line Algorithm");
	printf("\n\t\t\t===================");
	printf("\n\n\t\tEnter the Coordinates:\t");
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

	dx    = abs(xb - xa);
	dy    = abs(yb - ya);
	xinc  = xa;
	yinc  = ya;
	slope = dy / dx;

	steps = (dx > dy) ? dx : dy;
	for(i = 0; i < steps; i++) {
		if(dx < dy && xa < xb) {
			xinc += 1;
			yinc += slope;
			putpixel(xinc, yinc, WHITE);
			delay(50);
		}
		else if(dx < dy && xa > xb) {
			xinc -= 1;
			yinc -= slope;
			putpixel(xinc, yinc, WHITE);
			delay(50);
		}
		else {
			xinc += (1 / slope);
			yinc += 1;
			putpixel(xinc, yinc, WHITE);
			delay(50);
		}
	}
	getch();
	closegraph();
}