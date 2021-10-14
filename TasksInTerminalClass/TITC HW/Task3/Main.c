#include <stdio.h>
#include <locale.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "rus");
	int n, k = 0, mass[] = { 1,2,3,4,5,6,7,8 }; // ���������� ��������, ������� � ������
	float len = sizeof(mass) / sizeof(int); // ����� �������
	int r;
	printf("����� ������ ����� �������� � ��������?\n1. ��� ���. �������\n2. � ���.��������\n������� �����: ");
	scanf_s("%d", &r);

	if (r == 1)
	{
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
		printf("\n// ��� ��������������� �������\n");
		for (int i = 0; i != len; i++) // ����� �������
		{
			printf("%d ", mass[i]);
		}
	}
	// � �������������� ��������
	else if (r == 2)
	{
		int* dop_mass = (int*)malloc((int)len * sizeof(int)); // ��� ������
		k = 0;
		int sr = len / 2;
		if ((int)len % 2 != 0)
		{

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
}