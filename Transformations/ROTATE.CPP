#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int ans[4][2];
int index = 0;

void drawLine(int x1, int y1, int x2, int y2)
{
	int X_MAX = getmaxx()/2;
	int Y_MAX = getmaxy()/2;
	line( X_MAX+x1, Y_MAX-y1, X_MAX+x2, Y_MAX-y2);
}

int round(double x)
{	double value = (x<0.0? -1*x : x);
	value = (int)((value-((int)value))>0.5? value+1 : value );
	return (x<0? -1*value : value);
}

void rotate(int x, int y, float theta)
{  	theta = theta*3.14/180;
	double R[3][3] ={	cos(theta),	-sin(theta), 	0,
				sin(theta),	cos(theta), 	0,
				0,	   	0,		1
			};
	int X[3] = 	{	x,
				y,
				1
			};
	int Xt[3];
	for(int row = 0; row <2; row++)
	{	double value = 0;
		for(int element = 0; element<3; element++)
			value += R[row][element]*X[element];
		Xt[row] = round(value);
	}
	ans[index][0] = Xt[0];
	ans[index][1] = Xt[1];
	index++;
}

void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "e:\\bgi");

	int input_values[4][2];
	float theta;
	printf("\n Enter the 4 coordinates : \n");
	for(int i=0; i<4; i++)
	{	scanf("%d %d",&input_values[i][0],&input_values[i][1]);
	}
	printf("\n Enter Theta : ");
	scanf("%f",&theta);
	for(i=0; i<4; i++)
		rotate(input_values[i][0], input_values[i][1], theta);

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
