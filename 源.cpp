#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	float width, height, gravity;
	float ball_x, ball_y, ball_vy, radius;
	float rect_left_x, rect_top_y, rect_width, rect_height, rect_vx;

	width = 800;
	height = 600;
	gravity = 0.9;
	initgraph(width, height);

	radius = 20;	//半径
	ball_x = width / 4;
	ball_y = height - radius;
	ball_vy = 0;

	rect_height = 100;
	rect_width = 20;
	rect_left_x = width * 3 / 4;
	rect_top_y = height - rect_height;
	rect_vx = -3;

	while (1)
	{
		if (_kbhit())
		{
			char input = _getch();
			if (input == ' ')
			{
				ball_vy = -16;
			}
		}

		ball_vy = ball_vy + gravity;
		ball_y = ball_y + ball_vy;
		if (ball_y >= height - radius)
		{
			ball_vy = 0;
			ball_y = height - radius;
		}
		else if (ball_y <= radius)
		{
			ball_y = radius;
		}

		rect_left_x = rect_left_x + rect_vx;
		if (rect_left_x <= 0)
		{
			rect_left_x = width;
		}

		cleardevice(); //清空画布
		fillcircle(ball_x, ball_y, radius);
		fillrectangle(rect_left_x, height - rect_height, rect_left_x + rect_width, height);
		Sleep(10);
	}
	closegraph();
	return 0;
}