// IntDivWays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int intDivide(int, int);
void printResult(int*, int);

int main()
{
	const int sum = 5;
	const int num = 6;
	bool bInc=false;
	int p[num];
	int numNow = 0, rest = sum, total = 0;
	
	while (numNow >= 0)
	{
		if (bInc)
		{
			p[numNow]++;
			rest--;
			bInc = false;
		}
		else
		{
			p[numNow] = intDivide(rest, num - numNow);
			rest -= p[numNow];
		}
		
		if (numNow != 0 && p[numNow] > p[numNow - 1])
		{
			rest += p[numNow];
			numNow--;
			bInc = true;
			continue;
		}
		if (rest+numNow<num-1)
		{
			rest += p[numNow];
			numNow--;
			bInc = true;
			continue;
		}
		if (rest> 0)
		{
			numNow++;
			continue;
		}
		if (rest == 0 && numNow == num - 1)
		{
			total++;
			//printResult(p, num);
			rest = p[numNow];
			numNow--;
			bInc = true;
			continue;
		}
		if (rest <= 0 )
		{
			rest += p[numNow];
			numNow--;
			bInc = true;
			continue;
		}
	}
	cout << total << endl;
    return 0;
}

int intDivide(int D, int d)
{
	if (D%d==0)
		return D / d;
	else
		return int(D / d) + 1;
}

void printResult(int *a, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << '\t';
	}
	cout << endl;
}