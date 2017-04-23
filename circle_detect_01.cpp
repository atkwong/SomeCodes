//============================================================================
// Name        : circle_detect.cpp
// Author      : atkwong
// Version     : 1 (23/4/2017)
//
// 				***	for dim{20 * 10} image
//				***	for testing
//============================================================================

#include <iostream>
using namespace std;

struct circle
{
	int x;
	int y;
	int distance;
};

circle circle_detection(int image[20][10], int length, int width)
{
//	bool found = false;
	circle sphere;
	sphere.distance = 0;
	sphere.x = 0;
	sphere.y = 0;
	int count = 0;
	int x_temp = 0;
	int y_temp = 0;
//	int x_match = 0;
	int y_match = 0;

//	if (found != false){
	for (int y = 0; y < width; y++)
		for (int x = 0; x < length; x++)
		{
			if (image[x][y] == 1)					// find dark pixel from 2d image
			{
				if (count == 0)
				{	x_temp = x;
					y_temp = y;}
				count++;
			}
			else									// a circle must able to form a square inside
			{
				if ( count > 2)						// ignore a dot
				{
					for (int j = y_temp; j < width ; j++)
					{
							if (image[x_temp][j] == 1)
							{	y_match++;	}
							else break;
					}
					if (y_match == count)// && (image[x_temp +count -1][y_temp +count -1] == 1))				// if x = y, it is a square/circle
					{
						sphere.x = x_temp;			// start pt. of x
						sphere.y = y_temp;			// start pt. of y
						sphere.distance = count;
				//		found = true;
						break;
					}
				}
				count = 0;
				y_match = 0;
			}
	}
	return sphere;
}



int main()
{
	circle test;

	int map[20][10];
	for (int j = 0; j<10; j++)
	{
		for (int i = 0; i < 20; i++)
		{	map[i][j] = 0;	}
	}

// Test set 1
/*
	for (int count = 0; count < 4; count++)
	{
		map[5+count][5] = 1;
		map[5][5+count] = 1;
	}
*/
//	map[9][5] = 1;							// not a square
//	map[5][9] = 1;							// not a square

// Test set 2

	for (int count = 0; count < 4; count++)
	{
		map[3+count][3] = 1;
//		map[3][3+count] = 1;
	}
/*	map[3][4] = 1;							// not a square
	map[4][4] = 1;							// not a square
	map[5][4] = 1;
	map[6][4] = 1;
*/
	map[3][6] = 1;


	for (int count = 0; count < 4; count++)
	{
		map[10+count][5] = 1;
		map[10][5+count] = 1;
	}


	test = circle_detection(map, 20, 10);
	cout << "the value is " << test.distance << endl;
	cout << "the value is " << test.x << endl;
	cout << "the value is " << test.y << endl;

	return 0;
}

