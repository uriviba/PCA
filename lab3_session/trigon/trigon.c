
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define N 6000
#define PUNTS 1000

double **memoization;

int main(int argc, char *argv[])
{
	unsigned int i, r, j, n;
	double d, x, y;

	memoization = malloc(sizeof(double) * 2 * PUNTS);

	// Construct memoization cache
	for (i = 0, d = 0; i < PUNTS; ++i)
	{
		memoization[i][0] = sin(d);
		memoization[i][1] = cos(d);
		d += 2*M_PI/PUNTS;
	}
	

	if (argc == 1) n = N; else n = atoi(argv[1]);

	srand(0);
	for (i=0; i<n; i++)
	{
		r = rand();
		for (j=0, d=0; j<PUNTS; j++)
		{
			/*x = r*cos(d); y = r*sin(d);
			fwrite(&x, sizeof(x), 1, stdout);
			fwrite(&y, sizeof(y), 1, stdout);
			d += 2*M_PI/PUNTS;*/
			x = r * memoization[j][1];
			y = r * memoization[j][0];
			fwrite(&x, sizeof(x), 1, stdout);
			fwrite(&y, sizeof(y), 1, stdout);
		}
	}
	return 0;
}
