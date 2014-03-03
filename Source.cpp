
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "float.h"
#define n 3



struct coordinate
{
	float x;
	float y;
	float z;
};

int sortByZ(coordinate* coord);
int findDist(coordinate coord[]);

int main()
{
	coordinate table[n];

	printf("Enter coordinates for %d points.\nYou should enter three digits for X, Y and Z of each point. \n", n);
	for (int i = 0; i < n; i++)
	{
		printf("-Point %d-\n", i + 1);
		scanf_s("%f%f%f", &table[i].x, &table[i].y, &table[i].z);
	}

	sortByZ(table);

	printf("\nPoints were sorted by accession of Z. \n       X        Y        Z\n");
	for (int i = 0; i < n; i++)
	{
		printf("P%d    %5.2f    %5.2f    %5.2f \n", i, table[i].x, table[i].y, table[i].z);

	}
	printf("\n");

	findDist(table);

	system("pause");
	return 0;
}


/* Takes a pointer to a first element of "coordinate" type array and sorts the array
	by accession of Z coordinate. */
int sortByZ(coordinate* coord)
{
	coordinate temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		if ((coord + j)->z >(coord + j + 1)->z)
		{

			temp = *(coord + j);
			*(coord + j) = *(coord + j + 1);
			*(coord + j + 1) = temp;
		}
	}
	return 0;
};


/* Takes a pointer to a first element of "coordinates" type array and prints out two points
	with gratest distance between them. */
int findDist(coordinate coord[])
{
	float leastDist = FLT_MAX;
	float dist, x, y, z;
	int point1 = 0, point2 = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			x = coord[i].x - coord[j].x;
			y = coord[i].y - coord[j].y;
			z = coord[i].z - coord[j].z;
			dist = sqrt(x*x + y*y + z*z);

			if ((dist < leastDist) && (i != j))
			{
				leastDist = dist;
				point1 = i;
				point2 = j;
			}
		}
	}

	printf("The least distance is %5.2f between P%d and P%d.\n\n", leastDist, point1, point2);
	return 0;
}