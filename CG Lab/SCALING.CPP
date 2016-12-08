dd#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void main() {
	int gdriver = DETECT, gmode;
	int x, y, r;
	float sr;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");

	printf("\n\n\t\t\tScaling");
	printf("\n\t\t\t========");

	printf("\n\nEnter Midpoint, Radius and Scaling Factor:\t");
	scanf("%d%d%d%f", &x, &y, &r, &sr);

	circle(x, y, r);
	getch();

	circle(x, y, r * sr);

	getch();
	closegraph();
}