#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
	srand(time(NULL));
	int n, r, k = 0, i;// Длина массива, диапазон, кол-во
	scanf_s("%d %d %d", &n, &r, &i);
	int* mass = (int*)malloc(n * sizeof(int));
	while (n > 0)
	{
		int m = (rand() % r * 2 + 1) - r;
		printf("%d\t", m);
		mass[k] = m;
		n--; k++;
	}
	for (; i > 0; i--)
	{
		int save = mass[k - 1];
		for (int j = k - 1; j > 0; --j)
		{
			mass[j] = mass[j - 1];
		}
		mass[0] = save;
	}	
	printf("\n");
	while (n < k)
	{
		printf("%d\t", mass[n]);
		n++;
	}
}