#define SIZE 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int n, flag = 0 , number[SIZE], number2[SIZE], pop = 0, chislo1 = 0; //Длина числа, флажок, два массива разбитых чисел на цифры ИИ и User, попытки и рандомное число
	printf("Какой длины будем отгадывать число (от 2 до 5): ");
	scanf_s("%d", &n);
	while (1)
	{
		if (n <= 5 && n >= 2)
		{
			int k = 0, s = 0; // Количество совпадений
			while (k < n && flag != 1)
			{
				number[k] = rand() % 10; // Создание псевдорандомного числа с занесением цифр в массив
				if (number[0] != 0) // ПРОВЕРКА НА ПЕРВЫЙ 0
				{
					k++;
					for (int kk = k - 1; kk >= 0; kk--)
					{
						if (!(number[kk - 1] != number[k - 1])) //Проверка числа на разные цифры
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
					//printf("%d", number[k]); // Получившееся рандомное число
					chislo1 *= 10;
					chislo1 += number[k];
				}
				int num;
				printf("\nПробуем угадывать!\nВведите ваше число: ");
				scanf_s("%d", &num);
				int ost, knum = 0;
				while (num > 0) // Разбиение введенного числа на цифры
				{
					ost = num % 10;
					num /= 10;
					knum++;
					number2[knum] = ost; //Занесение цифр в массив
				}
				if (knum == n)
				{
					int i = n, ss = 0;
					while (i > 0)
					{
						int j = n;
						for (; j > 0; j--)
						{
							if (!(number2[i] != number2[j])) // Проверка введенного числа на разные цифры
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
							chislo2 += number2[ss];// Создание введенного числа
							ss--;
						}
						if (chislo1 != chislo2) // Сама игра. Проверяем, чтобы два числа были одинаковы
						{
							int korov = 0, bik = 0, i = n;
							while (i > 0)
							{
								int j = n;
								for (; j > 0; j--)
								{
									if (number[i - 1] == number2[j] && i == j)
									{
										printf("Цифра %d - угадана на верной позиции\n", number[i-1]);
										bik++;
									}
									else if (number[i - 1] == number2[j] && i != j)
									{
										printf("Цифра %d - угадана на неверной позиции\n", number[i - 1]);
										korov++;
									}
								}
								i--;
							}
							printf("Вы угадали %d - 'Коров'\n", korov);
							printf("Вы угадали %d - 'Быков'\n", bik);
							//printf("%d %d\n", chislo1, chislo2); //Здесь можно вывести загаданное число и число пользователя, для проверки
							pop++;
						}
						else
						{
						printf("Поздравляем, вы отгадали число: %d\n", chislo1);
						printf("Ваше количество попыток: %d\n", pop);
						break;
						}
					}
					else
					{
						printf("Введите число без повторяющихся цифр!\n");
						continue;
					}
				}
				else
				{
					printf("Введите %d - значное число!\n", n);
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
			printf("Недействительная длинa, повторите попытку!\n");
			printf("Какой длины будем отгадывать число (от 2 до 5): ");
			scanf_s("%d", &n);
		}
	}
}