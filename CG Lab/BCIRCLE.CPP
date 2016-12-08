#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<graphics.h>
#include<dos.h>

void cliplot(int xc, int yc, int x, int y) {
	putpixel(xc + x, yc + y, 255);
	putpixel(xc - x, yc + y, 255);
	putpixel(xc + x, yc - y, 255);
	putpixel(xc - x, yc - y, 255);
	putpixel(xc + y, yc + x, 255);
	putpixel(xc - y, yc + x, 255);
	putpixel(xc + y, yc - x, 255);
	putpixel(xc - y, yc - x, 255);
	delay(20);
}

void cir(int x1, int y1, int r) {
	int x = 0;
	int y = r;
	int p = 1 - r;

	cliplot(x1, y1, x, y);
	while(x < y) {
		x++;
		if(p < 0)
			p += 2 * x + 1;
		else {
			y--;
			p += 2 * (x - y) + 1;
		}
		cliplot(x1, y1, x, y);
	}
}

void main() {
	int gdriver = DETECT, gmode;
	int x, y, r;

	clrscr();

	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");

	printf("\n\n\t\t\tBresenham\'s Circle Drawing Algorithm");
	printf("\n\t\t\t===================================");

	printf("\n\n\t\tEnter the Mid Point & Radius:\t");
	scanf("%d%d%d", &x, &y, &r);

	cir(x, y, r);

	getch();
	closegraph();
}