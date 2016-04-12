/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
int path_wrapper(int *maze, int rows, int columns, int a, int b, int c, int d, int prev1, int prev2)
{
	int side[2] = { 0 };
	int top[2] = { 0 };
	int ans1, ans2;
	if ((a == c && (b + 1 == d || b - 1 == d)) || (b == d && (a + 1 == c || a - 1 == c)))
		return 1;
	if (b - 1 > 0 && *((maze + a*columns) + (b - 1)) == 1 && !(a == prev1&&b - 1 == prev2))
		side[0] = 1;
	if (b + 1 < columns&&*((maze + a*columns) + (b + 1)) == 1 && !(a == prev1&&b + 1 == prev2))
		side[1] = 1;
	if (a - 1 > 0 && *((maze + (a - 1) * columns) + b) == 1 && !(a - 1 == prev1&&b == prev2))
		top[0] = 1;
	if (a + 1 < rows && *((maze + (a + 1) * columns) + b) == 1 && !(a + 1 == prev1&&b == prev2))
		top[1] = 1;
	if (top[0] == 1 && top[1] == 1)
	{
		if (c - a - 1 < c - a + 1)
			ans1 = a - 1;
		else
			ans1 = a + 2;
		ans2 = b;
	}
	else if (top[0] == 1)
	{
		ans1 = a - 1; ans2 = b;
	}
	else if (top[1] == 1)
	{
		ans1 = a + 1; ans2 = b;
	}
	else if (side[0] == 1 && side[1] == 1)
	{
		if (d - b - 1 < d - b + 1)
			ans2 = b - 1;
		else
			ans2 = b + 1;
		ans1 = a;
	}
	else if (side[0] == 1)
	{
		ans1 = a; ans2 = b - 1;
	}
	else if (side[1] == 1)
	{
		ans1 = a; ans2 = b + 1;
	}
	else
		return 0;
	return path_wrapper(maze, rows, columns, ans1, ans2, c, d, a, b);
}


int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows<0 || columns<0 || x1<0 || y1<0 || x2<0 || y2<0 || x1 >= rows || x2 >= rows || y1 >= columns || y2 >= columns)
		return 0;
	if (*((maze + x2*columns) + y2) == 0)
		return 0;
	return path_wrapper(maze, rows, columns, x1, y1, x2, y2, -1, -1);
}