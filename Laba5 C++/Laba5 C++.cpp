#include "pch.h"
#include <stdio.h>
#include <string.h>
#define MAX_DATES 10
#pragma warning(disable : 4996)

struct str
{
	int date;
	int month;
	int year;
} dat[MAX_DATES];

int main()
{
	FILE *read;
	int n, i, min_year;

	//read from file to struct
	i = 0;
	read = fopen("years.txt", "rt");
	while (!feof(read))
	{
		fscanf(read, "%d.%d.%d", &dat[i].date, &dat[i].month, &dat[i].year);
		i++;
	}
	fclose(read);
	n = i++;  //years count
	// end of read

	min_year = dat[0].year;
	for (i = 1; i < n; i++)
	{
		if (dat[i].year < min_year)
			min_year = dat[i].year;
	}

	printf("Min year = %d", min_year);

	return 0;
}