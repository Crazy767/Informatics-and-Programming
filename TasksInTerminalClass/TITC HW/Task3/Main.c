#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k = 0, mass[] = { 5,6,7,8,1,2,3,4 }; // ���������� ��������, ������� � ������
	float len = sizeof(mass) / sizeof(int); // ����� �������
	// ��� ��������������� �������

	if ((int)len % 2 != 0)
	{
		int sr = len / 2 + 1; // ������� �������
		while (len != sr + k)
		{
			n = mass[k];
			mass[k] = mass[(int)sr + k];
			mass[(int)sr + k] = n;
			k++;
		}
	}
	else
	{
		int sr = len / 2; // ������� �������
		while (sr + k != len)
		{
			n = mass[k];
			mass[k] = mass[sr + k];
			mass[sr + k] = n;
			k++;
		}
	}
	printf("// ��� ��������������� �������\n");
	for (int i = 0; i != len; i++) // ����� �������
	{
		printf("%d ", mass[i]);
	}

	// � �������������� ��������

	int* dop_mass = (int*)malloc((int)len * sizeof(int)); // ��� ������
	k = 0;
	free(dop_mass);

	if ((int)len % 2 != 0)
	{
		int sr = len / 2;
		while (sr + k != len)
		{
			dop_mass[k] = mass[sr + k + 1];
			dop_mass[(int)len - k] = mass[sr - k];
			k++;
		}
		dop_mass[sr] = mass[sr];
	}
	else
	{
		int sr = len / 2;
		while (sr + k - 1 != len)
		{
			dop_mass[k] = mass[sr + k];
			dop_mass[(int)len - k] = mass[sr - k];
			k++;
		}
	}
	printf("\n// � �������������� ��������\n");
	for (int i = 0; i != len; i++) // ����� �������
	{
		printf("%d ", dop_mass[i]);
	}
}