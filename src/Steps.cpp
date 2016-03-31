/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->121
	->211
	->22
	So total number of ways is 5

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int fact(int num)
{
	int c, facto = 1;
	for (c = 1; c <= num; c++)
		facto = facto * c;
	return facto;
}
int rec(int twos, int ones)
{
	int temp;
	if (twos > 1)
	{
		ones += 2;
		twos--;
		temp = fact(ones + twos) / (fact(ones)*fact(twos));
	}
	else
		return 0;
	return temp + rec(twos, ones);
}
int get_steps(int s)
{
	if (s == 0)
		return 0;
	if (s == 1)
		return 1;
	int count = 1, temp, ones = 0, twos = 0;
	if (s % 2 == 0)
	{
		count++;
		twos = s / 2;
		count += rec(twos, ones);
	}
	else
	{
		twos = (s - 1) / 2;
		ones = 1;
		temp = fact(ones + twos) / (fact(ones)*fact(twos));
		count = count + temp;
		count += rec(twos, ones);
	}
	return count;
}
