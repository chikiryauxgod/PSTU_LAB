#include <stdio.h>
#include <windows.h>
#include <math.h>
#include<stdlib.h>

#define _weights 3
double w[_weights];

double activate(double a)
{
	return (a <= 0) ? 0 : 1;
}

double rightProp(double inputs[3])
{
	double res = 0;
	for (int i = 0; i < 3; i++)
	{
		res += w[i] * inputs[i];
	}

	return res;
}

void train(int data[4][3], int exp [4])
{
	const double lr = 0.1, epoch = 50;
	double error;
	for (int i = 0; i < epoch; i++)
	{
		for (int d = 0; d < 4; d++)
		{
			error = exp[d] - activate(rightProp((double*)data[d]));
			for (int n = 0; n < _weights; n++)
			{
				w[n] += lr * error * data[d][n];
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int trainingdata[4][3] = { {0, 0, 1 }, {0, 1, 1 }, {1, 0, 1}, {0, 1, 0} }, expresults[4] = { 0, 0, 1 };
	srand(1);
	for (int i = 0; i < 3; i++)
	{
		w[i] = fmod(rand() % 100000000 * 0.1, 1.05);
	}
	train(trainingdata, expresults);
	for (int i = 0; i < 3; i++)
	{
		w[i] = (w[i] > 0) ? w[i] : 0;
	}

	double new[3] = { 1, 1, 0 };
	printf("%.lf", activate(rightProp(new)));

	return 0;
}

