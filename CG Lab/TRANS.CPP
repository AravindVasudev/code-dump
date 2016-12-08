#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
}

void rotate(int x1, int y1, int x2, int y2, int x3, int y3, int angle) {
	float radian = (angle * 3.14) / 180;
	int rx = x2, ry = y2;

	x1 = rx + (x1 - rx) * cos(radian) - (y1 - ry) * sin(radian);
	y1 = ry + (x1 - rx) * sin(radian) - (y1 - ry) * cos(radian);
	x2 = rx + (x2 - rx) * cos(radian) - (y2 - ry) * sin(radian);
	y2 = ry + (x2 - rx) * sin(radian) - (y2 - ry) * cos(radian);
	x3 = rx + (x3 - rx) * cos(radian) - (y3 - ry) * sin(radian);
	y3 = ry + (x3 - rx) * sin(radian) - (y3 - ry) * cos(radian);
	triangle(x1, y1, x2, y2, x3, y3);
}

void main() {
	int gdriver = DETECT, gmode;
	int x1, y1, x2, y2, x3, y3;
	int angle;
	initgraph(&gdriver, &gmode, "C:\\tc\\bgi");

	printf("\n\t\t\tRotation");
	printf("\n\t\t\t========");

	printf("\n\n\tEnter the coords for the triangle:\t");
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

	triangle(x1, y1, x2, y2, x3, y3);
	getch();

	printf("\n\n\tEnter Rotation angle:\t");
	scanf("%d", angle);

	rotate(x1, y1, x2, y2, x3, y3, angle);

	getch();
	closegraph();
}
