#define SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int n, flag = 0 , number[SIZE], number2[SIZE], pop = 0, chislo1 = 0; //����� �����, ������, ��� ������� �������� ����� �� ����� �� � User, ������� � ��������� �����
	printf("����� ����� ����� ���������� ����� (�� 2 �� 5): ");
	scanf_s("%d", &n);
	while (1)
	{
		if (n <= 5 && n >= 2)
		{
			int k = 0, s = 0; // ���������� ����������
			while (k < n && flag != 1)
			{
				number[k] = rand() % 10; // �������� ���������������� ����� � ���������� ���� � ������
				if (number[0] != 0) // �������� �� ������ 0
				{
					k++;
					for (int kk = k - 1; kk >= 0; kk--)
					{
						if (!(number[kk - 1] != number[k - 1])) //�������� ����� �� ������ �����
						{
							s++;
						}
					}
				}
			}
			if (s == 0)
			{
				flag = 1;
				while (k > 0) 
				{
					k--;
					//printf("%d", number[k]); // ������������ ��������� �����
					chislo1 *= 10;
					chislo1 += number[k];
				}
				int num;
				printf("\n������� ���������!\n������� ���� �����: ");
				scanf_s("%d", &num);
				int ost, knum = 0;
				while (num > 0) // ��������� ���������� ����� �� �����
				{
					ost = num % 10;
					num /= 10;
					knum++;
					number2[knum] = ost; //��������� ���� � ������
				}
				if (knum == n)
				{
					int i = n, ss = 0;
					while (i > 0)
					{
						int j = n;
						for (; j > 0; j--)
						{
							if (!(number2[i] != number2[j])) // �������� ���������� ����� �� ������ �����
							{
								ss++;
							}
						}
						i--;
					}
					if (ss - n == 0)
					{
						int chislo2 = 0;
						while (ss > 0)
						{
							chislo2 *= 10;
							chislo2 += number2[ss];// �������� ���������� �����
							ss--;
						}
						if (chislo1 != chislo2) // ���� ����. ���������, ����� ��� ����� ���� ���������
						{
							int korov = 0, bik = 0, i = n;
							while (i > 0)
							{
								int j = n;
								for (; j > 0; j--)
								{
									if (number[i - 1] == number2[j] && i == j)
									{
										printf("����� %d - ������� �� ������ �������\n", number[i-1]);
										bik++;
									}
									else if (number[i - 1] == number2[j] && i != j)
									{
										printf("����� %d - ������� �� �������� �������\n", number[i - 1]);
										korov++;
									}
								}
								i--;
							}
							printf("�� ������� %d - '�����'\n", korov);
							printf("�� ������� %d - '�����'\n", bik);
							//printf("%d %d\n", chislo1, chislo2); //����� ����� ������� ���������� ����� � ����� ������������, ��� ��������
							pop++;
						}
						else
						{
						printf("�����������, �� �������� �����: %d\n", chislo1);
						printf("���� ���������� �������: %d\n", pop);
						break;
						}
					}
					else
					{
						printf("������� ����� ��� ������������� ����!\n");
						continue;
					}
				}
				else
				{
					printf("������� %d - ������� �����!\n", n);
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		else
		{
			printf("���������������� ����a, ��������� �������!\n");
			printf("����� ����� ����� ���������� ����� (�� 2 �� 5): ");
			scanf_s("%d", &n);
		}
	}
}