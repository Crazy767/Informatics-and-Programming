#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include "func.h"

int main()
{
    int menu, mode, NMax, count = 0;
    func.x, func.etalon = 0, func.eps = 0.000001;
    long double result = 0;
    
    do 
    {
        printf("Input: x = ");
        scanf_s("%lf", &func.x);
        printf("Select mode (0 - exit): ");
        scanf_s("%d", &mode);
        if (mode == 0) break;
        printf("Select function:\n1. Sin\n2. Cos\n3. Exp\n4. Sinh\nInput: ");
        scanf_s("%d", &menu);

        switch (mode)
        {
        case 1:
            printf("Input N (1...1000): ");
            scanf_s("%d", &func.N);
            Menu(menu, &result);
            printf("\netalon - % .7f\nresult - % .7lf\nsumm - % d\ndifference - %.10lf\n\n", func.etalon, result, func.count, fabs(func.etalon-result));
            break;
        case 2:
            printf("Enter NMax: ");
            scanf_s("%d", &NMax);

            srand(time(NULL));

            for (int i = 1; i < NMax+1; i++) {
                func.N = i;
                Menu(menu,&result);
                printf("\netalon - % .7f\nresult - % .7lf\nsumm - % d\ndifference - %.10lf\n\n", func.etalon, result, func.count, fabs(func.etalon - result));
            }
            break;
        }
    } while (1);
}