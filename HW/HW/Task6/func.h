#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>

struct Function
{
    double x;
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
        if (fabs(func.etalon - result) < func.eps)
            break;
    }
    func.count = i;
    return result;
}

long double Cos() {
    int i; func.etalon = cos(func.x);
    long double result = 0;
    for (i = 1; i < func.N; i++) {
        result += (pow(-1, i) * pow(func.x, 2 * i)) / (long double)fact(2 * i);
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
        result += (1 / ((long double)fact(2 * i + 1)) * pow(func.x, 2 * i - 1));
        if (fabs(func.etalon - result) < func.eps)
            break;
    }
    func.count = i;
    return result;
}
void Menu(int menu, long double* result) {

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
#endif