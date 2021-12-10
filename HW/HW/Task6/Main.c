#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

struct Function
{
    int menu;
    double x;
    long double* result;
    double etalon;
    double eps;
    int count;
    int N;
}func;

long long fact(long long n)
{
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

long double Sin() {
    int i; func.etalon = sin(func.x);
    long double result = 0;
    for (i = 1; i < func.N; i++) {
        result += (pow(-1, i + 1) * pow(func.x, 2 * i - 1)) / (long double)fact(2 * i - 1);
        printf("%lf\n", result);
        printf("%lf\n", fabs(func.etalon - result));
        if (fabs(func.etalon - result) < func.eps)
            break;
    }
    func.count = i;
    return result;
}

long long Cos() {
    int i; func.etalon = cos(func.x);
    long double result = 0;
    for (i = 1; i < func.N; i++) {
        result += (pow(-1, i) * pow(func.x, 2 * i)) / (long double)fact(2 * i);
        printf("%lf\n", result);
        printf("%lf\n", fabs(func.etalon - result));
        if (fabs(func.etalon - result) < func.eps)
            break;
    }
    func.count = i;
    return result;
}

long double Exp() {
    int i; func.etalon = sin(func.x);
    long double result = 0;
    for (i = 1; i < func.N; i++) {
        result += pow(func.x, i) / (long double)fact(i);
        printf("%lf\n", result);
        printf("%lf\n", fabs(func.etalon - result));
        if (fabs(func.etalon - result) < func.eps)
            break;
    }
    func.count = i;
    return result;
}


long double Sh() {
    int i; func.etalon = sin(func.x);
    long double result = 0;
    for (i = 1; i < func.N; i++) {
        result += (1 / ( (long double)fact(2 * i + 1)) * pow(func.x, 2 * i - 1));
        printf("%llf\n", result);
        printf("%llf\n", fabs(func.etalon - result));
        if (fabs(func.etalon - result) < func.eps)
            break;
    }
    func.count = i;
    return result;
}

void menu(int menu, long double* result) {

    switch (menu) 
    {
    case 1:
        *result = Sin();
        break;
    case 2:
        *result = Cos();
        break;
    case 3:
        *result = Exp();
        break;
    case 4:
        *result = Sh();
        break;
    default:
        break;
    }
}

int main()
{
    int mode, NMax, count = 0;
    func.menu, func.x, func.etalon = 0, func.eps = 0.000001;
    long double result = 0;

    do 
    {
        printf("Input: x = ");
        scanf_s("%lf", &func.x);
        printf("Select mode (0 - exit): ");
        scanf_s("%d", &mode);
        if (mode == 0) break;
        printf("Select function:\n1. Sin\n2. Cos\n3. Exp\n4. Sinh\nInput: ");
        scanf_s("%d", &func.menu);

        switch (mode)
        {
        case 1:
            printf("Input N (1...1000): ");
            scanf_s("%d", &func.N);
            menu(func.menu, &func.x, &result, &func.etalon, func.eps, &func.count, func.N);
            printf("etalon - % .10f\nresult - % .10lf\nsummand - % d\n", func.etalon, result, func.count);
            break;
        case 2:
            printf("Enter NMax: ");
            scanf_s("%d", &NMax);

            srand(time(0));

            for (int i = 0; i < NMax; i++) {
                func.N = rand() % 999 + 1;
                menu(func.menu, &func.x, &result, &func.etalon, func.eps, &func.count, func.N);
                printf("etalon - % .10f\tresult - % .10lf\tsummand - % d\n", func.etalon, result, func.count);
            }
            break;
        }
    } while (1);
}