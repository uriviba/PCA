
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define N 6000
#define PUNTS 1000

double *memoization;
double *buffer;

int main(int argc, char *argv[])
{
	unsigned int i, r, j, n, index;
	double d/;

	memoization = malloc(sizeof(double) * 2 * PUNTS);
	buffer = malloc(sizeof(double) * 2 * PUNTS);

	// Construct memoization cache
	for (i = 0, d = 0; i < PUNTS; ++i)
	{
		memoization[   i<<1   ] = cos(d);
		memoization[(i<<1) + 1] = sin(d);
		d += 2*M_PI/PUNTS;
	}
	
	if (argc == 1) n = N;
	else n = atoi(argv[1]);

	srand(0);
	for (i = 0; i < n; i++)
	{
		r = rand();
		for (j = 0; j < PUNTS; j++)
		{
			index = j<<1;
			buffer[  index  ] = r * memoization[  index  ]; // x
			buffer[index + 1] = r * memoization[index + 1]; // y
		}
		fwrite(buffer, sizeof(double), 2 * PUNTS, stdout);
	}
	return 0;
}
