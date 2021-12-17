#include <stdio.h>
#include <locale.h>
#include <malloc.h>

void print()
{
	printf("��� ����� ������ � ��������?\n"
		"1. ����� ������������ �������� ��������� �������\n"
		"2. ����� ������������ ��������� ������� � ��������� ���������\n"
		"3. ����� ������������ ��������� ������� �������� �� ��������\n"
		"4. �������� ������� �������� � ��������� ���������\n"
		"5. �������� ������� ������ � ����� �������� �������\n"
		"6. ������� �������\n"
		"7. ������� ���� ��������\n"
		"0. ������� ���������\n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	int* mass, *dop_mass, n1, n2, menu, size, tmp;
	printf("������� ���-�� ��������� �������: ");
	scanf_s("%d", &size);
	mass = (int*)malloc(size * sizeof(int));
	dop_mass = (int*)malloc(size * sizeof(int));
	printf("������� �������� �������: ");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &mass[i]);
		dop_mass[i] = 0;
	}
	print();
	do
	{
		int proiz = 1;
		printf("����: ");
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			for (int i = 0; i < size; i++)
			{
				if (mass[i] % 2 != 0)
				{
					proiz *= mass[i];
				}
			}
			printf("%d\n", proiz); break;
		case 2:
			for (int i = 0; i < size; i++)
			{
				if (i % 2 != 0)
				{
					proiz *= mass[i];
				}
			}
			printf("%d\n", proiz); break;
		case 3:
			for (int i = 0; i < size; i++)
			{
				if (mass[i] % 2 != 0)
				{
					proiz *= i;
				}
			}
			printf("%d\n", proiz); break;
		case 4:
			printf("������� 2 �������: ");
			scanf_s("%d %d", &n1, &n2);
			tmp = mass[n1];
			mass[n1] = mass[n2];
			mass[n2] = tmp;
			break;
		case 5:
			if (size % 2 == 0)
			{
				for (int i = 0; i < size / 2; i++)
				{
					dop_mass[size / 2 + i] = mass[i];
				}
			}
			else
			{
				dop_mass[size / 2] = mass[size / 2];
				for (int i = 0, j = size - 1; i < size / 2; i++, j--)
				{
					dop_mass[size / 2 + i + 1] = mass[i];
					dop_mass[size - j - 1] = mass[j];
				}
			}break;
		case 7:
			print();
			break;
		case 6:
			printf("������: ");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", mass[i]);
			}
			printf("\n");
			printf("���. ������: ");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", dop_mass[i]);
			}
			printf("\n");
			break;
		default:
			break;
		}
	} while (menu != 0);
}