#define SIZE 10
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <math.h>
void spmenu()
{
	printf("\nВыберите операцию из списка (цифру)\
		\n1. Сканировать товар \
		\n2. Посмотреть инофрмацию о последнем товаре \
		\n3. Добавить товар в чек \
		\n4. Сформировать чек \
		\n5. Рассчитать итоговую стоимость чека \
		\n0. Вывести меню повторно\n");
}

int main()
{
	setlocale(LC_ALL, "");
	char product[SIZE][50] = 
		{ {"Профнастил C20R (м2)"}, {"Планка торцевая 100x80 RAL (3м)"}, 
		{"Саморез кровельный 8x35 мм (шт)"}, {"Гвозди строительные 3,5x90 (1,0 кг)"}, 
		{"Саморез по ГКЛ(дерево) 3,8x51 (1,0 кг)"}, {"Доска 150x25 (3м)"}, 
		{"Доска 25x100 (3и)"}, {"Планка примыкания 90x140 (3м)"}, 
		{"Лампа светодиодная (шт)"}, {"Подвесная люстра SAFARI (шт)"} };
	int barcode[SIZE] = { 5041, 3467, 1334, 1500, 4169, 7241, 6478, 4358, 1962, 2343 };
	int price[SIZE] = { 327, 210, 4, 100, 200, 85, 60, 160, 120, 4500 };
	int discount[SIZE] = { 5, 10, 1, 8, 20, 2, 1, 15, 5, 25 };
	int storage[100] = { 0 };

	printf("Магазин строительных материалов приветствует вас!\n");
	spmenu();
	int menu, code, new = 0, save_code,i = 0;
	do
	{
		printf("\nВыберите цифру: ");
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("Введите штрих-код: ");
			scanf_s("%d", &code);
			for (int i = 0; i < SIZE; i++)
			{
				if (code == barcode[i])
				{
					printf("Сканирование успешно!");
					save_code = code;
					break;
				}
				else if (i + 1 == SIZE)
				{
					printf("Товар не найден!");
				}
			}break;
		case 2:
			i = 0;
			printf("\nОтсканированный товар: \n");
			printf("Штрихкод |\t\tНазвание\t\t    | Цена за шт. | Скидка\n");
			while (save_code != barcode[i])
			{
				i++;
			}
			printf("# %d\t | %40s | %10dр | %5d%%", barcode[i], product[i], price[i], discount[i]);
			break;
		case 3:
			printf("Товар добавлен!");
			storage[new] = save_code;
			new++; break;
		case 4:
			printf("\nВаши товары: \n");
			float sum = 0;
			for (int i = 0; i < SIZE; i++)
			{
				int k = 0;
				for (int j = 0; j < new; j++)
				{
					if (barcode[i] == storage[j])
					{
						k++;
					}
				}
				if (k > 0)
				{
					float sumproduct = (float)price[i] * k;
					float resproduct = abs(((float)discount[i] / 100 - 1) * sumproduct);
					sum += resproduct;
					printf("%s\t  %d x %dр\n", product[i], k, price[i]);
					printf("Стоимость ............... %.2fр\n", sumproduct);
					printf("Стоимость (с учетом скидок) ............... %.2fр\n\n", resproduct);
				}
			}
			printf("Итоговая стоимость .......... %.2f", sum);
			break;
		case 5:
			printf("\nВаш чек: \n\n");
			sum = 0;
			float sumdiscount = 0;
			for (int i = 0; i < SIZE; i++)
			{
				int k = 0;
				for (int j = 0; j < new; j++)
				{
					if (barcode[i] == storage[j])
					{
						k++;
					}
				}
				if (k > 0)
				{
					float sumproduct = (float)price[i] * k;
					float resproduct = abs(((float)discount[i] / 100 - 1) * sumproduct);
					sum += sumproduct;
					sumdiscount += sumproduct - resproduct;
					printf("%s\n", product[i]);
					printf("Стоимость ............... %.2fр\n", sumproduct);
					printf("Сумма скидки ............... -%.2fр\n", sumproduct - resproduct);
					printf("Итог ............... %.2fр\n", sumproduct - (sumproduct - resproduct));
				}
			}
			printf("\n<<=========================>>\n");
			printf("\nВсего .................... %.2fр\n", sum);
			printf("Суммарная скидка .................... -%.2fр\n", sumdiscount);
			printf("Итого .................... %.2fр\n", sum - sumdiscount);
			break;
		case 0:
			spmenu();
			break;
		}
	} while (menu != 5);
}