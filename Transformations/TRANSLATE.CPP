#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int ans[4][2];
int index = 0;

void drawLine(int x1, int y1, int x2, int y2)
{
	int X_MAX = getmaxx()/2;
	int Y_MAX = getmaxy()/2;
	line( X_MAX+x1, Y_MAX-y1, X_MAX+x2, Y_MAX-y2);
}

void translate(int x, int y, int Tx, int Ty)
{
	int T[3][3] = 	{	1, 0, Tx,
				0, 1, Ty,
				0, 0, 1
			};
	int X[3] = 	{	x,
				y,
				1
			};
	int Xt[3];
	for(int row = 0; row <2; row++)
	{	Xt[row] = 0;
		for(int element = 0; element<3; element++)
			Xt[row] += T[row][element]*X[element];
	}
	ans[index][0] = Xt[0];
	ans[index][1] = Xt[1];
	index++;
}

void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "e:\\bgi");

	int input_values[4][2], Tx, Ty;
	printf("\n Enter the 4 coordinates : \n");
	for(int i=0; i<4; i++)
	{	scanf("%d %d",&input_values[i][0],&input_values[i][1]);
	}
	printf("\n Enter Tx and Ty : ");
	scanf("%d %d",&Tx,&Ty);
	for(i=0; i<4; i++)
		translate(input_values[i][0], input_values[i][1], Tx, Ty);

	line(getmaxx()/2,0, getmaxx()/2,getmaxy());
	line(0,getmaxy()/2, getmaxx(),getmaxy()/2);

	setcolor(LIGHTGRAY);
	for(i=0; i<4; i++)
	{	drawLine(input_values[i][0],input_values[i][1],
		input_values[(i+1)%4][0],input_values[(i+1)%4][1]);
	}

	setcolor(WHITE);
	for(i=0; i<4; i++)
	{	drawLine(ans[i][0],ans[i][1],ans[(i+1)%4][0],ans[(i+1)%4][1]);
	}
	getch();
	closegraph();
}
